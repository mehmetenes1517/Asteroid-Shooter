#include"../headers/Enemy.hpp"


Enemy::Enemy(Position pos,Vector2 size,Color col,float s): Object(pos,size,col) , speed(s){
    this->tag=std::string("enemy");
    this->rotation=45.0f;
}
void Enemy::MovePoint(Position player_pos,float deltaTime){
    Position forward_vec=Position::Normalize(player_pos-this->pos);

    this->pos.GetX()+=deltaTime*speed*forward_vec.GetX();
    this->pos.GetY()+=deltaTime*speed*forward_vec.GetY();
    lookAt(player_pos);
}        
void Enemy::Draw(){
    DrawPoly({this->pos.GetX(),this->pos.GetY()},9,this->sizex,rotation,this->color);
}
void Enemy::LookAt(Position player_pos){
    Position p=Position::Normalize(player_pos-this->pos);
    this->rotation=Object::arctan(p.GetX()/p.GetY())+45.0f;
}
