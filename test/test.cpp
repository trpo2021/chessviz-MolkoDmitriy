#include <ctest.h>
#include <libchessviz/checkmove.h>
#include <libchessviz/mvfigure.h>
#include <libchessviz/mvpawn.h>

CTEST(chessviz_test, field_border)
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
