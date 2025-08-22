#ifndef JOGO_H
#define JOGO_H

#include "../mundo/mundo.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ACAO_ATACAR 1
#define ACAO_VERIFICAR_MISSAO 2
#define ACAO_SAIR 3

typedef struct {
    char descricao[100];
    int id;
} Missao;


typedef struct {
    Missao missaoAtual;
    Territorio territorios[NUM_TERRITORIOS];
} Jogo;

void inicializaJogo(Jogo *jogo);
int selecionaAcao();
void exibeInformacoes(Jogo *jogo);
void executaAcao(int acao, Jogo *jogo);
void atribuirMissao(Jogo *jogo);
int verificaMissao(Jogo *jogo);
void ataca(Jogo *jogo, int territorioAtacante, int territorioDefensor);

#endif