#include "GameObject.hpp"
#include <glm/ext/vector_float2.hpp>
#include <raylib.h>



GameObject::GameObject(Texture2D& tex):tex(tex),collider((Rectangle){this->position.x,this->position.y,tex.width*scale,tex.height*scale}){}
void GameObject::PhysicsUpdate(float deltaTime){
    this->position+=this->velocity*deltaTime;
    this->collider=(Rectangle){this->position.x,this->position.y,tex.width*scale,tex.height*scale};
}
void GameObject::Translate(const glm::vec2& forward){
    this->position+=forward;
}
void GameObject::Rotate(float speed){
    this->rotation+=speed;
}
void GameObject::Scale(float scale){
    this->scale=scale;
}
void GameObject::Update(float deltaTime){
    PhysicsUpdate(deltaTime);
    DrawTexturePro(this->tex, 
        (Rectangle){0,0,static_cast<float>(this->tex.width),static_cast<float>(this->tex.height)},
         collider,
          (Vector2){0.0f,0.0f},
           rotation,
            WHITE);
}
void GameObject::Velocity(const glm::vec2& velocity){
    this->velocity=velocity;
}
glm::vec2 GameObject::Velocity() const{
    return this->velocity;
}
glm::vec2& GameObject::Velocity(){
    return this->velocity;
}
glm::vec2 GameObject::Position() const{
    return this->position;
} 

glm::vec2& GameObject::Position(){
    return this->position;
} 
void GameObject::Position(const glm::vec2& pos){
    this->position=pos;
} 
float GameObject::Rotation() const{
    return this->rotation;
}
float& GameObject::Rotation() {
    return this->rotation;
}
void GameObject::Rotation(float rot){
    this->rotation=rot;
}
float GameObject::Scale() const{
    return this->scale;
}
float& GameObject::Scale(){
    return this->scale;
}
Rectangle GameObject::Collider() const{
    return this->collider;
}