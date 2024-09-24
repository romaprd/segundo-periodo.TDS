#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define o maximo de entradas que podem ser coletadas
#define MAX_ENTRADAS 100 
//tamanho maximo para o nome da empresa
#define MAX_NOME 100 
//tamanho maximo para o CNPJ 
#define CNPJ_TAMANHO 15 

//limites globais para comparacao
#define LIMITE_ENERGIA 5000.0  // Limite em kWh
#define LIMITE_AGUA 10000.0     // Limite em litros
#define LIMITE_RESIDUOS 2000.0  // Limite em kg

//estrutura para armazenar os dados de cada entrada
typedef struct {

    char nome_empresa[MAX_NOME]; //nome da empresa
    char cnpj[CNPJ_TAMANHO];     //CNPJ da empresa
    float energia_consumida; //consumo de energia em kWh
    float agua_consumida;    //consumo de água em litros
    float residuos_producao; //geracao de residuos em kg
} DadosAmbientais;

DadosAmbientais entradas[MAX_ENTRADAS];
int total_entradas = 0; //contador de entradas coletadas

void coletar_dados() {
    if (total_entradas >= MAX_ENTRADAS) {
        printf("Limite de entradas alcançado.\n");
        return; //sai da funcao se o limite foi atingido
    }
    printf("Digite o consumo de energia (kWh): ");
    scanf("%f", &entradas[total_entradas].energia_consumida);
    printf("Digite o consumo de agua (litros): ");
    scanf("%f", &entradas[total_entradas].agua_consumida);
    printf("Digite a quantidade de residuos gerados (kg): ");
    scanf("%f", &entradas[total_entradas].residuos_producao);

    total_entradas++; //incrementa o contador de entradas
}
void calcular_media() {
    if (total_entradas == 0) {
        printf("Nenhum dado coletado para calcular a média.\n");
        return;
    }

    float media_energia = 0, media_agua = 0, media_residuos = 0;
    for (int i = 0; i < total_entradas; i++) {
        media_energia += entradas[i].energia_consumida;
        media_agua += entradas[i].agua_consumida;
        media_residuos += entradas[i].residuos_producao;
    }

    media_energia /= total_entradas;
    media_agua /= total_entradas;
    media_residuos /= total_entradas;

    printf("\n--- Médias ---\n");
    printf("Média de Energia: %.2f kWh\n", media_energia);
    printf("Média de Água: %.2f litros\n", media_agua);
    printf("Média de Resíduos: %.2f kg\n", media_residuos);
    printf("---------------------------\n");

    //comparar medias com limites
    if (media_energia > LIMITE_ENERGIA){
        
        printf("A média de energia excedeu o limite!\n");
        printf("Sugestões para redução de energia:\n");
        printf("1. Substituir lâmpadas incandescentes por LEDs.\n");
        printf("2. Desligar equipamentos não utilizados.\n");
        printf("3. Utilizar termostatos programáveis.\n");
        printf("4. Realizar manutenção regular em equipamentos.\n");
        printf("5. Investir em fontes de energia renovável.\n");
    }
    if (media_agua > LIMITE_AGUA){
        
        printf("A média de água excedeu o limite!\n");
        printf("Sugestões para redução de consumo de água:\n");
        printf("1. Instalar torneiras e chuveiros de baixo fluxo.\n");
        printf("2. Utilizar sistemas de reuso de água.\n");
        printf("3. Implementar práticas de irrigação eficiente.\n");
        printf("4. Monitorar vazamentos.\n");
        printf("5. Educar sobre a conservação de água.\n");
    }
    if (media_residuos > LIMITE_RESIDUOS){
        
        printf("A média de resíduos excedeu o limite!\n");
        printf("Sugestões para redução de resíduos:\n");
        printf("1. Implementar a reciclagem de papel e plástico.\n");
        printf("2. Reduzir o uso de embalagens descartáveis.\n");
        printf("3. Promover a reutilização de materiais.\n");
        printf("4. Treinar sobre gestão de resíduos.\n");
        printf("5. Investir em produtos de baixo impacto ambiental.\n");
    }
}


void salvar_dados() {
    FILE *file = fopen("dados_ambientais.txt", "a"); //abre o arquivo para anexar dados
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return; //sai da função se houver erro ao abrir o arquivo
    }
    for (int i = 0; i < total_entradas; i++) {
        fprintf(file, "Empresa: %s, CNPJ: %s, Energia: %.2f kWh, Água: %.2f litros, Resíduos: %.2f kg\n", 
                entradas[i].nome_empresa, entradas[i].cnpj, 
                entradas[i].energia_consumida, entradas[i].agua_consumida, entradas[i].residuos_producao);
    }
    fclose(file); //fecha o arquivo
    printf("Dados salvos com sucesso.\n");
}
void gerar_relatorio(){
    
    int i;
    float total_agua = 0.0, total_energia = 0.0, total_residuos = 0.0;

    for(i = 0; i < total_entradas; i++){
        total_agua += entradas[i].agua_consumida;
        total_energia += entradas[i].energia_consumida;
        total_residuos += entradas[i].residuos_producao;
    }
    printf("RELATORIO AMBIENTAL\n");
    printf("total de consumo de energia: %.2f Kwh\n", total_energia);
    printf("total de consumo de agua: %.2f Litros\n", total_agua);
    printf("total de residuos gerados: %.2f Kg\n", total_residuos);
}
//funcao para sugestao de reducao de producao de residuos 
void sugestoes_reducao_residuos() {
    
    printf("\n--- Sugestoes para Reducao de Residuos ---\n");
    printf("1. Implementar a reciclagem de papel e plastico.\n");
    printf("2. Reduzir o uso de embalagens descartaveis.\n");
    printf("3. Promover a reutilização de materiais.\n");
    printf("4. Treinar funcionarios sobre a gestao de residuos.\n");
    printf("5. Investir em produtos de baixo impacto ambiental.\n");
}

//funcao para sugestoes sobre a reducao de consumo de agua
void sugestoes_reducao_agua() {
    
    printf("\n--- Sugestoes para Reducao de Consumo de Agua ---\n");
    printf("1. Instalar torneiras e chuveiros de baixo fluxo.\n");
    printf("2. Utilizar sistemas de reuso de agua (ex: aguas cinzas).\n");
    printf("3. Implementar praticas de irrigacao eficiente no paisagismo.\n");
    printf("4. Monitorar vazamentos e realizar manutencao regular.\n");
    printf("5. Educar funcionarios sobre a importancia da conservacao de agua.\n");
}

//funcao para sugestoes sobre a reducao de consumo de energia eletrica
void sugestoes_reducao_energia() {
    
    printf("\n--- Sugestoes para Reducao de Consumo de Energia Eletrica ---\n");
    printf("1. Substituir lampadas incandescentes por LEDs.\n");
    printf("2. Desligar equipamentos nao utilizados.\n");
    printf("3. Utilizar termostatos programaveis para controle de temperatura.\n");
    printf("4. Realizar manutencao regular em equipamentos para garantir eficiencia.\n");
    printf("5. Investir em fontes de energia renovavel (ex: paineis solares).\n");
}
void menu(){
    
    int op;
    do{
        printf("\n--- MENU ---\n");
        printf("\n");
        printf("1 - coletar dados\n2 - salvar dados\n3 - gerar relatorio\n4 - gerar media\n5 - sugestoes de reducao de residuos\n6 - sugestoes de reducao do consumo de agua\n7 - sugestoes de reducao de consumo de energia eletrica\n8 - sair\n");
        printf("\n");
        printf("para sair pressione 8\n");
        printf("informe a opcao desejada: ");
        scanf("%d", &op);
        
    
    switch(op){
        case 1:
        coletar_dados();
        break;
        case 2:
        salvar_dados();
        break;
        case 3:
        gerar_relatorio();
        break;
        case 4: 
            calcular_media();
        break;
        case 5:
        sugestoes_reducao_residuos();
        break;
        case 6:
        sugestoes_reducao_agua();
        break;
        case 7:
        sugestoes_reducao_energia();
        break;
        case 8:
        printf("\nsaindo. . .\n");
        break;
    }
    }while(op != 8);
    

    }

int main(){
    
    menu();
    
    return 0;
}
