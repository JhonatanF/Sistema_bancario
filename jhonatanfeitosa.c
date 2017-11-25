#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct idcliente IDCLIENTE;
struct idcliente {
        char nome[50];
        char cpf[20];
        int dia, mes, ano;
};
typedef struct usuario USUARIO;
struct usuario {
        int numconta;
        IDCLIENTE indent;
        double saldo;
} ;
void cabecalho();
void preencher();
void limparbuffer();
void limpartela();
void visualizar();
void pesquisar();
void bonus();
main () {
        setlocale(LC_ALL, "");
        int opcao=0;

        do{
                cabecalho();printf("\t\t\t\t\tMENU\n");cabecalho();
                printf("\n\t\t\t1 - Cadastramento de Contas\n");
                printf("\t\t\t2 - Visualizar Todas as Contas\n");
                printf("\t\t\t3 - Pesquisar Contas\n");
                printf("\t\t\t4 - Bônus de Aniversário\n");
                printf("\t\t\t5 - Sair\n\n");
                printf("\t\t\tESCOLHA UMA OPÇÃO DO MENU: ");
                scanf("%d", &opcao);

                switch(opcao){
                    case 1:
                                limpartela();
                                preencher();
                    break;
                    case 2:
                                limpartela();
                                visualizar();
                    break;
                    case 3:
                                limpartela();
                                pesquisar();
                    break;
                    case 4:
                                limpartela();
                                bonus();
                    break;
                    case 5:
                        limpartela();
                        printf("OBRIGADO VOLTE SEMPRE!\n");
                        break;
                    default:
                        printf("Opção Inválida\n");
                        break;
                }
        }while(opcao != 5);

}
void cabecalho(){
        printf("\t\t\t===================================\n");
}
void limparbuffer(){
        setbuf(stdin, NULL);
}
void limpartela(){
    system("cls");
}
void preencher(){
        int x=0;

        USUARIO temp;
        temp.saldo = 0;
        FILE *arquivo;

        arquivo = fopen("dados.txt", "ab");


        if(arquivo == NULL){

            printf("Não foi Possivel Abrir o Arquivo!\n");

        }else{

            do{
                limpartela();

                cabecalho();printf("\t\t\t\t\tCADASTRO\n");cabecalho();

                limparbuffer();
                printf("\n\t\t\tNumero da Conta :  ");
                scanf("%d", &temp.numconta);

                limparbuffer();
                printf("\n\t\t\tNome:  ");
                gets(temp.indent.nome);
                strupr(temp.indent.nome);

                limparbuffer();
                printf("\n\t\t\tCPF:  ");
                gets(temp.indent.cpf);

                limparbuffer();
                printf("\n\t\t\tData de Nascimento:  ");
                scanf("%d %d %d", &temp.indent.dia, &temp.indent.mes, &temp.indent.ano);

                printf("\n\t\t\tDeseja Depositar Algum Valor ? 1 - Sim 2 - Não\n");
                limparbuffer();
                scanf("%d", &x);
                if(x == 1){
                    printf("\n\t\t\tDigite o valor que vai ser depositado:  ");
                    scanf("%lf", &temp.saldo);
                    limpartela();
                    printf("\n\n\t\t\tValor Depositado com Sucesso!\n ");
                    system("pause");
                }

                fwrite(&temp, sizeof(USUARIO), 1, arquivo);
                limpartela();
                printf("\n\t\t\tDeseja Continuar ? 1 - Sim 2- Não\n");

            }while(getche() == '1');
            fclose(arquivo);
            limpartela();
        }

}
void visualizar(){
         cabecalho();puts("\t\t\tVISUALIZAR");cabecalho();
        int x=0;
        USUARIO temp;
        FILE *arquivo;

        arquivo = fopen("dados.txt", "rb");

        if(arquivo == NULL){

            printf("Não foi Possivel Abrir o Arquivo!\n");

        }else{
                while( fread(&temp, sizeof(USUARIO), 1,  arquivo) == 1){
                    printf("\t\tNome: %s\n", temp.indent.nome);
                    printf("\t\tNum.Conta: %d\n", temp.numconta);
                    printf("\t\tCPF:  %s\n", temp.indent.cpf);
                    printf("\t\tSaldo:  %.2lf\n", temp.saldo);
                    printf("------------------------------------------------------------   ");
                    system("pause");
                }

        }
        fclose(arquivo);
        system("pause");
        limpartela();


}
void pesquisar(){
     cabecalho();puts("\t\t\tPESQUISAR");cabecalho();
            FILE *arquivo;
            arquivo = fopen("dados.txt", "rb");
            USUARIO temp;
            char pnome[30];
            int pnum=0, x=0;

                if(arquivo == NULL){
                    printf("Não foi Possivel Abrir o Arquivo!\n");
                }else{
                    printf("\n\n\t\t\t0 - Pesquisar por número da conta\n");
                    printf("\t\t\t1 - Pesquisar por nome do cliente\n");
                    scanf("%d", &x);
                        if(x == 0){
                                limpartela();
                                 cabecalho();puts("\t\t\tPESQUISAR");cabecalho();
                                printf("\t\t\tDigite o numero da conta a ser pesquisada\n");
                            scanf("%d", &pnum);
                                while( fread(&temp, sizeof(USUARIO), 1,  arquivo) == 1){
                                        if( pnum == temp.numconta){
                                            printf("\t\tNome: %s\n", temp.indent.nome);
                                            printf("\t\tNum.Conta: %d\n", temp.numconta);
                                            printf("\t\tCPF:  %s\n", temp.indent.cpf);
                                            printf("\t\tData de Nascimento:  %d/%d/%d\n", temp.indent.dia, temp.indent.mes, temp.indent.ano);
                                            printf("\t\tSaldo:  %.2lf\n", temp.saldo);
                                            printf("------------------------------------------------------------   ");
                                            system("pause");
                                        }
                                }
                                //fim da nova linha

                        }else{
                            //mudar
                            limparbuffer();
                                    printf("\t\t\tDigite o nome da conta a ser pesquisado: \n");
                                    gets(pnome);
                                        while( fread(&temp, sizeof(USUARIO), 1,  arquivo) == 1){
                                                if( strcmp(pnome, temp.indent.nome)== 0 ){

                                                    printf("\t\tNome: %s\n", temp.indent.nome);
                                                    printf("\t\tNum.Conta: %d\n", temp.numconta);
                                                    printf("\t\tCPF:  %s\n", temp.indent.cpf);
                                                    printf("\t\tData de Nascimento:  %d/%d/%d\n", temp.indent.dia, temp.indent.mes, temp.indent.ano);
                                                    printf("\t\tSaldo:  %.2lf\n", temp.saldo);
                                                    printf("------------------------------------------------------------   ");
                                                    system("pause");
                                        }
                                }
                                //fim da

                            }
                }
                fclose(arquivo);
                system("pause");
                limpartela();
}
void bonus(){
        cabecalho();puts("\t\t\tBONUS");cabecalho();
        int mes=0, i=0;
        FILE *arquivo;
        USUARIO temp;
        arquivo = fopen("dados.txt", "rb");

        printf("\n\t\t\tDigite mês para receber os bônus ( EM NÚMERO):\n");
        scanf("%d", &mes);
            if( arquivo == NULL){
                printf("Não foi Possivel Abrir o Arquivo!\n");
            }else {
                    while( fread(&temp, sizeof(USUARIO), 1,  arquivo) == 1){
                                if(mes == temp.indent.mes){
                                  temp.saldo = temp.saldo + 1;
                                  i= i +1;
                                }
                    }
            }
        fclose(arquivo);
        printf("\t\t\t %d Contas receberam o bônus\n", i);
        system("pause");
        limpartela();
}

