#include <iostream>
#include <stdlib.h>
#include "classes.h"

using namespace std;

char p1Positions[8][8];
char p2Positions[8][8];

void llenarArreglos(){
    for (int i = 0; i<8; i++)
    {
        p1Positions[0][1] = 'P';
    }
}

void printBoard(){
    cout << "  __ __ __ __ __ __ __ __" << endl;
    for (int i = 0; i<8; i++)
    {
        cout << " ";
        for (int j = 0; j<8; j++)
        {
            cout << "|  ";
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
    printBoard();
    return 0;
}
