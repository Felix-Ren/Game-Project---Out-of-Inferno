/** @file b4.cpp
 *  @brief Stores implementations of B4 class.
 *
 *  This file contains implementations of constructors and other member functions.
 */

#include "b4.h"
#include "ui_b4.h"
#include <random>
#include <chrono>
#include "b3.h"
#include "debug.h"
#include "diedialog.h"

// Create a seed from the time
unsigned int seed2 = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator2(seed2);

B4::B4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::B4)
{
    ui->setupUi(this);

    const QString levelName = "B4";
    ui->level_label->setText(levelName);

    // Define pictures for props and add them to labels
    // Obstacles (tombs and coffins)
    RIP_pic = new QPixmap(":/pic/RIP_icon.png");
    ui->RIP1->setPixmap(*RIP_pic);
    ui->RIP1->setScaledContents(true);

    ui->RIP2->setPixmap(*RIP_pic);
    ui->RIP2->setScaledContents(true);

    ui->RIP3->setPixmap(*RIP_pic);
    ui->RIP3->setScaledContents(true);

    ui->RIP4->setPixmap(*RIP_pic);
    ui->RIP4->setScaledContents(true);

    coffin_pic = new QPixmap(":/pic/coffin_icon2.png");
    ui->coffin1->setPixmap(*coffin_pic);
    ui->coffin1->setScaledContents(true);

    ui->coffin2->setPixmap(*coffin_pic);
    ui->coffin2->setScaledContents(true);


    QPixmap* player_pic = new QPixmap(":/pic/player_icon.png");
    ui->player_label->setPixmap(*player_pic);
    ui->player_label->setScaledContents(true);

    // Zombies
    QPixmap* zombie1_pic = new QPixmap(":/pic/zombie1.png");
    ui->zombie_label_1->setPixmap(*zombie1_pic);
    ui->zombie_label_1->setScaledContents(true);

    QPixmap* zombie2_pic = new QPixmap(":/pic/zombie2.png");
    ui->zombie_label_2->setPixmap(*zombie2_pic);
    ui->zombie_label_2->setScaledContents(true);

    ui->zombie_label_3->setPixmap(*zombie2_pic);
    ui->zombie_label_3->setScaledContents(true);


    QPixmap* ladder_pic = new QPixmap(":/pic/ladder.png");
    ui->ladder_label->setPixmap(*ladder_pic);
    ui->ladder_label->setScaledContents(true);

    QPixmap* background_pic = new QPixmap(":/pic/stage_background.jpg");
    ui->stage_background_label->setPixmap(*background_pic);
    ui->stage_background_label->setScaledContents(true);

    QPixmap* player_pic_left = new QPixmap(":/pic/player_icon_left.png");
    ui->player_label_2->setPixmap(*player_pic_left);
    ui->player_label_2->setScaledContents(true);

    // Default the turn-left-player image to be invisible
    ui->player_label_2->hide();

    margin = new QLabel;
    margin->setGeometry(40, 40, 525, 525);

    // Create a LCD to display remaining life.
    remainingLife = new QLCDNumber;
    remainingLife->display(info.numberOfLife); // Display the intial number lives.
    ui->lifeHLayout->addWidget(remainingLife);

    // Call this level B2. Display it on the screen
    info.setLevel("B2");
    ui->level_label->setText(info.level);
}

B4::~B4()
{
    delete ui;
}

/** Enable user to user arrow keys on keyboard to control the character.
 * @param event is QKeyEvent pointer which will not be used.
*/
void B4::keyPressEvent(QKeyEvent* event){

    int x = ui->player_label->x();
    int y = ui->player_label->y();
    int w = ui->player_label->width();
    int h = ui->player_label->height();

    int x2 = ui->player_label_2->x();
    int y2 = ui->player_label_2->y();
    int w2 = ui->player_label_2->width();
    int h2 = ui->player_label_2->height();

    switch (event->key()) {
    case Qt::Key_Left:
        ui->player_label->setGeometry(x-10,y,w,h);
        ui->player_label_2->setGeometry(x2-10,y2,w2,h2);

        // Change the character to face left when moving left.
        ui->player_label->hide();
        ui->player_label_2->show();
        break;
    case Qt::Key_Right:
        ui->player_label->setGeometry(x+10,y,w,h);
        ui->player_label_2->setGeometry(x2+10,y2,w2,h2);

        // Change the character to face right when moving right.
        ui->player_label->show();
        ui->player_label_2->hide();
        break;
    case Qt::Key_Up:
        ui->player_label->setGeometry(x,y-10,w,h);
        ui->player_label_2->setGeometry(x2,y2 -10,w2,h2);
        break;
    case Qt::Key_Down:
        ui->player_label->setGeometry(x,y+10,w,h);
        ui->player_label_2->setGeometry(x2,y2 +10,w2,h2);
        break;
    default:
            QWidget::keyPressEvent(event);
        }

    // Allow player icon and zombies to move only if the player icon does not intersect\
        other static widgets or boundary.
    if((labelIntersected(ui->player_label, ui->RIP1) == false) &&
       (labelIntersected(ui->player_label, ui->RIP2) == false) &&
       (labelIntersected(ui->player_label, ui->RIP3) == false) &&
       (labelIntersected(ui->player_label, ui->RIP4) == false) &&
       (labelIntersected(ui->player_label, ui->coffin1) == false) &&
       (labelIntersected(ui->player_label, ui->coffin2) == false) &&
       (margin->geometry().contains(ui->player_label->geometry()) == true))
    {

        // Move two zombies randomly whenever the user moves the player icon.
        labelRandMove(ui->zombie_label_1);
        labelRandMove(ui->zombie_label_2);
        labelRandMove(ui->zombie_label_3);

        QCoreApplication::processEvents();
        repaint();

        // If the player is touched by any of zombies after this move, decrease life and end game.
        if((labelIntersected(ui->player_label, ui->zombie_label_1) == true) ||
           (labelIntersected(ui->player_label, ui->zombie_label_2) == true) ||
           (labelIntersected(ui->player_label, ui->zombie_label_3) == true) ||
           (labelIntersected(ui->player_label, ui->fire_label_2) == true) ||
           (labelIntersected(ui->player_label, ui->fire_label_3) == true) ||
           (labelIntersected(ui->player_label, ui->fire_label_1) == true)){

            //Check if the player dies.
            if(info.decreaseLife() == false){
                DieDialog* dieMessage = new DieDialog;
                dieMessage->setWindowTitle("You died!");
                dieMessage->show();
                this->hide();
            } else{
                remainingLife->display(info.numberOfLife);
            }
        }
        // Check if the player touches the ladder after the last move, direct the\
        player to B4.
        if(labelIntersected(ui->player_label, ui->ladder_label) == true && (info.numberOfLife>0))
            B4_to_B3();
    }else{
        event->ignore();

        // reset position for the player icon
        ui->player_label->setGeometry(x,y,w,h);\
        ui->player_label_2->setGeometry(x2, y2, w2, h2);
    }
    return;
}

/** movie a QLabel widget randomly.
 * @param label_ptr is the pointer of the label.
*/
void B4::labelRandMove(QLabel* label_ptr){

    // Create a "die", distribution of the results of random number.
    //std::uniform_int_distribution unif(generator);

    int x = label_ptr->x();
    int y = label_ptr->y();
    int w = label_ptr->width();
    int h = label_ptr->height();


    // Generate a integer from 1 to 4 according to the current system time.
    std::uniform_int_distribution<int> unif(1,4);
    int direction = unif(generator2);

    // Move zombies to four directions according to the random number.
    switch(direction){
    case 1:
        label_ptr->setGeometry(x+10,y,w,h);
        break;
    case 2:
        label_ptr->setGeometry(x-10,y,w,h);
        break;
    case 3:
        label_ptr->setGeometry(x,y+10,w,h);
        break;
    case 4:
        label_ptr->setGeometry(x,y-10,w,h);
        break;
    }
    // Make sure the movements is bounded by bricks.
    if(margin->geometry().contains(label_ptr->geometry())){
        return;
    }else{
        // if it is outside the bound, reset the position of the label.
        label_ptr->setGeometry(x,y,w,h);
        labelRandMove(label_ptr);
    }
}

/** Direct player from B4 level to B3 level when the player touches the ladder.
    @param level is the name of the level
    @param life is the number of remaining life
    @param spell is the number of remaining spell
*/
void B4::B4_to_B3(){
    B3* b1 = new B3();
//    PlayerInfo temp(level, life, spell);
//    PlayerInfo temp2(level, life, spell);

//    b3->info = temp;
    b1->setWindowTitle("B1");
    b1->show();
    this->hide();
}
