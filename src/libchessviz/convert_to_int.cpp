#include <libchessviz/convert_to_int.h>
int convert_to_int(vector<char> move, int position)
{
    const int from_askii_char_to_int = 96;
    const int from_askii_num_to_int = 48;
    const int size_mas = 8;
    int result = 0;
    if (position == 1 || position == 4)
        result = (int)(move[position]) - from_askii_char_to_int;

    if (position == 2 || position == 5)
        result = size_mas - ((int)(move[position]) - from_askii_num_to_int);

    return result;
}
