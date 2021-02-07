#include <iostream>

const int n = 9;
void OutArea(char (&a)[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
int main()
{
    using namespace std;
    char ChessArea[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ChessArea[i][j] = ' ';
        }
    }
    for (int i = 0; i < n; i++) {
        ChessArea[i][0] = (char)(48 + (n - i - 1));
        ChessArea[8][i] = (char)(96 + i);
    }
    for (int i = 1; i < n; i++) {
        ChessArea[1][i] = 'p';
    }
    ChessArea[0][1] = 'r';
    ChessArea[0][2] = 'n';
    ChessArea[0][3] = 'b';
    ChessArea[0][4] = 'q';
    ChessArea[0][5] = 'k';
    ChessArea[0][6] = 'b';
    ChessArea[0][7] = 'n';
    ChessArea[0][8] = 'r';
    for (int i = 1; i < n; i++) {
        ChessArea[7][i] = (char)(ChessArea[0][i] - 32);
        ChessArea[6][i] = (char)(ChessArea[1][i] - 32);
    }
    ChessArea[8][0] = ' ';

    OutArea(ChessArea);
}
