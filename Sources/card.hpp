#ifndef CARD_HPP
#define CARD_HPP
class Card
{
    public:
        Card(int i, int c, int v);
        ~Card();
        int get_id();
        int get_color();
        int get_value();

    private:
        int id;
        int color;
        int value;
};
#endif  // CARD_HPP
