#ifndef MUNDO_H
#define MUNDO_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../territorio/territorio.h"
#define NUM_TERRITORIOS 5

void inicializaMundo(Territorio *territorios);
void exibeMundo(Territorio *territorios);

#endif