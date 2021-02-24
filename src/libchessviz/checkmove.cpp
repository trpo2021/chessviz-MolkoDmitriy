#include "checkmove.h"

int check_move(char** area, string move)
{
    if (move.size() == 0)
        return 0;
    int i;
    int size_mv = 5;
    int first_prob = move.find_first_of(' ');
    bool no_pawn_fl = false;
    if (move[0] == 'r' || move[0] == 'n' || move[0] == 'b' || move[0] == 'q'
        || move[0] == 'k' || move[0] == 'R' || move[0] == 'N' || move[0] == 'B'
        || move[0] == 'Q' || move[0] == 'K') {
        i = 1;
        no_pawn_fl = true;
    } else if (move[0] >= 'a' && move[0] <= 'g')
        i = 0;
    else if (move.find_first_of(' '))
        i = first_prob + 1;

    vector<char> first_move;

    while (move[i] != ' ' && i < move.size()) {
        first_move.push_back(move[i]);
        i++;
    }
    if (first_move.size() > size_mv)
        return 0;
    i++;
    vector<char> second_move;
    while (i < move.size()) {
        second_move.push_back(move[i]);
        i++;
    }
    if (second_move.size() > size_mv)
        return 0;

    if (first_move[0] > 'h' || first_move[0] < 'a' || first_move[1] > '8'
        || first_move[1] < '1')
        return 0;
    else if (
            first_move[3] > 'h' || first_move[3] < 'a' || first_move[4] > '8'
            || first_move[4] < '1')
        return 0;

    if (second_move.size() >= size_mv) {
        if (second_move[0] > 'h' || second_move[0] < 'a' || second_move[1] > '8'
            || second_move[1] < '1')
            return 0;
        else if (
                second_move[3] > 'h' || second_move[3] < 'a'
                || second_move[4] > '8' || second_move[4] < '1')
            return 0;
    }
    if (no_pawn_fl)
        return 2;
    else
        return 1;
}
