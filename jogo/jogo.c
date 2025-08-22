#include "jogo.h"

void inicializaJogo(Jogo *jogo) {
    if (jogo == NULL) {
        printf("Erro ao alocar memória para o jogo.\n");
        exit(EXIT_FAILURE);
    }
    inicializaMundo(jogo->territorios);
    atribuirMissao(jogo);
}

void exibeInformacoes(Jogo *jogo) {
    exibeMundo(jogo->territorios);
    printf("\n\n--- MISSÃO ATUAL ---\n");
    printf("%s\n\n",jogo->missaoAtual.descricao);
}

int selecionaAcao()
{
    int acao;
    printf("--- MENU DE ACOES ---\n");
    printf("1. Atacar\n");
    printf("2. Verificar Missão\n");
    printf("3. Sair\n");
    printf("Escolha sua ação: ");
    scanf("%d", &acao);
    return acao;
}

void executaAcao(int acao, Jogo *jogo)
{
    int territorioAtacante;
    int territorioDefensor;
    switch (acao)
    {
    case ACAO_ATACAR:
        printf("Escolha o território atacante (1 a %d):\n", NUM_TERRITORIOS);
        scanf("%d", &territorioAtacante);
        printf("Escolha o território defensor (1 a %d):\n", NUM_TERRITORIOS);
        scanf("%d", &territorioDefensor);
        ataca(jogo, territorioAtacante - 1, territorioDefensor - 1);
        break;
    case ACAO_VERIFICAR_MISSAO:
        if (verificaMissao(jogo))
        {
            printf("Missão concluída!\n");
        }
        else
        {
            printf("Missão ainda não concluída.\n");
        }
        break;
    case ACAO_SAIR:
        printf("Saindo do jogo...\n");
        exit(0);
    default:
        printf("Ação inválida. Tente novamente.\n");
    }
}

void ataca(Jogo *jogo, int territorioAtacante, int territorioDefensor)
{
    if (territorioAtacante == territorioDefensor)
    {
        printf("Você não pode atacar o mesmo território.\n");
        return;
    }
    if (territorioAtacante < 0 || territorioAtacante >= NUM_TERRITORIOS ||
        territorioDefensor < 0 || territorioDefensor >= NUM_TERRITORIOS)
    {
        printf("Território inválido.\n");
        return;
    }

    Territorio *atacante = &jogo->territorios[territorioAtacante];
    Territorio *defensor = &jogo->territorios[territorioDefensor];

    if (atacante->tropas <= 0)
    {
        printf("Território atacante sem tropas.\n");
        return;
    }

    if (defensor->tropas <= 0)
    {
        printf("Território defensor sem tropas.\n");
        return;
    }

    srand(time(NULL));
    int dadoTerritorioAtacante = rand() % 6 + 1;
    srand(time(NULL) + 1);
    int dadoTerritorioDefensor = rand() % 6 + 1;

    if (dadoTerritorioAtacante > dadoTerritorioDefensor)
    {
        defensor->tropas--;
        printf("--- RESULTADO DA BATALHA ---\n");
        printf("Ataque (%s): %d | Defesa (%s): %d\n",
               atacante->nome, dadoTerritorioAtacante,
               defensor->nome, dadoTerritorioDefensor);
        printf("VITORIA DO ATAQUE! O defensor perdeu uma tropa.\n");
    }
    else if (dadoTerritorioAtacante == dadoTerritorioDefensor)
    {
        printf("Empate! Nenhum território perdeu tropas.\n");
    }
    else
    {
        atacante->tropas--;
        printf("\n\n--- RESULTADO DA BATALHA ---\n");
        printf("Ataque (%s): %d | Defesa (%s): %d\n",
               atacante->nome, dadoTerritorioAtacante,
               defensor->nome, dadoTerritorioDefensor);
        printf("VITORIA DA DEFESA! O atacante perdeu uma tropa.\n");
    }
}

void atribuirMissao(Jogo *jogo)
{
    const char *missaoDescricao[] = {"Destrua todas as tropas da América.",
                                   "Conquiste pelo menos dois continentes.",
                                   "Destrua todas as tropas de um território.",
                                   "Conquiste o território de cor Verde.",
                                   "Destrua todas as tropas da Oceania.",
                                   "Destrua todas as tropas de cor Roxa."};
    srand(time(NULL));
    int missaoId = rand() % 6;
    strncpy(jogo->missaoAtual.descricao, missaoDescricao[missaoId], 100);
    jogo->missaoAtual.id = missaoId;
    printf("Missão atribuída: %s\n", jogo->missaoAtual.descricao);
}

int verificaMissao(Jogo *jogo)
{
    int continentesConquistados = 0;
    switch (jogo->missaoAtual.id)
    {
    case 0:
        for (int i = 0; i < NUM_TERRITORIOS; i++)
        {
            if (strcmp(jogo->territorios[i].nome, "America") == 0 &&
                jogo->territorios[i].tropas > 0)
            {
                return 0;
            }
        }
        return 1;
    case 1:
        for (int i = 0; i < NUM_TERRITORIOS; i++)
        {
            if (jogo->territorios[i].tropas == 0)
            {
                continentesConquistados++;
            }
        }
        return continentesConquistados >= 2 ? 1 : 0;
    case 2:
        for (int i = 0; i < NUM_TERRITORIOS; i++)
        {
            if (jogo->territorios[i].tropas == 0)
            {
                return 1;
            }
        }
        return 0;
    case 3:
        for (int i = 0; i < NUM_TERRITORIOS; i++)
        {
            if (strcmp(jogo->territorios[i].cor, "Verde") == 0 &&
                jogo->territorios[i].tropas > 0)
            {
                return 1;
            }
        }
        return 0;
    case 4:
        for (int i = 0; i < NUM_TERRITORIOS; i++)
        {
            if (strcmp(jogo->territorios[i].nome, "Oceania") == 0 &&
                jogo->territorios[i].tropas > 0)
            {
                return 0;
            }
        }
        return 1;
    case 5:
        for (int i = 0; i < NUM_TERRITORIOS; i++)
        {
            if (strcmp(jogo->territorios[i].cor, "Roxo") == 0 &&
                jogo->territorios[i].tropas > 0)
            {
                return 0;
            }
        }
        return 1;
    default:
        printf("Missão desconhecida.\n");
        return 0;
    }
}