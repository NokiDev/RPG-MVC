//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#include "Ressources.hpp"

Ressources Ressources::ressourcesLoader;

sf::Texture &Ressources::Load(std::string textureName) {
    if(!ressourcesLoader.exist(textureName))
    {
        ressourcesLoader.add(textureName);
    }
    return ressourcesLoader.get(textureName);
}

Ressources::~Ressources() {
    textures.clear();
}


sf::Texture &Ressources::get(std::string index) {
    return textures[index];
}

void Ressources::add(std::string index) {
    sf::Texture texture;
    texture.loadFromFile("Ressources/sprites/"+ index);
    textures[index] = texture;
}

bool Ressources::exist(std::string index) {
    return textures.find(index) != textures.end();
}
