#include <stdio.h>
#include <string.h>

#define NUM_JOGADORES 11

typedef struct {
    char nome[30];
    char posicao;
    int forca;
} Jogador;

float calcularForcaPonderada(Jogador jogadores[]) {
    int forca_goleiro = 0;
    int forca_laterais = 0;
    int forca_zagueiros = 0;
    int forca_volantes = 0;
    int forca_meias = 0;
    int forca_atacantes = 0;

    for (int i = 0; i < NUM_JOGADORES; i++) {
        switch (jogadores[i].posicao) {
            case 'G':
                forca_goleiro = jogadores[i].forca;
                break;
            case 'L':
                forca_laterais += jogadores[i].forca;
                break;
            case 'Z':
                forca_zagueiros += jogadores[i].forca;
                break;
            case 'V':
                forca_volantes += jogadores[i].forca;
                break;
            case 'M':
                forca_meias += jogadores[i].forca;
                break;
            case 'A':
                forca_atacantes += jogadores[i].forca;
                break;
        }
    }

    float forca_ponderada = (8 * forca_goleiro + 10 * (forca_laterais + forca_zagueiros) +
                            5 * (forca_volantes + forca_meias) + 12 * forca_atacantes) / 100.0;

    return forca_ponderada;
}

int main() {
    char nome_time[2][30];
    Jogador jogadores[2][NUM_JOGADORES];

    for (int i = 0; i < 2; i++) {
        scanf("%s", nome_time[i]);

        for (int j = 0; j < NUM_JOGADORES; j++) {
            scanf("%s %c %d", jogadores[i][j].nome, &jogadores[i][j].posicao, &jogadores[i][j].forca);
        }
    }

    float forca_time1 = calcularForcaPonderada(jogadores[0]);
    float forca_time2 = calcularForcaPonderada(jogadores[1]);

    printf("%s: %.2f de força\n", nome_time[0], forca_time1);
    printf("%s: %.2f de força\n", nome_time[1], forca_time2);

    if (forca_time1 > forca_time2) {
        printf("%s é mais forte\n", nome_time[0]);
    } else if (forca_time2 > forca_time1) {
        printf("%s é mais forte\n", nome_time[1]);
    } else {
        printf("Os times têm a mesma força\n");
    }

    return 0;
}
