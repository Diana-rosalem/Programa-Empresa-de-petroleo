#include <stdio.h>
#include <string.h>
//Trablho de Programação de computadores - Aline Amy Kato, Bernado Zampiroli, Diana Rosalém

//variaveis
int Codigos[80] = {0};
int TipoDeLotes[80];
int NumeroDeBarris[80] = {0};
float ValorDeCompra[80] = {0};
float ValorDeVenda[80] = {0};
char NomeDaPlataforma[80][30];


//modulo
void Menu();
void Cadastro();
void BancoDeDados();
void AtualizaLote();
void DeletarCadastro();
void Relatorio();
void OrdemCrescente();
void PesquisaFornecedor();
int BuscarLote(int CodigoLote);


//main
int main(void) 
{
    BancoDeDados();
    Menu();
   
    return 0;
}


//modulo de Menu programa de Estoque Refinaria
void Menu() 
{
    int Opcao;

    do 
    {
      printf("\n\n");

      printf("========================MENU========================");
      printf("\n[1] - Cadastrar um novo lote de barris.");
      printf("\n[2] - Excluir o lote por seu código.");
      printf("\n[3] - Atualizar os dados do registro de um lote de barris cadastrado.");
      printf("\n[4] - consultar, calcular e mostrar o valor total comprado de um fornecedor.");
      printf("\n[5] - Imprimir o relatório");
      printf("\n[6] - Imprimir os dados dos lotes do estoque em ordem crescente.");
      printf("\n[7] - Sair");
      printf("\n====================================================");
      
      printf("\nInsira a opção com a ação desejada:");
     
        scanf("%i", &Opcao);

        switch (Opcao) 
        {
            case 1:
                Cadastro();
                break;

            case 2:
                DeletarCadastro();
                break;

            case 3:
                AtualizaLote();
                break;

            case 4:
                PesquisaFornecedor();
                break;

            case 5:
                Relatorio();
                break;

            case 6:
                OrdemCrescente();
                break;

            
        }
    } 
    while (Opcao != 7);
}


//Modulo de  cadastro de um  novo lote
//Dado que a Refinaria trabalha com no minimo  50  e vai até 100 Barris, e cadastra no máximo 80 Lotes
void Cadastro() 
{

    printf("\n======== [CADASTRO DE LOTES] ========\n");

    int CodigoDeLote, QuantidaDeBarris,TipoLote;
    double PC = 0.0 , PV = 0.0 ;
    char plataforma;

    printf("\nInsira o código do novo lote: ");
    scanf("%i", &CodigoDeLote);

    printf("\n\t1 - Parafínicos\n\t2 - Naftênicos\n\t3 - Mistos\n\t4 - Aromticos\n");

    printf("\n\tInsira [1-4] Tipo de Lote: ");
    scanf("%d", &TipoLote);

    printf("\n\tInsira a quantidade de barris: ");
    scanf("%i", &QuantidaDeBarris);

    printf("\n\tInsira o valor da compra do barril: ");
    scanf("%lf", &PC);

    printf("\n\tInsira o valor de venda do barril: ");
    scanf("%lf", &PV);

    printf("\n\tInsira o nome da plataforma onde foi extraido o oleo: ");
    scanf("%s", &plataforma);

    int i;
    for ( i = 0; i < 80; i++) 
    {
        //Armazena Novo Lote
        if (Codigos[i] == 0) 
        {
            Codigos[i] = CodigoDeLote;
            TipoDeLotes[i] = TipoLote;
            NumeroDeBarris[i] = QuantidaDeBarris;
            ValorDeCompra[i] = PC;
            ValorDeVenda[i] = PV;
            strcpy(NomeDaPlataforma[i], &plataforma);

            break;
        }

    }
    printf("\n\t\t\t===========================================");
    printf("\n\t\t\t\t===>Lote cadastrado com sucesso!<===");
    printf("\n\t\t\t===========================================");
}


// modulo de pesquisa lote pelo codigo 
int BuscarLote(int CodigoLote)
{

    int retorno = -1;

    for (int i = 0; i < 80; i++)
    {
        if (CodigoLote == Codigos[i])
            retorno = i;
    }

    return retorno;
}


// modulo de pesquisa pelo nome do fornecedor (pesquisa por String)
void PesquisaFornecedor() 
{

    int Int_Auxiliar;
    float Float_Auxiliar;
    char Char_Auxiliar;

    //Ordenando os Codigos dos lotes
    for (int i = 0; i < 80; i++) 
    {
        for (int j = i + 1; j < 80; j++) 
        {
            if (Codigos[i] > Codigos[j] && Codigos[i] != 0) 
            {
                Int_Auxiliar = Codigos[i];
                Codigos[i] = Codigos[j];
                Codigos[j] = Int_Auxiliar;

                Int_Auxiliar = TipoDeLotes[i];
                TipoDeLotes[i] = TipoDeLotes[j];
                TipoDeLotes[j] = Int_Auxiliar;

                Int_Auxiliar = NumeroDeBarris[i];
                NumeroDeBarris[i] = NumeroDeBarris[j];
                NumeroDeBarris[j] = Int_Auxiliar;

                Float_Auxiliar = ValorDeCompra[i];
                ValorDeCompra[i] = ValorDeCompra[j];
                ValorDeCompra[j] = Float_Auxiliar;

                Float_Auxiliar = ValorDeVenda[i];
                ValorDeVenda[i] = ValorDeVenda[j];
                ValorDeVenda[j] = Float_Auxiliar;

                strcpy(&Char_Auxiliar, NomeDaPlataforma[i]);
                strcpy(NomeDaPlataforma[i],NomeDaPlataforma[j]);
                strcpy(NomeDaPlataforma[j], &Char_Auxiliar);
            }
        }
    }

    char Plat_Nome = 0;
    float TotalComprado;
    int Cont = 0;

    printf("\nInsira o nome da plataforma: ");
    scanf("%s", &Plat_Nome);


    for (int i = 0; i < 80; i++) 
    {
        if (strcmp(&Plat_Nome, NomeDaPlataforma[i]) == 0) 
        {
            TotalComprado = TotalComprado + ValorDeCompra[i] * NumeroDeBarris[i];
            Cont = Cont + 1;
        }
    }

    printf("Total comprado na plataforma '%s': %.2f", &Plat_Nome, TotalComprado);
}


//modulo para deletar os dados de um lote já existente
void DeletarCadastro()
{

    int CodigoDeLote, Ind;

    printf("\nInsira o codigo do lote a ser excluido: ");
    scanf("%i", &CodigoDeLote);
    Ind = BuscarLote(CodigoDeLote);

    if(Ind < 0 )
    {
        printf("O lote requisitado não foi encontrado.");
    }
    else 
    {
        Codigos[Ind] = 0;
        TipoDeLotes[Ind] = 0;
        NumeroDeBarris[Ind] = 0;
        ValorDeCompra[Ind] = 0;
        ValorDeVenda[Ind] = 0;
        strcpy(NomeDaPlataforma[Ind], "");
        printf("\n\t\t\t===========================================");
        printf("\n\t\t\t\t===>Lote excluido com sucesso!<===");
        printf("\n\t\t\t===========================================");
    }
}


//Esta função preenche banco de dados
//Com 10 lotes fictícios pré registrados
void BancoDeDados()
{

    Codigos[0] = 111;
    TipoDeLotes[0] = 1;
    NumeroDeBarris[0] = 30;
    ValorDeCompra[0] = 100;
    ValorDeVenda[0] = 200;
    strcpy(NomeDaPlataforma[0],"Vila Velha");

    Codigos[1] = 222;
    TipoDeLotes[1] = 2;
    NumeroDeBarris[1] = 40;
    ValorDeCompra[1] = 100;
    ValorDeVenda[1] = 300;
    strcpy(NomeDaPlataforma[1],"Vitória");

    Codigos[2] = 333;
    TipoDeLotes[2] = 1;
    NumeroDeBarris[2] = 30;
    ValorDeCompra[2] = 250;
    ValorDeVenda[2] = 400;
    strcpy(NomeDaPlataforma[2],"Ibiraçu");

    Codigos[3] = 444;
    TipoDeLotes[3] = 3;
    NumeroDeBarris[3] = 60;
    ValorDeCompra[3] = 190;
    ValorDeVenda[3] = 380;
    strcpy(NomeDaPlataforma[3],"Guarapari");

    Codigos[4] = 555;
    TipoDeLotes[4] = 1;
    NumeroDeBarris[4] = 25;
    ValorDeCompra[4] = 100;
    ValorDeVenda[4] = 590;
    strcpy(NomeDaPlataforma[4],"Vitória");

    Codigos[5] = 666;
    TipoDeLotes[5] = 1;
    NumeroDeBarris[5] = 20;
    ValorDeCompra[5] = 220;
    ValorDeVenda[5] = 320;
    strcpy(NomeDaPlataforma[5],"Fundão");

    Codigos[6] = 777;
    TipoDeLotes[6] = 2;
    NumeroDeBarris[6] = 26;
    ValorDeCompra[6] = 260;
    ValorDeVenda[6] = 460;
    strcpy(NomeDaPlataforma[6],"Vila Velha");

    Codigos[7] = 888;
    TipoDeLotes[7] = 2;
    NumeroDeBarris[7] = 37;
    ValorDeCompra[7] = 350;
    ValorDeVenda[7] = 500;
    strcpy(NomeDaPlataforma[7],"Guarapari");

    Codigos[8] = 999;
    TipoDeLotes[8] = 1;
    NumeroDeBarris[8] = 12;
    ValorDeCompra[8] = 270;
    ValorDeVenda[8] = 560;
    strcpy(NomeDaPlataforma[8],"Guarapari");

    Codigos[9] = 101010;
    TipoDeLotes[9] = 2;
    NumeroDeBarris[9] = 24;
    ValorDeCompra[9] = 430;
    ValorDeVenda[9] = 200;
    strcpy(NomeDaPlataforma[9],"Vitória");
}//Fim BancoDeDados


//modulo para mudar os dados de um lote já existente
void AtualizaLote() 
{

    int CodigoDeLote, QuantidaDeBarris, TipoLote, CodigoLote, Ind;
    float ValorCompra, ValorVenda;
    char plataforma;


    printf("\nInsira o codigo a ser buscado: ");
    scanf(" %i", &CodigoLote);
    Ind = BuscarLote(CodigoLote);

    if (Ind < 0) 
    {
        printf("\n\t\t\t===========================================");
        printf("\n\t\t\t\t===>Lote não foi encontrado!<===");
        printf("\n\t\t\t===========================================");
    } 
    else 
    {

        printf("\n\t1 - Parafínicos\n\t2 - Naftênicos\n\t3 - Mistos\n\t4 - Aromáticos");

        printf("\n\nInsira o numero para o tipo de Lote: ");
        scanf("%i", &TipoDeLotes[Ind]);

        printf("\n\nInsira a quantidade de barris: ");
        scanf("%i", &NumeroDeBarris[Ind]);

        printf("\n\nInsira o Valor de compra por unidade: ");
        scanf("%f", &ValorDeCompra[Ind]);

        printf("\n\nInsira o Valor de venda por unidade: ");
        scanf("%f", &ValorDeVenda[Ind]);

        printf("\n\nInsira o nome da plataforma onde foi extraído o oleo: ");
        scanf("%s", NomeDaPlataforma[Ind]);

        printf("\n\t\t\t===========================================");
        printf("\n\t\t\t\t===>Lote atualizado com sucesso!<===");
        printf("\n\t\t\t===========================================");
    }
}


// imprimir um relatório com o total pago pelo lote de barris de petróleo, total dolucro bruto obtido com a venda e lucro líquido
void Relatorio() 
{

    int Int_Auxiliar;
    float Float_Auxiliar;
    char Char_Auxiliar;
    //Ordenando os Codigos dos lotes
    for (int i = 0; i < 80; i++) 
    {
        for (int j = i + 1; j < 80; j++) 
        {
            if (Codigos[i] > Codigos[j] && Codigos[i] != 0) 
            {
                Int_Auxiliar = Codigos[i];
                Codigos[i] = Codigos[j];
                Codigos[j] = Int_Auxiliar;

                Int_Auxiliar = TipoDeLotes[i];
                TipoDeLotes[i] = TipoDeLotes[j];
                TipoDeLotes[j] = Int_Auxiliar;

                Int_Auxiliar = NumeroDeBarris[i];
                NumeroDeBarris[i] = NumeroDeBarris[j];
                NumeroDeBarris[j] = Int_Auxiliar;

                Float_Auxiliar = ValorDeCompra[i];
                ValorDeCompra[i] = ValorDeCompra[j];
                ValorDeCompra[j] = Float_Auxiliar;

                Float_Auxiliar = ValorDeVenda[i];
                ValorDeVenda[i] = ValorDeVenda[j];
                ValorDeVenda[j] = Float_Auxiliar;

                strcpy(&Char_Auxiliar, NomeDaPlataforma[i]);
                strcpy(NomeDaPlataforma[i],NomeDaPlataforma[j]);
                strcpy(NomeDaPlataforma[j], &Char_Auxiliar);

                char Plat_Nome = 0;
                float TotalComprado, TotalVendido;
                int Cont = 0;

                printf("\nInsira o nome da plataforma: ");
                scanf("%s", &Plat_Nome);

                for (int i = 0; i < 80; i++) 
                {
                    if (strcmp(&Plat_Nome, NomeDaPlataforma[i]) == 0) 
                    {
                        TotalComprado = TotalComprado + ValorDeCompra[i] * NumeroDeBarris[i];
                        TotalVendido = TotalVendido + ValorDeVenda[i] * NumeroDeBarris[i];
                        Cont = Cont + 1;
                    }
                }

                printf("\n================ [RELATORIO REQUISITADO] ================\n");
                printf("\nNome da plataforma: %s", &Plat_Nome);
                printf("\nTotal comprado nessa plataforma: %.2f", TotalComprado);
                printf("\nLucro Bruto: %.2f", TotalVendido);
                printf("\nLucro Liquido: %.2f", TotalVendido - TotalComprado);
                printf("\n=========================================================\n");
            }
        }
    }
}


// Modulo que imprimi os dados dos lotes do estoque em ordem crescente pelo código
void OrdemCrescente() 
{

    int Int_Auxiliar;
    float Float_Auxiliar;
    char Char_Auxiliar;
    //Ordenando os Codigos dos lotes
    for (int i = 0; i < 80; i++) 
    {
        for (int j = i + 1; j < 80; j++) 
        {
                if (Codigos[i] > Codigos[j] && Codigos[i] != 0) 
                {
                    Int_Auxiliar = Codigos[i];
                    Codigos[i] = Codigos[j];
                    Codigos[j] = Int_Auxiliar;

                    Int_Auxiliar = TipoDeLotes[i];
                    TipoDeLotes[i] = TipoDeLotes[j];
                    TipoDeLotes[j] = Int_Auxiliar;

                    Int_Auxiliar = NumeroDeBarris[i];
                    NumeroDeBarris[i] = NumeroDeBarris[j];
                    NumeroDeBarris[j] = Int_Auxiliar;

                    Float_Auxiliar = ValorDeCompra[i];
                    ValorDeCompra[i] = ValorDeCompra[j];
                    ValorDeCompra[j] = Float_Auxiliar;

                    Float_Auxiliar = ValorDeVenda[i];
                    ValorDeVenda[i] = ValorDeVenda[j];
                    ValorDeVenda[j] = Float_Auxiliar;

                    strcpy(&Char_Auxiliar, NomeDaPlataforma[i]);
                    strcpy(NomeDaPlataforma[i],NomeDaPlataforma[j]);
                    strcpy(NomeDaPlataforma[j], &Char_Auxiliar);
                }
        }
    }

    int Cont = 0;

    for (int i = 0; i < 80; i++) 
    {
        if (Codigos[i] != 0) 
        {
            printf("\n================= [Vetor[%i] ==> %d] =================", Cont, Codigos[i]);
            printf("\nCodigo: %i", Codigos[i]);
            printf("\nTipo de Lote: %i", TipoDeLotes[i]);
            printf("\nQuantidade de Barris: %i", NumeroDeBarris[i]);
            printf("\nValor Compra Total: %.2f", ValorDeCompra[i] * NumeroDeBarris[i]);
            printf("\nValor Venda Total: %.2f", ValorDeVenda[i] * NumeroDeBarris[i]);
            printf("\nPlataforma: %s", NomeDaPlataforma[i]);
            printf("\n====================================================\n");
            Cont = Cont + 1;
        }

    }

}