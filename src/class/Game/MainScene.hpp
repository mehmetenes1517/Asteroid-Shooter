#ifndef MAINSCENE_H
#define MAINSCENE_H


#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "../Base/GameControler.hpp"
#include "SpaceShip.hpp"
#include <memory>
#include <raylib.h>
#include <vector>
class MainScene{
    private:

        float Score=0.0f;

        float timer;


        float asteroid_spawn_timer=1.0f;//seconds
        GameController& gamecontroller;
        std::vector<std::unique_ptr<Bullet>> bullets;
        std::vector<std::unique_ptr<Asteroid>> asteroids;
        SpaceShip character;
    public:
        MainScene(GameController& gamecontroller);
        void Update(float deltaTime);
};
#endif