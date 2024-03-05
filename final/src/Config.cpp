#include "Config.h"

Config& Config::getInstance() {
    static Config instance;
    return instance;
}

std::string Config::getGameName() const {
    return m_gameName;
}

float Config::getWindowWidth() const {
    return m_windowWidth;
};

float Config::getWindowHeight() const {
    return m_windowHeight;
};

Highscore Config::getHighScore() {
    std::ifstream file(m_scoreFile);
    std::string info;
    std::getline(file, info, ',');
    m_highScore.playerLevel = std::stoi(info);
    std::getline(file, info, ',');
    m_highScore.score = std::stoi(info);
    std::getline(file, info);
    m_highScore.time = std::stoi(info);
    return m_highScore;
}

void Config::setHighScore(Highscore highscore, int playerLevel, int score, int time) {
    if (highscore.score < score) {
        std::ostringstream strData;
        strData << playerLevel << "," << score << "," << time;
        std::string highscoreString = strData.str();
        std::ofstream file(m_scoreFile);
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open highscore.ini");
        }
        file << highscoreString << std::endl;
    }
}

void Config::loadFromFile() {
    std::ifstream file(m_configFile);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open config.ini");
    }

    std::unordered_map<std::string, std::string> configValues;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream str(line);
        std::string key, value;
        if (std::getline(str, key, '=')) {
            if (std::getline(str, value)) {
                configValues[key] = value;
            }
        }
    }
    file.close();

    if (configValues.find("gameName") != configValues.end()) {
        m_gameName = configValues["gameName"];
    }
    if (configValues.find("windowWidth") != configValues.end()) {
        m_windowWidth = std::atof(configValues["windowWidth"].c_str());
    }
    if (configValues.find("windowHeight") != configValues.end()) {
        m_windowHeight = std::atof(configValues["windowHeight"].c_str());
    }
}