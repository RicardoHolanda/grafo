#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int tamanho; //variável global para controlar o tamanho do grafo que será usada em várias funções
int matriz[100][100];
int teste;

int Menu(){
    setlocale(LC_ALL,"portuguese");
    system("cls"); //comando para limpar a tela
    printf("\n ====== MENU DE CONTROLE ======");
    printf("\n = 1: Inicializar a Matriz    =");
    printf("\n = 2: Imprimir a Matriz       =");
    printf("\n = 3: Inserir valor na Matriz =");
    printf("\n = 4: Percorrer a Matriz      =");
    printf("\n = 5: Identificar Menor       =");
    printf("\n = 6: Sair do programa        =");
    printf("\n ============================== ");
    printf("\n Digite a opção desejada: ");
    int resposta;
    scanf("%i",&resposta);
    return(resposta);
}

void LimparMatriz(){
    for(int linha =1; linha<=tamanho;linha++){ //
        for(int coluna=1;coluna<=tamanho;coluna++)
            matriz[linha][coluna] = 0;
    }
}

void ImprimirMatriz()
{
    printf("\n");
    for(int linha =1; linha<=tamanho;linha++){ //
        for(int coluna=1;coluna<=tamanho;coluna++){
            printf(" %i  ", matriz[linha][coluna]);
            if(coluna ==tamanho){
                printf("\n");
            }

        }
    }
    printf("\n");
    printf("\nPressione uma tecla para prosseguir...");
    getch();
}

void GravarValor(int A,int B,int C)
{
    matriz[A][B] = C;
    teste = B;
    printf("\n O valor %i foi gravado na posição[%i,%i] da Matriz.", C,A,B);
    printf("\n Pressione uma tecla para prosseguir...");
    getch();
}

int main()
{
    int resposta,vlr,lin,col;
    char confirma; //confirmar a sobreposição das arestas do grafo
    lin = -1;
    col = -1;
    do{
        resposta = Menu();
        if(resposta==1){//inicializar a matriz na memória limpando as arestas(valor zero)
            printf("\n Informe o tamanho do grafo: ");
            scanf("%i",&tamanho);
            LimparMatriz();
            printf("\nMatriz inicializada com sucesso! (Tamanho: %i)", tamanho);
            printf("\nPressione uma tecla para prosseguir...");
            getch(); //comando para aguardar o pressionamento de uma tecla (na biblioteca conio.h)

        }
        else if(resposta==2){//imprime a matriz
            ImprimirMatriz();
        }
        else if(resposta==3){//preenchendo a coluna
            do{

                if((lin==col)&(lin >0)){
                    printf("A linha e a coluna não podem ter o mesmo valor. Pressione algum botão para continuar...");
                    getch();
                    system("cls");
                }
                if(lin > tamanho){
                    printf("A linha informada está fora da matriz. Pressione algum botão para continuar...");
                    getch();
                    system("cls");
                }
                if(col > tamanho){
                     printf("A coluna informada está fora da matriz. Pressione algum botão para continuar...");
                    getch();
                    system("cls");
                }
                //fim da camada de regra de negócio


                printf("Informe a posição da linha: "); //pedindo os dados
                scanf("%i",&lin); //capturando o valore informado para a linha
                printf("Informe a posição da coluna: "); //pedindo os dados
                scanf("%i",&col); //capturando os valores informados
                if(matriz[lin][col]>0){
                    printf("\n A posição [%i][%i] já contem o valor %i! ",lin,col,matriz[lin][col]);
                    printf("\n Confirma a sobreposição? (S/N): ");
                    scanf("%s",&confirma);
                    if(confirma == 'N'| confirma == 'n')
                        break;
                }

            }while((lin == col)|(lin>tamanho)|(col>tamanho));
            do{
                if(confirma == 'N'| confirma == 'n')
                    break;
                printf("Informe um valor positivo para a Aresta: "); //pedindo os dados
                scanf("%i",&vlr);//capturando os valores informado para o peso
            }while(vlr <= 0);
            GravarValor(lin,col,vlr);
            lin = -1;
            col = -1;//limpamos os conteúdos das variáveis linha e coluna para a proxima rodada

        }

    } while(resposta!=6);



}
