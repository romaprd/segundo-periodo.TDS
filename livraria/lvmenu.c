#include <stdio.h>
#include <stdlib.h>
#include "lvcadastro.c"
void menu(){
    int op;
do{
    
   
    printf("\n1 - cadastro\n2 - consulta\n3 - venda\n4 - estoque\n5 - sair\ninforme a opcao desejada: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        cadastro ();
        menu();
        system("cls");
        break;
        case 2:
        //consulta();
        menu();
        system("cls");
        break;
        case 3:
        //venda();
        menu();
        system("cls");
        break;
        case 4:
        //estoque();
        menu();
        system("cls");
        break;
        case 5:
        printf("\nsaindo...");
        break;
        default :
        printf("opcao invalida!\ninforme uma opcao valida:");
        menu();
    
    }
}while (op < 0 && op > 5 );




}