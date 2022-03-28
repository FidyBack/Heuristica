#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <tuple>

int main(int argc, char const *argv[])
{
	std::vector<char> seq1, seq2;
	std::vector<std::tuple<int, int, int>> matr;

	// Inputs
	int n, m = 0;
	std::cin >> n >> m;
	seq1.reserve(n);
	seq2.reserve(m);
	matr.reserve(n*m);

	for (int i = 0; i < n; i++) {
		char k;
		std:: cin >> k;
		seq1.push_back(k);
	}

	for (int i = 0; i < m; i++) {
		char k;
		std::cin >> k;
		seq2.push_back(k);
	}

	// Cálculo da matriz - O vetor matr tem composição matr[(Valor, Index, Index_Origem)]
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

	// Valor máximo na matriz
	int maxim_glob = std::get<0>(*std::max_element(matr.begin(), matr.end()));

	// Procura o índice do valor máximo
	std::vector<std::tuple<int, int, int>> elements;
	for (auto l : matr) {
		if (std::get<0>(l) == maxim_glob) {
			elements.push_back(std::make_tuple(std::get<0>(l), std::get<1>(l), std::get<2>(l)));
			break;
		}
	}

	// Pega o elemento que originou aquela casa da matriz até chegar em 0
	int index = std::get<2>(elements[0]);
	while (index > 0) {
		std::tuple<int, int, int> next = matr[index];
		elements.push_back(next);
		if (std::get<0>(matr[index]) != 0) {
			index = std::get<2>(matr[index]);
		} else {
			index = 0;
		}
	}

	// Criação da resposta
	std::vector<char> new_seq1, new_seq2, simb_seq;
	new_seq1.reserve(elements.size()-1);
	new_seq2.reserve(elements.size()-1);
	simb_seq.reserve(elements.size()-1);

	int line, column = 0;
	for (int i = int(elements.size()-1); i >= 0; i--) {

		// Para pegar da lista, é necessário fazer a divisão e subtrair -1
		line = std::floor(std::get<1>(elements[i])/(m+1))-1;
		column = std::floor(std::get<1>(elements[i])%(m+1))-1;

		if (std::get<0>(elements[i]) == 0);

		else if (std::get<1>(elements[i])-(m+2) == std::get<2>(elements[i])) {
			if (std::get<0>(elements[i]) == std::get<0>(elements[i+1])+2) {
				new_seq1.push_back(seq1[line]);
				new_seq2.push_back(seq2[column]);
				simb_seq.push_back('*');
			} else {
				new_seq1.push_back(seq1[line]);
				new_seq2.push_back(seq2[column]);
				simb_seq.push_back('|');
			}
		}
		else if (std::get<1>(elements[i])-(m+1) == std::get<2>(elements[i])) {
			new_seq1.push_back(seq1[line]);
			new_seq2.push_back('_');
			simb_seq.push_back(' ');
		}
		else if (std::get<1>(elements[i])-1 == std::get<2>(elements[i])) {
			new_seq1.push_back('_');
			new_seq2.push_back(seq2[column]);
			simb_seq.push_back(' ');
		}
	} 
	std::cout << std::endl;
	
	std::cout << "------------------------------------------------------------" << std::endl;
	for (auto k : new_seq1) {
		std::cout << k;
	}
	std::cout << std::endl;
	for (auto l : simb_seq) {
		std::cout << l;
	}
	std::cout << std::endl;
	for (auto n : new_seq2) {
		std::cout << n;
	}
	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;

	// Print da Tabela
	if (argc == 2) {
		if (strcmp(argv[1], "-m") == 0) {
			std::cout << "    ";
			for (char x : seq2) {
				std::cout << x << " ";
			}
			std::cout << std::endl;

			int ak = 1;
			int count = -1;
			for (auto l : matr) {
				if (count == -1) {
					std::cout << "  ";
					count++;
				}
				if (m+1 < ak) {
					std::cout << std::endl;
					std::cout << seq1[count] << " ";
					count++;
					ak = 1;
				}
				std::cout << std::get<0>(l) << " ";
				ak++;
			}
		}
	}

	std::cout << std::endl;
	return 0;
}
