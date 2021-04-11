#include <ctest.h>
#include <libchessviz/checkmove.h>
#include <libchessviz/convert_to_int.h>
#include <libchessviz/mvfigure.h>
#include <libchessviz/mvpawn.h>

CTEST(area_test, field_border)
{
    const int n = 9;
    char** chess_area = new char*[n];
    string move = "e18-e2";
    vector<char> first_move;
    vector<char> second_move;
    const int expected = 0;
    const int result = check_move(chess_area, move, first_move, second_move);
    for (int i = 0; i < n; i++) {
        delete[] chess_area[i];
    }
    delete[] chess_area;
    ASSERT_EQUAL(expected, result);
}
CTEST(area_test, field_border2)
{
    const int n = 9;
    char** chess_area = new char*[n];
    string move = "Ra1-i9";
    vector<char> first_move;
    vector<char> second_move;
    const int expected = 0;
    const int result = check_move(chess_area, move, first_move, second_move);
    for (int i = 0; i < n; i++) {
        delete[] chess_area[i];
    }
    delete[] chess_area;
    ASSERT_EQUAL(expected, result);
}
CTEST(area_test, field_border3)
{
    const int n = 9;
    char** chess_area = new char*[n];
    string move = "e2-e3";
    vector<char> first_move;
    vector<char> second_move;
    const int expected = 1;
    const int result = check_move(chess_area, move, first_move, second_move);
    for (int i = 0; i < n; i++) {
        delete[] chess_area[i];
    }
    delete[] chess_area;
    ASSERT_EQUAL(expected, result);
}
CTEST(convert_test, num_to_int)
{
    std::vector<char> move = {' ', 'e', '2', '-', 'e', '4'};
    const int expected = 6;
    const int result = convert_to_int(move, 2);

    ASSERT_EQUAL(expected, result);
}
CTEST(convert_test, char_to_int)
{
    std::vector<char> move = {' ', 'e', '2', '-', 'e', '4'};
    const int expected = 5;
    const int result = convert_to_int(move, 1);

    ASSERT_EQUAL(expected, result);
}
CTEST(move_pawn, pawn)
{
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
    std::vector<char> move = {' ', 'e', '2', '-', 'e', '4'};
    pawn_move(chess_area,move);
    int result = chess_area[4][5];
    int expected = (int)'P';
     for (int i = 0; i < n; i++) {
        delete[] chess_area[i];
    }
    delete[] chess_area;
    ASSERT_EQUAL(expected, result);
}
CTEST(move_figure, figure)
{
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
    std::vector<char> move = {'R', 'a', '1', '-', 'a', '6'};
    figure_move(chess_area,move);
    int result = chess_area[2][1];
    int expected = (int)'R';
    
    ASSERT_EQUAL(expected, result);
}

CTEST(syntax_check, good_input)
{
    const int n = 9;
    char** chess_area = new char*[n];
    string move = "1. e2-e3 Ra1-a4";
    vector<char> first_move;
    vector<char> second_move;
    const int expected = 1;
    const int result = check_move(chess_area, move, first_move, second_move);
    ASSERT_EQUAL(expected, result);
    for (int i = 0; i < n; i++) {
        delete[] chess_area[i];
    }
    delete[] chess_area;
}
CTEST(syntax_check, error_input)
{
    const int n = 9;
    char** chess_area = new char*[n];
    string move = "1.e2-e3x$#a1-ap";
    vector<char> first_move;
    vector<char> second_move;
    const int expected = 0;
    const int result = check_move(chess_area, move, first_move, second_move);

    ASSERT_EQUAL(expected, result);
    for (int i = 0; i < n; i++) {
        delete[] chess_area[i];
    }
    delete[] chess_area;
}