#ifndef FIGURA_H
#define FIGURA_H
#include <stdio.h>


typedef struct {
    int tipo;
    int x;    
    int y;    
} Figura;

Figura criarFigura(int tipo, int x, int y);

#endif
