#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXENTRADAS 200

typedef struct{
     int cdb[100];//codigo de barras
 char titulo [50], autor [50];
 int qee, adp;//quantidade em estoque e ano de publicacao
 float vdv; //valor de vendas

}dados;
dados entradas [MAXENTRADAS];
int total_entradas = 0;//contador de entradas coletadas 

void cadastro(){


 printf("\n--- SOLICITACAO DECADASTRO ---\n");
 printf("\n");
 printf("informe o codigo de barras: ");
 scanf("%d", &entradas[total_entradas].cdb);
 getchar();
 printf("informe o titulo do livro: ");
 fgets(entradas[total_entradas].titulo, 50, stdin);
 printf("informe o nome do autor: ");
 fgets(entradas[total_entradas].autor, 50, stdin);
 printf("informe o ano de publicacao :");
 scanf("%d", &entradas[total_entradas].adp);
 printf("informe a quantidade em estoque: ");
 scanf("%d", &entradas[total_entradas].qee);
 printf("informe o valor por unidade em Reais: ");
 scanf("%f", &entradas[total_entradas].vdv);
 

}