class Players {
    public:
        char Positions[8][8];
};

class Piezas {
    private:
        int x,y;
    public:
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
        void checkMoves () {
            if (color==B){
                cout << "Tus movimientos disponibles son: ";
                if(player2.Positions[x+1][y+1] != NULL){
                    cout << " " << (8-(x+1)) << char(65+(y+1));
                }
                if(player2.Positions[x+1][y-1] != NULL){
                    cout << " " << (8-(x+1)) << char(65+(y-1));
                }
                if(player2.Positions[x+1][y] != NULL){
                } else {
                    cout << " " << (8-(x+1)) << char(65+(y)); 
                }
                if(player1.Positions[x+1][y] != NULL){
                } else {
                    cout << " " << (8-(x+1)) << char(65+(y));
                }
                if(y==1){
                   if(player2.Positions[x+2][y] != NULL){
                    } else {
                        cout << " " << (8-(x+2)) << char(65+(y)); 
                    }
                    if(player1.Positions[x+2][y] != NULL){
                    } else {
                        cout << " " << (8-(x+2)) << char(65+(y));
                    } 
                }
            } 
                
            
};
           
