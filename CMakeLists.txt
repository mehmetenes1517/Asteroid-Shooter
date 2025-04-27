cmake_minimum_required(VERSION 3.5.0)
project(GameProject VERSION 1.0.0)



add_executable(GameProject 
    src/main.cpp
    
    src/headers/Object.hpp
    src/implementings/Object.cpp

    src/headers/Position.hpp 
    src/implementings/Position.cpp

    src/headers/Bullet.hpp
    src/implementings/Bullet.cpp

    src/headers/Enemy.hpp
    src/implementings/Enemy.cpp

    
    )

target_link_libraries(GameProject raylib GL dl)