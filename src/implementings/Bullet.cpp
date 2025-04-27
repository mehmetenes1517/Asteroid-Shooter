#include"../headers/Bullet.hpp"


Bullet::Bullet(Position pos,Color col,Position forward_vec):Object(pos,{8.0f,8.0f},col),speed(70.0f){
    this->forward_vec=forward_vec;
    this->tag=std::string("bullet");
    this->timer=GetTime();
}
void Bullet::Move(float deltaTime){
    this->pos.GetX()+=deltaTime*speed*forward_vec.GetX();
    this->pos.GetY()+=deltaTime*speed*forward_vec.GetY();
    lookAt(forward_vec);
}
void Bullet::Draw(){

    DrawPoly({pos.GetX(),pos.GetY()},4,sizex,0.0,color);

}
