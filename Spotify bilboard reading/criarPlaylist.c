#include <stdio.h>
#include <string.h>
#include "leitura.hpp"
#include <stdlib.h>
#define link "billboard-lyrics-spotify.csv"

void criarPlaylist(char *nomePlaylist[]) {
    printf("Nome da playlist (nao use um nome que ja existe, ou vai perder a playlist antiga): ");
    scanf("%s", nomePlaylist);
    strcat(nomePlaylist, ".dat");
    FILE *fp = fopen(nomePlaylist, "wb");
    fclose(fp);
}
