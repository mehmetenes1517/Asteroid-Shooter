#include"../headers/Object.hpp"


Object::Object(){
    this->pos=Position();
    this->sizex=10.0f;
    this->sizey=10.0f;
    this->color=(Color){
        .r=255,
        .g=255,
        .b=255,
        .a=255,
    };
    this->rotation=0.0f;
}
Object::Object(float x,float y,float sizex,float sizey,Color color){
    this->pos.Set(x,y);
    this->sizex=sizex;
    this->sizey=sizey;
    this->color=color;
    this->rotation=0.0f;
}
Object::Object(Vector2 pos,Vector2 size,Color color){
    this->pos.GetPoint()=pos;
    this->sizex=size.x;
    this->sizey=size.y;
    this->color=color;
    this->rotation=0.0f;
    
}
Object::Object(Position pos,Vector2 size,Color color){
    this->pos=pos;
    this->sizex=size.x;
    this->sizey=size.y;
    this->color=color;
    this->rotation=0.0f;
    
}
Object::Object(Object& obj){
    this->pos=obj.pos;
    this->sizex=obj.sizex;
    this->sizey=obj.sizey;
    this->color=obj.color;
    this->rotation=obj.rotation;
}


Rectangle Object::as_rect(){
    return (Rectangle){
        .x=this->pos.GetX(),
        .y=this->pos.GetY(),
        .width=this->sizex,
        .height=this->sizey
    };
}



void Object::lookAt(Position& p){

    Position look_vector=Position::Normalize(p-this->pos);

    this->rotation=-static_cast<float>(Object::arctan(static_cast<double>( look_vector.GetX()/look_vector.GetY() )))+90.0f;
    
}
bool Object::CheckCollision(Object& other){
    Rectangle this_rect=(Rectangle){
        .x=pos.GetX(),
        .y=pos.GetY(),
        .width=sizex*2,
        .height=sizey*2,
    };
    Rectangle other_rect=(Rectangle){
        .x=other.pos.GetX(),
        .y=other.pos.GetY(),
        .width=other.sizex*2,
        .height=other.sizey*2,
    };
    return CheckCollisionRecs(this_rect,other_rect);
}
bool Object::CheckCollision(Object& other,std::string tag){
    if(other.tag==tag){
        
        Rectangle rect1={
            .x=other.pos.GetX()-other.sizex,
            .y=other.pos.GetY()-other.sizey,
            .width=other.sizex*2,
            .height=other.sizey*2
        };
        Rectangle rect2={
            .x=this->pos.GetX()-this->sizex,
            .y=this->pos.GetY()-this->sizey/2,
            .width=this->sizex*2,
            .height=this->sizey

        };
        //DRAWING COLLISION BUGS
        //DrawRectangleLines(rect1.x,rect1.y,rect1.width,rect1.height,MAGENTA);
        //DrawRectangleLines(rect2.x,rect2.y,rect2.width,rect2.height,MAGENTA);

        return CheckCollisionRecs(rect1,rect2);
            
    }
    return false;
}