#ifndef BULLET_HPP
#define BULLET_HPP
#include"Object.hpp"
#include"raylib.h"
class Bullet:public Object{
    public:
    Position forward_vec;
    float speed;
    float timer;
    Bullet(Position pos,Color col,Position forward_vec);
    void Move(float deltaTime);
    void Draw();

};    
#endif