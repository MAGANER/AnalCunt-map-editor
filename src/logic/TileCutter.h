#ifndef TILECUTTER_H
#define TILECUTTER_H
#include"stdafx.h"

class TileCutter
{
private:
    sf::Color* filling_color;
    sf::Vector2f size;
    RectangleShape* cutting_area_rect;
public:
    TileCutter(float tile_width, float tile_height);
    ~TileCutter();

    int get_width();
    int get_height();
    sf::Vector2f get_position();

    RectangleShape* get_rect();

    void cut_lefter(float speed);
    void cut_up(float speed);


    void move_lefter(float speed);
    void move_up(float speed);



};

#endif // TILECUTTER_H
