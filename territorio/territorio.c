#include "territorio.h"

Territorio criaTerritorio(char* nome, char* cor, int tropas) {
    Territorio territorio;
    strcpy(territorio.nome, nome);
    strcpy(territorio.cor, cor);
    territorio.tropas = tropas;
    return territorio;    
}