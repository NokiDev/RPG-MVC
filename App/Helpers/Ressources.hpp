//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_RESSOURCES_HPP
#define RPG_MVC_RESSOURCES_HPP


#include <string>
#include <SFML/Graphics.hpp>

/**
 * @brief Ressources Helper for load Textures Once
 **/
class Ressources {
public:
    /*
     * @brief dtor
     */
    ~Ressources();

    /**
     * @brief load a texture if it was already load else load the texture
     * @param std::string TextureName
     */
    static sf::Texture &Load(std::string textureName);
    //static  Load(std::string fileName);
    // static sf::Shader & LoadShader(std::string shader);

private:
    static Ressources ressourcesLoader;
    std::map<std::string, sf::Texture> textures;

    sf::Texture &get(std::string index);

    void add(std::string index);

    bool exist(std::string index);
};


#endif //RPG_MVC_RESSOURCES_HPP
