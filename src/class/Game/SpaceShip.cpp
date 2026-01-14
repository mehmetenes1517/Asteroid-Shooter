#include "SpaceShip.hpp"
#include "../Base/GameObject.hpp"
#include "../Base/PhysicsCheck.hpp"
#include <glm/ext/vector_float2.hpp>
#include <raylib.h>

SpaceShip::SpaceShip(Texture2D& tex):GameObject::GameObject(tex),mozzle_point(glm::vec2(this->collider.x,this->collider.y)){}
void SpaceShip::Update(float deltaTime){
    GameObject::Update(deltaTime);
    mozzle_point=std::move(glm::vec2(this->collider.x+(this->collider.width/2),this->collider.y));
    PhysicsCheck::CheckBorderX(*this,0,1280);
    DrawCircleV({mozzle_point.x,mozzle_point.y},5.5f,RED);


    PhysicsCheck::CheckBorderX(*this,0,1280.0f-collider.width*scale);
    PhysicsCheck::CheckBorderY(*this,0,720.0f-collider.height*scale);

    this->Velocity(glm::vec2(0.0f,0.0f));
    if(IsKeyDown(KEY_D)){
        this->Velocity(glm::vec2(playerspeed,Velocity().y));
    }
    if(IsKeyDown(KEY_A)){
        this->Velocity(glm::vec2(-playerspeed,Velocity().y));
    }
    if(IsKeyDown(KEY_W)){
        this->Velocity(glm::vec2(Velocity().x,-playerspeed));
    }
    if(IsKeyDown(KEY_S)){
        this->Velocity(glm::vec2(Velocity().x,playerspeed));
    }
}