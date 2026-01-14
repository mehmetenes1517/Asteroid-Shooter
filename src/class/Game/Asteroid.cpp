#include "Asteroid.hpp"
#include <glm/ext/vector_float2.hpp>



Asteroid::Asteroid(Texture2D& tex,float scale,float speed):GameObject::GameObject(tex),speed(speed){
    Scale(scale);
    
}
void Asteroid::Update(float deltaTime){
    GameObject::Update(deltaTime);
    if(position.y>=1280){
        isDestroyed=true;
    }
    Velocity(glm::vec2(0.0f,speed));

}
