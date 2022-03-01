/*
* Trabalho Prático 2 de Estrutura de Dados e Algoritmos I
* Aluno: Alleck Luka Patricio (Alleck Luka) RA: 206349
*/
#include <locale.h>

#include <stdio.h>
#include <stdlib.h>
#include "leitura.hpp"
#define link "billboard-lyrics-spotify.csv"
#include <time.h>
/*Arquivo csv inalterado*/

int main()
{

    char nomePlaylist[30];

    char buffer[8000];

    srand(time(NULL));
    Musica m1;
    Menu mn = {0};
    m1.artista[0]=" ";
    Musica *mptr = &m1;
    int row=0,i=0,j=0, nMus, aux;
    int musicas[1000] = {0};

    /*Questionario*/
    int anoI, anoF;
    char acustica[4], dancavel[4], explicita[4], resp[5];
    printf("/////////\tMENU\t/////////\n");
    printf("Insira NENHUM (ou N) para nao filtrar por ano ou comece inserindo somente o ANO_INICIAL:.\n");
    scanf("%s", resp);
    if(strcmp(resp, "NENHUM")==0 || strcmp(resp, "N")==0) {
        mn.anoI = 1960;
        mn.anoF = 2017;
    } else {
        mn.anoI = atoi(resp);
        printf("\nInsira o ANO_FINAL:\n");
        scanf("%d", &mn.anoF);
    }
    printf("Acustica ou nao? (Y/N): ");
    scanf("%s", mn.acusticaR);
    printf("Dancavel ou nao? (Y/N): ");
    scanf("%s", mn.dancavelR);
    printf("Explicita ou nao? (Y/N): ");
    scanf("%s", mn.explicitaR);

    /*LER BILBOARD*/
    FILE *fp = fopen(link,"r");

    if(!fp)
        printf("ERRO NA LEITURA DO ARQUIVO!!! Coloque o arquivo e o programa na mesma pasta.\n");
    else {

        for(row=0;row<=5566;row++) { /* De acordo com as colunas */
            fgets(buffer, 8000 ,fp);
            myStrtok(&buffer, '\"',',', mptr);  /* Atribui aos membros do struct -> valores relevantes */

            if(musOk(mptr, &mn)) {  /*Se musOk retorna 1, a musica entra no array*/
                musicas[i] = row+1;
                i++;
            }

            strncpy(buffer,"",strlen(buffer)); /* Se livra do resto de buffer */
        }
        nMus = i;
        printf("\nNumero de musicas que se encaixam na pesquisa: %d!!!\n",nMus);

        for(i=0;musicas[i] && i<20;i++) { /*Embaralha os 20 primeiros indices, com valores de todo o array*/
            aux = musicas[i];
            j = (rand()% nMus);
            musicas[i] = musicas[j];
            musicas[j] = aux;
        }

        /*for(i=0;i<nMus;i++) {
            printf("%d\t", musicas[i]);
        }*/

    strncpy(buffer,"",strlen(buffer));
    }   /*Posso pegar (em um array) o n de row de musicas que se encaixam na busca,
    e na hora de montar a playlist utilizar o randomizador */
    criarPlaylist(&nomePlaylist);
    for(i=0;i<20 && musicas[i]; i++) {
        procurarMusica(musicas[i], &buffer, fp);
        myStrtok(&buffer, '\"',',', mptr);

        inserirMusica(&nomePlaylist, m1);
    }
    lerPlaylist(&nomePlaylist);

    getch();
    fclose(fp);
}
