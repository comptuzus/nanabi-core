#include "card.hpp"

Card::Card (int i, int c, int v)
{
    id = i;
    color = c;
    value = v;
}

Card::~Card()
{
}

int Card::get_id()
{
    return id;
}

int Card::get_color()
{
    return color;
}

int Card::get_value()
{
    return value;
}
