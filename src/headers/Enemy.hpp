#ifndef ENEMY_HPP
#define ENEMY_HPP
#include"Object.hpp"

class Enemy: public Object{
    public:
        float speed;
        Enemy(Position pos,Vector2 size,Color col,float s);
        void MovePoint(Position player_pos,float deltaTime);        
        void LookAt(Position player_pos);
        void Draw();
};

#endif