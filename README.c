#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define TOTAL_PALAVRAS 1000


// LISTA DAS PALAVRAS PARA SORTEAR(EU TIVE A IDEIA DE SEPARAR UM NIVEL DE DIFICULDADE)
const char *palavras_para_sortear[TOTAL_PALAVRAS] = {
    "sagaz", "amago", "negro", "termo", "exito", "mexer", "nobre", "senso", "afeto", "algoz",
    "etica", "plena", "fazer", "tenue", "assim", "mutua", "vigor", "sobre", "aquem", "sutil",
    "secao", "porem", "poder", "fosse", "sanar", "ideia", "cerne", "audaz", "moral", "inato",
    "desde", "muito", "justo", "quica", "honra", "sonho", "torpe", "razao", "amigo", "icone",
    "etnia", "futil", "egide", "anexo", "tange", "dengo", "haver", "lapso", "expor", "entao",
    "tempo", "seara", "mutuo", "boçal", "habil", "casal", "saber", "avido", "pesar", "ardil",
    "graça", "dizer", "obice", "causa", "dever", "xibiu", "sendo", "genro", "tenaz", "coser",
    "paria", "estar", "posse", "brado", "crivo", "ainda", "prole", "comum", "temor", "apice",
    "corja", "animo", "detem", "pauta", "ceder", "assaz", "ansia", "fugaz", "culto", "censo",
    "digno", "mundo", "atroz", "forte", "gleba", "vicio", "vulgo", "cozer", "criar", "valha",
    "mesmo", "saude", "reves", "denso", "nenem", "pudor", "dogma", "jeito", "todos", "regra",
    "louco", "atras", "ordem", "merce", "homem", "feliz", "pedir", "impor", "banal", "round",
    "clava", "limbo", "usura", "coisa", "juizo", "sabio", "apraz", "forma", "servo", "prosa",
    "tenro", "falar", "desse", "pifio", "presa", "ajuda", "certo", "posso", "cunho", "ontem",
    "viril", "vendo", "legal", "devir", "heroi", "manso", "falso", "meiga", "valor", "reaça",
    "facil", "visar", "magoa", "serio", "ebrio", "acaso", "fluir", "guisa", "afago", "linda",
    "plato", "lugar", "impio", "temer", "garbo", "praxe", "obvio", "cisma", "matiz", "burro",
    "bruma", "uniao", "pleno", "crise", "exodo", "fluxo", "havia", "venia", "senil", "tedio",
    "ritmo", "morte", "enfim", "levar", "tomar", "olhar", "visao", "alibi", "casta", "brega",
    "genio", "prumo", "parvo", "vital", "bravo", "favor", "reles", "cabal", "falta", "pulha",
    "ouvir", "vivaz", "reter", "parco", "tecer", "calma", "valia", "sabia", "outro", "ameno",
    "laico", "grato", "viver", "tendo", "terra", "possa", "nocao", "carma", "forca", "passo",
    "unico", "achar", "nicho", "ranco", "pobre", "noite", "facam", "rever", "prime", "rogar",
    "fardo", "farsa", "fator", "obito", "ativo", "selar", "coeso", "dubio", "epico", "anelo",
    "citar", "nossa", "sinto", "papel", "leigo", "cisao", "sesta", "claro", "sonso", "ciume",
    "lider", "adiar", "cesta", "haste", "deter", "velho", "tende", "gente", "atuar", "humor",
    "revel", "sulco", "ideal", "vemos", "exato", "arduo", "ficar", "ponto", "igual", "vazio",
    "amplo", "fonte", "marco", "labor", "feixe", "lavra", "terno", "remir", "debil", "hiato",
    "senao", "capaz", "cauda", "gesto", "otica", "tanto", "ambos", "varao", "imune", "inata",
    "relva", "jovem", "vacuo", "tenra", "toada", "sonsa", "ciclo", "apoio", "cocar", "cacar",
    "raiva", "vimos", "algum", "pouco", "serie", "xeque", "chuva", "farao", "horda", "leito",
    "fusão", "advem", "entre", "feito", "sente", "probo", "coesa", "doido", "minha", "frase",
    "carro", "cruel", "anuir", "trama", "torco", "verso", "brisa", "impar", "rigor", "botar",
    "chata", "massa", "blase", "lazer", "prece", "maior", "dorso", "pegar", "sorte", "signo",
    "seita", "mocao", "fauna", "covil", "preso", "credo", "furor", "casto", "morar", "livro",
    "flora", "vetor", "adeus", "docil", "peste", "liame", "ambas", "plano", "comer", "faina",
    "senda", "houve", "ocaso", "nunca", "pecha", "saiba", "arido", "setor", "praia", "alias",
    "manha", "virus", "peixe", "ardor", "meses", "agora", "mudar", "visse", "salvo", "beata",
    "aceso", "antro", "rezar", "vulto", "parte", "vasto", "breve", "pajem", "saida", "morro",
    "junto", "banzo", "risco", "campo", "otimo", "avaro", "reger", "prado", "sinal", "grupo",
    "aureo", "anais", "birra", "segue", "andar", "lenda", "antes", "serao", "motim", "opcao",
    "acima", "chulo", "estao", "aurea", "fugir", "leite", "nacao", "conta", "rapaz", "atomo",
    "brava", "treta", "vilao", "oxala", "fruir", "verbo", "parar", "idolo", "texto", "fitar",
    "indio", "tirar", "jazia", "tenso", "prazo", "reino", "festa", "puxar", "gerir", "alude",
    "traga", "norma", "tosco", "exame", "epoca", "filho", "prova", "atrio", "bando", "malta",
    "turba", "corpo", "psico", "arcar", "ancia", "preto", "cheio", "sinha", "aonde", "acesa",
    "aviao", "voraz", "manha", "fatal", "sarca", "fatos", "quase", "copia", "praga", "venal",
    "certa", "ligar", "quota", "logro", "nosso", "magia", "dessa", "fixar", "apego", "nivel",
    "oasis", "afora", "coito", "pompa", "sumir", "soldo", "nodoa", "mente", "alado", "messe",
    "caixa", "tocar", "longe", "perda", "jirau", "bonus", "lidar", "parca", "tinha", "livre",
    "verve", "fraco", "lindo", "apelo", "sexta", "solto", "vezes", "glosa", "firme", "grave",
    "virao", "porta", "opaco", "bater", "turva", "faixa", "sabia", "astro", "salve", "exijo",
    "doido", "trupe", "fenda", "irmao", "navio", "canon", "pardo", "grata", "abriu", "elite",
    "parva", "supra", "atual", "autor", "alcar", "besta", "deixa", "viria", "pique", "junco",
    "bicho", "cioso", "ficha", "curso", "etico", "douto", "macio", "reses", "pagao", "abuso",
    "calda", "bioma", "cousa", "posto", "desta", "judeu", "radio", "locus", "caber", "menos",
    "verba", "retem", "video", "culpa", "supor", "chato", "prive", "aluno", "zelar", "extra",
    "molho", "super", "drops", "torso", "gosto", "calao", "vosso", "baixo", "suave", "light",
    "advir", "agudo", "combo", "vinha", "julia", "igneo", "asilo", "lapis", "orfao", "ruina",
    "facho", "turma", "podio", "sitio", "traço", "turvo", "peito", "estio", "pisar", "passa",
    "piada", "acoes", "ereto", "pilar", "chama", "louca", "brabo", "amena", "finda", "mosto",
    "avida", "refem", "mesma", "meigo", "forem", "local", "acola", "rouca", "museu", "facto",
    "pareo", "metie", "surja", "autos", "poeta", "tento", "cutis", "rumor", "optar", "paira",
    "lasso", "medir", "teste", "poema", "geral", "coral", "drama", "cocho", "folga", "aviso",
    "busca", "clima", "feudo", "hobby", "urgia", "boato", "clean", "idoso", "rubro", "tetra",
    "cetro", "pacto", "calmo", "feroz", "ateia", "tacha", "movel", "amiga", "monge", "ponha",
    "crime", "licao", "golpe", "acude", "daqui", "ebano", "carta", "ecoar", "cacho", "plumo",
    "verde", "riste", "monte", "vigia", "aroma", "corso", "casar", "saldo", "falha", "fazia",
    "briga", "conto", "artur", "vetar", "manga", "letal", "pasmo", "volta", "bença", "hoste",
    "itens", "tribo", "pedra", "rival", "escol", "grama", "forum", "penta", "troça", "tarde",
    "manga", "roupa", "swing", "chefe", "súcia", "unica", "venha", "civil", "sosia", "natal",
    "plebe", "fruto", "uteis", "plaga", "vento", "cover", "lesse", "amada", "sarau", "finjo",
    "cargo", "atimo", "macro", "nuvem", "ornar", "pinho", "virar", "orgão", "axila", "berro",
    "arado", "vazao", "areia", "stand", "magna", "farta", "tchau", "jogar", "jejum", "seixo",
    "fosso", "beijo", "catre", "tiver", "giria", "troca", "legua", "bruta", "traje", "nesse",
    "deste", "perto", "varoa", "inter", "midia", "assar", "perco", "bruto", "tiçao", "viram",
    "tutor", "renda", "trato", "guria", "todas", "gabar", "estro", "amado", "porte", "surto",
    "pomar", "close", "rural", "feita", "canso", "pedro", "arfar", "rocha", "nesta", "ambar",
    "tenha", "bazar", "silvo", "nessa", "vadio", "calor", "santo", "recem", "vedar", "depor",
    "fossa", "grota", "odiar", "irado", "pavor", "laudo", "vista", "cifra", "aviar", "negar",
    "etapa", "mamae", "canto", "xucro", "densa", "bucho", "clero", "logos", "verao", "visto",
    "ferpa", "bolsa", "marca", "regio", "minar", "cerca", "cinto", "vagar", "cenho", "cheia",
    "chula", "segar", "molde", "lesao", "inves", "salmo", "horto", "agape", "proto", "ruido",
    "coroa", "paiol", "burra", "urdir", "largo", "morfo", "sotao", "deram", "letra", "pasma",
    "velha", "simio", "danca", "final", "penso", "pugna", "folha", "esgar", "vasta", "ubere",
    "troco", "lesto", "narco", "fundo", "sofia", "jazer", "trago", "ceita", "podar", "ufano",
    "ardis", "quais", "mocho", "linha", "umido", "frota", "apear", "bulir", "ileso", "piche",
    "troco", "queda", "polis", "alamo", "preço", "neste", "peita", "resto", "civel", "audio",
    "manto", "matar", "folia", "redor", "monta", "cosmo", "misto", "seiva", "mover", "barro",
    "chaga", "labia", "bolso", "outra", "banto", "logia", "retro", "chave", "disso", "justa",
    "olhos", "limpo", "falsa", "album", "barao", "macho", "nacar", "campa", "lutar", "farol",
    "veloz", "bedel", "louro", "calvo", "gemer", "punha", "axial", "mimar", "porca", "venho",
    "arroz", "findo", "sabor", "vazia", "louca", "toque", "calca", "rente", "longo", "salva",
    "enjoo", "zumbi", "lucro", "viger", "coevo", "baixa", "nariz", "dados", "fazes", "lousa",
    "firma", "subir", "samba", "demao", "solta", "farto", "torna", "urgir", "forro", "ousar",
    "canil", "diabo", "sigla", "fugiu", "valer", "reler", "pagar", "gueto", "sexto", "pluma",
    "sabia", "bruxa", "xampu", "repor", "fatuo", "miope", "choca", "corar", "bugre", "vario",
    "cardo", "custo", "lento", "tumba", "hifen", "mania", "versa", "corte", "pular", "nesga",
    "penca", "modal", "racio", "sadio", "ferir", "voila", "socio", "sugar", "harem", "digna",
    "ceifa", "patio", "focar", "usual", "grelo", "casco", "casca", "areio", "tasco", "meiao"
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

//função para transformar letras maiusculas em minusculas
void letras_minusculas(char *x)
{
    for(int i=0; i<6; i++)
    {
        if(x[i]<'a' && x[i]!='\0' )
        {
            x[i]+=32;
        }

    }
}
int main()
{
//DECLARANDO VARIAVEIS
    srand(time(NULL));
    setlocale(LC_ALL, "");
    int entrada[6], escolha_do_usuario, i=1, x=1, y=1, w=1, z=1;
    char palavra_sorteada[6], palavra_sorteada_2[6], palavra_jogador[6], saida[50] = "", palavra_sorteada_3[6], palavra_sorteada_4[6];
//EXIBINDO MENUS
    exibir_nome_jogo();

    exibir_regras_jogo();
    system("cls");
    int opcao;

    do {
            int vetor[5] = {0, 0, 0, 0, 0}, vetor_2[5] = {0, 0, 0, 0, 0},vetor_3[5] ={0, 0, 0, 0, 0}, vetor_4[5] = {0, 0, 0, 0, 0},
             verificadas[5] = {0, 0, 0, 0, 0}, verificadas_2[5] = {0, 0, 0, 0, 0}, verificadas_3[5] = {0, 0, 0, 0, 0}, verificadas_4[5] = {0, 0, 0, 0, 0};
        // Exibindo o menu
        printf("\n===================================\n");
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
                sortear_palavras(palavras_para_sortear, palavra_sorteada);
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
                    letras_minusculas(palavra_jogador);
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
                    printf("\nvoce nao acertou a palavra.\nA palavra era: %s\n", palavra_sorteada);

    }
                printf("\nPressione enter para continuar");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 2:
                printf("Voce escolheu o Modo Dueto!\n");
                sortear_palavras(palavras_para_sortear, palavra_sorteada);
                do{
                sortear_palavras(palavras_para_sortear, palavra_sorteada_2);
                }while(palavra_sorteada==palavra_sorteada_2);
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
                    letras_minusculas(palavra_jogador);
                    letras_certas(palavra_sorteada, palavra_jogador, vetor);
                    letras_certas(palavra_sorteada_2, palavra_jogador, vetor_2);
                    for(int j = 0; j < strlen(palavra_sorteada); j++){
                        if(vetor[j] == 0){
                            printf("_");
                        }
                        else{
                            printf("%c", palavra_sorteada[j]);
                            }

                        }
                        printf("  |  ");
                        for( int l = 0; l < strlen(palavra_sorteada_2); l++){
                        if(vetor_2[l] == 0){
                            printf("_");
                        }
                        else{
                            printf("%c", palavra_sorteada_2[l]);
                            }

                        }
                    letras_ja_usadas(palavra_jogador, saida);
                    if(x==1){
                    printf("\n\n   PRIMEIRA PALAVRA\n");
                    letras_quase_certas(palavra_sorteada, palavra_jogador, vetor, verificadas);
                    if(strcmp(palavra_sorteada, palavra_jogador)== 0){
                        printf("\nParabens, voce acertou a primeira palavra!!\n");
                        x=0;
                    }
                    }
                    if(y==1){
                    printf("\n\n   SEGUNDA PALAVRA\n");
                    letras_quase_certas(palavra_sorteada_2, palavra_jogador, vetor_2, verificadas_2);
                    if(strcmp(palavra_sorteada_2, palavra_jogador)== 0){
                        printf("\nParabens, voce acertou a segunda palavra!!\n");
                        y=0;

                    }
                    }
                    if(x==0 && y==0){
                        break;

                    }
                    printf("\nVoce tem mais %d tentativas", 6 -i);
                    printf("\n\n");

                    i++;
                        }while(i < 7);
                if(x==1 || y==1){
                    printf("\nvoce nao acertou as duas palavras.\nAs palavras eram: %s  |  %s", palavra_sorteada, palavra_sorteada_2);
    }
                printf("\nPressione enter para continuar");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 3:
                printf("Voce escolheu o Modo Quarteto!\n");
                sortear_palavras(palavras_para_sortear, palavra_sorteada);
                do{
                sortear_palavras(palavras_para_sortear, palavra_sorteada_2);
                }while(palavra_sorteada==palavra_sorteada_2);
                do{
                sortear_palavras(palavras_para_sortear, palavra_sorteada_3);
                }while(palavra_sorteada_3==palavra_sorteada||palavra_sorteada_3==palavra_sorteada_2);
                do{
                sortear_palavras(palavras_para_sortear, palavra_sorteada_4);
                }while(palavra_sorteada_4==palavra_sorteada||palavra_sorteada_4==palavra_sorteada_2||palavra_sorteada_4==palavra_sorteada_3);
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
                    letras_minusculas(palavra_jogador);
                    letras_certas(palavra_sorteada, palavra_jogador, vetor);
                    letras_certas(palavra_sorteada_2, palavra_jogador, vetor_2);
                    letras_certas(palavra_sorteada_3, palavra_jogador, vetor_3);
                    letras_certas(palavra_sorteada_4, palavra_jogador, vetor_4);
                    for(int j = 0; j < strlen(palavra_sorteada); j++){
                        if(vetor[j] == 0){
                            printf("_");
                        }
                        else{
                            printf("%c", palavra_sorteada[j]);
                            }

                        }
                        printf("  |  ");
                        for( int l = 0; l < strlen(palavra_sorteada_2); l++){
                        if(vetor_2[l] == 0){
                            printf("_");
                        }
                        else{
                            printf("%c", palavra_sorteada_2[l]);
                            }

                        }
                        printf("  |  ");
                        for( int m = 0; m < strlen(palavra_sorteada_3); m++){
                        if(vetor_3[m] == 0){
                            printf("_");
                        }
                        else{
                            printf("%c", palavra_sorteada_3[m]);
                            }

                        }
                        printf("  |  ");
                        for( int n = 0; n < strlen(palavra_sorteada_4); n++){
                        if(vetor_4[n] == 0){
                            printf("_");
                        }
                        else{
                            printf("%c", palavra_sorteada_4[n]);
                            }

                        }
                    letras_ja_usadas(palavra_jogador, saida);
                    if(x==1){
                    printf("\n\n   PRIMEIRA PALAVRA\n");
                    letras_quase_certas(palavra_sorteada, palavra_jogador, vetor, verificadas);
                    if(strcmp(palavra_sorteada, palavra_jogador)== 0){
                        printf("\nParabens, voce acertou a primeira palavra!!\n");
                        x=0;
                    }
                    }
                    if(y==1){
                    printf("\n\n   SEGUNDA PALAVRA\n");
                    letras_quase_certas(palavra_sorteada_2, palavra_jogador, vetor_2, verificadas_2);
                    if(strcmp(palavra_sorteada_2, palavra_jogador)== 0){
                        printf("\nParabens, voce acertou a segunda palavra!!\n");
                        y=0;

                    }
                    }
                    if(w==1){
                    printf("\n\n   TERCEIRA PALAVRA\n");
                    letras_quase_certas(palavra_sorteada_3, palavra_jogador, vetor_3, verificadas_3);
                    if(strcmp(palavra_sorteada_3, palavra_jogador)== 0){
                        printf("\nParabens, voce acertou a primeira palavra!!\n");
                        W=0;
                    }
                    }if(Z==1){
                    printf("\n\n   QUARTA PALAVRA\n");
                    letras_quase_certas(palavra_sorteada_4, palavra_jogador, vetor_4, verificadas_4);
                    if(strcmp(palavra_sorteada_4, palavra_jogador)== 0){
                        printf("\nParabens, voce acertou a primeira palavra!!\n");
                        Z=0;
                    }
                    }
                    if(x==0 && y==0 && W==0 && Z==0){
                        break;

                    }
                    printf("\nVoce tem mais %d tentativas", 6 -i);
                    printf("\n\n");

                    i++;
                        }while(i < 7);
                if(x==1 || y==1 || W==1 || Z==1){
                    printf("\nvoce nao acertou as quatro palavras.\nAs palavras eram: %s  |  %s  |  %s  |  %s", palavra_sorteada, palavra_sorteada_2, palavra_sorteada_3, palavra_sorteada_4);
    }
                printf("\nPressione enter para continuar");
                fflush(stdin);
                getchar();
                system("cls");
                break;
            case 9:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        *saida=NULL;
        i=1;
        x=1;
        y=1;
        w=1;
        z=1;
        system("cls");

    } while(opcao != 9);




    return 0;
}
