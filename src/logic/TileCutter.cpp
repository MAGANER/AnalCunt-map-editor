#include "TileCutter.h"

TileCutter::TileCutter(float tile_width, float tile_height)
{
    size.x = tile_width;
    size.y = tile_height;
    filling_color = new sf::Color(255,255,255,100);

    cutting_area_rect = new RectangleShape(size);
    cutting_area_rect->setFillColor(*filling_color);
    cutting_area_rect->setPosition(10.0f,10.0f);
}

TileCutter::~TileCutter()
{
    delete filling_color;
    delete cutting_area_rect;
}

void TileCutter::cut_lefter(float speed)
{
    sf::Vector2f size = cutting_area_rect->getSize();
    size.x-=speed;
    cutting_area_rect->setSize(size);
}
void TileCutter::cut_up(float speed)
{
     sf::Vector2f size = cutting_area_rect->getSize();
     size.y-=speed;
     cutting_area_rect->setSize(size);
}
void TileCutter::move_lefter(float speed)
{
    sf::Vector2f offset(cutting_area_rect->getPosition().x-speed,cutting_area_rect->getPosition().y);
    cutting_area_rect->setPosition(offset);
}
void TileCutter::move_up(float speed)
{
    sf::Vector2f offset(cutting_area_rect->getPosition().x,cutting_area_rect->getPosition().y-speed);
    cutting_area_rect->setPosition(offset);
}
sf::Vector2f TileCutter::get_position()
{
    return cutting_area_rect->getPosition();
}
RectangleShape* TileCutter::get_rect()
{
    return cutting_area_rect;
}
int TileCutter::get_height()
{
    return cutting_area_rect->getSize().y;
}
int TileCutter::get_width()
{
    return cutting_area_rect->getSize().x;
}
