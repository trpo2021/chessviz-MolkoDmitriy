#include <libchessviz/convert_to_int.h>
#include <libchessviz/mvpawn.h>
char** pawn_move(char** area, vector<char> move)
{
    int from_first = convert_to_int(move, 1);
    int from_second = convert_to_int(move, 2);
    int to_first = convert_to_int(move, 4);
    int to_second = convert_to_int(move, 5);

    char pawn = area[from_second][from_first];
    if (pawn == 'p' || pawn == 'P') {
        area[from_second][from_first] = ' ';
        area[to_second][to_first] = pawn;
    } else {
        std::cout << "Error! No pawn." << endl;
    }

    return area;
}
