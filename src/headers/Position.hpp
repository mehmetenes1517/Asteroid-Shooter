#ifndef POSITION_HPP
#define POSITION_HPP
#include "raylib.h"
class Position{
    private:
    
        Vector2 point;

    public:



        Position();
        Position(float x,float y);
        Position(Position& p);

        Vector2& GetPoint();

        static float Distance(Position p1,Position p2);
        static Position Normalize(Position p1);
        static float Magnitude(Position p1);


        float Distance(Position &p);

        void Set(float x,float y);
        float& GetX();
        float& GetY();
        Position operator-(Position& p);
        Position operator*(float p);
        Position operator+(Position& p);
};
#endif