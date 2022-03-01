#include <stdio.h>
#include <string.h>
#include "leitura.hpp"
#include <stdlib.h>
/*
*   Varre o string buffer e atribui valores
*   relevantes ao struct mus. Contorna o problema das colunas vazias.
*/

void myStrtok(char *buffer, char delim1, char delim2,Musica *mus) { /*Delimitador 1 tem precedencia*/
    int i=0, j=0, tok=0, row=0;
    char intString[5];
    char doubleString[40];
    for(;buffer[i]!='\0';row++) {
        if(buffer[i]==delim1) {
            i++;
            while((buffer[i]!=delim1) && buffer[i]!='\0') { /*para no primeiro delimitador*/
                    i++;
                }
            i++; /*Terminaria em outro delimitador*/
            if(buffer[i]!=delim2) { /*Verifica se é o final do valor/coluna */
                i++;
                while((buffer[i]!=delim2) && buffer[i]!='\0') {
                    i++;
                }
            }
        } else {
            while((buffer[i]!=delim2) && buffer[i]!='\0') { /*para no primeiro delimitador*/
                i++;
            }
        }


        if(row==0) { /*nome do artista*/
            strncpy(mus->artista, buffer + tok, i-tok);
            mus->artista[i-tok] = '\0'; /*Termina string*/

        }

        if(row==2){ /*rank*/
            strncpy(intString, buffer + tok+1, i-tok-1);
            mus->nRank=atoi(intString);
        }

        if(row==3){ /*nome da musica*/
            strncpy(mus->nomeMusica, buffer + tok+1, i-tok);
            mus->nomeMusica[i-tok-1] = '\0'; /*Termina string*/
        }

        if(row==4){ /*ano da musica*/
            strncpy(intString, buffer + tok+1, i-tok-1);
            mus->ano=atoi(intString);
        }

        if(row==9){ /*acustica*/
            strncpy(doubleString, buffer + tok+1, i-tok-1);
            mus->acustica=atof(doubleString);
        }

        if(row==10){ /*dancabilidade*/
            strncpy(doubleString, buffer + tok+1, i-tok-1);
            mus->dancavel=atof(doubleString);
        }

        if(row==12){ /*explicito*/
            strncpy(doubleString, buffer + tok+1, i-tok-1);
            mus->explicito=atof(doubleString);
        }

        /*for(j=tok;j<i;j++) {
            printf("%c",buffer[j]);
        }*/

        tok=i;
        i++;
    }
}
