# Trabalho Prático 1: Expressões Booleanas

## Introdução

Este projeto é um programa em C++ que resolve expressões booleanas e verifica a satisfiabilidade das mesmas. O programa é capaz de receber expressões via linha de comando e avaliar se são verdadeiras ou falsas, além de verificar se existem valores que satisfazem determinadas equações booleanas.

## Estrutura do Projeto

### Ambiente de Desenvolvimento

- **Linguagem:** C++
- **Compilador:** gcc

### Tipos Abstratos de Dados

- **Pilha Genérica:** Utilizada para armazenar operandos (inteiros) e operadores (caracteres).
- **Árvore Binária:** Implementada usando apontadores, utilizada para avaliar expressões booleanas.

### Principais Métodos

1. **evaluate:** Avalia a expressão booleana e retorna 1 ou 0.
2. **Construtor da Árvore:** Gera duas folhas (com valores 1 e 0) para cada quantificador de forma recursiva.
3. **Percurso da Árvore:** Avalia a expressão em cada folha e verifica o resultado considerando os quantificadores.

## Complexidade

- **Temporal:** O(n) para `evaluate`, O(2^n) para a verificação de satisfiabilidade.
- **Espacial:** O(n) para `evaluate`, O(2^n) para a verificação de satisfiabilidade.

## Estratégias de Robustez

- Utilização de valgrind para detectar vazamentos de memória.
- Uso extensivo de exceções para tratar entradas inválidas e comportamentos inesperados.
- Código padronizado em C++ com comentários e documentação em javadoc.

## Análise Experimental

Testes de desempenho confirmaram a complexidade teórica. O algoritmo `evaluate` mostrou crescimento linear em relação ao tamanho da expressão, enquanto a verificação de satisfiabilidade exibiu crescimento exponencial com a quantidade de quantificadores.

## Conclusão

O programa resolve expressões booleanas e verifica satisfiabilidade de maneira eficiente, utilizando pilhas e árvores binárias, revisitando conceitos importantes de POO e estruturas de dados.

## Referências

1. Slides da disciplina fornecidos pelos professores no Moodle.
2. Cormen, T., Leiserson, C., Rivest R., Stein, C. "Introduction to Algorithms," Third Edition, MIT Press, 2009.
3. Kenneth H. Rosen, "Discrete Mathematics and Its Applications," Eighth Edition.
4. [GeeksforGeeks: Expression Evaluation](https://www.geeksforgeeks.org/expression-evaluation/) acessado em 13 de outubro de 2023.
