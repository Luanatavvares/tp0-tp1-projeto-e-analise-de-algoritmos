#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers/quadro.h"

int main() {
    Quadro quadro;
    int tipoFigura, qtdFiguras;
    char continuar;

    srand(time(NULL)); 

    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");
    printf("Escolha o tipo de figura básica a ser usada para criar a obra:\n");
    printf("1 - asterisco simples\n");
    printf("2 - símbolo de soma com asteriscos\n");
    printf("3 - letra X com asteriscos\n");
    printf("4 - figuras aleatórias\n");
    printf("5 - casa com asteriscos\n");
    printf("6 - figuras aleatórias incluindo a casa\n");

    printf("Digite o tipo de figura desejada: ");
    scanf("%d", &tipoFigura);
    
    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatório): ");
    scanf("%d", &qtdFiguras);
    
    if (qtdFiguras <= 0) {
        qtdFiguras = rand() % 100 + 1; 
    } else if (qtdFiguras > 100) {
        qtdFiguras = 100; 
    }

    do {
        inicializarQuadro(&quadro);
        int figurasDesenhadas = 0;

        for (int i = 0; i < qtdFiguras; i++) {
            int x, y, tipoFiguraAleatoria;

            do {
                x = rand() % (LINHAS - 2) + 2;  
                y = rand() % (COLUNAS - 4) + 2; 

                if (tipoFigura == 4) {
                    tipoFiguraAleatoria = rand() % 3 + 1;  
                } else if (tipoFigura == 6) {
                    tipoFiguraAleatoria = rand() % 5 + 1; 
                } else {
                    tipoFiguraAleatoria = tipoFigura;  
                }

                

            } while (!areaDisponivel(&quadro, x, y, tipoFiguraAleatoria));

            desenharFigura(&quadro, tipoFiguraAleatoria, x, y);
            figurasDesenhadas++;

            if (!espacoDisponivel(&quadro, tipoFiguraAleatoria)) {
                printf("Não há mais espaço disponível para desenhar novas figuras.\n");
                break;
            }
        }

        imprimirQuadro(&quadro);
        printf("Foram desenhadas %d figuras no total.\n", figurasDesenhadas);

        printf("Deseja criar um novo quadro com as mesmas opções? (s/n): ");
        scanf(" %c", &continuar); 

    } while (continuar == 's' || continuar == 'S'); 

    return 0;
}
