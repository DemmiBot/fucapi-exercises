#ifndef LEITURA_H_
#define LEITURA_H_
#endif // leitura
#define nome "Playlist.bin"
#include <stdio.h>

/*myStrok() e musOk() servem o proposito de procura_musica*/

typedef struct musica{
    char artista[200];
    char nomeMusica[200];
    int ano;
    int nRank;
    double acustica;
    double dancavel;
    double explicito;
}Musica;

typedef struct menu{
    int anoI;
    int anoF;
    char acusticaR[4];
    char dancavelR[4];
    char explicitaR[4];
}Menu;

/*Utilizado em main*/
void testes(Musica *m1);
void myStrtok(char *buffer, char delim1, char delim2,Musica *mus); /*Tokenizador que trata delimitadores consecutivos*/
int musOk(Musica *mus, Menu *mn); /*Verifica se musica se encaixa nos filtros, retorna 1 ou 0*/
void criarPlaylist(char *nomePlaylist[]);
void lerPlaylist(char *nomePlaylist[]);

/*Utilizado em criarPlaylist*/
void procurarMusica(int *row, char *buffer, FILE *fp); /*Leva o ponteiro ate a linha a ser lida*/
void inserirMusica(char *nomePlaylist, Musica musica1); /*compila as informacoes do struct e escreve no arquivo bin*/

