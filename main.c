#include "jogo/jogo.h"
#include <stdlib.h>

int main() {
    Jogo* jogo = (Jogo*)malloc(sizeof(Jogo));
    if (jogo == NULL) {
        printf("Erro ao alocar memória para o jogo.\n");
        return EXIT_FAILURE;
    }
    inicializaJogo(jogo);
    int acao = -1;
    while (acao != ACAO_SAIR) {
        char c;
        exibeInformacoes(jogo);
        acao = selecionaAcao();
        executaAcao(acao, jogo);
        if (verificaMissao(jogo)) {
            printf("Parabéns! Você completou a missão!\n");
            break;
        }
        printf("Pressione Enter para continuar...\n"); 
        while ((c = getchar()) != '\n' && c != EOF);
        getchar();
    }
    free(jogo);
    return 0;   
}