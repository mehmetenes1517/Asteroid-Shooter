#include"../headers/Position.hpp"
#include<cmath>


Position::Position(){
    point.x=0;
    point.y=0;
}
Position::Position(float x,float y){
    point.x=x;
    point.y=y;
}
Position::Position(Position& p){
    point.x=p.GetPoint().x;
    point.y=p.GetPoint().y;
}
Vector2& Position::GetPoint(){
    return this->point;
}
float Position::Distance(Position p1,Position p2){
    return sqrt((p1.GetPoint().y-p2.GetPoint().y)*(p1.GetPoint().y-p2.GetPoint().y)+(p1.GetPoint().x-p2.GetPoint().x)*(p1.GetPoint().x-p2.GetPoint().x));
}
float Position::Distance(Position &p){
    return sqrt((this->GetPoint().y-p.GetPoint().y)*(this->GetPoint().y-p.GetPoint().y)+(this->GetPoint().x-p.GetPoint().x)*(this->GetPoint().x-p.GetPoint().x));
}

void Position::Set(float x,float y){
    this->point.x=x;
    this->point.y=y;
}
float& Position::GetX() {return point.x;}
float& Position::GetY() {return point.y;}

Position Position::Normalize(Position p1){

    float magnitude=sqrt(p1.GetX()*p1.GetX() + p1.GetY()*p1.GetY());

    Position p_normalized;

    p_normalized.GetX()=p1.GetX()/magnitude;
    p_normalized.GetY()=p1.GetY()/magnitude;
    return p_normalized;
}
float Position::Magnitude(Position p1){
    float magnitude=sqrt(p1.GetX()*p1.GetX() + p1.GetY()*p1.GetY());
    return magnitude;
}


Position Position::operator-(Position& p){
    Position sub;
    sub.Set(this->GetX()-p.GetX(),this->GetY()-p.GetY());
    return sub;
}
Position Position::operator*(float p){
    Position vec;
    vec.GetX()=this->GetX()*p;
    vec.GetY()=this->GetY()*p;
    return vec;
}

Position Position::operator+(Position& p){
    Position sum;
    sum.GetX()=this->GetX()+p.GetX();
    sum.GetY()=this->GetY()+p.GetY();
    return sum;
}
