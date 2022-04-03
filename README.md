# Alinhamento de Sequencias de DNA
Repositório contendo os projetos relacionados ao alinhamento de sequencias de DNA, feito por [Abel Cavalcante](https://github.com/FidyBack)

## **Projeto 1 - Heurística de Alinhamento Local de Smith-Waterman**

A primeira entrega, relacionada ao projeto _Heurística de Alinhamento_ Local de Smith-Waterman, está na pasta _Heuristica_Smith_Waterman_. Dentro dele, existem 4 arquivos:
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
Além disso, também será mostrado o tempo que levou do começo até o final da execução do código, em ms. 

É possível, ainda, executar:
```
./her < dna.seq -m
```
Para a visualização da matriz completa.
