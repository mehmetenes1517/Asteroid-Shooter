#include "Bullet.hpp"
#include <glm/ext/vector_float2.hpp>


Bullet::Bullet(Texture2D& tex):GameObject::GameObject(tex){
    Scale()=0.12f;
}
void Bullet::Update(float deltaTime){
    GameObject::Update(deltaTime);
    
    this->Velocity(glm::vec2(0.0f,-bulletspeed));
    uptime-=deltaTime;
    if(uptime<=0){
        isDead=true;
    }
}