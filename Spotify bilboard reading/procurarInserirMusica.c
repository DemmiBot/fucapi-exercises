#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.hpp"
#define link "billboard-lyrics-spotify.csv"

void procurarMusica(int *row, char *buffer, FILE *fp) {
    int i;
    fseek(fp, 0, SEEK_SET);
    for(i=1;i<=row;i++) {
        fgets(buffer, 8000 ,fp);
    }

}

void inserirMusica(char *nomePlaylist, Musica musica1) {
    FILE *fp = fopen(nomePlaylist, "ab");

    if(fp == NULL) {
        printf("ERRO AO ABRIR BINARIO PARA LEITURA!!!");
        exit(0);
    }

    fseek(fp,1,SEEK_END);


    fwrite(&musica1, sizeof(Musica), 1 ,fp);

    fclose(fp);
}
