#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define TOTAL_PALAVRAS 50


// LISTA DAS PALAVRAS PARA SORTEAR(EU TIVE A IDEIA DE SEPARAR UM NIVEL DE DIFICULDADE)
const char *palavras_para_sortear[TOTAL_PALAVRAS] = {
    // Nível fácil (30 palavras)
    "balas", "casas", "livro", "porta", "mesas", "prato", "sonho", "molas", "fruta", "clube",
    "peixe", "banco", "muros", "luzes", "zebra", "mares", "festa", "vilas", "olhos", "pedra",
    "folha", "piano", "risos", "gelos", "merda", "casas", "lesma", "carro", "salto",

    // Nível médio (15 palavras)
    "trens", "nuvem", "berco", "trava", "janta", "lanca", "grãos", "pinto", "carro", "falso",
    "barco", "faixa", "perto", "sinal", "tigre",

    // Nível difícil (5 palavras)
    "armas", "xaxim", "vinho", "espia", "pneus"
};

void sortear_palavras(const char *palavras_para_sortear[], char palavra_sorteio[]){
int sorteio = rand()%TOTAL_PALAVRAS;
strcpy(palavra_sorteio, palavras_para_sortear[sorteio]);

}


//FUNCAO QUE RETORNA UM VETOR PARA VERIFICAR AS LETRAS CERTAS QUE O USUARIO DIGITOU (RETORNA 0 SE A LETRA FOR ERRADA E 1 SE FOR CERTA)
int letras_certas(char *palavra_sorteada, char *palavra_jogador, int *vetor){
for(int i = 0; i < strlen(palavra_sorteada); i++){
    if(palavra_jogador[i] == palavra_sorteada[i]){
        vetor[i] = 1;
    }
    else{
        vetor[i]= 0;
    }
}
return vetor;
}

//FUNCAO PARA VERIFICAR SE A LETRA DA PALAVRA DO JOGADOR ESTA INSERIDA NA PALAVRA NORMAL MENOS NA MESMA POSICAO
void letras_quase_certas(char *x, char *y, int *vetor, int *verificadas){

memset(verificadas, 0, strlen(y) * sizeof(int));

for(int i = 0; i < strlen(y); i++){
    if(vetor[i] == 0){
       for(int j = 0; j < strlen(y); j++){
           if(x[i] == y[j] && i != j && verificadas[j] == 0){
               printf("\nA letra '%c' esta na posicao errada.", x[i]);
               verificadas[j] = 1;
               break;
          }
        }
    }
}
}
//FUNÇÃO PARA SALVAR STRINGS QUE JA FORAM USADAS NO JOGO
void letras_ja_usadas(char *x, char *saida){
for(int i = 0; i < strlen(x); i++){
    if(strchr(saida, x[i]) == NULL){
        int len = strlen(saida);
        saida[len] = x[i];
        saida[len + 1 ] = '\0';
    }

    }
}
//EXIBIR NOME DO JOGO
void exibir_nome_jogo() {
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*    _______ ______ _____  __  __  ____         *\n");
    printf("*   |__   __|  ____|  __ \\|  \\/  |/ __ \\        *\n");
    printf("*      | |  | |__  | |__) | \\  / | |  | |       *\n");
    printf("*      | |  |  __| |  _  /| |\\/| | |  | |       *\n");
    printf("*      | |  | |____| | \\ \\| |  | | |__| |       *\n");
    printf("*      |_|  |______|_|  \\_\\_|  |_|\\____/        *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n\n");
    printf("Pressione Enter para começar...\n");
    fflush(stdin);
    getchar();  // Espera o jogador pressionar Enter
}



// Função para exibir as regras do jogo e esperar o jogador pressionar Enter
void exibir_regras_jogo() {
    printf("\nRegras do Jogo Termo:\n");
    printf("1. Você deve adivinhar a palavra correta em 6 tentativas.\n");
    printf("2. A cada tentativa, você deve digitar uma palavra de 5 letras.\n");
    printf("3. O jogo indicará quais letras estão na posição correta e quais letras existem na palavra, mas estão na posição errada.\n");
    printf("4. As letras corretas na posição correta serão exibidas.\n");
    printf("5. Você vence o jogo ao acertar a palavra correta.\n");
    printf("Pressione Enter para iniciar o jogo...\n");
    fflush(stdin);
    getchar();  // Espera o jogador pressionar Enter
}

int main()
{
//DECLARANDO VARIAVEIS
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int entrada[6];
    int vetor[5] = {0, 0, 0, 0, 0};
    int verificadas[5] = {0, 0, 0, 0, 0};
    char palavra_sorteada[6];
    sortear_palavras(palavras_para_sortear, palavra_sorteada);
    char palavra_jogador[6];
    int i = 1;
    int escolha_do_usuario;
    char saida[50] = "";
//EXIBINDO MENUS
    exibir_nome_jogo();

    exibir_regras_jogo();
    int opcao;

    do {
        // Exibindo o menu
        printf("===================================\n");
        printf("           MENU DO TERMO           \n");
        printf("===================================\n");
        printf("1 - Modo Normal\n");
        printf("2 - Modo Dueto\n");
        printf("3 - Modo Quarteto\n");
        printf("9 - Sair\n");
        printf("===================================\n");
        do {
            printf("Escolha uma opcao valida: ");
            scanf("%d", &opcao);

            // Limpar o buffer para evitar loops infinitos caso a entrada seja inválida
            while(getchar() != '\n');

        } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 9);


        // Processando a escolha do usuário
        switch(opcao) {
            case 1:
                printf("Voce escolheu o Modo Normal!\n");
                do{
                    if(i != 1){
                        printf("\nLetras ja usadas:");
                        for(int k = 0; k < strlen(saida); k++){
                            printf("'%c'  ", saida[k]);
                            }
                        }
                    fflush(stdin);
                    printf("\nDigite sua palavra: ");
                    scanf(" %5s", palavra_jogador);
                    letras_certas(palavra_sorteada, palavra_jogador, vetor);
                    for(int j = 0; j < strlen(palavra_sorteada); j++){
                        if(vetor[j] == 0){
                            printf("_");
                        }
                        else{
                            printf("%c", palavra_sorteada[j]);
                            }

                        }
                    letras_ja_usadas(palavra_jogador, saida);
                    letras_quase_certas(palavra_sorteada, palavra_jogador, vetor, verificadas);
                    if(strcmp(palavra_sorteada, palavra_jogador)== 0){
                        printf("\nParabens, voce acertou a palavra!!\n");
                        break;
                    }
                    printf("\nVoce tem mais %d tentativas", 6 -i);
                    printf("\n\n");

                    i++;
                        }while(i < 7);
                if(strcmp(palavra_sorteada, palavra_jogador)!=0){
                    printf("\nvoce nao acertou a palavra.\nA palavra era: %s", palavra_sorteada);
    }
                break;
            case 2:
                printf("Voce escolheu o Modo Dueto!\n");
                // Aqui, você pode adicionar o código específico para iniciar o modo dueto
                break;
            case 3:
                printf("Voce escolheu o Modo Quarteto!\n");
                // Aqui, você pode adicionar o código específico para iniciar o modo quarteto
                break;
            case 9:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 9);



    return 0;
}
