#include <stdio.h>

void somar() {
    int num1, num2;
    printf("Informe o primeiro numero: ");
    scanf("%d", &num1);
    printf("Informe o segundo numero: ");
    scanf("%d", &num2);
    printf("O resultado da soma eh: %d\n", num1 + num2);
}

void subtrair() {
    int num1, num2;
    printf("Informe o primeiro numero: ");
    scanf("%d", &num1);
    printf("Informe o segundo numero: ");
    scanf("%d", &num2);
    printf("O resultado da subtracao eh: %d\n", num1 - num2);
}

void multiplicar() {
    int num1, num2;
    printf("Informe o primeiro numero: ");
    scanf("%d", &num1);
    printf("Informe o segundo numero: ");
    scanf("%d", &num2);
    printf("O resultado da multiplicacao eh: %d\n", num1 * num2);
}

void dividir() {
    int num1, num2;
    printf("Informe o primeiro numero: ");
    scanf("%d", &num1);
    printf("Informe o segundo numero: ");
    scanf("%d", &num2);

    while (num2 == 0) {
        printf("Divisao por zero é invalida!!\ninforme um outro numero: ");
        scanf("%d", &num2);
    }
    printf("O resultado da divisao eh: %.2f\n", (float)num1 / num2);
}
//esse codigo e meu ta 
void calculadora() {
    int opcao;

    do {
        printf("\nEscolha uma opcao\n");
        printf("1 - Soma\n2 - Subtracao\n3 - Divisao\n4 - Multiplicacao\n0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                somar();
                break;
            case 2:
                subtrair();
                break;
            case 3:
                dividir();
                break;
            case 4:
                multiplicar();
                break;
            case 0:
                printf("Saindo da calculadora\n");
                break;
            default:
                printf("Opcao invalida!!!\ninforme uma opcao valida\n");
        }
    } while (opcao != 0);
}

int main() {
    printf("\nInicio:\n");
    calculadora();
    return 0;
}
