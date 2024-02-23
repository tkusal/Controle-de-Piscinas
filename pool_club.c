//**************************
//File Encoding: ISO-8859-1 
//**************************

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

#define MAX_CAD 100
#define MAX_STR_CAD 51
#define MAX_CPF 12

void menu(void);
int gerarMatricula(void);
void cadastraUsuario(void);
void limpaStdin(void);
void entradaString(char *s, int tam);
void listarCadastros(void);
void listarAtletas(void);
void menuPiscina(void);
void listarPiscinas(void);
void buscarCadastro(void);
void editarCadastro(void);
void menuItemEdicao(void);
void excluirCadastro(void);

typedef struct {
    char nome[MAX_STR_CAD];
    char cpf[MAX_CPF];
    char endereco[MAX_STR_CAD];
    int idade;
    int atleta;
    int matricula;
}usuario;

usuario cliente[MAX_CAD];
int qtdCadastro = 0;
int indicadorCadEncontrado = -1;

int main () {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        menu();
        printf("        Escolha uma op��o: ");
        scanf("%d", &opcao);
        limpaStdin();

        switch(opcao) {
            case 1:
                system("cls");
                cadastraUsuario();
                break;
            case 2:
                system("cls");
                buscarCadastro();
                break;
            case 3:
                system("cls");
                editarCadastro();
                break;
            case 4:
                system("cls");
                listarCadastros();
                break;
            case 5:
                system("cls");
                listarPiscinas();
                break;
            case 6:
                system("cls");
                listarAtletas();
                break;
            case 7:
                system("cls");
                excluirCadastro();
                break;
            case 8:
                system("cls");
                printf("Finalizando o sistema.");
                break;
            default:
                system("cls");
                printf("Op��o inv�lida.\n");
        }

    } while(opcao != 8);
    for(int i = 0 ; i < 100 ; i++){
        printf("%d", cliente[i].matricula);
    }
    system("pause");
    return 0;
}

void menu(void) {
    printf("\t****************************************************************************\n");
    printf("\t*    Voc� est� prestes a ser atendido, escolha uma das op��es abaixo:      *\n");
    printf("\t*     1. Cadastrar Usu�rio                                                 *\n");
    printf("\t*     2. Buscar Cadastro                                                   *\n");
    printf("\t*     3. Editar Cadastro                                                   *\n");
    printf("\t*     4. Listar Cadastro                                                   *\n");
    printf("\t*     5. Listar Piscinas                                                   *\n");
    printf("\t*     6. Listar Atletas                                                    *\n");
    printf("\t*     7. Excluir Cadastro                                                  *\n");
    printf("\t*     8. Sair                                                              *\n");
    printf("\t****************************************************************************\n");
}

void menuPiscina(void){
    printf("\t****************************************************************************\n");
    printf("\t*    Qual piscina voc� quer listar?                                        *\n");
    printf("\t*     1. Piscina - 0.40m                                                   *\n");
    printf("\t*     2. Piscina - 1,50m                                                   *\n");
    printf("\t*     3. Piscina - 2,50m                                                   *\n");
    printf("\t*     4. Piscina - 3,00m                                                   *\n");
    printf("\t*     5. Sair                                                              *\n");
    printf("\t****************************************************************************\n");
}

void menuItemEdicao(void){
    printf("\t****************************************************************************\n");
    printf("\t*    �tens dispon�veis para edi��o                                         *\n");
    printf("\t*     1. Nome                                                              *\n");
    printf("\t*     2. CPF                                                               *\n");
    printf("\t*     3. Endere�o                                                          *\n");
    printf("\t*     4. Idade                                                             *\n");
    printf("\t*     5. Atleta                                                            *\n");
    printf("\t*     6. Sair                                                              *\n");
    printf("\t****************************************************************************\n");
}

int gerarMatricula (void) {
    srand(time(NULL));
    int i = rand() % 9000000 + 1000000;
    return i;
}

void cadastraUsuario(void) {
    char x;
    int valid = 0;

    if (qtdCadastro < MAX_CAD) {
        cliente[qtdCadastro].matricula = gerarMatricula();

        printf("Insira o nome: ");
        entradaString(cliente[qtdCadastro].nome, sizeof(cliente[qtdCadastro].nome));
        printf("Informe o CPF: ");
        entradaString(cliente[qtdCadastro].cpf, sizeof(cliente[qtdCadastro].cpf));
        printf("Informe o endere�o: ");
        entradaString(cliente[qtdCadastro].endereco, sizeof(cliente[qtdCadastro].endereco));
        printf("Informe a idade: ");
        scanf("%d", &cliente[qtdCadastro].idade);
        limpaStdin();

        do {
            //Valida se o cliente � atleta ou n�o
            printf("O cliente � atleta? (s/n)");
            scanf("%c",&x);
            limpaStdin();

            if (x == 's' || x == 'S') {
                cliente[qtdCadastro].atleta = 1;
                valid = 1;
            } else if (x == 'n' || x == 'N') {
                cliente[qtdCadastro].atleta = 0;
                valid = 1;
            } else {
                system("cls");
                printf("Valor inv�lido.\n\n");
            }
        }while (!valid);
        qtdCadastro++;
    } else {
        printf("Limite de cadastros atingido.");
    }
    system("cls");
}

void limpaStdin(void) {
    while (getchar() != '\n' && getchar() != EOF);
    //fflush(stdin);
}

void entradaString(char *s, int tam){
    fgets(s, tam, stdin);
    s[strcspn(s, "\n")] = '\0';
    fflush(stdin);
    //limpaStdin();
}

void listarCadastros(void) {
    for (int i = 0; i < qtdCadastro; ++i) {
        printf("\t***************************\n");
        printf("\tnome: %s\n", cliente[i].nome);
        printf("\tCPF: %s\n", cliente[i].cpf);
        printf("\tmatr�cula: %d\n", cliente[i].matricula);
        printf("\tidade: %d\n", cliente[i].idade);
      
        if (cliente[i].atleta == 1) {
            printf("\t� atleta.\n");
        } else {
            printf("\tN�o � atleta.\n");
        }
    }
    system("pause");
    system("cls");
}

void listarAtletas(void){
    /* Temos clientes cadastrados no nosso sistema [ok]
     * temos quer ver quais desses clientes, s�o atletas [ok]
     * Imprime na console os clientes que s�o atletas [ok]
     * */
    printf("\t***************************\n");
    printf("\tOs atletas cadastrados s�o:\n");
    for (int i = 0; i < qtdCadastro; ++i) {//iterar a vari�vel cliente at� atingir o n�mero cadastro
        if(cliente[i].atleta == 1){
            printf("\t %s\n", cliente[i].nome);
        }
    }
    printf("\t***************************\n\n");
}

void listarPiscinas(void){
    int opcao;
    do{
        menuPiscina();
        printf("        Escolha uma op��o: ");
        scanf("%d", &opcao);
        limpaStdin();

        switch (opcao) {
            case 1:
                printf("\t*****************************************************************\n");
                printf("\tPiscina - 0,40m  -> menor que 7 anos ou maior que 18 anos        \n");
                printf("\t*****************************************************************\n");
                for (int i = 0; i < qtdCadastro; ++i) {
                    if(cliente[i].idade < 7 || cliente[i].idade > 18){
                        printf("\tnome: %s\n", cliente[i].nome);
                        printf("\tidade: %d\n", cliente[i].idade);
                    }
                }
                break;
            case 2:
                printf("\t*********************************************\n");
                printf("\tPiscina - 1,50m -> maior que 7 anos          \n");
                printf("\t*********************************************\n");
                for (int i = 0; i < qtdCadastro; ++i) {
                    if(cliente[i].idade >=7){
                        printf("\tnome: %s\n", cliente[i].nome);
                        printf("\tidade: %d\n", cliente[i].idade);
                    }
                }
                break;
            case 3:
                printf("\t********************************************\n");
                printf("\tPiscina - 2,50m  ->   maior que 18 anos     \n");
                printf("\t********************************************\n");
                for (int i = 0; i < qtdCadastro; ++i) {
                    if(cliente[i].idade > 18){
                        printf("\tnome: %s\n", cliente[i].nome);
                        printf("\tidade: %d\n", cliente[i].idade);
                    }
                }
                break;
            case 4:
                printf("\t**************************************\n");
                printf("\tPiscina - 3,00m  ->  Atletas          \n");
                printf("\t**************************************\n");
                for (int i = 0; i < qtdCadastro; ++i) {
                    if(cliente[i].atleta == 1){
                        printf("\tnome: %s\n", cliente[i].nome);
                        printf("\tidade: %d\n", cliente[i].idade);
                        printf("\t� atleta.\n");
                    }
                }
                break;
            case 5:
                menu();
                break;
            default:
                system("cls");
                printf("Op��o inv�lida.\n");
        }
        limpaStdin();
    }while(opcao != 5);
}

void buscarCadastro(void) {
    char busca[12];
    int valid = 0;


    //Buscar por CPF ou Matr�cula
    printf("Informe o CPF ou matr�cula do cliente (informe apenas n�meros): ");
    entradaString(busca, sizeof(busca));
    system("cls");

    int tam = strlen(busca);
    if (tam == 7) {//get matr�cula
        for (int i = 0; i < qtdCadastro; i++) {
            if(atoi(busca) == cliente[i].matricula) {
                printf("\tnome: %s\n", cliente[i].nome);
                printf("\tCPF: %s\n", cliente[i].cpf);
                printf("\tmatr�cula: %d\n", cliente[i].matricula);
                printf("\tidade: %d\n", cliente[i].idade);
                valid = 1;
                Sleep(3000);
                indicadorCadEncontrado = i;
            }
        }
        if (valid == 0) {
            printf("Matr�cula n�o encontrada");
        }
    } else if (tam == 11) {//get CPF
        for (int i = 0; i < qtdCadastro; i++) {
            if (!strcmp(busca, cliente[i].cpf)) {
                printf("\tnome: %s\n", cliente[i].nome);
                printf("\tCPF: %s\n", cliente[i].cpf);
                printf("\tmatr�cula: %d\n", cliente[i].matricula);
                printf("\tidade: %d\n", cliente[i].idade);
                valid = 1;
                indicadorCadEncontrado = i;
            }
        }
        if (valid == 0) {
            printf("CPF n�o encontrado");
        }
    } else {
        printf("N�mero informado � inv�lido.");
    }
    Sleep(3000);
}

void editarCadastro(){
    //1 - informar qual o cadastro que queremos editar
    //2 - buscar o cadastro que queremos editar
    //3 - Mostrar as informa��es do cadatro
    buscarCadastro();
    int opcao;
    char busca[50];
    //4 - Perguntar qual item do cadastro o usu�rio quer editar
        // 5 - Mostrar um menu para cada tipo de informa��o existente num cadastro de usu�rio.
    do{
        menuItemEdicao();
        printf("\nQual informa��o voc� deseja editar? ");
        scanf("%d", &opcao);
        limpaStdin();

        switch(opcao) {
            case 1://nome
                system("cls");
                printf("Digite o novo nome: ");
                entradaString(busca, sizeof(busca));
                strcpy(cliente[indicadorCadEncontrado].nome, busca);
                system("cls");
                printf("\nNome do cliente alterado para %s!\n\n", cliente[indicadorCadEncontrado].nome);
                Sleep(3000);
                break;
            case 2://CPF
                system("cls");
                printf("Digite o novo CPF: ");
                entradaString(busca, sizeof(busca));
                strcpy(cliente[indicadorCadEncontrado].cpf, busca);
                system("cls");
                printf("\nCPF do cliente alterado para %s!\n\n", cliente[indicadorCadEncontrado].cpf);
                Sleep(3000);
                break;
            case 3://endereco
                system("cls");
                printf("Digite o novo endere�o: ");
                entradaString(busca, sizeof(busca));
                strcpy(cliente[indicadorCadEncontrado].endereco, busca);
                system("cls");
                printf("\nEndere�o do cliente alterado para %s!\n\n", cliente[indicadorCadEncontrado].endereco);
                Sleep(3000);
                break;
            case 4://idade
                system("cls");
                int novaIdade;
                printf("Digite a idade: ");
                scanf(" %d", &novaIdade);
                cliente[indicadorCadEncontrado].idade = novaIdade;
                system("cls");
                printf("\nIdade do cliente alterado para %d!\n\n", cliente[indicadorCadEncontrado].idade);
                Sleep(3000);
                break;
            case 5://atleta
                system("cls");
                char altera;
                int eAtleta = cliente[indicadorCadEncontrado].atleta;// 1 = Sim ou 0 = N�o
                if(eAtleta == 1){
                    printf("O cliente � Atleta, deseja alterar? [s/n] \n");
                    scanf("%c", &altera);
                    if(altera == 's' || altera == 'S'){
                        cliente[indicadorCadEncontrado].atleta = 0;
                    }else{
                        break;
                    }
                }else {
                    printf("O cliente n�o � Atleta, deseja alterar? [s/n] \n");
                    scanf("%c", &altera);
                    if(altera == 's' || altera == 'N'){
                        cliente[indicadorCadEncontrado].atleta = 1;
                    }else{
                        break;
                    }
                }
                break;
            case 6:
                system("cls");
                printf("Finalizando o sistema.");
                break;
            default:
                system("cls");
                printf("Op��o inv�lida.\n");
        }

    } while(opcao != 6);
}

void excluirCadastro(){
    int matricula;
    usuario aux;

    system("cls");
    printf("Informe a matr�cula que deseja excluir: ");
    scanf("%d", &matricula);

    system("cls");

    for (int i = 0 ; i  < qtdCadastro ; i++) {
        if(cliente[i].matricula == matricula) {
            aux = cliente[i];
            cliente[i] = cliente[i + 1];
            cliente[i + 1] = aux;
        }
    }
    qtdCadastro--;
}
