#include <stdio.h>
#include <string.h>
#include <locale.h>

/*https://beginnersbook.com/2014/01/c-passing-array-to-function-example/*/
void readVector(int *a, int b){
    int i;
    for(i=0;i<b;i++){
        printf("Insert N# %d: ", i+1);
        scanf("%d", a);
        a++; /*a is a pointer, so incrementing a makes it point to the next index*/
    }
}

void readVectorFloat(float *a, int b){
    int i;
    for(i=0;i<b;i++){
        printf("Insert N# %d: ", i+1);
        scanf("%f", a);
        a++;
    }
}

void populateVector(int *a, int b){
    int i;
    for(i=0;i<b;i++){
        a[i] = i-4;
    }
}

void populateVectorFloat(float *a, int b){
    int i;
    for(i=0;i<b;i++){
        a[i] = i-4;
    }
}

/*https://stackoverflow.com/questions/5630478/printing-arrays-in-separate-function-in-c*/
void printArray(int *a, int b){
    int i;
    for(i=0;i<b;i++){
        printf("%d ", a[i]);
    }
}

void printArrayFloat(float *a, int b){
    int i;
    for(i=0;i<b;i++){
        printf("%.2f ", a[i]);
    }
}
void print2DArray(int *a, int rows, int columns){
    int i, j;
    for(i=0;i<rows*columns;i++){
        printf("\t%d", a[i]);
        if(!((i+1)%(columns)))
            printf("\n");
    }
}

int arrayIsEqual(int *array1, int arraySize1, int *array2, int arraySize2) {
    int i;
    if(arraySize1 != arraySize2)
        return 0;

    for(i=0;i<arraySize1;i++) {
        if(array1[i] != array2[i])
            return 0;
    }
    return 1;
}

void printMenu() {
    printf("\n\n---MENU---\n\n");
    printf("VECTOR LIST: \n");
    printf("1, 2, 3, 4, 5, 6, 7 \n");
    printf("MATRIX LIST: \n");
    printf("8, 9, 10, 11, 12, 13 \n");
    printf("EXIT: 14 \n");
    printf("\nInsert exercise number: ");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opt;


    do{
        printMenu();
        scanf("%d", &opt);
        switch(opt){
        case 1:
            {
                printf("1. Faça um programa que lê 10 números inteiros do teclado e armazene em um vetor. Ao final");
                printf("imprima o vetor armazenado nos dois sentidos. \n\n");

                int i, a, vect[10];

                readVector(vect, 10);

                printf("Vect: {");
                printArray(vect, 10);
                printf("}");

                printf("\nVect (mirrored) {");
                for(i=sizeof(vect)/sizeof(vect[0])-1;i>=0;i--){
                    printf("%d ", vect[i]);
                }
                printf("}");
            }
            break;

        case 2:
            {
                printf("2. Ler um vetor de 10 elementos. Crie um segundo vetor, com todos os elementos na ordem inversa,");
                printf("ou seja, o último elemento passará a ser o primeiro, o penúltimo será o segundo e assim por diante.");
                printf("Imprima os dois vetores.\n\n");

                int a, i, vect1[10], vect2[10];

                printf("Insert vector: ");
                readVector(vect1, 10);

                for(i=0;i<10;i++){
                    vect2[i] = vect1[9-i];
                }

                printf("\nVect1 = {");
                for(i=0;i<10;i++){
                    printf(" %d", vect1[i]);
                }
                printf(" }");

                printf("\nVect2 (mirrored Vect1) = {");
                for(i=0;i<10;i++){
                    printf(" %d", vect2[i]);
                }
                printf(" }");
            }
            break;

        case 3:
            {
                printf("3. Ler um vetor de 10 elementos inteiros e positivos. Criar um segundo vetor da seguinte forma: os");
                printf(" elementos de índice par receberão os respectivos elementos divididos por 2; os elementos de índice");
                printf(" ímpar receberão os respectivos elementos multiplicados por 3. Imprima os dois vetores.\n\n");

                int i;
                float vect1[10], vect2[10];

                readVectorFloat(vect1,10);

                for(i=0;i<10;i++){
                    if(!(i%2)){
                        vect2[i] = vect1[i]/2;
                    } else {
                        vect2[i] = vect1[i]*3;
                    }
                }
                printf("Vect1: \n");
                printArrayFloat(vect1, 10);
                printf("\n\nVect2: \n");
                printArrayFloat(vect2, 10);

            }
            break;

        case 4:
            {
                printf("4. Ler um vetor com 10 nomes de pessoas, após pedir que o usuário digite um nome qualquer de");
                printf("pessoa. Escrever a mensagem “ACHEI”, se o nome estiver armazenado no vetor C ou “NÃO ACHEI”");
                printf("caso contrário.");

                char stringVect[10][10] = {{"Anna"}, {"Bob"}, {"Charles"}, {"Dylan"}, {"Ethan"}, {"Fred"}, {"George"}, {"Henry"}, {"Irwin"}, {"Jonathan"}};
                int i;
                printf("\n\nNames: \n");
                for(i=0;i<10;i++){
                    printf("%s\n", stringVect[i]);
                }

                char answer=0;
                printf("\n");

                char name[10];
                printf("Insert name to search: ");
                scanf("%s", name);

                for(i=0;i<10;i++) {
                    if(!strcmp(name, stringVect[i]))
                        answer=1;
                }

                if(answer){
                    printf("ACHEI");
                } else{
                    printf("NAO ACHEI");
                }
            }
            break;

        case 5:
            {
                printf("5. Faça um programa que leia e monte dois vetores de números inteiros com 20 números cada. Depois");
                printf("de montados gere um terceiro vetor formado pela diferença dos dois vetores lidos, um quarto vetor");
                printf("formado pela soma dos dois vetores lidos e por último um quinto vetor formado pela multiplicação");
                printf("dos dois vetores lidos.\n\n");

                int i, vect1[20], vect2[20], vect3[20], vect4[20], vect5[20]; /*, vectTeste[4][4];*/

                printf("Insert Vect1: \n");
                readVector(vect1, 20);

                printf("Insert Vect2: \n");
                readVector(vect2, 20);


                for(i=0;i<20;i++){
                    vect3[i] = vect1[i] - vect2[i];
                    vect4[i] = vect1[i] + vect2[i];
                    vect5[i] = vect1[i] * vect2[i];
                }

                printf("Vect1: \n");
                printArray(vect1, 20);

                printf("\nVect2: \n");
                printArray(vect2, 20);

                printf("\nVect3(Diff.): \n");
                printArray(vect3, 20);

                printf("\nVect4(Sum): \n");
                printArray(vect4, 20);

                printf("\nVect5(Mult.): \n");
                printArray(vect5, 20);

            }
            break;

        case 6:
            {
                printf("6. Utilizando vetores, crie um programa que organize uma quantidade qualquer de números inteiros");
                printf(" fornecidos pelo usuário da seguinte forma: primeiro os números pares em ordem crescente e");
                printf(" depois os números ímpares em ordem decrescente.\n\n");

                int i, b, oddNumber=0, evenNumber=0;

                printf("Insert array size: ");
                scanf("%d", &b);
                int a[b];
                readVector(a, b);

                for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
                    if(!(a[i]%2)) {
                        evenNumber++;
                    } else {
                        oddNumber++;
                    }
                }

                printArray(a, sizeof(a)/sizeof(a[0]));

                int oddNumbers[oddNumber], evenNumbers[evenNumber], j, min, max;

                for(i=0, j=0; i < sizeof(a)/sizeof(a[0]) ;i++) {
                    if((a[i]%2)==1 || ((a[i]%2)==-1)) {
                        oddNumbers[j] = a[i];
                        j++;
                    }
                }


                for(i=0, j=0; i<sizeof(a)/sizeof(a[0]);i++) {
                    if(!(a[i]%2)) {
                        evenNumbers[j] = a[i];
                        j++;
                    }
                }

                min = oddNumbers[0];
                max = oddNumbers[0];
                int minIndex=0;
                int maxIndex=0;

                for(i=0;i<oddNumber;i++){
                    max = -2147483648;
                    for(j=i;j<oddNumber;j++) {
                        if(max<oddNumbers[j]){
                            max = oddNumbers[j];
                            maxIndex = j;
                        }
                    }
                    int aux = oddNumbers[i];
                    oddNumbers[i] = oddNumbers[maxIndex];
                    oddNumbers[maxIndex] = aux;
                }

                for(i=0;i<evenNumber;i++){
                    min = 2147483647;
                    for(j=i;j<evenNumber;j++) {
                        if(min>evenNumbers[j]){
                            min = evenNumbers[j];
                            minIndex = j;
                        }
                    }
                    int aux = evenNumbers[i];
                    evenNumbers[i] = evenNumbers[minIndex];
                    evenNumbers[minIndex] = aux;
                }

                printf("\n\nevenNumber: %d\noddNumber: %d\n", evenNumber, oddNumber);
                printf("\nEven Array: ");
                printArray(evenNumbers, evenNumber);
                printf("\n");
                printf("\nOdd Array: ");
                printArray(oddNumbers, oddNumber);
                printf("\n");
            }
            break;

        case 7:
            {
                printf("7.Dados dois vetores de tamanho N, faça uma função que diga se os mesmos possuam conteúdo");
                printf(" igual.\n\n");

                int sizeA, sizeB;

                printf("Size of array A: ");
                scanf("%d", &sizeA);
                printf("Size of array B: ");
                scanf("%d", &sizeB);

                int a[sizeA], b[sizeB];
                printf("Insert array A: \n");
                readVector(a, sizeA);
                printf("Insert array B: \n");
                readVector(b, sizeB);

                if(arrayIsEqual(a, sizeA, b, sizeB))
                    printf("\nA is equal to B!\n");
                else
                    printf("\nA is NOT equal to B!\n");
            }
            break;

            /*MATRIZES*/

        case 8:
            {
                printf("1. Faça um algoritmo que construa uma matriz de nome MAT de 10 linhas e 15 colunas contendo");
                printf(" números inteiros. Em seguida escreva a soma dos elementos de cada linha e se a soma dos");
                printf(" elementos é par ou impar. Por fim escreva a soma dos elementos de cada coluna e se a soma dos");
                printf(" elementos é par ou impar.\n\n");

                int mat[10][15], i, j, sum=0;

                populateVector(mat, 10*15);
                print2DArray(mat, 10, 15);

                printf("\nLine sums: \n");

                for(i=0;i<10;i++) {
                    for(j=0;j<15;j++) {
                        sum += mat[i][j];
                    }
                    printf("Sum is: %d, ", sum);
                    if(!(sum%2)) {
                        printf("Sum of %d# line is EVEN!\n", i+1);
                    } else {
                        printf("Sum of %d# line is ODD!\n", i+1);
                    }
                }
                sum = 0;

                printf("\nColumn sums: \n");
                for(i=0;i<15;i++) {
                    for(j=0;j<10;j++) {
                        sum += mat[j][i];
                    }
                    printf("Sum is: %d, ", sum);
                    if(!(sum%2)) {
                        printf("Sum of %d# column is EVEN!\n", i+1);
                    } else {
                        printf("Sum of %d# column is ODD!\n", i+1);
                    }
                }
            }
            break;

        case 9:
            {
                printf("2. Faça um algoritmo que construa uma matriz 50 por 50 de números reais e depois de construída,");
                printf(" colocar o conteúdo de sua diagonal principal dentro de um vetor e depois do vetor montado,");
                printf(" imprimir o vetor.\n\n");

                int i, mat[50][50], diag[50];
                populateVector(mat, 50*50);

                for(i=0; i<50; i++){
                    diag[i]= mat[i][i];
                }
                printArray(diag, 50);
                }
            break;

        case 10:
            {
                printf("3. Faça um programa que gere uma matriz transposta (Matriz transposta é toda a matriz onde são");
                printf(" trocadas as linhas pelas colunas, ouvice-versa).\n\n");

                int mat[4][5], i, j;
                populateVector(mat, 4*5);
                print2DArray(mat, 4, 5);
                printf("\n\nTransposing...\n\n");
                int mat2[5][4];

                for(i=0;i<5;i++) {
                    for(j=0;j<4;j++) {
                        mat2[i][j] = mat[j][i];
                    }
                }
                print2DArray(mat2, 5, 4);
            }
            break;

        case 11:
            {
                printf("4. Faça um programa que faça a multiplicação de duas matrizes.\n\n");

                int mat1[4][4], mat2[4][4], i, j, k;
                populateVector(mat1, 4*4);
                populateVector(mat2, 4*4);
                int mat3[4][4] = {0};

                for(i=0;i<4;i++) {
                    for(j=0;j<4;j++) {
                        for(k=0;k<4;k++){
                            mat3[i][j] += (mat1[i][k]) * (mat2[k][j]);
                        }
                    }
                }

                printf("\nMatrix A: \n");
                print2DArray(mat1,4,4);
                printf("\nMatrix B: \n");
                print2DArray(mat2,4,4);
                printf("\nMatrix A*B: \n");
                print2DArray(mat3,4,4);
            }
            break;

        case 12:
            {
                printf("5. Faça um programa que faça a soma de duas matrizes.\n\n");

                int mat1[4][4], mat2[4][4], i, j, k;

                populateVector(mat1, 4*4);
                populateVector(mat2, 4*4);

                int mat3[4][4] = {0};

                for(i=0;i<4;i++) {
                    for(j=0;j<4;j++) {
                        mat3[i][j] = (mat1[i][j]) + (mat2[i][j]);
                    }
                }

                printf("\nMatrix A: \n");
                print2DArray(mat1,4,4);
                printf("\nMatrix B: \n");
                print2DArray(mat2,4,4);
                printf("\nMatrix A + B: \n");
                print2DArray(mat3,4,4);
            }
            break;

        case 13:
            {
                printf("6. Faça um programa que deverá permitir que o usuário entre com os valores dos elementos de uma");
                printf(" matriz quadrada de ordem 4 e possibilite o usuário realizar as seguintes funcionalidades:\n");
                printf("a) Imprimir todos os elementos da matriz;\n");
                printf("b) Somar os quadrados de todos os elementos da primeira coluna;\n");
                printf("c) Somar todos os elementos da terceira linha;\n");
                printf("d) Somar os elementos da diagonal principal; e\n");
                printf("e) Somar todos os elementos de índice par da segunda linha.\n\n");

                printf("Insert a 4 by 4 matrix: \n");
                int mat1[4][4], mat2[4][4], i, sum = 0, j;
                populateVector(mat1,4*4);
                print2DArray(mat1, 4, 4);

                for(i=0;i<4;i++){
                    for(j=0;j<4;j++){
                        mat2[i][j] = mat1[i][j];
                    }
                }

                char opt2;

                do{
                    printf("(a)Print, (b)Sum of squares of Column 1, (c)Sum of Row 3,");
                    printf(" (d)Sum of main diag., (e)Sum of even col in row 2, (f)EXIT: \n");
                    scanf(" %c", &opt2);
                    switch(opt2){
                    case 'a':
                        printf("\n");
                        print2DArray(mat2, 4, 4);
                        printf("\n\n");
                        break;
                    case 'b':
                        printf("\n");
                        for(i=0;i<4;i++){
                            sum += mat1[i][0] * mat1[i][0];
                        }
                        printf("Sum: %d", sum);
                        printf("\n\n");
                        break;
                    case 'c':
                        printf("\n");
                        for(i=0;i<4;i++){
                            sum += mat1[2][i];
                        }
                        printf("Sum: %d", sum);
                        printf("\n\n");
                        break;
                    case 'd':
                        printf("\n");
                        for(i=0;i<4;i++){
                            sum += mat1[i][i];
                        }
                        printf("Sum: %d", sum);
                        printf("\n\n");
                        break;
                    case 'e':
                        printf("\n");
                        for(i=0;i<4;i++){
                            if(i%2==1)
                                sum += mat1[1][i];
                        }
                        printf("Sum: %d", sum);
                        printf("\n\n");
                        break;
                    case 'f':
                        printf("Closing! ...");
                    }
                    sum = 0;
                } while(opt2!='f');
            }
            break;
        }

    } while(opt!=14);

    printf("\nPress Enter to Exit\n");
    return getch();
}
