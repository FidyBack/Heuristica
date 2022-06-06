#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <vector>
#include <chrono>


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

	// Divide seq2 em todas as subsequencias de todos os tamanhos possiveis
	std::vector<std::vector<char>> subseqs;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= i; j++) {
			std::vector<char> subseq;
			for (int k = j; k <= i; k++) {
				subseq.push_back(seq2[k]);
			}
			subseqs.push_back(subseq);
		}
	}

	// // Compara as subsequências
	// int max_score = 0;
	// std::vector<char> max_subseq_minnor, max_subseq_major;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < int(subseqs.size()); j++) {
	// 		int score = 0;
	// 		std::vector<char> seq1_subseq;
	// 		if (i+int(subseqs[j].size()) <= n) {
	// 			for (int k = 0; k < int(subseqs[j].size()); k++) {
	// 				seq1_subseq.push_back(seq1[i+k]);
	// 				if (seq1[i+k] == subseqs[j][k]) {
	// 					score += 2;
	// 				}
	// 				else {
	// 					score -= 1;
	// 				}
	// 			}
	// 			if (score > max_score) {
	// 				max_score = score;
	// 				max_subseq_minnor = subseqs[j];
	// 				max_subseq_major = seq1_subseq;
	// 			}
	// 		}
	// 	}
	// }


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