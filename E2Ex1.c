#include <stdio.h>
#include <stdlib.h>


int sum(int a, int b) {
    return a+b;
}

int minus(int a, int b) {
    return a-b;
}

int main()
{
    printf("\n\n-----------Sum Function-------------\n\n");
    printf("1 + 2 equals: %d", sum(1, 2));
    printf("\n\n-----------Subtraction Function-------------\n\n");
    printf("1 - 2 equals: %d", minus(1, 2));
    printf("\n\n-----------Fatorial-------------\n\n");

    printf("Insert number: ");

    int a;
    scanf("%d", &a);

    int i;
    for(i=a-1;i>0;i--) {
        a*=i;
    }
    printf("%d", a);


    printf("\n\n------------Notas---------------\n\n");

    printf("How many students?");
    scanf("%d", &a);

    for(i=0;i<a;i++) {
        printf("Student name: ");
        char name[40];
        scanf("%s", name);
        float grade[4];
        float gradeAverage=0;
        printf("Insert four grades: ");
        scanf("%f %f %f %f", &grade[0],&grade[1],&grade[2],&grade[3]);
        int j;

        for(j=0;j<4;j++){
            gradeAverage+=grade[j];
        }
        gradeAverage = gradeAverage/4;

        if(gradeAverage>7.5){
            printf("\nStudent name: %s, Student Average: %f, Aproved!\n", name, gradeAverage);
        } else {
            printf("\nStudent name: %s, Student Average: %f, Failed!\n", name, gradeAverage);
        }
    }


    printf("\n\n------------Tabuada---------------\n\n");
    for(i=0;i<4;i++){
        int k;
        int j;
        switch(i){
        case 0:
            printf("\n------Sum Table----\n");
            for(j=1; j<10; j++){
                for(k=1; k<10; k++) {
                    printf("\n%d + %d = %d", j, k, j+k);
                }
                printf("\n");
            }
            break;
        case 1:
            printf("\n------Subtraction Table----\n");
            for(j=1; j<10; j++){
                for(k=1; k<10; k++) {
                    printf("\n%d - %d = %d", j, k, j-k);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("\n------Multiplication Table----\n");
            for(j=1; j<10; j++){
                for(k=1; k<10; k++) {
                    printf("\n%d * %d = %d", j, k, j*k);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("\n------Division Table----\n");
            for(j=1; j<10; j++){
                for(k=1; k<10; k++) {
                    printf("\n%d / %d = %f", j, k, (float)j/k);
                }
                printf("\n");
            }
            break;
        }
    }

    printf("\n\n-----------Numero maior/menor-------------\n\n");

    printf("Insert number A and B: ");

    int b;
    scanf("%d %d", &a, &b);

    if(a>b){
        printf("%d is more than %d", a, b);
    } else if(a==b) {
        printf("%d is equal to %d", a, b);
    } else {
        printf("%d is more than %d", b, a);
    }

    return 0;
}
