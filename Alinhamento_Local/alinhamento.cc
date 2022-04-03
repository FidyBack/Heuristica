// randRange foi feita a partir de: https://www.reddit.com/r/cpp_questions/comments/37cy1g/why_does_rand_high_low_1_low_work/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>
#include <string.h>
#include <chrono> 

int randRange (int low, int high) {
    return rand() % (high - low + 1) + low;
}

int matriz (int n, int m, std::vector<char> seq1, std::vector<char> seq2) {
	std::vector<std::tuple<int, int, int>> matr;
	
	matr.reserve(n*m);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				matr.push_back(std::make_tuple(0, i*(m+1)+j, 0));
			}
			else {
				// Calcula Diagonal, Na esquerda e Acima
				int diag = 0;
				if (seq1[i-1] == seq2[j-1]) {
					diag = std::get<0>(matr[(i-1)*(m+1)+(j-1)]) + 2;
				}
				else {
					diag = std::get<0>(matr[(i-1)*(m+1)+(j-1)]) - 1;
				}
				int inser = std::get<0>(matr[i*(m+1)+(j-1)]) - 1;
				int del = std::get<0>(matr[(i-1)*(m+1)+j]) - 1;

				// Procura o maior valor e armazena na tupla (valor, index)
				if (diag < 0 && inser < 0 && del < 0) {
					matr.push_back(std::make_tuple(0, i*(m+1)+j, i*(m+1)+j));
				}
				else if (diag >= inser && diag >= del) {
					matr.push_back(std::make_tuple(diag, i*(m+1)+j, (i-1)*(m+1)+(j-1)));
				}
				else if (inser > del) {
					matr.push_back(std::make_tuple(inser, i*(m+1)+j, i*(m+1)+(j-1)));
				}
				else {
					matr.push_back(std::make_tuple(del, i*(m+1)+j, (i-1)*(m+1)+j));
				}
			}
		}
	}

	return std::get<0>(*std::max_element(matr.begin(), matr.end())); // Retorna o maior valor da matriz
}

int main(int argc, char const *argv[]) {
	// Seed usada: 30
	srand(30);

	// Inputs
	std::vector<char> seq1, seq2;
	int n, m = 0;
	std::cin >> n >> m;
	seq1.reserve(n);
	seq2.reserve(m);

	for (int i = 0; i < n; i++) {
		char z;
		std:: cin >> z;
		seq1.push_back(z);
	}

	for (int i = 0; i < m; i++) {
		char z;
		std::cin >> z;
		seq2.push_back(z);
	}

	// Medida de tempo
	auto start = std::chrono::high_resolution_clock::now();

	// Criação das sequiências aleatórias
	std::vector<char> seq2_rand;
	int k = 0, j = 0;
	int p = (m/n)*1.5;

	if (m <= n) {	// Tamanho depende de quem é a maior sequência
		k = randRange(1, m);
	} else {
		k = randRange(1, n);
	}

	j = randRange(0, m); // Posição inicial da sequência aleatória (j+k não deve passar o tamanho da sequência)
	if (j+k > m) {
		j = m - k;
	}

	seq2_rand.reserve(k);
	for (int i = 0; i < k; i++) {
		seq2_rand.push_back(seq2[j]);
		j++;
	}

	// Print
	std::cout << "Sb: "; // Sequência Sb
	for (int i = 0; i < k; i++) {
		std::cout << seq2_rand[i];
	}
	std::cout << std::endl;

	// Cálculo das P sequências e o máximo
	std::vector<int> max_values;
	max_values.reserve(p);
	for (int z = 0; z < p; z++) {
		std::vector<char> seq1_rand;
		int i = 0;
		
		i = randRange(0, n); // Posição inicial da sequência aleatória (i+k não deve passar o tamanho da sequência)
		if (i+k > n) {
			i = n - k;
		}

		seq1_rand.reserve(k);
		for (int w = 0; w < k; w++) {
			seq1_rand.push_back(seq1[i]);
			i++;
		}

		int max = matriz(k, k, seq1_rand, seq2_rand);
		max_values.push_back(max);

		// Print das Sequências Sa
		if (argc == 2) {
			if (strcmp(argv[1], "-m") == 0) {
				std::cout << "Sa[" << z << "]: ";
				for (int i = 0; i < k; i++) {
					std::cout << seq1_rand[i];
				}
				std::cout << "  Máximo: " << max << std::endl; // Print Máximo daquela comparação
			}
		}
	}

	// Maior elemento encontrado
	std::cout << "Máximo: " << *std::max_element(max_values.begin(), max_values.end()) << std::endl;

	// Medida de tempo
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsed = end - start;
	std::cout << "Tempo: " << elapsed.count() << " ms";
	std::cout << std::endl;

	return 0;
}
