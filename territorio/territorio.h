#ifndef _TERRITORIO_H
#define _TERRITORIO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

Territorio criaTerritorio(char* nome, char* cor, int tropas);

#endif