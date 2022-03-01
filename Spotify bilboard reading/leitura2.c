#include <stdio.h>
#include <string.h>
#include "leitura.hpp"
/*Colunas: 0=artist_all,1=artist_base,2=rank,3=song,4=year,5=artist_featured,6=song_clean,7=artist_clean
    ,8=lyrics,9=acousticness,10=danceability,11=energy,12=explicit,13=instrumentalness
    ,14=key,15=liveness,16=loudness,17=mode,18=popularity,19=release_date,20=speechiness
    ,21=tempo,22=time_signature,23=valence,24=duration_min,25=num_words
    ,26=words_per_sec,27=num_uniq_words,28=decade,29=uniq_ratio
    IMPORTANTES:
    0=artista(s);
    3=nome da musica;
    4=ano;
    8=letras;
    9=acustica;
    10=dancavel;
    12=explicito;
    */

void lerFiltrado(FILE *fp, Musica *mus) {

    char buffer[7000];

    fgets(buffer, 8000 ,fp);    /*Le linha*/
    char* value = strtok(buffer, ",");
    int column = 0;

    while (value) {

        if (column==0) {
            printf("\n\nArtista(s) : ");
            if(value[0] == '\"') {
                value[0] ='\0';
                printf("%s", value);

                value = strtok(NULL, "\"");
            }
            printf("%s", value);

        }

        /*if (column == 2) {
            printf("\nRank : ");
            printf("%s", value);
        }*/

        if (column == 3) {
            printf("\nMusica : ");
            if(value[0] == '\"') {
                value[0] =' ';
                printf("%s", value);

                value = strtok(NULL, "\"");
            }
            printf("%s", value);
        }

        if (column == 4) {
            mus->ano = atoi(value);
        }

        /*if (column == 7) {
            printf("\nLetra : ");
            if(value[0] == '\"') {
                value[0] =' ';
                printf("%s", value);

                value = strtok(NULL, "\"");
            }
            printf("%s", value);
        }*/

        if (column == 8) {
            printf("\nAcustica : ");
            printf("%s", value);
        }

        if (column == 9) {
            printf("\nDancavel : ");
            printf("%s", value);
        }

        if (column == 11) {
            printf("\nExplicito : ");
            printf("%s", value);
        }

        value = strtok(NULL, ",");

        column++;
    }
}


