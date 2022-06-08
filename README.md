# Alinhamento de Sequencias de DNA
Repositório contendo os projetos relacionados ao alinhamento de sequencias de DNA, feito por [Abel Cavalcante](https://github.com/FidyBack)

## **Projeto 1 - Heurística de Alinhamento Local de Smith-Waterman**

A primeira entrega, relacionada ao projeto *Heurística de Alinhamento Local de Smith-Waterman*, está na pasta *Heuristica_Smith_Waterman*. Dentro dele, existem 4 arquivos:
- **SequenceGenerator.ipynb:** É o arquivo usado para gerar as sequências aleatoriamente;
- **dna.seq:** Arquivo contendo ambas sequências, assim como o tamanho das mesmas;
- **her:** Executável criado a partir de *heuristica.cc*;
- **heuristica.cc:** Arquivo em C++ que contém o algoritmo em si.
 
Assim, as seguintes sequências foram utilizadas nesse projeto:

**Sequência 1:**<br/>
*AATCTGGTCTTAGAAACAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT*<br/>
**Tamanho:** 50

**Sequência 2:**<br/>
*TTTGAGCCA-GG-C-A--TTGCCTGCA-TGTCAATAGA-ACACTCAT-TCG-TGGTG-CC-G--ATG-TA--GG-ACG--TGAC-ATATC--TGCTTCCGTGG-TGC-AGTTATAGAGCATACCAGAACATCGCATTAGGTCTAG-C-G-CTT-AATCCGTCTGTGGGCG--CCATTTAGGTTTACA---AAC-ATACCGA-CGCG-GACTAG-A-TCTAAGTAG---TT-TCTAAC-T--AGAAGTGTTAGA-AC-TGTA-CAGT-TC-TT-CA-AC-T-TCAA-CG--AACAT--ATAGAGTTGAA-C-GCCGGCCAGG-TC-AAGAAATGTCGGTG-CTTCTAACTGC-CTGCATTGTGAT-G-CAC-A-G-GGACTTTTAAG-CGAATCTT-GCTCGTCGCT--CTACACAACTGCATAT--CTA-TAGC-AC--CGGGC-TGGT-A-G-GTCCAAA----ATCTGT--TATACTC-AC-AT-GAAACA--CAG--TC-AATTGGCCA-TCGAAAT-AG--ATTAC--CATCGCAAGATTCTCA-TTC-TGCT-ACAT--CCGCCC-CCAA--CGTCC--TTTACAAACCGAGTCAGCGGT-CTTC-AATT-A--CCGAC-CGAAGTCCC-G-G-TTA-GTCTTG--TCTT-TTG-GGAG-GC-C-AA-ACCGGT-CT--GAATATA--GTGGT--ATAACAG-GAGAGCCCT-CGTCCTA--CAC-GG-TA-TC-TTGG--ATA-TTCGAATT-TT-GT-TAGCCAC-GC-CAA-AAGGAGCGGTC-ATGTCA-AGC-CTTTGCATC-AATG-C-CTC-AAACTATGCAAGCGATGACTCGGTCG-GGGCACG-GGT--TC-CCAC-ATAGTAGCG-CGTTCGCGGC-TC-TATGCAT-TT-GC-A-TTT-CAAGGT-TA-AT-TT-TATCGTT-C-TACCTGA-AG--TATCC-TCTC-TC-GTTGCG--TAATC-G-G-C--CT-ATCC-AGT*<br/>
**Tamanho:** 1000

É possível rodar o algoritmo com o seguinte comando:
```
./her < dna.seq
```
E, caso seja necessário recompilar o arquivo, o seguinte comando deve ser utilizado:
```
g++ -Wall -O3 heuristica.cc -o her
```

O programa responderá com o melhor mach de ambas sequências de DNA. Nesse caso, o output do programa será:
```
AATC_T_G___GT__CT___TAGA_AAC_AC-ACC--T-GT_-TAG___C_GCGGGAAACATGCGAT
**** * *   **  **   **|* *** |* *|||* *|* ****   * |****   *|** * *
AATCTT-GCTCGTCGCT--CTACACAACTGC_ATAT-_-CTA-TAGC-AC--CGGG___C-TG_G_T
```
Sendo possível validar usando a [Freiburg RNA Tools](http://rna.informatik.uni-freiburg.de/Teaching/index.jsp?toolName=Smith-Waterman)<br/>
![Imagem_site](/Heuristica_Smith_Waterman/Imagens/comparacao_site.png)

Além disso, também será mostrado o tempo que levou do começo até o final da execução do código, em ms. 

É possível, ainda, executar:
```
./her < dna.seq -m
```
Para a visualização da matriz completa.

## **Projeto 2 - Um algoritmo Local para Alinhamento**
A segunda entrega, que se encontra na pasta *Alinhamento_Local*, possui uma estrutura parecida com a do primeiro projeto, porém com 3 arquivos:
- **dna.seq:** Arquivo contendo ambas sequências, assim como o tamanho das mesmas;
- **ali:** Executável criado a partir de *alinhamento.cc*;
- **alinhamento.cc:** Arquivo em C++ que contém o algoritmo em si.
E foram usadas as mesmas sequências com os mesmos tamanhos do projeto 1.

Tendo isso em mente, o projeto segue o mesmo esquema de compilação e execução:
```
g++ -Wall -O3 alinhamento.cc -o ali
./ali < dna.seq
```
Porém, nesse caso, o programa responderá com 3 coisas: Sb, ou o pedaço da sequência 2 que foi utilizado, o valor máximo que foi obtido entre as comparações realizadas e o tempo que levou para o programa ser executado.

Como o programa foi executado usando uma **seed = 30, os resultados podem ser replicados.**<br/>
Assim, para esse caso, foi possível extrair os seguintes resultados:
```
Sb: CTTG--TCTT-TTG-GGAG-GC-C-AA-ACCGGT
Máximo: 20
```
Com um tempo levemente variável.

Além disso, também é possível rodar:
```
./ali < dna.seq -m
```
Para uma lista completa de todas as Sa geradas, para efeito de comparação:
```
./ali < dna.seq -m
Sb: CTTG--TCTT-TTG-GGAG-GC-C-AA-ACCGGT
Sa[0]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[1]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[2]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[3]: CTGGTCTTAGAAACAC-ACC--T-GT-TAGCGCG  Máximo: 16
Sa[4]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[5]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[6]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[7]: GGTCTTAGAAACAC-ACC--T-GT-TAGCGCGGG  Máximo: 15
Sa[8]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[9]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[10]: AACAC-ACC--T-GT-TAGCGCGGGAAACATGCG  Máximo: 19
Sa[11]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[12]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[13]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[14]: AGAAACAC-ACC--T-GT-TAGCGCGGGAAACAT  Máximo: 18
Sa[15]: AATCTGGTCTTAGAAACAC-ACC--T-GT-TAGC  Máximo: 15
Sa[16]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[17]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[18]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[19]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[20]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[21]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[22]: CTGGTCTTAGAAACAC-ACC--T-GT-TAGCGCG  Máximo: 16
Sa[23]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[24]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[25]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Sa[26]: TGGTCTTAGAAACAC-ACC--T-GT-TAGCGCGG  Máximo: 17
Sa[27]: TAGAAACAC-ACC--T-GT-TAGCGCGGGAAACA  Máximo: 18
Sa[28]: CTGGTCTTAGAAACAC-ACC--T-GT-TAGCGCG  Máximo: 16
Sa[29]: CAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT  Máximo: 20
Máximo: 20
```

## **Projeto 3 - Busca Exaustiva**
O terceiro projeto, que se encontra na pasta *Busca_Exaustiva*, possui a mesma estrutura do segundo projeto:
- **dna.seq:** Arquivo contendo ambas sequências, assim como o tamanho das mesmas;
- **exaust:** Executável criado a partir de *exaustiva.cc*;
- **exaustiva.cc:** Arquivo em C++ que contém o algoritmo em si.
E foram usadas as mesmas sequências com os mesmos tamanhos do projeto 1 e 2.

Tendo isso em mente, o projeto segue o mesmo esquema de compilação e execução dos anteriores:
```
g++ -Wall -O3 exaustiva.cc -o exaust
./exaust < dna.seq
```

O programa funciona usando o seguinte algoritmo:
1. A menor sequência é selecionada e todaas suas subsequências são calculadas;
2. Cada subsequência é comparada com cada elemento da sequência maior.
 
Ou seja, em um exemplo prático, se temos as duas sequências
```
ABCD
123
```
O programa fará o seguinte processo:
```
123 -> [1, 2, 3, 12, 23, 123];
```
E as segintes comparações:
```
1 -> A, 1 -> B, 1 -> C, 1 -> D;
2 -> A, 2 -> B, 2 -> C, 2 -> D;
3 -> A, 3 -> B, 3 -> C, 3 -> D;
12 -> AB, 12 -> BC, 12 -> CD;
23 -> AB, 23 -> BC, 23 -> CD;
123 -> ABC, 123 -> BCD.
```

Levando isso em consideração, o resultado atingido foi:
```
Score Máximo: 19
Subsequência Menor: ACC--T-GT-TAGC
Subsequência Maior: ATT-TT-GT-TAGC
```
Com um tempo levemente variável.

## **Relatório Intermediário**
O Relatório Intermediário está localizado dentro do diretório *Relatorio_Preliminar*, e possui tanto a extensão .ipynb qunato .html que pode ser vista [aqui](https://htmlpreview.github.io/?https://github.com/FidyBack/Heuristica/blob/master/Relatorio_Preliminar/Relatorio_Abel.html).

Caso seja necessário baixar e testar os algoritmos, é necessário descompactar as entradas presentes em *Entradas/entradas_8*.

## **Projeto 4 - OpenMP**
O quarto projeto, que se encontra na pasta *OpenMP*, possui a mesma estrutura do segundo e terceiro projeto:
- **dna.seq:** Arquivo contendo ambas sequências, assim como o tamanho das mesmas;
- **open:** Executável criado a partir de *openmp.cc*;
- **openmp.cc:** Arquivo em C++ que contém o algoritmo em si.
E foram usadas as mesmas sequências com os mesmos tamanhos dos outros projetos.
 
Tendo isso em mente, o projeto segue o mesmo esquema de compilação e execução dos anteriores:
```
g++ -Wall -O3 -fopenmp openmp.cc -o open
./open < dna.seq
```
Todavia, para a compilação desse programa, a flag *-fopenmp* é necessária.

Esse programa foi feito baseando-se no algoritmo do projeto 3, e tem como objetivo paralelizar o mesmo. Levando isso em conta, é possível observar três pontos principais no código original:  
 
<p align="center">
  <img src="/OpenMP/Imagens/firstPart.png">
</p>
 
<p align="center">
  <img src="/OpenMP/Imagens/secondPart.png">
</p>
 
<p align="center">
  <img src="/OpenMP/Imagens/thirdPart.png">
</p>
 
Analisando cada uma delas, é possível perceber que, por fazer chamadas de push_back, paralelizar a segunda parte do código não seria vantajoso, porém, as outras partes aceitam paralelização. Levando isso em conta, cada parte do código será paralelizada de maneira diferente:
 
A primeira parte usará *#pragma omp parallel* juntamente com *#pragma omp single*
 
<p align="center">
  <img src="/OpenMP/Imagens/firstPartChanged.png">
</p>
 
Já a terceira será paralelizada usando *#pragma omp parallel for reduction(max:max_score)*
 
<p align="center">
  <img src="/OpenMP/Imagens/thirdPartChanged.png">
</p>

## **Projeto 5 - GPU**
O quinto e ultimo projeto, que se encontra na pasta *GPU*, possui a mesma estrutura do segundo, terceiro e quarto projeto:
- **dna.seq:** Arquivo contendo ambas sequências, assim como o tamanho das mesmas;
- **gpu:** Executável criado a partir de *openmp.cc*;
- **gpu.cu:** Arquivo em CUDA que contém o algoritmo em si.
Com a única diferença de que o arquivo utilizado é do tipo CUDA ao invés de C++. Além disso, foram usadas as mesmas sequências com os mesmos tamanhos dos outros projetos.
 
Tendo isso em mente, o projeto possui um sistema de compilação um tanto único:
```
nvcc -arch=sm_70 -std=c++14 gpu.cu -o gpu
./gpu < dna.seq
```
Por sua estrutura ser baseada em CUDA, é necessário a compilação usando *nvcc* ao invés de *g++* ou *g++*. Além disso, flags especiais são necessárias. A flag *-arch=sm_70*, de acordo com a documentação oficial da Nvidia para a linguagem CUDA:


> Specify the name of the class of NVIDIA virtual GPU architecture for which the CUDA input files must be compiled.

Assim, nesse caso, a arquitetura da GPU utilizada no mosntão é a *sm_70*. Já a flag *-std=c++14* basicamente define qual versão do C++ será utilizada, já que CUDA é uma extensão do C++.

Esse programa foi feito baseando-se no algoritmo do projeto 3, e tem como objetivo executá-lo em uma GPU utilizando a biblioteca **THRUST**. Para isso, é necessário realizar uma série de mudanças e adições em relação ao código original:

1. Foram importadas as bibliotecas do Thrust que serão utilizadas:
2. Um struct *calculate_score* foi sdicionado. Ele pega dois elementos do tipo 'char' e devolve 2 se forem iguais, se não, ele retorna -1:
3. Os vetores são inicialmente armazenados em iteradores do tipo *thrust::host_vector<char>*, e posteriormente convertidos para *thrust::device_vector<char>*:
4. Ao invés de armazenar as subsequências, agora um *thrust::device_vector* armazena os indices iniciais e finais de cada subsequência:
5. As subsequências são comparadas usando um *thrust::transform*, e o resultado é armazenado em um terceiro vetor, que tem seus elementos somados usando o *thrust::reduce* e o score máximo é obtido:

 ## **Relatório Final**
O Relatório Final está localizado dentro do diretório *Relatorio_Final*, e possui tanto a extensão .ipynb qunato .html que pode ser vista [aqui](https://htmlpreview.github.io/?https://github.com/FidyBack/Heuristica/blob/master/Relatorio_Preliminar/Relatorio_Abel.html).
