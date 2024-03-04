#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.h"
#include "Upgrade.h"
#include "AssetManager.h"

class UpgradeModal {
public:
    UpgradeModal(const std::vector<Upgrade>& upgrades);

    void show();
    void hide();
    bool isVisible() const;
    void handleClick(const sf::Vector2i& mousePosition);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape m_modalBackground;
    sf::Text m_text;
    std::vector<sf::Sprite> m_upgradeSprites;
    std::vector<Upgrade> m_upgrades;
    bool m_visible = false;
};