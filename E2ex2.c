#include <math.h>
int main() {
    /*int lenght, height;
    printf("Insert retangle height and lenght: ");
    scanf("%d %d", &height, &lenght);
    printf("Area is: %d", height*lenght);*/
    /*int a=5, b=6;
    b += a;
    a = b-a;
    b = b-a;
    printf("a and b: %d, %d", a, b);*/
    /*double a=2.0, b=6.0, c=-4.0;
    if((b*b-4.0*a*c)>0){
        int d= sqrt(b*b-4.0*a*c);
        printf("x1= %.2f, x2= %.2f", (-b+d)/(a*2), (-b-d)/(a*2));
    }*/
    char ch;
    printf("Menu \nA: Fish\nB: Chicken\nC: Lobster\nD: Liver\n");
    scanf("%c", &ch);
    switch(ch){
    case 'A':
        printf("\nFish!");
        break;
    case 'B':
        printf("\nChicken!");
        break;
    case 'C':
        printf("\nLobster!");
        break;
    case 'D':
        printf("\nliver");
        break;
    default:
        printf("Error!");
    }

}
