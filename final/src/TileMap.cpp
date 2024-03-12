#include "TileMap.h"

TileMap::TileMap(int screenWidth, int screenHeight, int tileSize)
        : m_screenWidth(screenWidth), m_screenHeight(screenHeight), m_tileSize(tileSize) {
    sf::Sprite sprite;
    for (int i = 0; i < screenHeight / tileSize + 2; ++i) {
        for (int j = 0; j < screenWidth / tileSize; ++j) {
            sprite.setTexture(AssetManager::getInstance().getTexture("ground"));
            sprite.setPosition(static_cast<float>(j * tileSize), static_cast<float>(i * tileSize));
            m_tiles.push_back(sprite);
        }
    }
}

void TileMap::update(float deltaTime) {
    for (auto& tile : m_tiles) {
        tile.move(0, m_speed * deltaTime);
        if (tile.getPosition().y >= m_screenHeight) {
            tile.setPosition(tile.getPosition().x, tile.getPosition().y - m_screenHeight - m_tileSize);
        }
    }
}

void TileMap::draw(sf::RenderWindow& window) {
    for (const auto& tile : m_tiles) {
        window.draw(tile);
    }
}
