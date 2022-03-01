#include <stdio.h>
#include <string.h>
#include "leitura.hpp"


void lerBilboard(char link[100]) {

    char buffer[7000];
    FILE *fp = fopen(link,"r");
    char *token;
    char buffer2[100];
    int i;

    if(!fp)
        printf("falhou!");
    else {
        /*for(i=0;i<5544;i++){
            fgets(buffer, 8000 ,fp);
        }*/
        for(i=0;i<=20;i++) { /*Le todas as linhas do csv, musica por musica*/
            fgets(buffer, 8000 ,fp);
            char* value = strtok(buffer, ", ");
            int column = 0;

            while (value) {

                if (column==0) {
                    printf("\n\nNome : ");
                    if(value[0] == '\"') {
                        value[0] =' ';
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
                    printf("\nAno : ");
                    printf("%s", value);
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

                value = strtok(NULL, ", ");

                column++;
            }
        }
    }
    fclose(fp);
}
