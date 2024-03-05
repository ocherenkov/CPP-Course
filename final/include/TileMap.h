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
    std::vector<sf::Sprite> m_tiles;
    int m_screenWidth;
    int m_screenHeight;
    int m_tileSize;
    float m_speed = 100.0f;
};