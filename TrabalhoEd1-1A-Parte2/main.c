//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#include "functions.h"

void main(void){
    //configurando a lingua padr�o do programa
    setlocale(LC_ALL, "Portuguese");
    //variaveis globais da fun��o main 8 variaveis que precisam ser declaradas localmente
     int comando = 0; // comando digitado pelo usu�rio

    //Aplica��o pr�pria!
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
                    printf("Digite o material que voc� deseja:");
                    scanf("%s",tipoMaterial);
                    //mostro a lista do produto especificado em cada lote e seus respectivos valores
                    mostrandoValorPorLote(tipoMaterial);
                    //pergunto a quantidade para o usu�rio
                    printf("Digite a quantidade que voc� deseja retirar do lote de %s: ", tipoMaterial);
                    scanf("%d",&quantidadeMaterial);
                    //pergunto em qual lote ele quer retirar o material especificado
                    printf("Em qual lote voc� deseja retirar o material:");
                    scanf("%d", &valorLote);
                    //chamo a fun��o para executar todo procedimento especificado pelo usu�rio
                    RetiraMaterialLote(tipoMaterial);
                break;
            case 4:
                for(register int i = 0; i < TOTALLOTES; i++){
                        int loteEscolhido = 0;
                        int usuarioDigitouCerto;
                        char strUsuario[4];
                       //fornece o tipo de produto
                       printf("Digite o tipo de produto que voc� deseja?\n");
                       scanf("%s", tipoMaterial);
                       //verifico a digita��o

                       //chama uma fun��o que mostra os valores de cada lote com o produto especificado
                       mostrandoValorPorLote(tipoMaterial);

                       //pergunta a quantidade que o usu�rio deseja armazenar!
                       printf("Digite a quantidade dele?\n");
                       scanf("%d", &quantidade);

                       //pergunta em qual lote o usu�rio deseja armazenar!
                       printf("Digite que lote voc� quer armazenar?\n");
                       scanf("%d", &loteEscolhido);
                       //chamo a fun��o que verifica se tem espa�o e ao mesmo tempo adiciona
                       verificaLoteAddLote(quantidade,loteEscolhido,tipoMaterial);
                       // Se a condi��o for falsa ent�o executa consertar isso
                       do{
                       printf("Voc� quer adcionar outro produto:\n");
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
                printf("Voc� selecionou a op��o de sa�da do programa obrigado!");
        }
    }
}
