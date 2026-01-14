#ifndef PHYSICS_CHECK
#define PHYSICS_CHECK

#include "GameObject.hpp"
#include <raylib.h>
class PhysicsCheck{
    public:
    static bool CheckBorderX(GameObject& obj1,float lowx,float highx){
        const Rectangle& collider=obj1.Collider();
        if(collider.x>=lowx && collider.x+collider.width <=highx){
            
            return true;
        }
        if(collider.x<lowx){
            obj1.Position().x=lowx;
        }else if(collider.x+collider.width >highx){
            obj1.Position().x=highx-collider.width;
        }
        return false;       
    }
    static bool CheckBorderY(GameObject& obj1,float lowy,float highy){
        const Rectangle& collider=obj1.Collider();
        if(collider.y>=lowy && collider.y+collider.height <=highy){
            return true;
        }
        if(collider.y<lowy){
            obj1.Position().y=lowy;
        }else if(collider.y+collider.height > highy){
            obj1.Position().y=highy-collider.height;
        }
        return false;       
    }
    static bool IsColliding(const Rectangle& rec1,const Rectangle& rec2){
        return CheckCollisionRecs(rec1,rec2);
    }
};
#endif