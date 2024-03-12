#include "AssetManager.h"

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}

void AssetManager::loadTexture(const std::string& name, const std::string& filename) {
    sf::Texture texture;
    if (texture.loadFromFile(filename)) {
        m_textures[name] = texture;
    }
}

sf::Texture& AssetManager::getTexture(const std::string& name) {
    return m_textures.at(name);
}

void AssetManager::loadFont(const std::string& name, const std::string& filename) {
    sf::Font font;
    if (font.loadFromFile(filename)) {
        m_fonts[name] = font;
    }
}

sf::Font& AssetManager::getFont(const std::string& name) {
    return m_fonts.at(name);
}

void AssetManager::loadSoundBuffer(const std::string& name, const std::string& filename) {
    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(filename)) {
        m_soundBuffers[name] = buffer;
    }
}

sf::SoundBuffer& AssetManager::getSoundBuffer(const std::string& name) {
    return m_soundBuffers.at(name);
}