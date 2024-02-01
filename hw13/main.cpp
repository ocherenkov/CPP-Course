#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

const int WORD_LENGTH = 5;
const int COUNT_ATTEMPS_FOR_GAME_TYPE = 10;
enum GameMode { EXIT, RANDOM, DAILY };
enum GameType { ENDLESS = 1, WITHATTEMPS = 2 };
int modeGame;
int typeGame;

const std::string dataFile = "daily_game.log";
const std::string wordsDatabase = "words.txt";

int getRandNumber(int maxNum = 0) {
    return std::rand() % maxNum;
}

std::vector<std::string> readWordsFromFile() {
    std::vector<std::string> words;
    std::ifstream file(wordsDatabase);

    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cerr << "Failed to open file: " << wordsDatabase << std::endl;
    }
    return words;
}

std::string formatDate() {
    char dateFormatted[11];
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* currentDate = std::localtime(&currentTimeT);
    std::strftime(dateFormatted, 11, "%Y-%m-%d", currentDate);
    return dateFormatted;
}

std::vector<std::string> splitString(const std::string& str, char delimiter){
    std::vector<std::string> result;
    std::string token;
    std::stringstream stream(str);
    while (getline(stream, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

std::string getRandomWord() {
    std::vector<std::string> words = readWordsFromFile();
    const int wordsCount = words.size();
    const int index = getRandNumber(wordsCount);
    return words[index];
}

// TODO "Won't cover more complex cases with duplicative letters". Change algorithm
void printWord(const std::string& word, const std::string& guessed) {
    for (int i = 0; i < WORD_LENGTH; ++i) {
        if (guessed[i] == word[i]) {
            std::cout << static_cast<char>(toupper(word[i])) << " ";
        } else if (guessed.find(word[i]) != std::string::npos) {
            std::cout << static_cast<char>(tolower(word[i])) << " ";
        } else {
            std::cout << "* ";
        }
    }
    std::cout << std::endl;
}

bool isWordGuessed(const std::string& word, const std::string& guessed) {
    return word == guessed;
}

void updateDailyGameData(const std::string& word, bool isGuessed = false) {
    std::ofstream file(dataFile);
    if (file.is_open()) {
        file << formatDate() << ";" << word << ";" << isGuessed;
    }
    file.close();
}

bool hasPlayedToday() {
    std::ifstream file(dataFile);
    if (file.is_open()) {
        std::string line;
        if (std::getline(file, line)) {
            std::vector<std::string> data = splitString(line, ';');
            std::string storedDate = data[0];
            std::string currentDate = formatDate();
            bool isDailyGameCompleted = static_cast<bool>(std::stoi(data[2]));

            return isDailyGameCompleted && storedDate == currentDate;
        }
    }
    return false;
}

GameMode SelectGameMode() {
    while (true) {
        std::cout << std::endl << CYAN << "[Select game mode]" << RESET << std::endl;
        std::cout << "1. " << YELLOW << "Wordle of the day" << RESET << std::endl << "2. " << BLUE << "Random Wordle" << RESET << std::endl << "0. " << RED << "Exit" << RESET << std::endl;
        std::cout << "Enter number: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                return GameMode::DAILY;
            case 2:
                return GameMode::RANDOM;
            case 0:
                return GameMode::EXIT;
            default:
                std::cout << RED << "Invalid choice." << RESET << " Please enter " << BLUE << "1" << RESET << " or " << BLUE << "2" << RESET << " for playing." << std::endl
                          << "For " << RED << "exit" << RESET << " enter " << RED << "0" << RESET << "." << std::endl;
        }
    }
}

GameType SelectGameType() {
    while (true) {
        std::cout << std::endl << CYAN << "[Select game type]" << RESET << std::endl;
        std::cout << "1. " << MAGENTA << "Endless" << RESET << std::endl << "2. " << YELLOW << COUNT_ATTEMPS_FOR_GAME_TYPE <<" attempts" << RESET << std::endl;
        std::cout << "Enter number: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                return GameType::ENDLESS;
            case 2:
                return GameType::WITHATTEMPS;
            default:
                std::cout << RED << "Invalid choice." << RESET << " Please enter " << BLUE << "1" << RESET << " or " << BLUE << "2" << RESET << " for playing." << std::endl;
        }
    }
}

void playGame(std::string secretWord) {
    std::string guessedWord;

    int attempts = 0;

    while (true) {
        std::cout << "Enter 5 letter word: ";
        std::string userGuess;
        std::cin >> userGuess;

        ++attempts;

        if (userGuess.length() != WORD_LENGTH) {
            std::cout << RED <<"Invalid input." << RESET << " Please enter " << RED << "5" << RESET << " letter word." << std::endl;
            continue;
        }

        guessedWord = userGuess;
        printWord(secretWord, guessedWord);

        if (isWordGuessed(secretWord, guessedWord)) {
            std::cout << BLUE << "Congratulations!" << RESET << " You guessed the word in " << BLUE << attempts << RESET << " attempts." << std::endl;
            break;
        }

        if (typeGame == GameType::WITHATTEMPS) {
            std::cout << MAGENTA << "Attempts left: " << COUNT_ATTEMPS_FOR_GAME_TYPE - attempts << "/" << COUNT_ATTEMPS_FOR_GAME_TYPE << RESET << std::endl;
            if (attempts == COUNT_ATTEMPS_FOR_GAME_TYPE) {
                std::cout << YELLOW << "The attempts are over." << RESET << std::endl << "There was word - " << CYAN << secretWord << RESET << std::endl;
                break;
            }
        }
    }
}

void initRandomGame() {
    std::string secretWord = getRandomWord();
    playGame(secretWord);
}

void initDailyGame() {
    if (hasPlayedToday()) {
        std::cout << YELLOW << "You've already played today. Try again tomorrow!" << RESET << std::endl;
    } else {
        std::string secretWord = getRandomWord();
        updateDailyGameData(secretWord);
        playGame(secretWord);
        updateDailyGameData(secretWord, true);
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << "Welcome to " << GREEN << "Wordle" << RESET << " Game!" << std::endl;

    while (true) {
        modeGame = SelectGameMode();
        if (modeGame == GameMode::EXIT) {
            std::cout << "Goodbye! Come back to play!";
            break;
        }
        typeGame = SelectGameType();
        if (modeGame == GameMode::DAILY) {
            initDailyGame();
        } else if (modeGame == GameMode::RANDOM) {
            initRandomGame();
        }
    }

    return 0;
}