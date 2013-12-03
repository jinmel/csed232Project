#include "sellpopup.h"
#include "ui_sellpopup.h"
#include <list>
#include "subjectblock.h"

Sellpopup::Sellpopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sellpopup)
{
    ui->setupUi(this);
    layout = new QVBoxLayout(ui->scrollAreaWidgetContents);

    /*
    Player* player = new Player(new QGameItem(), 1);

    std::list<Block*> block_list = player->getBlocks();
    SubjectBlock** blocks = new SubjectBlock*[block_list.size()];
    checks = new QCheckBox*[block_list.size()];

    int index = 0;
    for(std::list<Block*>::iterator itor = block_list.begin(); itor != block_list.end(); itor++) {
        blocks[index] = (SubjectBlock*)*itor;
        index++;
    }

    for(int i=0; i < block_list.size(); i++) {
        QString string = "Test";

        // append department
        string +=  convertDept(blocks[i]->getDept());

        string += " - ";

        // append Subject name
        string += blocks[i]->getName();

        string += " - ";

        // append grade
        string += convertGrade(blocks[i]->getGrade());
        
        QCheckBox* newCheck = new QCheckBox();
        newCheck->setText(string);

        checks[i] = newCheck;
        layout->addWidget(newCheck);
    }
    */

    for(int i=0; i < 10; i++) {
        QString string = "Test";


        QCheckBox* newCheck = new QCheckBox();
        newCheck->setText(string);

        checks[i] = newCheck;
        layout->addWidget(newCheck);
    }


}

Sellpopup::~Sellpopup()
{
    delete ui;
}


QString Sellpopup::convertDept(SubjectType::Type type)
{
    QString dept = "";

    switch(type) {
        using namespace SubjectType;
        case CSED:
            dept += "컴공과";
            break;
        case ME:
            dept += "기계과";
            break;
        case MATH:
            dept += "수학과";
            break;
        case EE:
            dept += "전자과";
            break;
        case PHYS:
            dept += "물리과";
            break;
        case BIO:
            dept += "생명과";
            break;
        case CHEM:
            dept += "화학과";
            break;
        case IME:
            dept += "산경과";
            break;
    }

    return dept;
}

QString Sellpopup::convertGrade(int grade)
{
    QString str = "";

    switch(grade) {
        case 2:
            str += "C";
            break;
        case 3:
            str += "B";
            break;
        case 4:
            str += "A";
            break;
    }  

    return str;
}
