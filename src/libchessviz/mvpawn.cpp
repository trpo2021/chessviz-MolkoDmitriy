#include "mvpawn.h"
char** pawn_move(char** area, string move)
{
    long unsigned int i;
    int first_prob = move.find_first_of(' ');
    if (move[0] >= 'a' && move[0] <= 'g')
        i = 0;
    else if (move.find_first_of(' '))
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
    const int from_askii_char_to_int = 96;
    const int from_askii_num_to_int = 48;
    const int size_mas = 8;
    int from_first = (int)(first_move[0]) - from_askii_char_to_int;
    int from_second = size_mas - ((int)(first_move[1]) - from_askii_num_to_int);
    int to_first = (int)(first_move[3]) - from_askii_char_to_int;
    int to_second = size_mas - ((int)(first_move[4]) - from_askii_num_to_int);
    if (first_move.size() == 5) {
        char pawn = area[from_second][from_first];
        area[from_second][from_first] = ' ';
        area[to_second][to_first] = pawn;
    }
    if (second_move.size() == 5) {
        int next_from_first = (int)(second_move[0]) - from_askii_char_to_int;
        int next_from_second
                = size_mas - ((int)(second_move[1]) - from_askii_num_to_int);
        int next_to_first = (int)(second_move[3]) - from_askii_char_to_int;
        int next_to_second
                = size_mas - ((int)(second_move[4]) - from_askii_num_to_int);

        char pawn = area[next_from_second][next_from_first];
        area[next_from_second][next_from_first] = ' ';
        area[next_to_second][next_to_first] = pawn;
    }
    return area;
}
