#include <libchessviz/checkmove.h>

int check_move(
        char** area,
        string move,
        vector<char>& first_move,
        vector<char>& second_move)
{
    if (move.size() == 0)
        return 0;
    long unsigned int i;
    long unsigned int size_mv = 6;
    int first_prob = move.find_first_of(' ');
    bool pawn = 1;

    if (check_figure(move, 0)) {
        i = 0;
        pawn = 0;
    } else if (move[0] >= 'a' && move[0] <= 'g')
        i = 0;
    else if (move.find_first_of(' '))
        i = first_prob + 1;

    if (check_figure(move, i)) {
        pawn = 0;
    }
    if (pawn) {
        first_move.push_back(' ');
    } else {
        first_move.push_back(move[i]);
        i++;
    }
    while (move[i] != ' ' && i < move.size()) {
        first_move.push_back(move[i]);
        i++;
    }
    if (first_move.size() > size_mv)
        return 0;
    i++;
    if (i < move.size()) {
        pawn = 1;
        if (check_figure(move, i)) {
            pawn = 0;
        }
        if (pawn) {
            second_move.push_back(' ');
        } else {
            second_move.push_back(move[i]);
            i++;
        }
        while (move[i] != ' ' && i < move.size()) {
            second_move.push_back(move[i]);
            i++;
        }
    }
    if (second_move.size() > size_mv)
        return 0;

    if (move_check_area(first_move, 1))
        return 0;

    if (second_move.size() == size_mv)
        if (move_check_area(second_move, 1))
            return 0;

    return 1;
}

bool move_check_area(vector<char> move, int position)
{
    if (move[position] > 'h' || move[position] < 'a' || move[position + 1] > '8'
        || move[position + 1] < '1')
        return 1;

    if (move[position + 3] > 'h' || move[position + 3] < 'a'
        || move[position + 4] > '8' || move[position + 4] < '1')
        return 1;

    return 0;
}

bool check_figure(string move, int position)
{
    if (move[position] == 'r' || move[position] == 'n' || move[position] == 'b'
        || move[position] == 'q' || move[position] == 'k'
        || move[position] == 'R' || move[position] == 'N'
        || move[position] == 'B' || move[position] == 'Q'
        || move[position] == 'K')
        return 1;

    return 0;
}
