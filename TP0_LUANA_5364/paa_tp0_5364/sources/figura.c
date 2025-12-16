#include "../headers/figura.h"
#include <stdio.h>


Figura criarFigura(int tipo, int x, int y) {
    Figura fig;
    fig.tipo = tipo;
    fig.x = x;
    fig.y = y;
    return fig;
}
