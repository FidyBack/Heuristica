#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <vector>
#include <chrono>


// struct calculate_score 
// {
// 	int score;
// 	__host__ __device__
// 	int operator()(const char &lhs, const char &rhs) 
// 	{
// 	for (int i = 0; i < lhs.size(); i++) {
// 		if (lhs == rhs) {
// 			score += 2;
// 		}
// 		else {
// 			score -= 1;
// 		}
// 	}
// 	return score;
//   }
// };


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

	// Define seq1 como a maior sequencia
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
	thrust::device_vector<int> vgpu_out(subseqs.size());

	// Compara as subsequências na GPU
	for (int i = 0; i < int(vgpu_indexes.size()); i+=2) {
		for (int j = 0; j < n; j++) {
			if ((vgpu_indexes[i+1] - vgpu_indexes[i] - j) < m) {
				std::cout << vgpu_seq2[i] << " " << vgpu_seq2[i+1] << std::endl;
			// 	std::cout << vgpu_seq1[j] << " " << vgpu_seq1[j + (vgpu_indexes[i+1] - vgpu_indexes[i])] << std::endl;
				// thrust::transform(vgpu_seq2.begin() + vgpu_indexes[i], vgpu_seq2.begin() + vgpu_indexes[i+1], vgpu_seq1.begin() + j, vgpu_out.begin() + j, thrust::equal_to<char>());
				// std::cout << vgpu_out[j] << std::endl;
			}
		}
	}
	


	// std::cout <<"Score Máximo: " << max_score << std::endl;
	// std::cout <<"Subsequência Menor: ";
	// for (int i = 0; i < int(max_subseq_minnor.size()); i++) {
	// 	std::cout << max_subseq_minnor[i];
	// }
	// std::cout << std::endl;
	// std::cout <<"Subsequência Maior: ";
	// for (int i = 0; i < int(max_subseq_major.size()); i++) {
	// 	std::cout << max_subseq_major[i];
	// }
	// std::cout << std::endl;

	// // Medida de tempo
	// auto end = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double, std::milli> elapsed = end - start;
	// std::cout << "Tempo: " << elapsed.count() << " ms";
	// std::cout << std::endl;

	// return 0;
}