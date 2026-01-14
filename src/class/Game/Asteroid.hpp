#ifndef ASTEROID_H
#define ASTEROID_H

#include <glm/ext/vector_float2.hpp>
#include <raylib.h>
#include "../Base/GameObject.hpp"
class Asteroid:public GameObject{
    public:
        float scale=0.2f;
        float speed=300.0f;
        float isDestroyed=false;
        Asteroid(Texture2D& tex,float rot,float speed);
        void Update(float deltaTime);
};
#endif