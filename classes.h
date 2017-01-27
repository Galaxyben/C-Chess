#include <iostream>
#include <cstring>

using namespace std;

class Piezas {
    public:
        int x,y;
        char color,literal;
        void setColor (char col) {
            color = col;
        }
        void setLiteral (char lit) {
            literal = lit;
        }
        void setPosition (int px, int py) {
            x = px;
            y = py;
        }
};

class Peon: public Piezas{
    public:
        void checkMoves (Players p1, Players p2);
};

class Players {
private:
    string nombre;
public:
    Peon peones[7];
    string getNombre();
    char Positions[8][8];
    char color;
    void setNombre(string nom);
    char checarPosition(char cx, int cy);
};

char Players::checarPosition(char cx, int cy){
    int px, py;
    px = int(cx)-65;
    py = (8-cy);
    if (Positions[px][py] != NULL)
    {
        return Positions[px][py];
    }
}

void Players::setNombre(string nom){
    nombre = nom;
}

string Players::getNombre(){
    return nombre;
}

void Peon::checkMoves(Players p1, Players p2)
{
    if (color == 'B')
    {
        cout << "Tus movimientos disponibles son: " << endl;
        if (p2.Positions[x+1][y+1] != NULL)
        {
            cout << " " << (8-(x+1)) << char(65+(y+1));
        }
        if(p2.Positions[x+1][y-1] != NULL)
        {
            cout << " " << (8-(x+1)) << char(65+(y-1));
        }
        if(p2.Positions[x+1][y] != NULL)
        {

        }
        else
        {
            cout << " " << (8-(x+1)) << char(65+(y));
        }
        if (p1.Positions[x+1][y] != NULL)
        {

        }
        else
        {
            cout << " " << (8-(x+1)) << char(65+(y));
        }
        if(y==1)
        {
            if(p2.Positions[x+2][y] != NULL)
            {

            }
            else
            {
                cout << " " << (8-(x+2)) << char(65+(y));
            }
            if(p1.Positions[x+2][y] != NULL)
            {

            }
            else
            {
                cout << " " << (8-(x+2)) << char(65+(y));
            }
        }
    }
}
