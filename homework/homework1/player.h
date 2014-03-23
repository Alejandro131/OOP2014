#ifndef PLAYER_H
#define PLATER_H

class Player
{
public:
    Player(char* name, char* nickname, int score=0);
    Player(const Player& other);

    char* get_name() const;
    char* get_nickname() const;

    int get_score() const;
    void add_score(int points);

private:
    char* name;
    char* nickname;
    int score;
};

#endif
