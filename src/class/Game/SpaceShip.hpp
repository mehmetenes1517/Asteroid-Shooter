#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "../Base/GameObject.hpp"
#include <raylib.h>
class SpaceShip: public GameObject{
    public:
        bool isDead=false;
        float playerspeed=550.0f;
        glm::vec2 mozzle_point;
        Texture2D bullet_tex;

        SpaceShip(Texture2D& tex);
        void Update(float deltaTime);
};
#endif