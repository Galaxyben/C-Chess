#include <stdlib.h>
#include <cstring>
#include "classes.h"

public Players player1, player2;

void llenarArreglos(){
    for (int i = 0; i<8; i++)
    {
        player1.Positions[i][1] = 'P';
        player2.Positions[i][6] = 'P';
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

int main()
{
    llenarArreglos();
    player1.color = 'B';
    player2.color = 'N';
    printBoard();
    return 0;
}
