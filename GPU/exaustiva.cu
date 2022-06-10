#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <vector>
#include <chrono>

template<typename T = void>
struct calculate_score
{
	int score;
	calculate_score(int score) : score(score) {};

	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef int result_type;

    __host__ __device__
    int operator()(const T &x, const T &y) {
		if (x == y) {
			score = 2;
		}
		else {
			score = -1;
		}
        return score;
    }
};


int main(int argc, char const *argv[]) {
	// Inputs
	int n, m = 0;
	std::cin >> n >> m;
	thrust::host_vector<char> vcpu_seq1(n);
	thrust::host_vector<char> vcpu_seq2(m);

	for (int i = 0; i < n; i++) {
		std:: cin >> vcpu_seq1[i];
	}

	for (int i = 0; i < m; i++) {
		std::cin >> vcpu_seq2[i];
	}

	// Define seq1 e n como a maior sequencia
	if (n < m) {
		std::swap(vcpu_seq1, vcpu_seq2);
		std::swap(n, m);
	}

	// Passa para a GPU
	thrust::device_vector<char> vgpu_seq1(vcpu_seq1);
	thrust::device_vector<char> vgpu_seq2(vcpu_seq2);


	// Medida de tempo
	auto start = std::chrono::high_resolution_clock::now();

	// Divide seq2 em indexes de subsequencias e manda para a GPU
	std::vector<int> subseqs;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= i; j++) {
			if (j != i) {
				for (int k = j; k <= i; k++) {
					if (k == j || k == i) {
						subseqs.push_back(k);
					}
				}
			}
		}
	}
	thrust::device_vector<int> vgpu_indexes(subseqs);


	// Compara as subsequências na GPU
	int score = 0, max_score = 0;
	for (int i = 0; i < int(vgpu_indexes.size()); i+=2) {
		for (int j = 0; j < n; j++) {
			int tam_subseq = vgpu_indexes[i+1] - vgpu_indexes[i];
			if (tam_subseq + j <= vgpu_seq1.size()) {
				thrust::device_vector<int> vgpu_score(tam_subseq+1);
				thrust::transform(vgpu_seq2.begin()+vgpu_indexes[i], vgpu_seq2.end()+vgpu_indexes[i+1], vgpu_seq1.begin()+j, vgpu_score.begin(), calculate_score<char>(score));
				
				max_score = thrust::reduce(vgpu_score.begin(), vgpu_score.end(), 0) > max_score ? thrust::reduce(vgpu_score.begin(), vgpu_score.end(), 0) : max_score;
			}
		}
	}

 	std::cout <<"Score Máximo: " << max_score << std::endl;

	// Medida de tempo
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "Tempo: " << elapsed.count() << " ms";
	std::cout << std::endl;

	return 0;
}