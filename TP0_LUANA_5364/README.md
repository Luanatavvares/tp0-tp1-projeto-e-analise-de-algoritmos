# 🎨 Trabalho Prático 0 — Projeto e Análise de Algoritmos  
## Geração de Obras de Arte Aleatórias com Matrizes

Este trabalho tem como objetivo introduzir conceitos fundamentais de programação em C no contexto da disciplina **Projeto e Análise de Algoritmos (PAA)**, por meio da criação de um programa capaz de gerar **"obras de arte" aleatórias**. O projeto utiliza uma matriz para representar um quadro e desenha figuras simples, como asteriscos, símbolos variados e até uma casinha, de forma totalmente aleatória. A ideia é permitir que cada execução produza um resultado único, explorando tanto criatividade quanto lógica algorítmica.

A proposta combina **uso de números aleatórios**, **manipulação de matrizes**, **verificação de espaço**, organização modular com **TADs**, e desenho de formas com coordenadas cuidadosamente calculadas.

## Funcionalidades Principais

- **Posicionamento aleatório:**  
  Cada figura é posicionada por meio de coordenadas aleatórias geradas com `rand()`, garantindo que cada execução produza um quadro diferente.

- **Quantidade de figuras variável:**  
  O usuário pode definir quantas figuras deseja desenhar — ou deixar que o programa escolha um valor aleatório.

- **Variedade de desenhos:**  
  O programa pode gerar:
  - Asteriscos (`*`)  
  - Letras "X"  
  - Símbolos variados  
  - Uma **casinha** completa (telhado, paredes, porta)

- **Verificação de espaço:**  
  Funções específicas garantem que as figuras não ultrapassem os limites da matriz e não se sobreponham.

- **Desenho estruturado da casinha:**  
  A casinha é o desenho mais complexo, composta por múltiplas linhas de asteriscos formando base, paredes e telhado.

## Principais Desafios e Soluções

Durante o desenvolvimento, surgiram desafios importantes relacionados ao uso da matriz como espaço limitado para desenhar:

###  1. Espaço insuficiente na matriz  
Como algumas figuras (especialmente a casinha) ocupam muitos espaços, tornou-se essencial detectar quando não havia mais área disponível para continuar desenhando.  
**Solução:**  
Foi criada a função **`espacoDisponivel()`**, que percorre o quadro e determina se ainda há área livre suficiente para novos desenhos.

###  2. Sobreposição de figuras  
As coordenadas aleatórias poderiam colocar uma figura em cima de outra.  
**Solução:**  
A função **`areaDisponivel()`** checa se todas as posições necessárias para o desenho estão vazias antes de permitir que ele seja colocado.

###  3. Controle de coordenadas da casinha  
Por ocupar mais linhas e colunas, a casinha não podia ser posicionada muito próximo das bordas da matriz.  
**Solução:**  
O algoritmo ajusta automaticamente as coordenadas para garantir que o desenho sempre caiba dentro do quadro.

## Organização do Projeto

O código foi estruturado usando **TADs** para facilitar manutenção e legibilidade:

- **`quadro.h`** — funções para criar, imprimir e verificar áreas livres no quadro.  
- **`figura.c`** — funções responsáveis por criar as figuras (asteriscos, X, casa etc.).

Além disso, foi criado um **Makefile** para automatizar a compilação do projeto.

## Como Executar

Para compilar e executar o programa, basta rodar no terminal:

```bash
make
./programa
