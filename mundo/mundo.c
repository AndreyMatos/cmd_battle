#include "mundo.h"

void inicializaMundo(Territorio *territorios)
{
    if (territorios == NULL)
    {
        printf("Erro ao alocar memória para os territórios.\n");
        exit(EXIT_FAILURE);
    }
    char *regioes[] = {
        "America",
        "Europa",
        "Africa",
        "Asia",
        "Oceania"};
    char *cores[] = {
        "Vermelho",
        "Azul",
        "Verde",
        "Amarelo",
        "Roxo"};
    for (int i = 0; i < NUM_TERRITORIOS; i++)
    {
        srand(time(NULL) + i);
        territorios[i] = criaTerritorio(regioes[i], cores[i], rand() % 10 + 1);
    }
}

void exibeMundo(Territorio *territorios)
{
    printf("------------ MAPA DO MUNDO ------------\n");
    if (territorios == NULL)
    {
        printf("Nenhum território disponível.\n");
        return;
    }
    for (int i = 0; i < NUM_TERRITORIOS; i++)
    {
        printf("%d. %s,\tExército: (%s,\tTropas: %d)\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }
}