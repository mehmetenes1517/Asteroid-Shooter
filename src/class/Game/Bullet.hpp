#ifndef BULLET_H
#define BULLET_H

#include "../Base/GameObject.hpp"
#include <glm/ext/vector_float2.hpp>
#include <raylib.h>
class Bullet: public GameObject{
    public:
        float uptime=3.0f;
        bool isDead=false;
        float bulletspeed=650.0f;
        Bullet(Texture2D& tex);
        void Update(float deltaTime);
};
#endif