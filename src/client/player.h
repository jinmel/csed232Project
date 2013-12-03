#pragma once
#include <QString>
#include <list>
#include <map>
#include "block.h"
#include "types.h"
#include "qgameitem.h"

// circular dependency
class Block;

class Player : public QGameItem
{
private:
    int         id;
    QString     name;
    int         position;
    int         energy;
    bool        bankrupt;
    bool        mobile;                    // is player movable? (Mouindo, Drink...)
    int         penalty;                   // how long to be punished
    bool        plural;                    // plural major status
    int         totalownsubjectenergy;
    std::map<SubjectType::Type, int> registered;     // registered class for each subject
    std::list<Block*> own_blocks;
    CharacterType::Type character_type;

public:
    Player(QGameItem * parent,int id);
    ~Player();

    int  getPosition() const;
    int  getId() const;

    bool isBankrupt() const;
    bool isMobile() const;
    int  getEnergy() const;
    int  getPenalty() const;
    bool isPlural() const;
    int getTotalOwnSubjectEnergy() const;
    CharacterType::Type getType() const;
    std::list<Block*> getBlocks() const;

    void setType(CharacterType::Type new_type);
    void setEnergy(int getenergy);
    void setPlural(bool plural);
    void setMouindo(int penalty);
    bool escapeMouindo();

    void walkTo(int dice);
    void jumpTo(int block_num);

    void addTotalOwnSubjectEnergy(int subjectenergy);
    void setBankrupt(bool bankrupt);
    void pushBlock(Block* block);
    void removeBlock(Block* block);

    bool hasBlock(Block* block);
    void buyBlock(Block* block);
    void sellBlock(Block* block);
    void takeBlock(Block* block);
    void loseBlock(Block* block);
    void giveSalary();
    void payEnergy(int payenergy);
    void paidEnergy(int paidenergy);
    void takeEnergy(int paidenergy);

    bool checkWinStatus();

private:
    //void moveAnimation(int block_num);
};
      
