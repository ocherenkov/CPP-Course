#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

struct Highscore {
    int playerLevel;
    int score;
    int time;
};

class Config {
public:
    static Config& getInstance();

    std::string getGameName() const;
    float getWindowWidth() const;
    float getWindowHeight() const;
    Highscore getHighScore();
    void setHighScore(Highscore highscore, int level, int score, int time);
    void loadFromFile();

private:
    std::string m_configFile = "./resources/config.ini";
    std::string m_scoreFile = "./resources/highscore.ini";
    std::string m_gameName;
    float m_windowWidth;
    float m_windowHeight;
    Highscore m_highScore;
};