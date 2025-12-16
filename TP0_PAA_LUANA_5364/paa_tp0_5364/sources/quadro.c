#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/quadro.h"

void inicializarQuadro(Quadro *quadro) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == 0 || i == LINHAS - 1) {
                quadro->matriz[i][j] = '-';
            } else if (j == 0 || j == COLUNAS - 1) {
                quadro->matriz[i][j] = '|';
            } else {
                quadro->matriz[i][j] = ' ';
            }
        }
    }
}

void imprimirQuadro(Quadro *quadro) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", quadro->matriz[i][j]);
        }
        printf("\n");
    }
}

int areaDisponivel(Quadro *quadro, int x, int y, int tipoFigura) {
    switch (tipoFigura) {
        case 1: 
            return quadro->matriz[x][y] == ' ' &&
                   quadro->matriz[x][y - 1] == ' ' &&
                   quadro->matriz[x][y + 1] == ' ' &&
                   quadro->matriz[x - 1][y] == ' ' &&
                   quadro->matriz[x + 1][y] == ' ';
                   
        case 2: 
            return quadro->matriz[x][y] == ' ' &&
                   quadro->matriz[x - 1][y] == ' ' &&
                   quadro->matriz[x + 1][y] == ' ' &&
                   quadro->matriz[x][y - 1] == ' ' &&
                   quadro->matriz[x][y + 1] == ' ' &&
                   quadro->matriz[x - 1][y - 1] == ' ' &&
                   quadro->matriz[x - 1][y + 1] == ' ' &&
                   quadro->matriz[x + 1][y - 1] == ' ' &&
                   quadro->matriz[x + 1][y + 1] == ' ';
                   
        case 3: 
            return quadro->matriz[x][y] == ' ' &&
                   quadro->matriz[x - 1][y - 1] == ' ' &&
                   quadro->matriz[x + 1][y + 1] == ' ' &&
                   quadro->matriz[x - 1][y + 1] == ' ' &&
                   quadro->matriz[x + 1][y - 1] == ' ' &&
                   quadro->matriz[x - 1][y] == ' ' &&
                   quadro->matriz[x + 1][y] == ' ' &&
                   quadro->matriz[x][y - 1] == ' ' &&
                   quadro->matriz[x][y + 1] == ' ';
                   
        case 5: 
            for (int i = -3; i <= 3; i++) {
                if (quadro->matriz[x][y + i] != ' ') {
                    return 0;
                }
            }
            if (quadro->matriz[x + 1][y - 1] != ' ' || quadro->matriz[x + 1][y] != ' ') {
                return 0;
            }
            if (quadro->matriz[x + 1][y - 3] != ' ' || quadro->matriz[x + 1][y + 3] != ' ' ||
                quadro->matriz[x + 2][y - 3] != ' ' || quadro->matriz[x + 2][y + 3] != ' ' ||
                quadro->matriz[x + 2][y + 2] != ' ' || quadro->matriz[x + 2][y + 1] != ' ' ||
                quadro->matriz[x + 2][y] != ' ' || quadro->matriz[x + 2][y - 1] != ' ' ||
                quadro->matriz[x + 2][y - 2] != ' ') {
                return 0;
            }
            for (int i = -2; i <= 2; i++) {
                if (quadro->matriz[x - 1][y + i] != ' ') {
                    return 0;
                }
            }
            if (quadro->matriz[x - 2][y] != ' ') {
                return 0;
            }
            return 1;

        default:
            return 0;
    }
}




void desenharFigura(Quadro *quadro, int tipoFigura, int x, int y) {
    switch (tipoFigura) {
        case 1: // Asterisco simples
            quadro->matriz[x][y] = '*';
            break;
        case 2: // Símbolo de soma
            quadro->matriz[x][y] = '*';
            quadro->matriz[x-1][y] = '*';
            quadro->matriz[x+1][y] = '*';
            quadro->matriz[x][y-1] = '*';
            quadro->matriz[x][y+1] = '*';
            break;
        case 3: // Letra X
            quadro->matriz[x][y] = '*';
            quadro->matriz[x-1][y-1] = '*';
            quadro->matriz[x+1][y+1] = '*';
            quadro->matriz[x-1][y+1] = '*';
            quadro->matriz[x+1][y-1] = '*';
            break;


        
        case 5: // Casinha 
            for (int i = -3; i <= 3; i++) {  
                quadro->matriz[x][y+i] = '*'; 
            }

            quadro->matriz[x+1][y-1] = ' ';
            quadro->matriz[x+1][y] = ' ';

            quadro->matriz[x+1][y-3] = '*';  
            quadro->matriz[x+1][y+3] = '*';
            quadro->matriz[x+2][y-3] = '*';
            quadro->matriz[x+2][y+3] = '*';
            quadro->matriz[x+2][y+2] = '*';
            quadro->matriz[x+2][y+1] = '*';
            quadro->matriz[x+2][y] = '*';
            quadro->matriz[x+2][y-1] = '*';
            quadro->matriz[x+2][y-2] = '*';





            quadro->matriz[x+1][y+1] = '|';


            quadro->matriz[x+1][y-1] = '|';





            for (int i = -2; i <= 2; i++) {  
                quadro->matriz[x-1][y+i] = '*';
            }
            quadro->matriz[x-2][y] = '*';  

            break;
    }
}



int espacoDisponivel(Quadro *quadro, int tipoFigura) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (areaDisponivel(quadro, i, j, tipoFigura)) {
                return 1;
            }
        }
    }

    printf("Não há mais espaço disponível para desenhar novas figuras.\n");
    return 0; 
}

