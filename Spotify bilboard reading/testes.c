#include <stdio.h>
#include <string.h>
#include "leitura.hpp"
#include <stdlib.h>

void testes(Musica *m1) {
    printf("\nARTISTA: %s\n", m1->artista);
    printf("NOME DA MUSICA: %s\n", m1->nomeMusica);
    printf("ANO: %d\n", m1->ano);
    printf("RANK: %d\n", m1->nRank);
    printf("ACUSTICA: %.1f\n", m1->acustica);
    printf("DANCAVEL: %.1f\n", m1->dancavel);
    printf("EXPLICITO: %.1f\n", m1->explicito);
}
