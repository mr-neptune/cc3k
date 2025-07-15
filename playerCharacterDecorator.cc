#include "PlayerCharacterDecorator.h"

PlayerCharacterDecorator::PlayerCharacterDecorator(PlayerCharacter* player)
    : PlayerCharacter(player->getXCoor(), player->getYCoor(), player->getBelow()), basePlayer(player) {}

PlayerCharacterDecorator::~PlayerCharacterDecorator() {
    delete basePlayer;
}

PlayerCharacter* PlayerCharacterDecorator::getBase() {
    return basePlayer->getBase();
}


// -------- these need to be overridden in specific decorators ---------
int PlayerCharacterDecorator::getAtk() const {
    return basePlayer->getAtk();
}

int PlayerCharacterDecorator::getDef() const {
    return basePlayer->getDef();
}
// ---------------------------------------------------------------------

/*
void PlayerCharacterDecorator::attack(EnemyCharacter &enemy) {
    basePlayer->attack(enemy);
}

void PlayerCharacterDecorator::isAttackedBy(EnemyCharacter &enemy) {
    basePlayer->isAttackedBy(enemy);
}

int PlayerCharacterDecorator::getGold() const {
    return basePlayer->getGold();
}

void PlayerCharacterDecorator::setGold(int increase) {
    basePlayer->setGold(increase);
}

void PlayerCharacterDecorator::pickupGold(Gold &gold) {
    basePlayer->pickupGold(gold);
}

void PlayerCharacterDecorator::moveTo(int x, int y) {
    basePlayer->moveTo(x, y);
}

void PlayerCharacterDecorator::die() {
    basePlayer->die();
}
*/
