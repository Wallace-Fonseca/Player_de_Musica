#include<stdio.h>
#include<stdlib.h>

int menu(); //Função de menu das opções
int inserir(); //Função que vai inserir novos dados no playerlist no inicio
int mostrar(); //Função para imprimir na tela todos os dados da estrutura playerlist

struct playerlist { //Estrutura de armazenamento de dados Heterogeneo
    char musica[30];
    char artista[30];
    float duracao;
    struct playerlist *proximo;
} *Head;

int main()
{
    int opcao = NULL; // Opções do menu.
    Head = NULL ;
    do
    {
        printf("-----------------------------------------------------");
        printf("\n\n*** PlayerList ***\n\n");
        printf("\n1 - Inserir uma música no inicio da Playlist. \n\n");
        printf("2 - Mostrar a Playlist. \n\n");
        printf("3 - Fechar o Programa. \n\n");
        printf("\nPor favor informe sua opção: ");
        scanf( "%d" , &opcao);
        
        system("clear"); //Como estou utilizando o VS Code e o Linux Mint, está é a forma de limpar a tela.
        switch (opcao)
        {
            case 1:
            inserir();
            break;

            case 2:
            mostrar();
            break;

            case 3:
            return 0;
            break;
            default :
            printf("Opção inválida! Tente novamente. \n");
        }
    }
    while (opcao);
}

int menu() {
    int opcao;
    system("clear"); //Como estou utilizando o VS Code e o Linux Mint, está é a forma de limpar a tela.
    printf("1 - Inserir uma música no inicio da Playlist.\n");
    printf("2 - Mostrar a Playlist. \n");
    printf("3 - Fechar o Programa. \n");
    printf("Digite sua escolha: ");
    scanf( "%d" , &opcao);
    system("clear"); //Como estou utilizando o VS Code e o Linux Mint, está é a forma de limpar a tela.
    return opcao;
}

int inserir() {
    struct playerlist *Novo_Elemento;
    Novo_Elemento = ( struct playerlist*) malloc( sizeof(struct playerlist)); // Adicionando espaço na estutura
    printf("\nInforme o nome da Música: ");
    scanf("%s" , Novo_Elemento->musica); //Add novo elemento no dado música
    printf("\nInforme o nome do Artista: ");
    scanf("%s" , Novo_Elemento->artista); //Add novo elemento no dado artista
    printf("\nInforme a duraçao da Música: ");
    scanf("%f" , &Novo_Elemento->duracao); //add novo elemento no dado duração
    system("clear"); //Como estou utilizando o VS Code e o Linux Mint, está é a forma de limpar a tela.
    
    if (Head == NULL ) { //Se Head for nulo o programa irá colocar os dados na primeira posição que é o Head.
        Head = Novo_Elemento;
        Head->proximo = NULL ;
    }
    else {//Ira mover o Head para a proxima e ira adinicionar um novo Head
        Novo_Elemento->proximo = Head;
        Head = Novo_Elemento;
    }
}

int mostrar() { //Imprime os valores na tela.
    struct playerlist *Elemento_Varredura; //Elemento criado para percorrer as variaveis
    Elemento_Varredura = (struct playerlist*)malloc(sizeof (struct playerlist));
    Elemento_Varredura = Head;
    if (Elemento_Varredura == NULL ) { //Caso o Elemento Varredura percorra as variaveis e não encontre nada.
        printf("\nSua Playerlist está vazia!");
        return 0;
    }
    while (Elemento_Varredura != NULL ) { //Caso o Elemento Varredura esteja com dados em sua variavel, ele irá mostrar esses dados na tela.
        while (Elemento_Varredura != NULL ) {
        printf("Música: %s\n", Elemento_Varredura->musica);
        printf("\nArtista: %s\n", Elemento_Varredura->artista);
        printf("\nDuração: %.2f\n", Elemento_Varredura->duracao);
        printf("-----------------------------------------------------\n");
        Elemento_Varredura = Elemento_Varredura->proximo;
        }
    }
    printf("\n");
    return 0;
}