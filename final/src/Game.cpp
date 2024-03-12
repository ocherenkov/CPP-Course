#include "Game.h"

Game::Game() {
    Game::loadConfigs();
    Game::loadAssets();
    Game::createWindow();
    Game::setupBackground();
    Game::createButtons();
    Game::createPlayer();
    Game::createUpgradeModal();
    Game::createHighScoreBlock();
    Game::createTexts();
    Game::createTileMap();
    Game::setupSounds();
}

void Game::createWindow() {
    m_window.create(sf::VideoMode(config.getWindowWidth(), config.getWindowHeight()), config.getGameName());
    m_window.setFramerateLimit(60);
}

void Game::createButtons() {
    int offsetPosY = 0;
    m_startButton = new Button("Start", sf::Vector2f((m_window.getSize().x - assetManager.getTexture("button").getSize().x) / 2,
                                                     ((m_window.getSize().y - assetManager.getTexture("button").getSize().y) / 2) + offsetPosY));
    offsetPosY += 75;
    m_highscoreButton = new Button("Highscore", sf::Vector2f((m_window.getSize().x - assetManager.getTexture("button").getSize().x) / 2,
                                                                 ((m_window.getSize().y - assetManager.getTexture("button").getSize().y) / 2) + offsetPosY));
    offsetPosY += 75;
    m_exitButton = new Button("Exit", sf::Vector2f((m_window.getSize().x - assetManager.getTexture("button").getSize().x) / 2,
                                                                 ((m_window.getSize().y - assetManager.getTexture("button").getSize().y) / 2) + offsetPosY));
    offsetPosY += 75;
    m_backButton = new Button("Back", sf::Vector2f((m_window.getSize().x - assetManager.getTexture("button").getSize().x) / 2,
                                                   ((m_window.getSize().y - assetManager.getTexture("button").getSize().y) / 2) + offsetPosY));
}

void Game::createPlayer() {
    m_player = new Player();
}

void Game::resetPlayer() {
    delete m_player;
    m_player = new Player();
    Game::createUpgradeModal();
}

void Game::createUpgradeModal() {
    m_upgradeModal = new UpgradeModal(m_player->getUpgrades());
}

void Game::createHighScoreBlock() {
    m_highScoreBlock = new HighScoreBlock();
}

void Game::createTexts() {
    m_scoreText = new ScoreText();
    m_timeText = new TimeText();
    m_bossTimerText = new BossTimerText(m_bossTime);
}

void Game::resetTexts() {
    delete m_scoreText;
    delete m_timeText;
    delete m_bossTimerText;

    m_scoreText = new ScoreText();
    m_timeText = new TimeText();
    m_bossTimerText = new BossTimerText(m_bossTime);
}

void Game::createTileMap() {
    m_tileMap = new TileMap(config.getWindowWidth(), config.getWindowHeight(), 32);
}

void Game::setupSounds() {
    m_soundClick.setBuffer(assetManager.getSoundBuffer("buttonClick"));
    m_soundPlayerAttack.setBuffer(assetManager.getSoundBuffer("playerAttack"));
    m_soundEnemyDeath.setBuffer(assetManager.getSoundBuffer("enemyDeath"));
}

void Game::setupBackground() {
    m_backgroundSprite.setTexture(AssetManager::getInstance().getTexture("background"));
    float scaleX =
            m_window.getSize().x / static_cast<float>(AssetManager::getInstance().getTexture("background").getSize().x);
    float scaleY =
            m_window.getSize().y / static_cast<float>(AssetManager::getInstance().getTexture("background").getSize().y);
    m_backgroundSprite.setScale(scaleX, scaleY);
}

void Game::loadConfigs() {
    config.loadFromFile();
    m_highscore = config.getHighScore();
}

void Game::loadAssets() {
    // Fonts
    assetManager.loadFont("main", "./assets/fonts/pixel.otf");

    // Images
    assetManager.loadTexture("background", "./assets/textures/ui/background.png");
    assetManager.loadTexture("button", "./assets/textures/ui/button.png");
    assetManager.loadTexture("buttonHover", "./assets/textures/ui/button_hover.png");
    assetManager.loadTexture("frameHp", "./assets/textures/ui/frame_hp.png");
    assetManager.loadTexture("barHp", "./assets/textures/ui/bar_hp.png");
    assetManager.loadTexture("frameExp", "./assets/textures/ui/frame_exp.png");
    assetManager.loadTexture("barExp", "./assets/textures/ui/bar_exp.png");
    assetManager.loadTexture("m_score", "./assets/textures/ui/score.png");
    assetManager.loadTexture("time", "./assets/textures/ui/time.png");
    assetManager.loadTexture("playerLevel", "./assets/textures/ui/player_level.png");
    assetManager.loadTexture("block", "./assets/textures/ui/block.png");
    assetManager.loadTexture("m_player", "./assets/textures/player/player.png");
    assetManager.loadTexture("ground", "./assets/textures/ui/ground.png");
    assetManager.loadTexture("hyenaRun", "./assets/textures/enemies/hyena_run.png");
    assetManager.loadTexture("hyenaAttack", "./assets/textures/enemies/hyena_attack.png");
    assetManager.loadTexture("snakeRun", "./assets/textures/enemies/snake_run.png");
    assetManager.loadTexture("snakeAttack", "./assets/textures/enemies/snake_attack.png");
    assetManager.loadTexture("scorpioRun", "./assets/textures/enemies/scorpio_run.png");
    assetManager.loadTexture("scorpioAttack", "./assets/textures/enemies/scorpio_attack.png");
    assetManager.loadTexture("kingSlimeRun", "./assets/textures/enemies/king_slime_run.png");
    assetManager.loadTexture("kingSlimeAttack", "./assets/textures/enemies/king_slime_attack.png");
    assetManager.loadTexture("projectileMain", "./assets/textures/player/projectile_main.png");
    assetManager.loadTexture("experienceOrb", "./assets/textures/items/experience_orb.png");
    assetManager.loadTexture("healthPotion", "./assets/textures/items/health_potion.png");
    assetManager.loadTexture("chest", "./assets/textures/items/chest.png");
    assetManager.loadTexture("upgradeHp", "./assets/textures/ui/upgrade_hp.png");
    assetManager.loadTexture("upgradeAttackSpeed", "./assets/textures/ui/upgrade_attack_speed.png");
    assetManager.loadTexture("upgradeDamage", "./assets/textures/ui/upgrade_damage.png");
    assetManager.loadTexture("m_bossTimer", "./assets/textures/ui/boss_timer.png");

    // Sounds
    assetManager.loadSoundBuffer("buttonClick", "./assets/sounds/ui/button_click.wav");
    assetManager.loadSoundBuffer("playerAttack", "./assets/sounds/player/player_attack.wav");
    assetManager.loadSoundBuffer("enemyDeath", "./assets/sounds/enemies/enemy_death.wav");
}

void Game::addScore(int points) {
    m_score += points;
    m_scoreText->setScore(m_score);
}

void Game::run() {
    sf::Clock clock;
    while (m_window.isOpen()) {
        sf::Time dt = clock.restart();
        Game::processEvents();
        Game::update(dt.asSeconds());
        Game::draw();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonPressed:
                Game::handleMouseButtonPressed(event);
                break;
            case sf::Event::KeyPressed:
                Game::handleKeyPressed(event);
                break;
        }
    }
}

void Game::handleMouseButtonPressed(const sf::Event &event) {
    if (m_gameState == GameState::MainMenu || m_gameState == GameState::Paused || m_gameState == GameState::Highscore || m_gameState == GameState::GameOver) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (m_startButton->isMouseOver(m_window)) {
                if (m_gameState != GameState::Paused) {
                    m_bossTimer.restart();
                }
                if (m_gameState == GameState::GameOver) {
                    Game::resetGame();
                }
                Game::setState(GameState::InGame);
                m_soundClick.play();
            } else if (m_highscoreButton->isMouseOver(m_window)) {
                Game::setState(GameState::Highscore);
                m_soundClick.play();
            } else if (m_backButton->isMouseOver(m_window)) {
                Game::setState(GameState::MainMenu);
                m_soundClick.play();
            } else if (m_exitButton->isMouseOver(m_window)) {
                m_window.close();
                m_soundClick.play();
            }
        }
    }

    if (m_upgradeModal->isVisible() && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
        m_upgradeModal->handleClick(mousePos);
        m_soundClick.play();
    }
}

void Game::handleKeyPressed(const sf::Event &event) {
    if (event.key.code == sf::Keyboard::Escape) {
        if (m_gameState == GameState::InGame) {
            Game::setState(GameState::Paused);
        } else if (m_gameState == GameState::Paused) {
            Game::setState(GameState::InGame);
        }
    }
}

void Game::menuGame() {
    m_startButton->update(m_window);
    m_highscoreButton->update(m_window);
    m_exitButton->update(m_window);
}

void Game::highScoreWindow() {
    m_highScoreBlock->setHighScore(m_highscore);
    m_backButton->update(m_window);
}

void Game::resetGame() {
    m_score = 0;
    m_gameTimer.restart();
    m_bossTimer.restart();
    m_enemies.clear();
    m_items.clear();

    Game::resetPlayer();
    Game::resetTexts();
}

void Game::playGame(float deltaTime) {
    if (m_upgradeModal->isVisible()) {
        return;
    }

    Game::updateTimeText();
    Game::updatePlayer(deltaTime);
    Game::handleGameOver();
    Game::updateEnemies(deltaTime);
    Game::spawnBossIfNeeded();
    Game::spawnRandomEnemies();
    Game::shootAtClosestEnemy();
    Game::checkCollisions();
}

void Game::updatePlayer(float deltaTime) {
    if (m_player->isMoving()) {
        m_tileMap->update(deltaTime);
    }
    m_player->update(deltaTime);
}

void Game::updateTimeText() {
    m_timeText->setTime(m_gameTimer.getElapsedTime().asSeconds());
}

void Game::handleGameOver() {
    if (!m_player->isAlive()) {
        Game::setState(GameState::GameOver);
        config.setHighScore(m_highscore, m_player->getLevel(), m_score, m_gameTimer.getElapsedTime().asSeconds());
        m_highscore = config.getHighScore();
        return;
    }
}

void Game::updateEnemies(float deltaTime) {
    for (Enemy *enemy: m_enemies) {
        enemy->update(deltaTime);
    }
}

void Game::spawnBossIfNeeded() {
    m_bossTimerText->setTime(m_bossTimer.getElapsedTime().asSeconds());
    if (m_bossTimer.getElapsedTime().asSeconds() >= m_bossTime) {
        Game::spawnBoss();
    }
}

void Game::spawnBoss() {
    sf::Vector2f spawnPosition(0.f, 0.f);
    Enemy *boss = new KingSlime(m_player, spawnPosition);
    m_enemies.push_back(boss);
    m_bossTimer.restart();
}

void Game::spawnRandomEnemies() {
    if (m_enemies.size() < m_maxEnemies) {
        static sf::Clock clock;
        if (clock.getElapsedTime().asSeconds() > m_spawnInterval) {
            Game::spawnEnemyAtRandomPosition();
            clock.restart();
        }
    }
}

void Game::spawnEnemyAtRandomPosition() {
    sf::Vector2f spawnPosition;
    do {
        spawnPosition.x = rand() % (int) config.getWindowWidth();
        spawnPosition.y = rand() % (int) config.getWindowHeight();
    } while (Game::isTooCloseToPlayer(spawnPosition));

    m_enemies.push_back(Game::createRandomEnemy(m_player, spawnPosition));
}

bool Game::isTooCloseToPlayer(const sf::Vector2f &position) const {
    return position.x < m_player->getPosition().x - m_spawnRadius ||
           position.x > m_player->getPosition().x + m_spawnRadius ||
           position.y < m_player->getPosition().y - m_spawnRadius ||
           position.y > m_player->getPosition().y + m_spawnRadius;
}

void Game::shootAtClosestEnemy() {
    if (!m_enemies.empty()) {
        float minDistance = std::numeric_limits<float>::max();
        sf::Vector2f closestEnemyDirection;
        for (const auto &enemy: m_enemies) {
            sf::Vector2f direction = enemy->getPosition() - m_player->getPosition();
            float distance = sqrt(direction.x * direction.x + direction.y * direction.y);
            if (distance < minDistance) {
                minDistance = distance;
                closestEnemyDirection = direction;
            }
        }
        m_player->shoot(closestEnemyDirection);
    }
}

Enemy *Game::createRandomEnemy(Player *player, sf::Vector2f spawnPosition) {
    int type = std::rand() % 3;

    switch (type) {
        case 0:
            return new Hyena(player, spawnPosition);
        case 1:
            return new Snake(player, spawnPosition);
        case 2:
            return new Scorpio(player, spawnPosition);
        default:
            return new Hyena(player, spawnPosition);
    }
}

void Game::update(float deltaTime) {
    switch (m_gameState) {
        case GameState::MainMenu:
        case GameState::Paused:
        case GameState::GameOver:
            menuGame();
            break;
        case GameState::InGame:
            playGame(deltaTime);
            break;
        case GameState::Highscore:
            highScoreWindow();
            break;
    }
}

void Game::checkCollisions() {
    Game::handleProjectileCollisions();
    Game::handleItemCollisions();
    Game::removeDestroyedProjectiles();
    Game::removeDestroyedEnemies();
}

void Game::handleProjectileCollisions() {
    for (auto &projectile: m_player->getProjectiles()) {
        for (auto &enemy: m_enemies) {
            if (projectile.getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
                Game::handleProjectileCollision(projectile, *enemy);
            }
        }
    }
}

void Game::handleProjectileCollision(Projectile &projectile, Enemy &enemy) {
    m_soundPlayerAttack.play();
    enemy.takeDamage(projectile.getDamage());
    if (enemy.isDestroyed()) {
        Game::handleEnemyDestroyed(enemy);
    }
    projectile.destroy();
}

void Game::handleEnemyDestroyed(Enemy &enemy) {
    Game::addScore(enemy.getPoints());
    m_soundEnemyDeath.play();
    int dropChance = std::rand() % 100;
    if (dropChance < m_healthPotionDropChance) {
        Game::spawnHealthPotion(enemy.getPosition());
    }
    Game::spawnEnemyDropItem(enemy);
}

void Game::spawnHealthPotion(const sf::Vector2f &position) {
    Item *item = new HealthPotion();
    item->drop(position);
    m_items.push_back(item);
}

void Game::spawnEnemyDropItem(const Enemy &enemy) {
    Item *item = enemy.getDropItem();
    item->drop(enemy.getPosition());
    m_items.push_back(item);
}

void Game::handleItemCollisions() {
    for (auto it = m_items.begin(); it != m_items.end();) {
        if (m_player->getSprite().getGlobalBounds().intersects((*it)->getSprite().getGlobalBounds())) {
            bool showUpgradeModal = (*it)->collect(m_player);
            if (showUpgradeModal) {
                m_upgradeModal->show();
                m_player->clearLevelUpFlag();
            }
            it = m_items.erase(it);
        } else {
            it++;
        }
    }
}

void Game::removeDestroyedProjectiles() {
    m_player->getProjectiles().erase(std::remove_if(m_player->getProjectiles().begin(), m_player->getProjectiles().end(), [](const Projectile &projectile) { return projectile.isDestroyed(); }), m_player->getProjectiles().end());
}

void Game::removeDestroyedEnemies() {
    m_enemies.erase(std::remove_if(m_enemies.begin(), m_enemies.end(), [](const Enemy *enemy) { return enemy->isDestroyed(); }), m_enemies.end());
}

void Game::setState(GameState newState) {
    m_gameState = newState;
}

void Game::draw() {
    m_window.clear();
    switch (m_gameState) {
        case GameState::MainMenu:
            m_window.draw(m_backgroundSprite);
            m_startButton->draw(m_window);
            m_highscoreButton->draw(m_window);
            m_exitButton->draw(m_window);
            break;
        case GameState::InGame:
            m_tileMap->draw(m_window);
            m_scoreText->draw(m_window);
            m_timeText->draw(m_window);
            m_bossTimerText->draw(m_window);
            m_player->draw(m_window);
            for (Enemy *enemy: m_enemies) {
                enemy->draw(m_window);
            }
            for (Item *item: m_items) {
                item->draw(m_window);
            }
            m_upgradeModal->draw(m_window);
            break;
        case GameState::Highscore:
            m_window.draw(m_backgroundSprite);
            m_highScoreBlock->draw(m_window);
            m_backButton->draw(m_window);
            break;
        case GameState::Paused:
        case GameState::GameOver:
            m_window.draw(m_backgroundSprite);
            m_scoreText->draw(m_window);
            m_timeText->draw(m_window);
            m_startButton->draw(m_window);
            m_highscoreButton->draw(m_window);
            m_exitButton->draw(m_window);
            break;
    }
    m_window.display();
}