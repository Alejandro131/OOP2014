#include <cstring>

#include "Player.hpp"

Player::Player(const char* _nickname):
    score(0)
{
    nickname = new char[strlen(nickname) + 1];
    strcpy(nickname, _nickname);
}

Player::Player(const Player& other)
{
    copy(other);
}

Player::~Player()
{
    del();
}

Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        del();
        copy(other);
    }

    return *this;
}

const char* Player::getNickname() const
{
    return nickname;
}

double Player::getScore() const
{
    return score;
}

void Player::addScore(double _score)
{
    score += _score;
}

void Player::copy(const Player& other)
{
    score = other.score;

    nickname = new char[strlen(other.nickname) + 1];
    strcpy(nickname, other.nickname);
}

void Player::del()
{
    delete[] nickname;
}
