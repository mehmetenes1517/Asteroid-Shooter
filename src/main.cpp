
#include<iostream>
#include<iomanip>
#include<vector>
#include"raylib.h"

using namespace std;

#include"headers/Object.hpp"
#include"headers/Bullet.hpp"
#include"headers/Enemy.hpp"

#define WIDTH 1280  
#define HEIGHT 720


void UserMovement(Object& player,float speed,float deltaTime);
int main(){
    
    InitWindow(WIDTH,HEIGHT,"Shoot Asteroids");
    InitAudioDevice();

    Music m=LoadMusicStream("music.mp3");
    SetMusicVolume(m,0.5f);
    PlayMusicStream(m);

    Sound shoot=LoadSound("shoot.wav");
    SetSoundVolume(shoot,0.1f);
    GAMESTART:
    
    //CHARACTER
    Object rect1=Object(Position(300,400),(Vector2){.x=10.0f,.y=20.0f},RED);
    //CURSOR MOVEMENT VARIABLE
    Position cursor=Position();
    
    //BULLET LIST
    std::vector<Bullet*> bullet_list;
    bullet_list.clear();
    //ENEMY LIST
    std::vector<Enemy*> enemy_list;
    enemy_list.clear();

    
    //DeltaTime Variables
    float deltaTime=0.0f,time=0.0f;
    float Speed=20.0f;
    
    //Clamping fps to 120
    SetTargetFPS(120);
    
    //Points Variable
    int Point=0;


    //Timer for spawn Enemy Vertical
    float timer2=GetTime();
    //Timer for spawn Enemy Horizontal
    float timer3=GetTime();
    //Timer For Multiple Bullet Fire
    float timer4=GetTime();

    bool isPaused=false;


    int bullets_shot=0;

    float coefficient=1.0f;

    if(IsMusicStreamPlaying(m)==false){
        PlayMusicStream(m);
    }
    int t=2.0f;

    float user_coefficient=1.0f;

    while (WindowShouldClose()!=true)
    {   
        UpdateMusicStream(m);
        //Background and Begin Drawing 
        ClearBackground(BLACK);
        BeginDrawing();
        
        DrawFPS(0,0);


        //SCALING FOR HARDNESS OF GAME
        coefficient=(Point>=25.0f) ?  (Point>=50.0f ? (Point>=65.0f ? 4.0f : 2.0f) : 1.5f) :1.0; 
        if(coefficient>=1.5f) t=1.0f;

        //deltaTime
        deltaTime=GetTime()-time;
        time=GetTime();

        

        if(isPaused==true){
            DrawText((string("You Lose !\n Total Points : ")+std::to_string(Point)+string("\nAccuracy : %")+std::to_string(100*(float)Point/(float)bullets_shot)+string("\nPress [R] to restart game...")).c_str(),WIDTH/2,HEIGHT/2,25,RED);
            if(IsKeyPressed(KEY_R)){
                goto GAMESTART;
            }
        }else{

            //Character Operations 

            //Drawing Points earned
            std::string counter="Points :"+std::to_string(Point);
            DrawText(counter.c_str(),WIDTH-200,0,32,WHITE);        
            
            //Drawing character on the screen
            Position forward_rect=Position::Normalize((cursor-rect1.pos))*14.0f;
            DrawLine(rect1.pos.GetX(),rect1.pos.GetY(),rect1.pos.GetX()+forward_rect.GetX(),rect1.pos.GetY()+forward_rect.GetY(),GREEN);
            DrawPoly({rect1.pos.GetX(),rect1.pos.GetY()},5,rect1.sizex,rect1.rotation,rect1.color);
            rect1.lookAt(cursor);
            
            //Character Movement
            if(IsCursorOnScreen()) cursor.Set(GetMouseX(),GetMouseY());
            user_coefficient=(Point>=25.0f) ?  (Point>=50.0f ? (Point>=65.0f ? 2.0f : 1.5f) : 1.25f) :1.0; 
            UserMovement(rect1,user_coefficient*190.0f,deltaTime);
            
            //Firing Mechanics     
                //SpawnBullet
                if(IsCursorOnScreen()&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){ 
                    bullets_shot++;
                    bullet_list.push_back(new Bullet(rect1.pos,GREEN,forward_rect));
                    PlaySound(shoot);
                } 

                //BROKEN MULTİPLE BULLET FIRING
                /*
                if(IsCursorOnScreen()&& IsMouseButtonDown(MOUSE_BUTTON_LEFT)){ 
                    if(GetTime()-timer4>=0.05f){
                        bullets_shot++;
                        bullet_list.push_back(new Bullet(rect1.pos,GREEN,forward_rect));
                        timer4=GetTime();
                    }
                    
                } */
                //Draw And Move All
                for(auto bullet: bullet_list){
                    bullet->Move(deltaTime);
                    bullet->Draw();
                }
                //Delete bullet if t second elapsed
        
                    for(int i=0;i<bullet_list.size();i++){
                        if(GetTime()-bullet_list[i]->timer>=1.0f){
                            if(bullet_list.size()>0){
                                Bullet *p=bullet_list.front();
                                bullet_list.erase(bullet_list.begin());
                                delete p;
                            }
                        }
                    }
            
            //Enemy Spawn Operations
            //Spawn Enemy
            
            if(GetTime()-timer2>t){
                srand(GetTime());
                
                int place=rand()%2;
                // rand()%(max-min+1)+min 
                //TOP
                if(place){
                    int coordx=rand()%(WIDTH-0+1)+0;
                    int coordy=rand()%(0+30+1)-30;
                    enemy_list.push_back(new Enemy(Position(coordx,coordy),{20.0f,20.0f},BLUE,100.0f*coefficient));
                }
                //BOTTOM
                else{
                    int coordx=rand()%(WIDTH-0+1)+0;
                    int coordy=rand()%(HEIGHT+30-HEIGHT+1)+HEIGHT;
                    enemy_list.push_back(new Enemy(Position(coordx,coordy),{20.0f,20.0f},BLUE,100.0f*coefficient));
                }
                timer2=GetTime();
            }
            
            if(GetTime()-timer3>t){
                srand(GetTime());
                
                int place=rand()%2;
                // rand()%(max-min+1)+min 
                //RIGHT
                if(place){
                    int coordx=rand()%(WIDTH+30-WIDTH+1)+WIDTH;
                    int coordy=rand()%(HEIGHT-0+1)+0;
                    enemy_list.push_back(new Enemy(Position(coordx,coordy),{20.0f,20.0f},BLUE,100.0f*coefficient));
                }
                //LEFT
                else{
                    int coordx=rand()%(0+30+1)-30;
                    int coordy=rand()%(HEIGHT-0+1)+0;
                    enemy_list.push_back(new Enemy(Position(coordx,coordy),{20.0f,20.0f},BLUE,100.0f*coefficient));
                }
                timer3=GetTime();
            }
            
            
            
            ///////////////////////////////////////////////////////////////////////
            
            //CollisionCheking 
            
            for (int j = 0; j < enemy_list.size(); j++)
            {
                //MOVEMENT OF ENEMY
                enemy_list[j]->MovePoint(rect1.pos,deltaTime);
                enemy_list[j]->Draw();
                
                //WHEN PLAYER COLLİDES ENEMY !!GAME END!!
                if(rect1.CheckCollision(*enemy_list[j],"enemy")){
                    enemy_list.clear();
                    bullet_list.clear();
                    isPaused=true;
                }
                
                
                //WHEN BULLET COLLİDES ENEMY !!POİNTS İNCREMENT!!  
                for (int i = 0; i < bullet_list.size(); i++)
                {
                    if (bullet_list[i]->CheckCollision(*enemy_list[j],"enemy"))
                    {
                        Bullet* p1=bullet_list[i];
                        bullet_list.erase(bullet_list.begin()+i);
                        delete p1;
                        
                        Enemy* p2=enemy_list[j];
                        enemy_list.erase(enemy_list.begin()+j);
                        delete p2;
                        
                        Point++;
                        goto break_loop;
                    }
                }
                break_loop:
                
            }                    
            //CollisionChecking Holding player on screen
            if(rect1.pos.GetX()>WIDTH-rect1.sizex){
                rect1.pos.GetX()=WIDTH-rect1.sizex;
            }if(rect1.pos.GetX()<rect1.sizex){
                rect1.pos.GetX()=rect1.sizex;
            }if(rect1.pos.GetY()>HEIGHT-rect1.sizex){
                rect1.pos.GetY()=HEIGHT-rect1.sizex;
            }if(rect1.pos.GetY()<rect1.sizex){
                rect1.pos.GetY()=rect1.sizex;
            }
            
        }
        EndDrawing();
            
        }
        UnloadMusicStream(m);
        UnloadSound(shoot);
    CloseWindow();

    return 0;
}
void UserMovement(Object& player,float speed,float deltaTime){
    if(IsKeyDown(KEY_W))player.pos.GetY()-=speed*deltaTime;
    if(IsKeyDown(KEY_S))player.pos.GetY()+=speed*deltaTime;
    if(IsKeyDown(KEY_A))player.pos.GetX()-=speed*deltaTime;
    if(IsKeyDown(KEY_D))player.pos.GetX()+=speed*deltaTime;
}

