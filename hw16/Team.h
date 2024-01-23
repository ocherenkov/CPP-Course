#include <string>

class Player;

const int MAX_PLAYERS = 10;

class Team {
public:
    Team(const std::string& name);
    bool addPlayer(Player* player);
    bool removePlayer(Player* player);
    void getInfo(bool isFullInfo = true) const;

private:
    std::string m_name;
    Player* m_Players[MAX_PLAYERS];
    int m_numPlayers;
};