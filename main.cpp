#include <stdlib.h>
#include "classes.h"

Players player1, player2;
Peon peonesB[7], peonesN[7];

void llenarArreglos();

void nombresJugadores();

void printBoard();

string verifPstionPza(string ret, char color, int x, int y);

int coorX(char let);

int coorY(int num);

int main()
{
    int coordY;
    char coordX;
    string pzaRtrn = "XX";
    llenarArreglos();
    nombresJugadores();
    while (1)
    {
        system("cls");
        cout << "Tu turno " << player1.getNombre() << " Introduce la coordenada de la pieza que quieres mover" << endl;
        cout << "(Recuerda que tu mueves las fichas con la letra " << player1.color << ")" << endl << endl;
        printBoard();
        cout << endl << "Introduce la letra de la coordenada horizontal" << endl;
        cin >> coordX;
        coordX = coorX(coordX);
        cout << endl << "Introduce el numero de la coordenada vertical" << endl;
        cin >> coordY;
        coordY = coorY(coordY);
        pzaRtrn = verifPstionPza(pzaRtrn, player2.color, coordX, coordY);
        cout << "Pza encontrada " << pzaRtrn;
        /*Aqui va lo referente a la juagada*/
        system("PAUSE");
        system("cls");
        cout << "Tu turno " << player2.getNombre() << " Introduce la coordenada de la pieza que quieres mover" << endl;
        cout << "(Recuerda que tu mueves las fichas con la letra " << player2.color << ")" << endl << endl;
        printBoard();
        /*Aqui va lo referente a la juagada*/
        system("PAUSE");
    }
    printBoard();
    return 0;
}

string verifPstionPza(string ret, char color, int x, int y){

    for (int i = 0; i < 8; i++)
    {
        if (color == 'B')
        {
            if (peonesB[i].x == x && peonesB[i].y == y)
            {
                ret = peonesB[i].literal;
                ret += 'B';
                break;
            }
        } else {
            if (peonesN[i].x == x && peonesN[i].y == y)
            {
                ret = peonesN[i].literal;
                ret += 'N';
                break;
            }
        }
    }
    return ret;
}

int coorX(char let)
{
    return int(let)-65;
}

int coorY(int num)
{
    return 8 - num;
}

void llenarArreglos(){
    for (int i = 0; i<8; i++)
    {
        player1.Positions[i][1] = 'P';
        player2.Positions[i][6] = 'P';
        peonesB[i].x = i;
        peonesB[i].y = 1;
        peonesB[i].literal = 'P';
        peonesB[i].color = player1.color;

        peonesN[i].literal = 'P';
        peonesN[i].x = i;
        peonesN[i].y = 6;
        peonesN[i].color = player2.color;
        for (int j = 0; j<8; j++)
        {
            if (i==0)
            {
                if  (j == 0 || j==7)
                {
                    player1.Positions[j][i] = 'T';
                }
                else if (j == 1 || j==6)
                {
                    player1.Positions[j][i] = 'C';
                }
                else if (j == 2 || j==5)
                {
                    player1.Positions[j][i] = 'A';
                }
            }
            else if (i==7)
            {
                if  (j == 0 || j==7)
                {
                    player2.Positions[j][i] = 'T';
                }
                else if (j == 1 || j==6)
                {
                    player2.Positions[j][i] = 'C';
                }
                else if (j == 2 || j==5)
                {
                    player2.Positions[j][i] = 'A';
                }
            }
        }
        player1.Positions[3][0] = 'Q';
        player1.Positions[4][0] = 'K';
        player1.Positions[3][7] = 'Q';
        player1.Positions[4][7] = 'K';
    }
}

void printBoard(){
    cout << "  __ __ __ __ __ __ __ __" << endl;
    for (int i = 0; i<8; i++)
    {
        cout << " ";
        for (int j = 0; j<8; j++)
        {
            if (player1.Positions[j][i] != NULL)
            {
                cout << "|" << player1.Positions[j][i] << player1.color;
            } else if (player2.Positions[j][i] != NULL)
            {
                cout << "|" << player2.Positions[j][i] << player2.color;
            } else
            {
                cout << "|  ";
            }
        }
        cout << "|" << endl << (8-i);
        for (int j = 0; j<8; j++)
        {
            cout << "|__";
        }
        cout << "|" << endl;

    }
    cout << "   A  B  C  D  E  F  G  H" << endl;

}

void nombresJugadores(){
    string nombres;
    player1.color = 'B';
    player2.color = 'N';
    cout << "Bienvenido a C-Chess" << endl << "Cual es el nombre del primer jugador?" << endl;
    cin >> nombres;
    player1.setNombre(nombres);
    system("cls");
    cout << "Cual es el nombre del segundo jugador?" << endl;
    cin >> nombres;
    player2.setNombre(nombres);
    system("cls");
}
