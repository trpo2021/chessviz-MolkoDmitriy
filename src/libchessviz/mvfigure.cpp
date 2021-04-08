#include <libchessviz/convert_to_int.h>
#include <libchessviz/mvfigure.h>
char** figure_move(char** area, vector<char> move)
{
    int i = 0;
    char figure = move[i];

    int from_first = convert_to_int(move, 1);
    int from_second = convert_to_int(move, 2);
    int to_first = convert_to_int(move, 4);
    int to_second = convert_to_int(move, 5);

    char figure_on_board = area[from_second][from_first];
    if (figure_on_board == figure) {
        area[from_second][from_first] = ' ';
        area[to_second][to_first] = figure_on_board;
    } else {
        std::cout << "Error! Wrong figure." << endl;
    }
    return area;
}
