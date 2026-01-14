#include "../Game/MainScene.hpp"
#include "GameControler.hpp"
#include <glm/common.hpp>
#include <glm/ext/vector_float2.hpp>
#include <map>
#include <raylib.h>
#include <string>



GameController::GameController(const std::string& title,float width,float height):width(width),height(height),title(title){
    InitWindow(width, height, title.c_str());
    InitAudioDevice();
    musics["bg1"]=LoadMusicStream("./Sounds/bg_music1.mp3");

    sounds["explode_sound"]=LoadSound("./Sounds/explode.mp3");
    sounds["death_sound"]=LoadSound("./Sounds/death.mp3");
    sounds["laser_sound"]=LoadSound("./Sounds/laser_fire.mp3");

    textures["spaceship_tex"]=LoadTexture("./Textures/ship.png");
    textures["bullet_tex"]=LoadTexture("./Textures/laser.png");
    textures["asteroid_tex"]=LoadTexture("./Textures/asteroid.png");


    Init();
}
void GameController::Init(){
    float deltaTime=0,time=GetTime();

    MainScene scene1(*this);

    while (!WindowShouldClose()) {
        deltaTime=GetTime()-time;
        time=GetTime();
        BeginDrawing();
        
        ClearBackground(BLACK);
        scene1.Update(deltaTime);


        EndDrawing();



    }    
}
std::map<std::string, Texture2D>& GameController::GetTextures(){
    return textures;
}
std::map<std::string, Sound>& GameController::GetSounds(){
    return sounds;
}
std::map<std::string, Music>& GameController::GetMusics(){
    return musics;
}

float GameController::Width(){
    return width;
}
float GameController::Height(){
    return height;
}

