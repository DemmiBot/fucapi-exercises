#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Data Structure binary search
    Método binário para pesquisa em array ordenado:
    Verifica metade -> se metade>busca procuraEsquerda(), senao procuraDireita() -> Verifica metade
    da metade até achar valor ou metade for <0;
    test
    
*/

void scanArray(int* arr, int size) {    /*scan array*/
    int i;
    printf("\n");
    for(i=0;i<size;i++, arr++) {
        printf("[%d]", i);
        scanf("%d", arr);
    }
}

void printArray(int* arr, int size) { /*Print array ue*/
    int i;
    printf("\n");
    for(i=0;i<size;i++) {
        printf("[%d]", arr[i]);
    }
}

void sortArray(int* arr, int size){ /*Metodo bolha, ordem crescente*/
    int i, j, aux;
    for(i=0;i<size;i++) {
        for(j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]) {
                aux = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int size;

    printf("Insert an array: ");
    printf("\nInsert array size: ");
    scanf("%d", &size);

    int arr[size], i, key;

    for(i=0;i<size;i++) {
        arr[i] = rand()%100;
    }

    sortArray(arr, size);
    printArray(arr, size);

    printf("\nInsert number to find: ");
    scanf("%d", &key);
    int low = 0, high = size, aux=0;
    int tracker= (int)size/2;

    for(;low <=high;){

        if(arr[tracker]==key){
            printf("Found at %d", tracker);
            exit(0);
        }

        if(arr[tracker]<key) {
            low = tracker + 1;
        } else {
            high = tracker -1;
        }

        tracker = low + (high-low)/2;
    }

    printf("\nCouldn't find!");
}