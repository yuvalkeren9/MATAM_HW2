//
// Created by eladm on 02/05/2022.
//

#include "Player.h"
#include <iostream>
#include <cassert>

using std::cout;
using std::endl;
using std::string;

Player::Player(const string& name, const int maxHP, const int force) :
    m_name(name),
    m_level(1),
    m_force(force),
    m_maxHP(maxHP),
    m_HP(maxHP),
    m_coins(0)
{
    if (maxHP <= 0){
        this->m_maxHP = DEFAULT_MAX_HP;
        this->m_HP = DEFAULT_MAX_HP;
    }
    if (force < 0){
        this->m_force = DEFAULT_FORCE;
    }
}

void Player::printInfo() const {
    const char* nameSent = m_name.c_str();     //converting from string type to char* type
    printPlayerInfo(nameSent, this->m_level, this->m_force, this->m_HP, this->m_coins);
    //delete[] nameSent;
}

Player& Player::levelUp(){
    if (this->m_level <10 ){
        ++this->m_level;
    }
    return *this;
}

int Player::getLevel() const{
    return this->m_level;
}

Player& Player::buff(const int addedForce){
    assert(addedForce >= 0);
    if (addedForce < 0){
        return *this;
    }
    this->m_force += addedForce;
    return *this;
}

Player& Player::heal(const int addedHP){
    assert(addedHP >=0);
    if (addedHP < 0){
        return *this;
    }
    if(this->m_HP + addedHP >= this->m_maxHP){
        this->m_HP = this->m_maxHP;
    }
    else{
        this->m_HP += addedHP;
    }
    return *this;
}

Player& Player::damage(const int damageInflicted){
    assert(damageInflicted >= 0);
    if (damageInflicted < 0){
        return *this;
    }
    if (this->m_HP - damageInflicted <= 0){
        this->m_HP =0;
    }
    else {
        this->m_HP -= damageInflicted;
    }
    return *this;
}

bool Player::isKnockedOut() const{
    return !(this->m_HP);
}

Player& Player::addCoins(const int numOfCoins){
    assert(numOfCoins);
    if (numOfCoins < 0){
        return *this;
    }
    this->m_coins += numOfCoins;
    return *this;
}
bool Player::pay(const int price){
    assert (price >= 0);
    if (price <= 0){
        return true;
    }
    if (this->m_coins < price){
        return false;
    }
    this->m_coins -= price;
    return true;
}

int Player::getAttackStrength() const{
    return (this->m_level + this->m_force);
}