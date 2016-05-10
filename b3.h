/** @file b3.h
 *  @brief Stores B3 class.
 *
 * Stores the B3 level of this game and connect PlayerInfo.h with this file.
 */

#ifndef B3_H
#define B3_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QKeyEvent>
#include <QLabel>
#include "playerinfo.h"

/** @class B3
 *  @brief Stores the B3 class
 *
 *  Stores important move functions, character information, and relevant pictures.
 */
namespace Ui {
class B3;
}

class B3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit B3(QWidget *parent = 0);
    ~B3();

    PlayerInfo info;

    void keyPressEvent(QKeyEvent*);
    void labelRandMove(QLabel*);

private:
    Ui::B3 *ui;

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

#endif // B3_H
