#include "MainScene.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "SpaceShip.hpp"
#include <cstdlib>
#include <glm/ext/vector_float2.hpp>
#include "../Base/PhysicsCheck.hpp"
#include <memory>
#include <raylib.h>
#include <string>
#include <utility>

MainScene::MainScene(GameController& gamecontroller):gamecontroller(gamecontroller),character(SpaceShip(gamecontroller.GetTextures()["spaceship_tex"])){
    timer=asteroid_spawn_timer;
    character.Scale(0.2f);
    character.Position()=glm::vec2(gamecontroller.Width()/2,gamecontroller.Height()-character.Collider().height*character.Scale());
    srand(time(0));

    PlayMusicStream(gamecontroller.GetMusics()["bg1"]);
    SetMusicVolume(gamecontroller.GetMusics()["bg1"],0.1f);
    SetSoundVolume(gamecontroller.GetSounds()["laser_sound"],0.2f);
    SetMusicVolume(gamecontroller.GetMusics()["explode_sound"],0.2f);
    SetMusicVolume(gamecontroller.GetMusics()["death_sound"],0.2f);

}
void MainScene::Update(float deltaTime){
    character.Update(deltaTime);
    std::string score_text="Score : "+std::to_string(Score);
    UpdateMusicStream(gamecontroller.GetMusics()["bg1"]);

    if(!character.isDead){

        //Bullet Spawning 
        if(IsKeyPressed(KEY_SPACE)){
            std::unique_ptr<Bullet> b=std::make_unique<Bullet>(gamecontroller.GetTextures()["bullet_tex"]);
            b->Position(character.mozzle_point);
            bullets.push_back(std::move(b));
            PlaySound(gamecontroller.GetSounds()["laser_sound"]);
        }
        //Rendering Bullets
        for (auto iter=bullets.begin();iter!=bullets.end();iter++) {
            if((*iter)->isDead){
                bullets.erase(iter);
                break;
            }
            (*iter)->Update(deltaTime);
        }
        
        //Asteroid Spawning
        timer-=deltaTime;
        if (timer<=0) {
            
            float scale=((rand()%200)+100)/1000.0f;
            float speed=(rand()%200)+300;
            
            std::unique_ptr<Asteroid> asteroid1=std::make_unique<Asteroid>(gamecontroller.GetTextures()["asteroid_tex"],scale,speed);
            asteroid1->Position().x=rand() % static_cast<int>(1280-asteroid1->Collider().width*asteroid1->Scale());
            asteroid1->Position().y=-asteroid1->Collider().height*asteroid1->Scale();
            
            asteroids.push_back(std::move(asteroid1));
            
            
            timer=asteroid_spawn_timer;
        }
        
        //Render Asteroids
        for(auto iter=asteroids.begin();iter!=asteroids.end();iter++){
            if((*iter)->isDestroyed){
                asteroids.erase(iter);
                break;
            }
            (*iter)->Update(deltaTime);
        }
        
        //Check Collisions
        for(auto iter_asteroid=asteroids.begin();iter_asteroid!=asteroids.end();iter_asteroid++){
            
            if(!(*iter_asteroid)->isDestroyed){
                
                if(PhysicsCheck::IsColliding(character.Collider(),(*iter_asteroid)->Collider())){
                    character.isDead=true;
                    PlaySound(gamecontroller.GetSounds()["death_sound"]);
                }
            }
            
            for (auto iter_bullet=bullets.begin();iter_bullet!=bullets.end();iter_bullet++) {
                
                if(!(*iter_asteroid)->isDestroyed && !(*iter_bullet)->isDead){
                    
                    if(PhysicsCheck::IsColliding((*iter_asteroid)->Collider(),(*iter_bullet)->Collider())){              
                        (*iter_asteroid)->isDestroyed=true;
                        (*iter_bullet)->isDead=true;
                        PlaySound(gamecontroller.GetSounds()["explode_sound"]);
                        Score+=(*iter_asteroid)->scale*100.0f;
                    }
                }
            }
        }

        //Score Display
        DrawText(score_text.c_str(),0,0, 24,GREEN);
        
    }else{
        
        DrawText("You are dead ! Press [R] for retry",550,250, 24,GREEN);
        DrawText(score_text.c_str(),550,350,24,GREEN);
        if(IsKeyPressed(KEY_R)){
            Score=0;
            character.isDead=false;
            bullets.clear();
            asteroids.clear();
        }
        

    }
}