#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <glm/ext/vector_float2.hpp>
#include <glm/glm.hpp>
#include <raylib.h>
class GameObject{
    protected:
        
        glm::vec2 position=glm::vec2(0.0f,0.0f);
        float rotation=0.0f;
        float scale=1.0f;
        
        Texture2D& tex;

        glm::vec2 velocity=glm::vec2(0.0f,0.0f);
        Rectangle collider;
        
    public:
        GameObject(Texture2D& tex);
        void PhysicsUpdate(float deltaTime);
        void Translate(const glm::vec2& forward);
        void Rotate(float speed);
        void Update(float deltaTime);
        
        glm::vec2 Velocity() const;
        glm::vec2& Velocity();
        void Velocity(const glm::vec2& velocity);
        glm::vec2 Position() const; 
        glm::vec2& Position();
        void Position(const glm::vec2& pos); 
        float Rotation() const;
        float& Rotation();
        void Rotation(float rot);
        float Scale()const;
        float& Scale();
        void Scale(float scale);

        Rectangle Collider() const;

};

#endif