#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER
#include <map>
#include <raylib.h>
#include <string>
class GameController{
    private:
        std::string title;
        float width,height;
        std::map<std::string, Model> models;  
        std::map<std::string, Texture2D> textures;  
        std::map<std::string, Sound> sounds;  
        std::map<std::string, Music> musics;  
    public:
        GameController(const std::string& title,float width,float height);
        void Init();
        float Width();
        float Height();
        std::map<std::string, Texture2D>& GetTextures();
        std::map<std::string, Sound>& GetSounds();
        std::map<std::string, Music>& GetMusics();
};

#endif