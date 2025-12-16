# Trabalho Prático 1 — Projeto e Análise de Algoritmos  
## Navegação em Labirintos com Backtracking

Este trabalho implementa um programa em C capaz de **simular a navegação de um estudante em um labirinto**, utilizando técnicas clássicas de **backtracking**, estruturas de dados dinâmicas e manipulação de matrizes. O objetivo é permitir que o estudante parta de uma posição inicial e tente alcançar a saída localizada na parte superior do labirinto, explorando recursivamente todos os caminhos possíveis.

O projeto foi desenvolvido no contexto da disciplina **Projeto e Análise de Algoritmos (PAA)**, com foco na aplicação de conceitos fundamentais como busca recursiva, gerenciamento dinâmico de memória e organização modular do código.

##  Funcionalidades Principais

- **Carregar labirinto de arquivo:**  
  O programa lê um arquivo contendo a matriz do labirinto e identifica automaticamente a posição inicial do estudante.

- **Navegação com backtracking:**  
  A função responsável pelo movimento utiliza uma abordagem recursiva: tenta avançar, marca posições visitadas e retorna (backtrack) ao encontrar becos sem saída.

- **Exibição do caminho percorrido:**  
  Após a busca, o programa mostra passo a passo o trajeto percorrido pelo estudante — ou indica quando não existe solução.

- **Geração de labirinto aleatório (extra):**  
  O usuário pode solicitar a criação de um labirinto aleatório com dimensões personalizadas e quantidade definida de elementos. Esse labirinto pode ser salvo em arquivo para uso posterior.

##  Organização do Projeto

O código foi estruturado de maneira modular, dividido em duas pastas principais:

- **headers/** — arquivos `.h` contendo definições de estruturas, protótipos das funções e constantes utilizadas.
- **sources/** — arquivos `.c` com as implementações de cada módulo, incluindo as funções de leitura do labirinto, busca, geração aleatória, exibição e controle geral do programa.


##  Como Executar

A compilação é feita por meio do **Makefile**, que automatiza todo o processo. No terminal, dentro do diretório do trabalho, execute:

```bash
make
./programa
