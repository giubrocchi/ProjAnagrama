#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <windows.h>

///Feito por Giulia Brocchi e Nicole Bertin

using namespace std;

void iniciar();
void mudacor(int cor);
void gotoxy(int lin, int col);
void cabecalho();
void mudafundo (int cor);
int main()
{
    char BancoPalavras[24][11]={"AR", "DOR", "COR", "EGO", "ERA", "ACRE", "ARCO", "AGRO", "CARA", "GADO", "DOCE", "RODA", "AGORA", "CARGO", "CARRO", "ERRAR", "GORDA", "REGRA", "CORRER", "RECADO", "CERRADO", "GERADORA", "CARREGADO", "CARREGADOR"};
    char BancoRespostas[24][11], Palavra[20];
    char Letras[]={ 'O', 'G', 'R', 'A', 'E', 'A', 'D', 'R', 'C', 'R'};
    int Acertos=0, i, j, achou, a;
    SetConsoleTitle("ANAGRAMA - Feito por Giulia B. e Nicole B.");
    system("color F0");
    iniciar();
    while (Acertos<24)
    {
        cabecalho();
        cout<<"\n\n\tLetras:  ";
        mudacor(9);
        mudafundo(15);
        for(i=0; i<10; i++)
        {
            cout<<"\t"<<Letras[i]<<"  ";
        }
        mudacor(0);
        mudafundo(15);
        cout<<"\n\tAcertos: "<<Acertos<<"/24\n\n";
        cout<<"\t\t";
        for(i=0, a=1;i<Acertos;i++,a++)
        {
            cout<<"\t"<<setw(15)<<BancoRespostas[i];
            if(a%4==0)
                cout<<"\n\t\t";
        }
        cout<<"\n\n\tInsira a palavra: ";
        cin.getline(Palavra, 20);
        strupr(Palavra);
        for(i=0; i<24; i++)
        {
            if(strcmp(BancoPalavras[i], Palavra)==0)
            {
                for(j=0, achou=0; j<24 && achou==0;j++)
                {
                    if(strcmp(BancoRespostas[j], Palavra)==0)
                        achou=1;
                }
                if(achou==0)
                {
                    strcpy(BancoRespostas[Acertos], Palavra);
                    Acertos++;
                }
            }
        }
    system("cls");
    }
    cabecalho();
    cout<<"\n\n\tLetras:  ";
    mudacor(9);
    mudafundo(15);
    for(i=0; i<10; i++)
        cout<<"\t"<<Letras[i]<<"  ";
    mudacor(0);
    mudafundo(15);
    cout<<"\n\tAcertos: "<<Acertos<<"/24\n\n";
    cout<<"\t\t";
    for(i=0, a=1;i<24;i++,a++)
    {
        cout<<"\t"<<setw(15)<<BancoRespostas[i];
        if(a%4==0)
            cout<<"\n\t\t";
    }
    mudacor(4);mudafundo(15);
    gotoxy(18,36);
    cout<<"\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273";
	gotoxy(19,36);
    cout<<"\272 ";
    mudacor(12);mudafundo(15);
    cout<<"PARABENS! VOCE ACHOU TODAS AS "<<Acertos<<" PALAVRAS!";
    mudacor(4);mudafundo(15);
    cout<<" \272";
	gotoxy(20,36);
    cout<<"\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274\n\n\n";
    mudacor(0);mudafundo(15);

    Sleep(900);
    mudacor(2);mudafundo(15);
    gotoxy(17,31);
    cout<<" \\ /";
    gotoxy(18,30);
    cout<<"--  --";
    gotoxy(19,31);
    cout<<" / \\";
    Sleep(900);

    mudacor(13);mudafundo(15);
    gotoxy(21,67);
    cout<<" \\ /";
    gotoxy(22,66);
    cout<<"--  --";
    gotoxy(23,67);
    cout<<" / \\";
    Sleep(900);

    mudacor(5);mudafundo(15);
    gotoxy(17,84);
    cout<<" \\ /";
    gotoxy(18,83);
    cout<<"--  --";
    gotoxy(19,84);
    cout<<" / \\";
    mudacor(0);mudafundo(15);
    gotoxy(24,1);
    cout<<"\n\n\n";
    return 0;
}

void cabecalho()
{
    gotoxy(1,28);
    cout<<"\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273";
    cout<<"\n\t\t\t    \272                 Bem Vindo ao nosso ANAGRAMA                \272";
    cout<<"\n\t\t\t    \272 Use as letras abaixo para formar as 24 palavras diferentes \272";
    cout<<"\n\t\t\t    \272                         BOA SORTE!                         \272";
    gotoxy(5,28);
    cout<<"\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274";
}

void mudacor(int cor)
{
/*
0 = Preto        8 = Cinza
1. = Azul        9 = Azul Claro
2. = Verde       A = Verde Claro
3. = Verde-Agua  B = Verde-Agua Claro
4. = Vermelho    C = Vermelho Claro
5. = Roxo        D = Lilas
6. = Amarelo     E = Amarelo Claro
7. = Branco      F = Branco Brilhante
*/
HANDLE Saida;
Saida = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(Saida,cor);
}

void iniciar()
{
    char a[2];
    cout<<"\n\n\t\t\333\333\333\333\333\333\333\333\333  \333\333\333    \333\333  \333\333\333\333\333\333\333\333\333  \333\333\333\333\333\333\333\333\333  \333\333\333\333\333\333\333\333\333\333  \333\333\333\333\333\333\333\333\333  \333\333      \333\333  \333\333\333\333\333\333\333\333\333\n";
    cout<<"\t\t\333\333     \333\333  \333\333 \333   \333\333  \333\333     \333\333  \333\333         \333\333      \333\333  \333\333     \333\333  \333\333\333\333  \333\333\333\333  \333\333     \333\333\n";
    cout<<"\t\t\333\333\333\333\333\333\333\333\333  \333\333  \333  \333\333  \333\333\333\333\333\333\333\333\333  \333\333  \333\333\333\333\333  \333\333\333\333\333\333\333\333    \333\333\333\333\333\333\333\333\333  \333\333  \333\333  \333\333  \333\333\333\333\333\333\333\333\333\n";
    cout<<"\t\t\333\333     \333\333  \333\333   \333 \333\333  \333\333     \333\333  \333\333     \333\333  \333\333     \333\333   \333\333     \333\333  \333\333      \333\333  \333\333     \333\333\n";
    cout<<"\t\t\333\333     \333\333  \333\333    \333\333\333  \333\333     \333\333  \333\333\333\333\333\333\333\333\333  \333\333      \333\333  \333\333     \333\333  \333\333      \333\333  \333\333     \333\333";
    cout<<"\n\n\t\t                                BEM VINDO AO NOSSO JOGO!";
    do{
    cout<<"\n\t\t                                Aperte ENTER para inciar";
    cin.getline(a, 2);
    }while(strcmp(a, ""));
    system("cls");
}

void mudafundo (int cor)
{
    CONSOLE_SCREEN_BUFFER_INFO var;
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(Saida, &var);
    var.wAttributes &= 0x000F;
    SetConsoleTextAttribute (Saida, var.wAttributes |= (cor << 4));

}
void gotoxy(int lin, int col)
{
	HANDLE Saida;

	COORD Posicao;

	Saida = GetStdHandle(STD_OUTPUT_HANDLE);

	Posicao.X = col;
	Posicao.Y = lin;

	SetConsoleCursorPosition(Saida, Posicao);
}
