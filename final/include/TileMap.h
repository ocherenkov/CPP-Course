#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"
#include "AssetManager.h"

class TileMap {
public:
    TileMap(int screenWidth, int screenHeight, int tileSize);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    std::vector<sf::Sprite> tiles;
    int screenWidth;
    int screenHeight;
    int tileSize;
    float speed = 100.0f;
};

//#include "Config.h"
//
//class TileMap {
//public:
//    TileMap(int screenWidth, int screenHeight, int tileSize):
//            screenWidth(screenWidth), screenHeight(screenHeight), tileSize(tileSize) {
//        sf::Sprite m_sprite;
//        for (int i = 0; i < screenHeight / tileSize + 2; ++i) {
//            for (int j = 0; j < screenWidth / tileSize; ++j) {
//                m_sprite.setTexture(AssetManager::getInstance().getTexture("ground"));
//                m_sprite.setPosition(static_cast<float>(j * tileSize), static_cast<float>(i * tileSize));
//                tiles.push_back(m_sprite);
//            }
//        }
//    }
//
//    void update(float deltaTime) {
//        for (auto& tile : tiles) {
//            tile.move(0, m_speed * deltaTime);
//            if (tile.getPosition().y >= screenHeight) {
//                tile.setPosition(tile.getPosition().x, tile.getPosition().y - screenHeight - tileSize);
//            }
//        }
//    }
//
//    void draw(sf::RenderWindow& m_window) {
//        for (const auto& tile : tiles) {
//            m_window.draw(tile);
//        }
//    }
//
//private:
//    std::vector<sf::Sprite> tiles;
//    int screenWidth;
//    int screenHeight;
//    int tileSize;
//    float m_speed = 100.0f;
//};