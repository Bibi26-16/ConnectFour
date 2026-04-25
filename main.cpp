#include <iostream>
using namespace std;

void drawBoardRow(int rowArray[7]) {
    for(int j=0; j<7; j++) {
        if(rowArray[j] == -1) cout << "X";
        else if(rowArray[j] == -2) cout << "O";
        else cout << ".";
        if(j < 6) cout << "|";
    }
    cout << endl;
}

void drawBoard(int b[6][7]) {
    for(int i=0; i<6; i++) {
        drawBoardRow(b[i]);
    }
}

bool isWin(int b[6][7]) {
    for(int i=0; i<6; i++) {
        for(int j=0; j<7; j++) {
            int player = b[i][j];
            if(player == 0) continue;
            if(j+3 < 7 && player==b[i][j+1] && player==b[i][j+2] && player==b[i][j+3]) return true;
            if(i+3 < 6 && player==b[i+1][j] && player==b[i+2][j] && player==b[i+3][j]) return true;
            if(i+3 < 6 && j+3 < 7 && player==b[i+1][j+1] && player==b[i+2][j+2] && player==b[i+3][j+3]) return true;
            if(i+3 < 6 && j-3 >= 0 && player==b[i+1][j-1] && player==b[i+2][j-2] && player==b[i+3][j-3]) return true;
        }
    }
    return false;
}

int checkAvailableRow(int b[6][7], int col) {
    for(int i = 5; i >= 0; i--) {
        if(b[i][col] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int b[6][7] = {0};
    int p = 1;
    int col;
    bool gameOver = false;

    do {
        drawBoard(b);
        cout << "Player " << p << ", alege coloana 1-7: ";
        cin >> col;
        col--;

        if(col < 0 || col > 6) continue;

        int row = checkAvailableRow(b, col);
        if(row == -1) continue;

        if(p == 1) b[row][col] = -1;
        else b[row][col] = -2;

        if(isWin(b)) {
            drawBoard(b);
            cout << "Player " << p << " wins!" << endl;
            gameOver = true;
        }

        if(!gameOver) p = (p == 1) ? 2 : 1;

    } while(!gameOver);

    return 0;
}
