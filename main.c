#include <stdio.h>
#include <stdlib.h>

int coordenadaExiste(int linha, int coluna) {
    return (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3);
}

void jogarJogo(int *vitoriasJogador1, int *vitoriasJogador2) {
    int l, c, linha, coluna, jogador = 1, ganhou = 0, jogadas = 0;
    char jogo[3][3], nome1[100], nome2[100];

    printf("Digite o nome do jogador 1: ");
    scanf("%s", nome1);
    printf("Digite o nome do jogador 2: ");
    scanf("%s", nome2);

    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            jogo[l][c] = ' ';
        }
    }

    do {
        printf("\n\n\t 0   1   2\n\n");
        for (l = 0; l < 3; l++) {
            for (c = 0; c < 3; c++) {
                if (c == 0)
                    printf("\t");
                printf(" %c ", jogo[l][c]);
                if (c < 2)
                    printf("|");
                if (c == 2)
                    printf("  %d", l);
            }
            if (l < 2)
                printf("\n\t-----------");
            printf("\n");
        }

        do {
            printf("\n%s = O\n%s = X\n", nome1, nome2);
            printf("\n%s: Digite a linha e a coluna que deseja jogar: ", (jogador == 1) ? nome1 : nome2);
            scanf("%d%d", &linha, &coluna);

            if (!coordenadaExiste(linha, coluna)) {
                printf("\nPosição inválida! Escolha uma posição valida.\n");
            }
        } while (!coordenadaExiste(linha, coluna) || jogo[linha][coluna] != ' ');

        if (jogador == 1) {
            jogo[linha][coluna] = 'O';
            jogador++;
        } else {
            jogo[linha][coluna] = 'X';
            jogador = 1;
        }
        jogadas++;

        if ((jogo[0][0] == jogo[0][1] && jogo[0][1] == jogo[0][2] && jogo[0][0] != ' ') ||
            (jogo[1][0] == jogo[1][1] && jogo[1][1] == jogo[1][2] && jogo[1][0] != ' ') ||
            (jogo[2][0] == jogo[2][1] && jogo[2][1] == jogo[2][2] && jogo[2][0] != ' ') ||
            (jogo[0][0] == jogo[1][0] && jogo[1][0] == jogo[2][0] && jogo[0][0] != ' ') ||
            (jogo[0][1] == jogo[1][1] && jogo[1][1] == jogo[2][1] && jogo[0][1] != ' ') ||
            (jogo[0][2] == jogo[1][2] && jogo[1][2] == jogo[2][2] && jogo[0][2] != ' ') ||
            (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[0][0] != ' ') ||
            (jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[0][2] != ' ')) {
            printf("\nParabens! %s venceu!\n", (jogador == 1) ? nome1 : nome2);
            if (jogador == 1) {
                (*vitoriasJogador1)++;
            } else {
                (*vitoriasJogador2)++;
            }
            ganhou = 1;
        }
    } while (ganhou == 0 && jogadas < 9);

    printf("\n\n\t 0   1   2\n\n");
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            if (c == 0)
                printf("\t");
            printf(" %c ", jogo[l][c]);
            if (c < 2)
                printf("|");
            if (c == 2)
                printf("  %d", l);
        }
        if (l < 2)
            printf("\n\t-----------");
        printf("\n");
    }

    if (ganhou == 0)
        printf("\nO jogo finalizou sem vencedor!\n");
}

void verRanking(int vitoriasJogador1, int vitoriasJogador2) {
    printf("\n=== RANKING ===\n");
    printf("Jogador 1: %d vitórias\n", vitoriasJogador1);
    printf("Jogador 2: %d vitórias\n", vitoriasJogador2);
}

void mostrarCreditos() {
    printf("\nDesenvolvido por Five Devs...\n");
}

int main() {
    int opcao, vitoriasJogador1 = 0, vitoriasJogador2 = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Jogar\n");
        printf("2. Ver Ranking\n");
        printf("3. Créditos\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogarJogo(&vitoriasJogador1, &vitoriasJogador2);
                break;
            case 2:
                verRanking(vitoriasJogador1, vitoriasJogador2);
                break;
            case 3:
                mostrarCreditos();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Escolha novamente.\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}
