#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <iomanip>
#include <sstream>
#include "Config.h"
#include "AssetManager.h"
#include "TileMap.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Item.h"
#include "UI/Button.h"
#include "UI/DisplayText.h"
#include "UI/UpgradeModal.h"
#include "UI/HighScoreBlock.h"

enum class GameState {
    MainMenu,
    InGame,
    Paused,
    Highscore,
    GameOver
};

class Game {
public:
    Game();

    void run();

private:
    sf::RenderWindow m_window;
    sf::Sprite m_backgroundSprite;
    GameState m_gameState = GameState::MainMenu;
    TileMap* m_tileMap;
    Player* m_player;
    std::vector<Enemy*> m_enemies;
    std::vector<Item*> m_items;
    Button* m_startButton;
    Button* m_highscoreButton;
    Button* m_backButton;
    Button* m_exitButton;
    HighScoreBlock* m_highScoreBlock;
    const int m_maxEnemies = 50;
    const float m_spawnRadius = 500.f;
    float m_spawnInterval = 0.7f;
    ScoreText* m_scoreText;
    int m_score = 0;
    sf::Clock m_gameTimer;
    sf::Clock m_bossTimer;
    BossTimerText* m_bossTimerText;
    int m_bossTime = 120;
    TimeText* m_timeText;
    UpgradeModal* m_upgradeModal;
    int m_healthPotionDropChance = 15;
    sf::Sound m_soundClick;
    sf::Sound m_soundPlayerAttack;
    sf::Sound m_soundEnemyDeath;
    Config& config = Config::getInstance();
    AssetManager& assetManager = AssetManager::getInstance();
    Highscore m_highscore;

    void loadConfigs();
    void loadAssets();
    void createWindow();
    void createButtons();
    void createPlayer();
    void createUpgradeModal();
    void createHighScoreBlock();
    void createTexts();
    void createTileMap();
    void setupSounds();
    void setupBackground();
    void addScore(int points);
    void processEvents();
    void handleMouseButtonPressed(const sf::Event& event);
    void handleKeyPressed(const sf::Event& event);
    void menuGame();
    void highScoreWindow();
    void playGame(float deltaTime);
    void update(float deltaTime);
    void updatePlayer(float deltaTime);
    void updateTimeText();
    void handleGameOver();
    void updateEnemies(float deltaTime);
    void spawnBossIfNeeded();
    void spawnBoss();
    void spawnRandomEnemies();
    Enemy* createRandomEnemy(Player* player, sf::Vector2f spawnPosition);
    void spawnEnemyAtRandomPosition();
    bool isTooCloseToPlayer(const sf::Vector2f& position) const;
    void shootAtClosestEnemy();
    void checkCollisions();
    void handleProjectileCollisions();
    void handleProjectileCollision(Projectile& projectile, Enemy& enemy);
    void handleEnemyDestroyed(Enemy& enemy);
    void spawnHealthPotion(const sf::Vector2f& position);
    void spawnEnemyDropItem(const Enemy& enemy);
    void handleItemCollisions();
    void removeDestroyedProjectiles();
    void removeDestroyedEnemies();
    void setState(GameState newState);
    void resetGame();
    void resetPlayer();
    void resetTexts();
    void draw();
};