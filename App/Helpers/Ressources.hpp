//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_RESSOURCES_HPP
#define RPG_MVC_RESSOURCES_HPP


#include <string>
#include <SFML/Graphics.hpp>

class Ressources {
public:

    ~Ressources();

    static sf::Texture & Load(std::string textureName);
    //static  Load(std::string fileName);
   // static sf::Shader & LoadShader(std::string shader);

private:
    static Ressources ressourcesLoader;
    std::map<std::string, sf::Texture> textures;
    //std::map<std::string, sf::Shader> shaders;
    sf::Texture &get(std::string index);

    void add(std::string index);

    bool exist(std::string index);
};


#endif //RPG_MVC_RESSOURCES_HPP
