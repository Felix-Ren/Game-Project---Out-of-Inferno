/** @file b5.h
 *  @brief Stores Stage class.
 *
 * Stores the B5 level of this game and connect PlayerInfo.h with this file.
 */

#ifndef STAGE_H
#define STAGE_H

#include <QMainWindow>
#include <QKeyEvent>
#include <iostream>
#include <QRegion>
#include <cstdlib>
#include <QLabel>
//#include <chrono>
//#include <random>
#include <QLCDNumber>
#include "playerinfo.h"

/** @class Stage
 *  @brief Stores the Stage class
 *
 *  Stores important move functions, character information, and relevant pictures for the B5 level.
*/
namespace Ui {
class Stage;
}

class Stage : public QMainWindow
{
    Q_OBJECT

public:

    explicit Stage(QWidget *parent = 0);
//    Stage(const PlayerInfo&);
    ~Stage();

    void keyPressEvent(QKeyEvent*);
    void labelRandMove(QLabel*);

    PlayerInfo info;

//signals:
//    void goUpOneLevel();

//public slots:
//    void touchLadder();

private:
    Ui::Stage *ui;

    void B5_to_B4();

    //Pictures
    QPixmap* RIP_pic;
    QPixmap* coffin_pic;
    QPixmap* player_pic;
    QPixmap* zombie1_pic;
    QPixmap* zombie2_pic;
    QPixmap* ladder_pic;
    QPixmap* background_pic;
    QPixmap* player_pic_left;

    QLabel* margin; //a label indicating the area inside the bricks, i.e.\
                      the area in which the player is allowed to move.
    QLCDNumber* remainingLife;
};

#endif // STAGE_H
