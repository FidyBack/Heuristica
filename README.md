# Alinhamento de Sequencias de DNA
Repositório contendo os projetos relacionados ao alinhamento de sequencias de DNA, feito por [Abel Cavalcante](https://github.com/FidyBack)

## **Projeto 1 - Heurística de Alinhamento Local de Smith-Waterman**

A primeira entrega, relacionada ao projeto _Heurística de Alinhamento Local de Smith-Waterman_, está na pasta _Heuristica_Smith_Waterman_. Dentro dele, existem 4 arquivos:
* **SequenceGenerator.ipynb:** É o arquivo usado para gerar as sequências aleatoriamente;
* **dna.seq:** Arquivo contendo ambas sequências, assim como o tamanho das mesmas;
* **her:** Executável criado a partir de _heuristica.cc_;
* **heuristica.cc:** Arquivo em C++ que contém o algorítmo em sí.
 
Assim, as seguintes sequências foram utilizadas nesse projeto:

**Sequência 1:**<br/>
_AATCTGGTCTTAGAAACAC-ACC--T-GT-TAGCGCGGGAAACATGCGAT_<br/>
**Tamanho:** 50

**Sequência 2:**<br/>
_TTTGAGCCA-GG-C-A--TTGCCTGCA-TGTCAATAGA-ACACTCAT-TCG-TGGTG-CC-G--ATG-TA--GG-ACG--TGAC-ATATC--TGCTTCCGTGG-TGC-AGTTATAGAGCATACCAGAACATCGCATTAGGTCTAG-C-G-CTT-AATCCGTCTGTGGGCG--CCATTTAGGTTTACA---AAC-ATACCGA-CGCG-GACTAG-A-TCTAAGTAG---TT-TCTAAC-T--AGAAGTGTTAGA-AC-TGTA-CAGT-TC-TT-CA-AC-T-TCAA-CG--AACAT--ATAGAGTTGAA-C-GCCGGCCAGG-TC-AAGAAATGTCGGTG-CTTCTAACTGC-CTGCATTGTGAT-G-CAC-A-G-GGACTTTTAAG-CGAATCTT-GCTCGTCGCT--CTACACAACTGCATAT--CTA-TAGC-AC--CGGGC-TGGT-A-G-GTCCAAA----ATCTGT--TATACTC-AC-AT-GAAACA--CAG--TC-AATTGGCCA-TCGAAAT-AG--ATTAC--CATCGCAAGATTCTCA-TTC-TGCT-ACAT--CCGCCC-CCAA--CGTCC--TTTACAAACCGAGTCAGCGGT-CTTC-AATT-A--CCGAC-CGAAGTCCC-G-G-TTA-GTCTTG--TCTT-TTG-GGAG-GC-C-AA-ACCGGT-CT--GAATATA--GTGGT--ATAACAG-GAGAGCCCT-CGTCCTA--CAC-GG-TA-TC-TTGG--ATA-TTCGAATT-TT-GT-TAGCCAC-GC-CAA-AAGGAGCGGTC-ATGTCA-AGC-CTTTGCATC-AATG-C-CTC-AAACTATGCAAGCGATGACTCGGTCG-GGGCACG-GGT--TC-CCAC-ATAGTAGCG-CGTTCGCGGC-TC-TATGCAT-TT-GC-A-TTT-CAAGGT-TA-AT-TT-TATCGTT-C-TACCTGA-AG--TATCC-TCTC-TC-GTTGCG--TAATC-G-G-C--CT-ATCC-AGT_<br/>
**Tamanho:** 1000

É possível rodar o algorítmo com o seguinte comando:
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
A segunda entrega, que se encontra na pasta _Alinhamento_Local_, possui uma estrutura parecida com a do primeiro projeto, porém com 3 arquivos:
* **dna.seq:** Arquivo contendo ambas sequências, assim como o tamanho das mesmas;
* **ali:** Executável criado a partir de _alinhamento.cc_;
* **alinhamento.cc:** Arquivo em C++ que contém o algorítmo em sí.
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

Além disso, também é possivel rodar:
```
./ali < dna.seq -m
```
Para uma lista comleta de todas as Sa geradas, para efeito de comparação:
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
