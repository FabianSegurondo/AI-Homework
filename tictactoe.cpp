#include <iostream>
using namespace std;

// Tablero y variable de símbolo
static char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}, ch1;

// Variables de los jugadores
string p1, p2;

// Filas/Columnas
int r, c;
// Cantidad de movidas
int alt = 0;

// Se vacía el tablero para volver a jugar
void boardReset(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Se imprime el tablero
void printBoard(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0)
                cout << "\t\t\t";
            cout << " " << board[i][j] << " ";
            if(j != 2)
                cout << "|";
        }
        cout << "\n";
        if(i != 2)
            cout << "\t\t\t-----------\n";
    }
}

// Se verifica que algún jugador sea el ganador
bool isWinner(char ch4){
    // Todos los casos en los que el jugador gana
    return ((board[0][0] == ch4 && board[0][1] == ch4 && board[0][2] == ch4) ||
            (board[1][0] == ch4 && board[1][1] == ch4 && board[1][2] == ch4) ||
            (board[2][0] == ch4 && board[2][1] == ch4 && board[2][2] == ch4) ||
            (board[0][0] == ch4 && board[1][0] == ch4 && board[2][0] == ch4) ||
            (board[0][1] == ch4 && board[1][1] == ch4 && board[2][1] == ch4) ||
            (board[0][2] == ch4 && board[1][2] == ch4 && board[2][2] == ch4) ||
            (board[0][0] == ch4 && board[1][1] == ch4 && board[2][2] == ch4) ||
            (board[0][2] == ch4 && board[1][1] == ch4 && board[2][0] == ch4));
}

// Se verifica si el tablero está lleno
bool Boardfull(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                return false;
    return true;
}

// Se coloca la jugada o se muestra un mensaje si el lugar está ocupado
void makeMove(char c1){
    if(board[r-1][c-1] == ' ')
        board[r-1][c-1] = c1;
    else{
        cout << "\nEsta posición ya esta ocupada!\n\n";
        alt--;
    }
}

// Código para jugar
void playGame(){
    do{
        if(alt % 2 == 0){
            cout << endl << "\nTurno de " << p1 << "\n";
            ch1 = 'X';
        }
        else{
            cout << endl << "\nTurno de " << p2 << "\n";
            ch1 = 'O';
        }
        while(1){
            cout << "Numero de columna que deseas jugar:: ";
            cin >> c;
            if(c < 1 || c > 3)
                cout << "Un numero entre 1 y 3\n";
            else
                break;
        }
        while(1){
            cout << "Numero de fila que deseas jugar: ";
            cin >> r;
            if(r < 1 || r > 3)
                cout << "Un numero entre 1 y 3\n";
            else
                break;
        }
        makeMove(ch1);
        alt++;
        printBoard();
    }while(!isWinner(ch1) && !Boardfull());
}

// Main
int main(){
    char ch;
    //system("cls");
    do{
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\tBienvenidos al juego de 3 EN RAYA\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nNombre del primer jugador: ";
        cin >> p1;
        cout << "Simbolo asignado al jugador " << p1 << " es 'X'\n";
        cout << "\nNombre del segundo jugador: ";
        cin >> p2;
        cout << "Simbolo asignado al jugador " << p2 << " is 'O'\n\n";
        printBoard();
        playGame();
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\t\t\t\tResultado: ";
        if(Boardfull() && !(isWinner('X') || isWinner('O')))
            cout << "El juego se ha empatado!\n";
        else if(alt % 2 == 0)
            cout << p2 << " Gana!\n";
        else
            cout << p1 << " Gana!\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "\nDeseas jugar nuevamente? \n1. Si \n2. No";
        boardReset();
        alt = 0;
        cin >> ch;
    }while(ch != '2');
}