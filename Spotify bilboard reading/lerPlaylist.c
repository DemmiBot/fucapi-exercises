#include <stdio.h>
#include <string.h>
#include "leitura.hpp"
#include <stdlib.h>

void lerPlaylist(char *nomePlaylist[]) {
    int i;
    Musica mus;

    FILE *fp = fopen(nomePlaylist, "rb");
    if(fp == NULL) {
        printf("ERRO AO ABRIR BINARIO!!!");
        exit(0);
    }
    fseek(fp, 0, SEEK_SET);
    for(i=0; fread(&mus, sizeof(Musica), 1, fp); i++) {

            printf("\nARTISTA: %s\n", mus.artista);
            printf("NOME DA MUSICA: %s\n", mus.nomeMusica);
            printf("ANO: %d\n", mus.ano);
            printf("RANK: %d\n", mus.nRank);
            printf("ACUSTICA: %.2f\n", mus.acustica);
            printf("DANCAVEL: %.2f\n", mus.dancavel);
            printf("EXPLICITO: %.2f\n", mus.explicito);
            fseek(fp, 0, SEEK_CUR);

    }


    fclose(fp);
}
