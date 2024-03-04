#include "Config.h"

Config Config::instance;

Config& Config::getInstance() {
    return instance;
}

Config::Config() {}

std::string Config::getGameName() const {
    return gameName;
}

float Config::getWindowWidth() const {
    return windowWidth;
};

float Config::getWindowHeight() const {
    return windowHeight;
};

Highscore Config::getHighScore() {
    std::ifstream file(scoreFile);
    std::string info;
    std::getline(file, info, ',');
    highScore.playerLevel = std::stoi(info);
    std::getline(file, info, ',');
    highScore.score = std::stoi(info);
    std::getline(file, info);
    highScore.time = std::stoi(info);
    return highScore;
}

void Config::setHighScore(Highscore highscore, int playerLevel, int score, int time) {
    if (highscore.score < score) {
        std::ostringstream strData;
        strData << playerLevel << "," << score << "," << time;
        std::string highscoreString = strData.str();
        std::ofstream file(scoreFile);
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open highscore.ini");
        }
        file << highscoreString << std::endl;
    }
}

void Config::loadFromFile() {
    std::ifstream file(configFile);
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
        gameName = configValues["gameName"];
    }
    if (configValues.find("windowWidth") != configValues.end()) {
        windowWidth = std::atof(configValues["windowWidth"].c_str());
    }
    if (configValues.find("windowHeight") != configValues.end()) {
        windowHeight = std::atof(configValues["windowHeight"].c_str());
    }
}