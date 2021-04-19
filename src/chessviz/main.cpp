#include <iostream>
#include <libchessviz/checkmove.h>
#include <libchessviz/mvfigure.h>
#include <libchessviz/mvpawn.h>
void out_area(char** a, int n)
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
    char** chess_area = new char*[n];
    for (int i = 0; i < n; i++) {
        chess_area[i] = new char[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            chess_area[i][j] = ' ';
        }
    }
    for (int i = 0; i < n; i++) {
        chess_area[i][0] = (char)(trans_num_to_aski + (n - i - 1));
        chess_area[8][i] = (char)(trans_lett_to_aski + i);
    }
    for (int i = 1; i < n; i++) {
        chess_area[1][i] = 'p';
    }
    for (int i = 1; i < n; i++) {
        if (i == 1 || i == 8)
            chess_area[0][i] = 'r';
        if (i == 2 || i == 7)
            chess_area[0][i] = 'n';
        if (i == 3 || i == 6)
            chess_area[0][i] = 'b';
        if (i == 4)
            chess_area[0][i] = 'q';
        if (i == 5)
            chess_area[0][i] = 'k';
    }
    for (int i = 1; i < n; i++) {
        chess_area[7][i] = (char)(chess_area[0][i] + lowercase_trans);
        chess_area[6][i] = (char)(chess_area[1][i] + lowercase_trans);
    }
    chess_area[8][0] = ' ';
    cout << "Input your move: number move. move move" << endl;
    cout << "To exit input 1 \n" << endl;
    out_area(chess_area, n);

    cout << endl;
    while (true) {
        string move;
        vector<char> first_move;
        vector<char> second_move;
        getline(cin, move);

        if (move == "1")
            break;

        if (check_move(chess_area, move, first_move, second_move)) {
            if (first_move[0] == ' ')
                chess_area = pawn_move(chess_area, first_move);
            else
                chess_area = figure_move(chess_area, first_move);
            if (second_move.size() == 6) {
                if (second_move[0] == ' ')
                    chess_area = pawn_move(chess_area, second_move);
                else
                    chess_area = figure_move(chess_area, second_move);
            }
            cout << endl;
            out_area(chess_area, n);
            cout << endl;
        } else {
            cout << "Error! Try again." << endl << endl;
            continue;
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] chess_area[i];
    }
    delete[] chess_area;
}
