#include "mvpawn.h"
char** pawn_move(char** area, string move)
{
    long unsigned int i = 0;
    int first_prob = move.find_first_of(' ');
    if (move.find_first_of(' '))
        i = first_prob + 1;
    vector<char> first_move;
    while (move[i] != ' ' && i < move.size()) {
        first_move.push_back(move[i]);
        i++;
    }
    i++;
    vector<char> second_move;
    while (i < move.size()) {
        second_move.push_back(move[i]);
        i++;
    }

    int from_first = convert_to_int(first_move, 0);
    int from_second = convert_to_int(first_move, 1);
    int to_first = convert_to_int(first_move, 3);
    int to_second = convert_to_int(first_move, 4);

    if (first_move.size() == 5) {
        char pawn = area[from_second][from_first];
        area[from_second][from_first] = ' ';
        area[to_second][to_first] = pawn;
    }

    if (second_move.size() == 5) {
        int next_from_first = convert_to_int(second_move, 0);
        int next_from_second = convert_to_int(second_move, 1);
        int next_to_first = convert_to_int(second_move, 3);
        int next_to_second = convert_to_int(second_move, 4);

        char pawn = area[next_from_second][next_from_first];
        area[next_from_second][next_from_first] = ' ';
        area[next_to_second][next_to_first] = pawn;
    }

    return area;
}

int convert_to_int(vector<char> move, int position)
{
    const int from_askii_char_to_int = 96;
    const int from_askii_num_to_int = 48;
    const int size_mas = 8;
    int result = 0;
    if (position == 0 || position == 3)
        result = (int)(move[position]) - from_askii_char_to_int;

    if (position == 1 || position == 4)
        result = size_mas - ((int)(move[position]) - from_askii_num_to_int);

    return result;
}
