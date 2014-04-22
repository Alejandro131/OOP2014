#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
    Player(const char*);
    Player(const Player&);
    ~Player();

    Player& operator=(const Player&);

    const char* getNickname() const;
    double getScore() const;

    void addScore(double);

private:
    double score;
    char* nickname;

    void copy(const Player&);
    void del();
};

#endif
