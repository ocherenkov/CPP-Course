#include "TileMap.h"

TileMap::TileMap(int screenWidth, int screenHeight, int tileSize)
        : screenWidth(screenWidth), screenHeight(screenHeight), tileSize(tileSize) {
    sf::Sprite sprite;
    for (int i = 0; i < screenHeight / tileSize + 2; ++i) {
        for (int j = 0; j < screenWidth / tileSize; ++j) {
            sprite.setTexture(AssetManager::getInstance().getTexture("ground"));
            sprite.setPosition(static_cast<float>(j * tileSize), static_cast<float>(i * tileSize));
            tiles.push_back(sprite);
        }
    }
}

void TileMap::update(float deltaTime) {
    for (auto& tile : tiles) {
        tile.move(0, speed * deltaTime);
        if (tile.getPosition().y >= screenHeight) {
            tile.setPosition(tile.getPosition().x, tile.getPosition().y - screenHeight - tileSize);
        }
    }
}

void TileMap::draw(sf::RenderWindow& window) {
    for (const auto& tile : tiles) {
        window.draw(tile);
    }
}
