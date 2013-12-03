#pragma once
#include <QString>
#include <list>
#include <map>
#include "block.h"
#include "types.h"
#include "qgameitem.h"

// circular dependency
class Block;

class Player;

class Player : public QGameItem
{
    Q_OBJECT
private:
    int         id;
    QString     name;
    int         position;
    int         energy;
    bool        bankrupt;
    bool        mobile;                    // is player movable? (Mouindo, Drink...)
    int         penalty;                   // how long to be punished
    bool        plural;                    // plural major status
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
    CharacterType::Type getType() const;
    std::list<Block*> getBlocks() const;
    int getAssetValue() const;

    void setType(CharacterType::Type new_type);
    void setEnergy(int getenergy);
    void setPlural(bool plural);
    void setMouindo(int penalty);
    void setMobile(bool mobile);
    bool escapeMouindo();

    void setBankrupt();
    bool hasBlock(Block* block);
    void addBlock(Block* block);
    void removeBlock(Block* block);
    void giveSalary();
    void payEnergy(int payenergy);
    void giveEnergy(int paidenergy);
    bool checkWinStatus();
    QPointF adjustCoord(QPointF & coord);

signals:
    void playerArrived(Player * player);
public slots:
    void arrived();
    void walkBy(int dice);
    void jumpTo(int block_num);

};
      
