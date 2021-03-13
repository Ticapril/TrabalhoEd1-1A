#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(void){
    //settando a linguagem padrão do programa!
    setlocale(LC_ALL, "Portuguese");
    //sempre inicialize suas variaveis, variáveis globais do sistema isso é uma má prática;
    int comandoUsuario = 0;
    int numeroCidades = 0;
    int distanciaCidade = 0;
    int numeroRotas = 0;
    int matrizCidades[5][5];
    int rotas[10];
         while(comandoUsuario != 5){
                    //menu principal da aplicação
                        printf("Digite a tecla [1] para especificar o numero de cidades:\n");
                        printf("Digite a tecla [2] para definir a distancia:\n");
                        printf("Digite a tecla [3] para especificar uma rota:\n");
                        printf("Digite a tecla [4] para limpar a tela:\n");
                        printf("Digite a tecla [5] para sair:\n");

                    //pedindo e lendo a opção do usuário
                        do{
                        printf("Digite o comando do usuário:\n");
                        scanf("%3d",&comandoUsuario);
                        } while(comandoUsuario <= 0 && comandoUsuario > 5);
                 //escolha caso para a opção digitada
                 switch(comandoUsuario){
                    case 1:
                            printf("Você digitou a oção de especificar no número de cidades!\n");
                            do{
                                printf("Digite o numero de cidades?");
                                scanf("%3d", &numeroCidades);
                            }while(numeroCidades <= 0 || numeroCidades > 5);
                            //atribuindo as posições da matriz o valor 9999
                            for(register int i = 0; i < numeroCidades; i++){
                                for(register int j = 0; j < numeroCidades; j++){
                                    matrizCidades[i][j] = 9999;
                                }
                            }
                        break;
                    case 2:
                            printf("Você escolheu a opção de Registro de distâncias das cidades criadas por você!\n");
                            // perguntando ao usuário a distancia de cada cidade
                            for(register int i = 0; i < numeroCidades; i++){
                                for(register int j = 0; j < numeroCidades; j++){
                                    if(matrizCidades[i][j] == 9999){
                                        printf("Digite quantos kilometros a cidade tem?\n");
                                        scanf("%3d", &distanciaCidade);
                                        matrizCidades[i][j] = distanciaCidade;
                                        if(i != j){
                                            matrizCidades[j][i] = matrizCidades[i][j];
                                        }
                                    }
                                }
                            }
                            //printando a distancia de cada cidade
                            for(register int i = 0; i < numeroCidades; i++){
                                for(register int j = 0; j < numeroCidades; j++){
                                    printf("%3d ",matrizCidades[i][j]);
                                }
                            printf("\n");
                        }
                        break;
                    case 3:
                         //perguntando ao usuário o numero de rotas e armazenando na sua correspondente variavel!
                          do{
                             printf("Digite o numero de rotas?");
                             scanf("%3d", &numeroRotas);
                          }while(numeroRotas <= 0);
                          //preenchendo o vetor rotas[numeroRotas]
                          for(register int i = 0; i < numeroRotas; i++){
                            printf("A[0]B[1]C[2]D[3]E[4]\n");
                            printf("Digite a cidade que voce deseja?\n");
                            scanf("%3d", &rotas[i]);
                          }
                          for(register int i = 0; i < numeroCidades - 1; i++){
                            for(register int j = 0; j < numeroCidades; j++){
                                 if(matrizCidades[rotas[i]][rotas[i + 1]] == 0){
                                    printf("Não há conexão entre essas rotas. Rota inválida!\n");
                                    break;
                                 }else if(rotas[i] == i && rotas[i + 1] == j){
                                    printf("%3d\n", matrizCidades[i][i + 1]);
                                 }
                            }
                          }
                          break;
                    case 4:
                          system("cls");
                          break;

                    case 5:
                          printf("Voce escolheu a opcao para sair do programa!\n");

                }
            }

}
