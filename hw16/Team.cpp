#include "Team.h"
#include "Player.h"
#include <iostream>

Team::Team(const std::string& name) : m_name(name), m_numPlayers(0) {}

bool Team::addPlayer(Player* player) {
    if (m_numPlayers < MAX_PLAYERS) {
        m_Players[m_numPlayers++] = player;
        player->setTeam(this);
        return true;
    }
    return false;
}

bool Team::removePlayer(Player* player) {
    for (int i = 0; i < m_numPlayers; i++) {
        if (m_Players[i] == player) {
            for (int j = i; j < m_numPlayers - 1; j++) {
                m_Players[j] = m_Players[j + 1];
            }
            m_numPlayers--;
            player->setTeam(nullptr);
            return true;
        }
    }
    return false;
}

void Team::printTeamName() const {
    std::cout << "| Team \\-_-/\\-_-/ |" << std::endl;
    std::cout << "Name: " << m_name << std::endl;
}

void Team::printTeamFullInfo() const {
    std::cout << "| Team \\-_-/\\-_-/ |" << std::endl;
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Number of players: " << m_numPlayers << std::endl;
}