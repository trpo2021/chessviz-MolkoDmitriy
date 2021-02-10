#include <iostream>

void OutArea(char** a, int n)
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
    const int n = 9;
    const int trans_num_to_aski = 48;
    const int trans_lett_to_aski = 96;
    const int lowercase_trans = -32;
    char** ChessArea = new char*[n];
    for (int i = 0; i < n; i++) {
        ChessArea[i] = new char[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ChessArea[i][j] = ' ';
        }
    }
    for (int i = 0; i < n; i++) {
        ChessArea[i][0] = (char)(trans_num_to_aski + (n - i - 1));
        ChessArea[8][i] = (char)(trans_lett_to_aski + i);
    }
    for (int i = 1; i < n; i++) {
        ChessArea[1][i] = 'p';
    }
    for (int i = 1; i < n; i++) {
        if (i == 1 || i == 8)
            ChessArea[0][i] = 'r';
        if (i == 2 || i == 7)
            ChessArea[0][i] = 'n';
        if (i == 3 || i == 6)
            ChessArea[0][i] = 'b';
        if (i == 4)
            ChessArea[0][i] = 'q';
        if (i == 5)
            ChessArea[0][i] = 'k';
    }
    for (int i = 1; i < n; i++) {
        ChessArea[7][i] = (char)(ChessArea[0][i] + lowercase_trans);
        ChessArea[6][i] = (char)(ChessArea[1][i] + lowercase_trans);
    }
    ChessArea[8][0] = ' ';

    OutArea(ChessArea, n);
}
