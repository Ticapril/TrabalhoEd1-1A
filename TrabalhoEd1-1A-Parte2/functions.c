#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

#include "functions.h"
//minhas funções
    int  mostrandoValorPorLote(char strProduto[10]){
        for(register int i = 0; i < TOTALLOTES; i++){
                if(!(strncmp(strProduto,"cimento",7)))
                    printf("Quantidade cimento lote[%d] =  %d\n",i, lote[i].cimento);
                if(!(strncmp(strProduto,"areia",5)))
                    printf("Quantidade areia   lote[%d] =  %d\n",i, lote[i].areia);
                if(!(strncmp(strProduto,"cal",3)))
                    printf("Quantidade cal     lote[%d] =  %d\n",i, lote[i].cal);
                if(!(strncmp(strProduto,"tubos",5)))
                    printf("Quantidade tubos   lote[%d] =  %d\n",i, lote[i].tubos);
                if(!(strncmp(strProduto,"saibro",6)))
                    printf("Quantidade saibro  lote[%d] =  %d\n",i, lote[i].saibro);
        }
        return 1;
    }
    void  listarQuantidadeTotalMaterialLote(void){
        auto int totalMaterialCimento = 0,totalMaterialAreia = 0,totalMaterialCal = 0,totalMaterialTubos = 0,totalMaterialSaibro = 0;
        for(register int i = 0; i < TOTALLOTES; i++){
            totalMaterialCimento += lote[i].cimento;
            totalMaterialAreia += lote[i].areia;
            totalMaterialCal += lote[i].cal;
            totalMaterialTubos += lote[i].tubos;
            totalMaterialSaibro += lote[i].saibro;
        }
        printf("A quantidade total de Cimento: %d\n", totalMaterialCimento);
        printf("A quantidade total de Areia: %d\n", totalMaterialAreia);
        printf("A quantidade total de Cal: %d\n", totalMaterialCal);
        printf("A quantidade total de Tubos: %d\n", totalMaterialTubos);
        printf("A quantidade total de Saibro: %d\n", totalMaterialSaibro);
    }
    void  inicializandoVetorLotes(void){
     //Inicializando os valores das variaveis de cada lote em 0
        for(register int i = 0; i < TOTALLOTES; i++){
            lote[i].cimento = 0;
            lote[i].areia = 0;
            lote[i].cal = 0;
            lote[i].tubos = 0;
            lote[i].saibro = 0;
        }
    }
    int   ComparaStrings(char strCalculo[10]){
            //declaro as variaveis comparativas
            char str1[8] = "cimento" ,str2[6] = "areia", str3[4] = "cal", str4[6] = "tubos", str5[6] = "saibro";
            int resultadoComparacaoCimento = strncmp(str1,strCalculo,7);
            int resultadoComparacaoAreia = strncmp(str2,strCalculo,5);
            int resultadoComparacaoCal = strncmp(str3,strCalculo,3);
            int resultadoComparacaoTubos = strncmp(str4,strCalculo,5);
            int resultadoComparacaoSaibro = strncmp(str5,strCalculo,6);

            //calculos para verificar se o usuário digitou o valor correto
            if(resultadoComparacaoCimento == 0)
                 return resultadoComparacaoCimento;
            if(resultadoComparacaoAreia == 0)
                return resultadoComparacaoAreia;
            if(resultadoComparacaoCal == 0)
                return resultadoComparacaoCal;
            if(resultadoComparacaoTubos == 0)
                return resultadoComparacaoTubos;
            if(resultadoComparacaoSaibro == 0)
                return resultadoComparacaoSaibro;
            else return 0;
    }
    void  menuPrograma(void){
         //menu da aplicação com as operações possíveis!
             printf("Digite [1] para listar a quantidade total em cada depósito\n");
             printf("Digite [2] para indicar um material e obter a a lista de quantidades desse material por lote\n");
             printf("Digite [3] para retirar um dado material ou todo o material de um dado lote.\n");
             printf("Digite [4] para Fornecer uma quantidade de material e obter o numero de lotes disponíveis,e entrar com o lote a ser inserido\n");
             printf("Digite [5] para inicializar os lotes\n");
             printf("Digite [6] para limpar a tela\n");
             printf("Digite [7] para sair do programa.\n");
    }
    void  listarMaterialPorLote(void){
        char tipoMaterial[10];
              printf("Digite o material que você deseja:");
              scanf("%s",tipoMaterial);
            for(register int i = 0; i < TOTALLOTES; i++){
                int verificacao = ComparaStrings(tipoMaterial);
                                                    if(verificacao == 0 && !(strncmp(tipoMaterial,"cimento",7)))
                                                        printf("lote:[%d] produto: Cimento = %d\n",i,lote[i].cimento);
                                                    else if(verificacao == 0 && !(strncmp(tipoMaterial,"areia",5)))
                                                        printf("lote:[%d] produto: Areia = %d\n",i,lote[i].areia);
                                                    else if(verificacao == 0 && !(strncmp(tipoMaterial,"cal",3)))
                                                        printf("lote:[%d] produto: Cal = %d\n",i,lote[i].cal);
                                                    else if(verificacao == 0 && !(strncmp(tipoMaterial,"tubos",5)))
                                                        printf("lote:[%d] produto: Tubos = %d\n",i,lote[i].tubos);
                                                    else if(verificacao == 0 && !(strncmp(tipoMaterial,"saibro",6)))
                                                        printf("lote:[%d] produto: Saibro = %d\n",i,lote[i].saibro);
                                                    else{
                                                        printf("Digitou o produto errado!\n");
                                                        break;
                                                    }
          }
    }
    int   RetiraMaterialLote(char tipoMaterial[10]){
        int valorLote = 0,quantidadeMaterial = 0;
                        for(register int i = 0; i < TOTALLOTES; i++){
                            int resultadoFinal = ComparaStrings(tipoMaterial), quantidadeFinal = 0;

                        if(resultadoFinal == 0 && valorLote == i){
                                if(lote[valorLote].cimento == 0 || ((lote[valorLote].cimento - quantidadeMaterial) < 0)){
                                    printf("É impossivel retirar o valor solicitado!\n");
                                    break;
                                }
                                quantidadeFinal =  lote[i].cimento - quantidadeMaterial;
                                printf("o valor após a retirada foi de %d\n", quantidadeFinal);
                        }
                        if(resultadoFinal == 0 && valorLote == i){
                                if(lote[valorLote].areia == 0 || ((lote[valorLote].areia - quantidadeMaterial) < 0)){
                                    printf("É impossivel retirar o valor solicitado!\n");
                                    break;
                                }
                            quantidadeFinal =  lote[i].areia - quantidadeMaterial;
                            printf("o valor após a retirada foi de %d\n", quantidadeFinal);
                        }
                        if(resultadoFinal == 0 && valorLote == i){
                            if(lote[valorLote].cal == 0 || ((lote[valorLote].cal - quantidadeMaterial) < 0)){
                                    printf("É impossivel retirar o valor solicitado!\n");
                                    break;
                            }
                             quantidadeFinal =  lote[i].cal - quantidadeMaterial;
                             printf("o valor após a retirada foi de %d\n", quantidadeFinal);
                        }
                        if(resultadoFinal == 0 && valorLote == i){
                            if(lote[valorLote].tubos == 0 || ((lote[valorLote].tubos - quantidadeMaterial) < 0)){
                                    printf("É impossivel retirar o valor solicitado!\n");
                                    break;
                            }
                             quantidadeFinal =  lote[i].tubos - quantidadeMaterial;
                             printf("o valor após a retirada foi de %d\n", quantidadeFinal);
                        }
                        if(resultadoFinal == 0 && valorLote == i){
                            if(lote[valorLote].saibro == 0 || ((lote[valorLote].saibro - quantidadeMaterial) < 0)){
                                    printf("É impossivel retirar o valor solicitado!\n");
                                    break;
                            }
                             quantidadeFinal =  lote[i].saibro - quantidadeMaterial;
                             printf("o valor após a retirada foi de %d\n", quantidadeFinal);
                        }
                      }
                      return 1;
                }
    int   verificaLoteAddLote(int qtd, int loteEsc,char tipoProd[10]){
        char tipoMaterial[10];
        int quantidade;
                             //declaro as variaveis comparativas
                                int usuarioDigitouCerto = ComparaStrings(tipoMaterial);
                                int somaTotalToneis = 0, somaTotalTubos = 0;
                                int somaProvavelToneis = 0,somaProvavelTubos = 0;
                                somaTotalToneis += lote[loteEsc].cimento + lote[loteEsc].areia + lote[loteEsc].cal + lote[loteEsc].saibro;
                                somaTotalTubos += lote[loteEsc].tubos;
                                somaProvavelToneis = quantidade + somaTotalToneis;

                                if(usuarioDigitouCerto == 0 && somaProvavelToneis <= 20 && !(strncmp(tipoMaterial,"cimento", 7)))
                                     return lote[loteEsc].cimento += quantidade;
                                else if(usuarioDigitouCerto == 0 && somaProvavelToneis <= 20 && !(strncmp(tipoMaterial,"areia", 5)))
                                        return lote[loteEsc].areia += quantidade;
                                else if(usuarioDigitouCerto == 0 && somaProvavelToneis <= 20 && !(strncmp(tipoMaterial,"cal", 3)))
                                        return lote[loteEsc].cal += quantidade;
                                else if(usuarioDigitouCerto == 0 && somaProvavelTubos <= 100 && !(strncmp(tipoMaterial,"tubos", 5)))
                                         return lote[loteEsc].tubos += quantidade;
                                else if(usuarioDigitouCerto == 0 && somaTotalToneis <= 20 && !(strncmp(tipoMaterial,"saibro", 6)))
                                         return lote[loteEsc].saibro += quantidade;
                                else {
                                    printf("Não é possivel adicionar produtos no lote [%d]\n",loteEsc);
                                    return 0;
                                }
}
