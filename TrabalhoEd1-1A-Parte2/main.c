//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#include "functions.h"

void main(void){
    //configurando a lingua padrão do programa
    setlocale(LC_ALL, "Portuguese");
    //variaveis globais da função main 8 variaveis que precisam ser declaradas localmente
     int comando = 0; // comando digitado pelo usuário

    //Aplicação própria!
    while(comando != 7){
            char tipoMaterial[10],tipoProd[10],strConf[4];
            int quantidade = 0;
            int quantidadeMaterial, valorLote;
             menuPrograma();
             scanf("%d", &comando);
        switch(comando){
            case 1:
                listarQuantidadeTotalMaterialLote();
                break;
            case 2:
                listarMaterialPorLote();
                break;
            case 3:
                    printf("Digite o material que você deseja:");
                    scanf("%s",tipoMaterial);
                    //mostro a lista do produto especificado em cada lote e seus respectivos valores
                    mostrandoValorPorLote(tipoMaterial);
                    //pergunto a quantidade para o usuário
                    printf("Digite a quantidade que você deseja retirar do lote de %s: ", tipoMaterial);
                    scanf("%d",&quantidadeMaterial);
                    //pergunto em qual lote ele quer retirar o material especificado
                    printf("Em qual lote você deseja retirar o material:");
                    scanf("%d", &valorLote);
                    //chamo a função para executar todo procedimento especificado pelo usuário
                    RetiraMaterialLote(tipoMaterial);
                break;
            case 4:
                for(register int i = 0; i < TOTALLOTES; i++){
                        int loteEscolhido = 0;
                        int usuarioDigitouCerto;
                        char strUsuario[4];
                       //fornece o tipo de produto
                       printf("Digite o tipo de produto que você deseja?\n");
                       scanf("%s", tipoMaterial);
                       //verifico a digitação

                       //chama uma função que mostra os valores de cada lote com o produto especificado
                       mostrandoValorPorLote(tipoMaterial);

                       //pergunta a quantidade que o usuário deseja armazenar!
                       printf("Digite a quantidade dele?\n");
                       scanf("%d", &quantidade);

                       //pergunta em qual lote o usuário deseja armazenar!
                       printf("Digite que lote você quer armazenar?\n");
                       scanf("%d", &loteEscolhido);
                       //chamo a função que verifica se tem espaço e ao mesmo tempo adiciona
                       verificaLoteAddLote(quantidade,loteEscolhido,tipoMaterial);
                       // Se a condição for falsa então executa consertar isso
                       do{
                       printf("Você quer adcionar outro produto:\n");
                       scanf("%s",strUsuario);
                       }while( strncmp(strUsuario,"nao",3) || strncmp(strUsuario,"sim",3) );
                            if(strncmp(strUsuario,"nao",3))
                                break;
                    }
                break;
            case 5:
                inicializandoVetorLotes();
                break;
            case 6:
                system("cls");
                break;
            case 7:
                printf("Você selecionou a opção de saída do programa obrigado!");
        }
    }
}
