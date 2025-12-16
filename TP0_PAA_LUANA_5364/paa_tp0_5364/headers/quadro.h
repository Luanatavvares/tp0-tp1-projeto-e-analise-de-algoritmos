#ifndef QUADRO_H
#define QUADRO_H
#include <stdio.h>


#include "figura.h"

#define LINHAS 20
#define COLUNAS 80

typedef struct {
    char matriz[LINHAS][COLUNAS];
} Quadro;

void inicializarQuadro(Quadro *quadro);
void imprimirQuadro(Quadro *quadro);
int espacoDisponivel(Quadro *quadro, int tipoFigura);
int areaDisponivel(Quadro *quadro, int x, int y, int tipoFigura);
void desenharFigura(Quadro *quadro, int tipoFigura, int x, int y);


#endif
