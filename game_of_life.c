#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define CWB    "\x1b[7m"    /*White background ANSI*/
#define CR   "\x1b[0m"      /*Color reset ANSI*/
/*https://stackoverflow.com/questions/2778785/what-does-6d-mean-in-printf*/
/*https://en.wikipedia.org/wiki/ANSI_escape_code#Colors*/
/*https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c*/
/*https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c*/
/*https://stackoverflow.com/questions/10922900/
is-it-possible-to-wait-a-few-seconds-before-printing-a-new-line-in-c*/

/*JODO DA VIDA de John Cnway*/

void printAlive(){
    printf(CWB " " CR);
}

void populateColony(int*colony, int size){
    int i;
    srand(time(NULL));
    for(i=0;i<size;i++){
        colony[i] = rand()%2;
    }
}

void updateColony(int*colony, int column, int size) {
    int i, neighbourCount=0;
    int* colonyTwo = (int*)malloc(size * sizeof(int));
    
    for(i=0;i<size;i++){
        colonyTwo[i] = colony[i];
    }

    for(i=0;i<size;i++){
        neighbourCount = 0;

        if(colonyTwo[i+1] >= 1 && i+1<size) {
            neighbourCount++;
        }
        if(colonyTwo[i-1] >= 1 && i-1 >0 ) {
            neighbourCount++;
        }
        if(colonyTwo[i-column+1] >= 1 && i-column+1>0) {
            neighbourCount++;
        }
        if(colonyTwo[i-column] >= 1 && i-column>0) {
            neighbourCount++;
        }
        if(colonyTwo[i-column-1] >= 1&& i-column-1>0) {
            neighbourCount++;
        }
        if(colonyTwo[i+column-1] >= 1 && i+column-1 <size) {
            neighbourCount++;
        }
        if(colonyTwo[i+column] >= 1 && i+column < size) {
            neighbourCount++;
        }
        if(colonyTwo[i+column+1] >= 1 && i+column+1 <size) {
            neighbourCount++;
        }

        if(colonyTwo[i] == 0) {
            if(neighbourCount==3){
                colony[i] = 1;
            }
        } else {
            if(neighbourCount>=4) {
                colony[i] = 0;
            }
            if(neighbourCount<2) {
                colony[i] = 0;
            }
        }
    }
    free(colonyTwo);
}


int main() {
    int i, j, k;

    int colony[12][40] = {0};
    /*POPULA RANDOMICAMENTE*/
    populateColony(colony, 12*40);
    /*POPULA MANUALMENTE*/
    colony[6][11] = 1;
    colony[6][9] = 1;
    colony[6][10] = 1;
    colony[7][10] = 1;
    colony[5][10] = 1;

    printf("\e[1;1H\e[2J"); /*Clears screen*/

    for(k=0;k<1000;k++) {
        for(i=0;i<12;i++) {
            for(j=0;j<40;j++) {
                if(colony[i][j]>=1) { /*Se vivo, print bloco branco*/
                    printAlive();
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        Sleep(100); /*Espera 100 milisegundos*/

        printf("\e[1;1H\e[2J"); /*Clears screen*/
        updateColony(colony, 40, 40*12);
    }
}