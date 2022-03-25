#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct Struct1 {
    char name[32];
    int age;
    int address;
} Struct1;

typedef struct Struct2 {
    int x;
    int y;
} Ponto;

typedef struct Struct3 {
    Ponto a, b;
    float area;
    float diagonal;
    int perimeter;
} Retangulo;

typedef struct Struct4 {
    int matricula;
    char nome[16];
    float notas[3];
    float media;
} Aluno;

typedef struct Struct5 {
    int hora;
    int minuto;
    int segundo;
    int totalSegundos;
} Hora;

typedef struct Struct6Aux{
    int ano;
    int mes;
    int dia;
} Data;

typedef struct Struct6 {
    char nome[16];
    Data dataDeNascimento;
    int diasVividos;
} Pessoa;

typedef struct Struct7 {
    char nome[16];
    char esporte[16];
    int idade;
    float altura;
} Atleta;

typedef struct Struct8 {
    int posicao;
    int nCamisa;
    float peso;
    float altura;
} Jogador;

typedef struct Struct9 {
    char nome[64];
    Data nascimento;
    float mensalidade;
    int dependentes;
} Associado;

typedef struct Struct10Aux {
    int endereco;
    int telefone;
    Data nascimento;
} Dados;

typedef struct Struct10 {
    char nome[64];
    int idade;
    int carteira;
    int dependentes;
    Dados dados;
} Socio;

typedef struct Struct11 {
    char nome[32];
    char sobrenome[32];
    char email[128];
    int telefoneMovel;
    int telefoneFixo;
} Agenda;
    /*15. Crie um programa com uma estrutura para simular uma agenda de telefone celular,
    com até 100 registros. Nessa agenda deve constar o nome, sobrenome, número de
    telefone móvel, número de telefone fixo e e-mail. O programa deverá fazer a leitura e,
    após isso, mostrar os dados na tela.*/

int main() {

    /*1. Implemente um programa em C que leia o nome, a idade e o endereço de uma pessoa
    e armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados da
    estrutura lida.*/
    srand(time(NULL));


    int opt;
    do{
        printf("\nInsert exercise option: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 (0 to exit)\n");
        scanf("%d", &opt);
        switch(opt){
        case 1:
            {
                Struct1 person;
                printf("Insert data, press enter after each: name, age, address\n");
                scanf("%s", person.name);
                scanf("%d", &person.age);
                scanf("%d", &person.address);

                printf("Name: %s, Age: %d, Address: %d", person.name, person.age, person.address);
            }
            break;
        case 2:
            {
            /*2. Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
            e Y). Em seguida, declare e leia do teclado um ponto e exiba a distância dele até a
            origem das coordenadas, isto é, posição (0, 0). Para realizar o cálculo, utilize a fórmula
            a seguir:*/
                Ponto pA, pB;
                pA.x = 0;
                pA.y = 0;

                printf("Insert X and Y: ");
                scanf("%d %d", &pB.x, &pB.y);
                float d = sqrt(pow(pB.x-pA.x,2)+pow(pB.y-pA.y,2));

                printf("Distance from point A to point B: %.2f", d);
            }
            break;
        case 3:
            {
            /*3. Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
            e Y). Em seguida, declare e leia do teclado dois pontos e exiba a distância entre eles,
            considere a mesma fórmula do exercício anterior.*/
                Ponto pA, pB;

                printf("Insert X and Y for point A: ");
                scanf("%d %d", &pA.x, &pA.y);

                printf("Insert X and Y for point B: ");
                scanf("%d %d", &pB.x, &pB.y);
                float d = sqrt(pow(pB.x-pA.x,2)+pow(pB.y-pA.y,2));

                printf("Distance from point A to point B: %.2f", d);

            }
            break;
        case 4:
            {
                /*4. Cria uma estrutura chamada retângulo. Essa estrutura deverá conter o ponto superior
                esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido por uma
                estrutura Ponto, a qual contém as posições X e Y. Faça um programa que declare e leia
                uma estrutura retângulo e exiba a área e o comprimento da diagonal e o perímetro
                desse retângulo.*/
                Retangulo retangulo;

                printf("Insert X and Y of the first vertex: ");
                scanf("%d %d", &retangulo.a.x, &retangulo.a.y);

                printf("Insert X and Y of the second vertex: ");
                scanf("%d %d", &retangulo.b.x, &retangulo.b.y);

                retangulo.diagonal = sqrt(pow(retangulo.b.x-retangulo.a.x,2)+pow(retangulo.b.y-retangulo.a.y,2));
                printf("Diagonal of the rectangle: %.2f\n", retangulo.diagonal);

                retangulo.area = fabs((retangulo.b.x-retangulo.a.x)) * fabs((retangulo.b.y-retangulo.a.y));
                printf("Area of the rectangle: %.2f\n", retangulo.area);

                retangulo.perimeter = abs((retangulo.b.x-retangulo.a.x)*2) + abs((retangulo.b.y-retangulo.a.y)*2);
                printf("Perimeter of the rectangle: %.d\n", retangulo.perimeter);
            }
            break;
        case 5:
            /*5. Usando a estrutura retângulo do exercício anterior, faça um programa que declare e
            leia uma estrutura retângulo e um ponto, e informe se esse ponto está ou não dentro
            do retângulo.*/
            {
                Retangulo retangulo;
                Ponto p;

                printf("Insert X and Y of the first vertex: ");
                scanf("%d %d", &retangulo.a.x, &retangulo.a.y);

                printf("Insert X and Y of the second vertex: ");
                scanf("%d %d", &retangulo.b.x, &retangulo.b.y);

                printf("Insert X and Y of the point p: ");
                scanf("%d %d", &p.x, &p.y);

                int *upperX, *lowerX, *upperY, *lowerY;


                if(retangulo.a.x>retangulo.b.x) {
                    upperX = &retangulo.a.x;
                    lowerX = &retangulo.b.x;
                } else {
                    upperX = &retangulo.b.x;
                    lowerX = &retangulo.a.x;
                }

                if(retangulo.a.y>retangulo.b.y) {
                    upperY = &retangulo.a.y;
                    lowerY = &retangulo.b.y;
                } else {
                    upperY = &retangulo.b.y;
                    lowerY = &retangulo.a.y;
                }

                printf("%d %d %d %d", *upperX, *lowerX, *upperY, *lowerY);

                if(p.x<=*upperX && p.x>=*lowerX && p.y<=*upperY && p.y>=*lowerY) {
                    printf("The point P is part of the rectangle!");
                } else {
                    printf("The point P is not a part of the rectangle!");
                }
            }
            break;
        case 6:
            {
                /*6. Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve
                conter o número de matrícula do aluno, seu nome e as notas de três provas. Defina
                também um tipo para esta estrutura. Agora, escreva um programa que leia os dados
                de cinco alunos e os armazena nessa estrutura. Em seguida, exiba o nome e as notas
                do aluno que possui a maior média geral dentre os cinco.*/

                Aluno alunos[5];
                int i, j, maxIndex = 0, maxValue;
                for(i = 0;i<5; i++) {
                    printf("Insert student %d info: \n\n", i+1);
                    printf("Name: ");
                    scanf("%s", alunos[i].nome);
                    printf("Register: ");
                    scanf("%d", &alunos[i].matricula);
                    for(j=0;j<3;j++){
                        printf("Grade %d: ", j+1);
                        scanf("%f", &alunos[i].notas[j]);
                    }
                    alunos[i].media = (alunos[i].notas[0]+ alunos[i].notas[1]+ alunos[i].notas[2])/3;
                }
                maxValue=alunos[0].media;

                for(i=0;i<5;i++){
                    if(alunos[i].media>=maxValue){
                        maxIndex = i;
                        maxValue = alunos[i].media;
                    }
                }

                printf("\nStudent with highest average: ");
                printf("%s, Register: %d, Grade Average: %.2f ", alunos[maxIndex].nome, alunos[maxIndex].matricula, alunos[maxIndex].media);

            }
            break;
        case 7:
            {
                /*7. Crie uma estrutura representando uma hora. Essa estrutura deve conter os campos
                hora, minuto e segundo. Agora, escreva um programa que leia um vetor de cinco
                posições dessa estrutura e imprima a maior hora.*/
                int i, max=0, maxIndex=0;
                Hora horas[5];

                for(i=0;i<5;i++) {
                    printf("Insert hour %d: ", i+1);
                    scanf("%d", &horas[i].hora);
                    printf("Insert minute %d: ", i+1);
                    scanf("%d", &horas[i].minuto);
                    printf("Insert second %d: ", i+1);
                    scanf("%d", &horas[i].segundo);

                    horas[i].totalSegundos = (horas[i].hora*60*60) + (horas[i].minuto*60) + horas[i].segundo;
                }

                for(i=0;i<5;i++) {
                    if(horas[i].totalSegundos>max){
                        max = horas[i].totalSegundos;
                        maxIndex = i;
                    }
                }

                printf("%d:%d:%d", horas[maxIndex].hora, horas[maxIndex].minuto, horas[maxIndex].segundo);

            }
            break;

        case 8:
            {
                /*8. Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma
                pessoa. Faça uso de estruturas aninhadas e definição de novo tipo de dado. Agora,
                escreva um programa que leia os dados de seis pessoas. Calcule e exiba os nomes da
                pessoa mais nova e da mais velha.*/

                int i, max=0, maxIndex=0, minIndex=0;
                Pessoa pessoas[6];
                Data dataAtual;
                dataAtual.ano = 2022;
                dataAtual.mes = 3;
                dataAtual.dia = 12;
                int dataAtualDias= dataAtual.ano*365 + dataAtual.mes*30 + dataAtual.dia;


                for(i=0;i<6;i++) {
                    printf("Insert name %d: ", i+1);
                    scanf("%s", pessoas[i].nome);
                    printf("Insert birth year %d: ", i+1);
                    scanf("%d", &pessoas[i].dataDeNascimento.ano);
                    printf("Insert birth month %d: ", i+1);
                    scanf("%d", &pessoas[i].dataDeNascimento.mes);
                    printf("Insert birth day %d: ", i+1);
                    scanf("%d", &pessoas[i].dataDeNascimento.dia);

                    pessoas[i].diasVividos = dataAtualDias - ((pessoas[i].dataDeNascimento.ano * 365) + (pessoas[i].dataDeNascimento.mes*30) + (pessoas[i].dataDeNascimento.dia));
                }

                int min = pessoas[0].diasVividos;

                for(i=0;i<6;i++) {
                    if(pessoas[i].diasVividos>max){
                        max = pessoas[i].diasVividos;
                        maxIndex = i;
                    }
                }

                for(i=0;i<6;i++) {
                    if(pessoas[i].diasVividos<min){
                        min = pessoas[i].diasVividos;
                        minIndex = i;
                    }
                }
                printf("Oldest person: %s\n", pessoas[maxIndex].nome);
                printf("Youngest person: %s\n", pessoas[minIndex].nome);
            }
            break;
        case 9:
            {
                /*9. Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do
                atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados de
                cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.*/
                int i;
                Atleta atletas[5];

                for(i=0;i<5;i++) {
                    printf("Insert name for athlete %d: ", i+1);
                    scanf("%s", atletas[i].nome);
                    printf("Insert sport played for athlete %d: ", i+1);
                    scanf("%s", atletas[i].esporte);
                    printf("Insert age for athlete %d: ", i+1);
                    scanf("%d", &atletas[i].idade);
                    printf("Insert height for athlete %d: ", i+1);
                    scanf("%f", &atletas[i].altura);
                }

                float max=atletas[0].altura;
                int maxIndex=0, min=atletas[0].idade, minIndex=0;

                for(i=0;i<5;i++) {
                    if(atletas[i].altura>max){
                        max = atletas[i].altura;
                        maxIndex = i;
                    }
                }

                for(i=0;i<5;i++) {
                    if(atletas[i].idade<min){
                        min = atletas[i].idade;
                        minIndex = i;
                    }
                }

                printf("Tallest athlete: %s\n", atletas[maxIndex].nome);
                printf("Youngest person: %s\n", atletas[minIndex].nome);
            }
            break;
        case 10:
            /*10. Usando a estrutura atleta do exercício anterior, escreva um programa que leia os
            dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.*/
            {
                int i, j, min = 0, minIndex = 0;
                Atleta atletas[5];

                for(i=0;i<5;i++) {
                    printf("Insert name for athlete %d: ", i+1);
                    scanf("%s", atletas[i].nome);
                    printf("Insert sport played for athlete %d: ", i+1);
                    scanf("%s", atletas[i].esporte);
                    printf("Insert age for athlete %d: ", i+1);
                    scanf("%d", &atletas[i].idade);
                    printf("Insert height for athlete %d: ", i+1);
                    scanf("%f", &atletas[i].altura);
                }


                for(i=0;i<5;i++){
                    min = 0;
                    for(j=i;j<5;j++) {
                        if(min>atletas[j].idade) {
                            min = atletas[j].idade;
                            minIndex = j;
                        }
                    }
                    Atleta aux = atletas[i];
                    atletas[i] = atletas[minIndex];
                    atletas[minIndex] = aux;
                }

                for(i=0;i<5;i++){
                    printf("%s\n", atletas[i].nome);
                }

            }
            break;
        case 11:
            {
                /*11. Escreva um programa que contenha uma estrutura representando uma data válida.
                Essa estrutura deve conter os campos dia, mês e ano. Em seguida, leia duas datas e
                armazene nessa estrutura. Calcule e exiba o número de dias que decorrem entre as
                duas datas.*/
                int i;
                Data d[2];
                int dias[2];

                for(i=0;i<2;i++){
                    printf("Insert %d# year: ", i+1);
                    scanf("%d", &d[i].ano);
                    printf("Insert %d# month: ", i+1);
                    scanf("%d", &d[i].mes);
                    printf("Insert %d# day: ", i+1);
                    scanf("%d", &d[i].dia);
                    dias[i] = d[i].ano*365 + d[i].mes*30 + d[i].dia;
                }

                printf("%d days passed between day 1 and 2.", abs(dias[0]-dias[1]));
            }
            break;
        case 12:
            {
                /*12. Astolfolov Oliveirescu é técnico de um time da série C do poderoso campeonato de
                futebol profissional da Albânia. Ele deseja manter os dados dos seus jogadores
                guardados de forma minuciosa. Ajude-o fazendo um programa para armazenar os
                seguintes dados de cada jogador: nº da camisa, peso (kg), altura (m) e a posição em
                que joga (atacante, defensor ou meio campista). Lembre-se que o time tem 22
                jogadores, entre reservas e titulares. Leia os dados e depois gere um relatório no
                vídeo, devidamente tabulado/formatado.*/
                int i, opt2 = 1, j=0;
                Jogador jogadores[22];
                printf(" \n");
                for(i = 0 ; i<22 && opt2!=0 ; i++, j++) {
                    printf("Player's shirt N# (%d): ", i+1);
                    scanf("%d", &jogadores[i].nCamisa);
                    printf("Weight (%d): ", i+1);
                    scanf("%f", &jogadores[i].peso);
                    printf("Height (%d): ", i+1);
                    scanf("%f", &jogadores[i].altura);
                    printf("Position (1 = atacante;2 = defensor;3 = meio-campista.)(%d): ", i+1);
                    scanf("%d", &jogadores[i].posicao);
                    printf("Insert another?(1 = Y ; 0 = N)");
                    scanf("%d", &opt2);
                }

                printf("\n-----------------------------------------------------------------\n");
                printf("| Position\t|\tN#\t|\tWeight\t|\tHeight\t|\n");
                printf("-----------------------------------------------------------------\n");

                for(i=0;i<j;i++) {
                    switch(jogadores[i].posicao){
                    case 1:
                        printf("| Atacante\t|");
                        break;
                    case 2:
                        printf("| Defensor\t|");
                        break;
                    case 3:
                        printf("| M.Campo\t|");
                        break;
                    }
                    printf("\t%d\t|", jogadores[i].nCamisa);
                    printf("\t%.2f\t|", jogadores[i].peso);
                    printf("\t%.2f\t|", jogadores[i].altura);
                    printf("\n");
                }

                printf("-----------------------------------------------------------------\n");

            }
            break;
        case 13:
            /*13. Um clube social com 37 associados deseja que você faça um programa para armazenar
            os dados cadastrais desses associados. Os dados são: nome, dia, mês e ano de
            nascimento, valor da mensalidade e quantidade de dependentes. O programa deverá
            ler os dados e imprimir depois na tela. Deverá também informar o associado (ou os
            associados) com o maior número de dependentes.*/
            {
                int i=0, j=0, opt2=1, opt3, associadosInseridos=37;
                Associado associados[37];
                char nomeAssociados[16][16] = {"Alan", "Buck", "Carlos", "Dana", "Elaine", "Fran", "George", "Ian", "Jack", "Kevin", "Lisa", "Marco", "Nissen", "Owen", "Peter", "Rogers"};

                printf(" \n");

                /*typedef struct Struct9 {
                    char nome[16];
                    Data nascimento;
                    float mensalidade;
                    int dependentes;
                } Associado;*/

                printf("\nAutomatically fill in ? (0 = N, 1 = Y)\n");
                scanf("%d", &opt3);

                switch(opt3) {
                case 0:
                    for(i = 0 , associadosInseridos = 0 ; i<37 && opt2!=0 ; i++, associadosInseridos++) {
                        printf("Associate's name: ");
                        scanf("%s", associados[i].nome);
                        printf("Associate's birth year, month and day: ");
                        scanf("%d %d %d", &associados[i].nascimento.ano, &associados[i].nascimento.mes, &associados[i].nascimento.dia);
                        printf("Associate's subscription: ");
                        scanf("%d", &associados[i].mensalidade);
                        printf("Associate's dependants: ");
                        scanf("%d", &associados[i].mensalidade);

                        printf("Insert another?(1 = Y ; 0 = N)\n");
                        scanf("%d", &opt2);
                    }
                    break;
                case 1:
                    for(i=0;i<37;i++) {
                        strcpy(associados[i].nome, nomeAssociados[rand()%16]);
                        strcat(associados[i].nome, " ");
                        strcat(associados[i].nome, nomeAssociados[rand()%16]);
                        associados[i].nascimento.ano = 2003 - rand()%104;
                        associados[i].nascimento.mes = rand()%12 +1;
                        associados[i].nascimento.dia = rand()%30 +1;
                        switch(rand()%4)
                        {
                        case 0:
                            associados[i].mensalidade = 1000.0;
                            break;
                        case 1:
                            associados[i].mensalidade = 1250.0;
                            break;
                        case 2:
                            associados[i].mensalidade = 1500.0;
                            break;
                        case 3:
                            associados[i].mensalidade = 1750.0;
                            break;
                        }
                        associados[i].dependentes = rand()%10;
                    }
                    break;
                }

                for(i=0 ; i<associadosInseridos ; i++) {
                    printf("Name: %s   \t", associados[i].nome);
                    printf("\tBirthday: %d/%d/%d \t", associados[i].nascimento.ano, associados[i].nascimento.mes, associados[i].nascimento.dia);
                    printf("Subscription: %.2fR$ \t", associados[i].mensalidade);
                    printf("Depentes: %d\n", associados[i].dependentes);
                }

                int max = 0, maxIndex = 0;

                for(i=0;i<associadosInseridos;i++) {
                    if(associados[i].dependentes>max){
                        max = associados[i].dependentes;
                    }
                }

                printf("Associate(s) with more dependants: ");

                for(i=0;i<associadosInseridos;i++) {
                    if(associados[i].dependentes==max)
                        printf("%s ,", associados[i].nome);
                }
                printf("\b ");


            }
            break;
        case 14:
            {

                /*14. Crie um programa que tenha uma estrutura para armazenar o nome, a idade e número
                da carteira de sócio de 50 associados de um clube. Crie também uma estrutura, dentro
                desta anterior, chamada dados que contenha o endereço, telefone e data de
                nascimento.*/

                Socio socios[50];
                int i;
                char nomeAssociados[16][16] = {"Alan", "Buck", "Carlos", "Dana", "Elaine", "Fran", "George", "Ian", "Jack", "Kevin", "Lisa", "Marco", "Nissen", "Owen", "Peter", "Rogers"};

                for(i=0;i<50;i++){
                    strcpy(socios[i].nome, nomeAssociados[rand()%16]);
                    strcpy(socios[i].nome, " ");
                    strcat(socios[i].nome, nomeAssociados[rand()%16]);
                    strcat(socios[i].nome, " ");
                    strcat(socios[i].nome, nomeAssociados[rand()%16]);
                    strcat(socios[i].nome, " ");
                    strcat(socios[i].nome, nomeAssociados[rand()%16]);

                    socios[i].idade = rand()%80 + 18;
                    socios[i].carteira = rand()%1000000001;
                    socios[i].dados.telefone = rand()%100000000;
                    socios[i].dados.endereco = rand()%100000000;

                    socios[i].dados.nascimento.ano = 2003 - rand()%104;
                    socios[i].dados.nascimento.mes = rand()%12 +1;
                    socios[i].dados.nascimento.dia = rand()%30 +1;
                }

                for(i=0 ; i<50 ; i++) {
                    printf("Name: %s   \t", socios[i].nome);
                    printf("Age: %d \t", socios[i].idade);
                    printf("Registry No.: %d\t", socios[i].carteira);
                    printf("Phone No.: %08d\t", socios[i].dados.telefone);
                    printf("Postal code: %08d\t", socios[i].dados.endereco);
                    printf("\Birthday: %d.%d.%d\n", socios[i].dados.nascimento.ano, socios[i].dados.nascimento.mes, socios[i].dados.nascimento.dia);
                }
            }
            break;
        case 15:
            {
                /*15. Crie um programa com uma estrutura para simular uma agenda de telefone celular,
                com até 100 registros. Nessa agenda deve constar o nome, sobrenome, número de
                telefone móvel, número de telefone fixo e e-mail. O programa deverá fazer a leitura e,
                após isso, mostrar os dados na tela.*/
                /*typedef struct Struct11 {
                    char nome[64];
                    char email[128];
                    int telefoneMovel;
                    int telefoneFixo;
                } Agenda;*/

                Agenda pessoa[100];
                int i;
                char nomes[16][16] = {"Alan", "Buck", "Carlos", "Dana", "Elaine", "Fran", "George", "Iann", "Jack", "Kevin", "Lisa", "Marco", "Nissen", "Owen", "Peter", "Rogers"};

                for(i=0;i<50;i++){

                    strcpy(pessoa[i].nome, nomes[rand()%16]);
                    strcpy(pessoa[i].sobrenome, nomes[rand()%16]);
                    strcpy(pessoa[i].email, pessoa[i].nome);
                    strcat(pessoa[i].email, pessoa[i].sobrenome);
                    strcat(pessoa[i].email, "@gmail.com");


                    pessoa[i].telefoneMovel = rand()*1281;
                    pessoa[i].telefoneFixo = rand()*1281;

                }

                for(i=0 ; i<50 ; i++) {
                    printf("Name: %s %s  \t", pessoa[i].nome, pessoa[i].sobrenome);
                    printf("Email: %s \t", pessoa[i].email);
                    printf("Cellphone No.: %08d\t", pessoa[i].telefoneMovel);
                    printf("Landline No.: %08d\t\n", pessoa[i].telefoneFixo);
                }
            }
            break;
        }
    }while(opt!=0);

}
