#include <stdio.h>
#include <stdlib.h>

void calculocpf (){

    int num[20], num1 = 0, num2 = 0, soma1 = 0, resultado1 = 0, soma2 = 0, resultado2 = 0;


    for (int i = 0; i < 9; i++){

        printf("Digite o %d numero do seu cpf: ", i+1);
        scanf("%d", &num1);
        num[i] = num1 * (i+1);
    }

    for (int i = 0; i < 9; i++){
        soma1 += num[i];
    }


    resultado1 = soma1 % 11;
    system("cls");
    printf("\nResultado: %d\n", resultado1);

    for (int i = 0; i < 10; i++){
        num[i] = 0;
    }

    for (int i = 0; i < 10; i++){
        printf("OBS: informe seu cpf novamente e insira o resultado da operacao anterior ao final!");
        printf("Digite o %d numero  do seu cpf: ", i+1);
        scanf("%d", &num2);
        num[i] = num2 * i;
    }

     for (int i = 0; i < 10; i++){
        soma2 += num[i];
    }


    resultado2 = soma2 % 11;
    printf("\n%d", resultado1);
    printf("\n%d", resultado2);
    
}
