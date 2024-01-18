#include <iostream>
#include <ctime>
#include <cstdlib>

const int maxNum = 50;
const int minNum = 0;

int getRandNumber() {
    return std::rand() % (maxNum + 1);  // 0 - 50
}

int main() {
    std::srand(std::time(nullptr));

    int randNumber = getRandNumber();
    int highscore = INT_MAX;
    int attempts = 0;

    std::cout << "Start of the game 'Guess the number'." << std::endl;
    std::cout << "Rules: I guess a number from " << minNum << " to " << maxNum << " and wait for your answer!" << std::endl;


    while (true) {
        int guess;
        std::cout << "I guessed a number, can you guess it?\nEnter -1 to end the game.\nYour answer: ";
        std::cin >> guess;

        if (guess == -1) {
            std::cout << "Game over!" << std::endl;
            break;
        }

        if (guess < minNum || guess > maxNum) {
            std::cout << "Have you read the rules?"<< std::endl;
            std::cout << "I guessed a number from" << minNum << " to " << maxNum << ". Try again." << std::endl;
            std::cout << "Your answer: ";
            continue;
        }

        attempts++;

        if (guess == randNumber) {
            std::cout << std::endl << "Winning! You guessed the number!" << std::endl;
            std::cout << "Number of attempts: " << attempts << std::endl;

            if (attempts < highscore) {
                highscore = attempts;
                std::cout << "New highscore! Congratulations! @->--" << std::endl << std::endl;
            }

            randNumber = getRandNumber();
            attempts = 0;

        } else {
            if (guess > randNumber + 20) {
                std::cout << "Your number is too high. Try less." << std::endl;
            } else if (guess > randNumber + 10) {
                std::cout << "Your number is bit high. Try less." << std::endl;
            } else if (randNumber > guess + 20) {
                std::cout << "Your number is too small. Try more." << std::endl;
            } else if (randNumber > guess + 10) {
                std::cout << "Your number is bit small. Try more." << std::endl;
            }
        }
    }

    return 0;
}