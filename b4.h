/** @file b4.h
 *  @brief Stores B4 class.
 *
 * Stores the B4 level of this game and connect PlayerInfo.h with this file.
 */

#ifndef B4_H
#define B4_H

#include <QMainWindow>
#include <QLabel>
#include <QLCDNumber>
#include <QKeyEvent>
//#include "debug.h"
//#include "diedialog.h"
#include "playerinfo.h"

/** @class B4
 *  @brief Stores the B4 class
 *
 *  Stores important move functions, character information, and relevant pictures.
*/
namespace Ui {
class B4;
}

class B4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit B4(QWidget *parent = 0);
    ~B4();

    PlayerInfo info;

    void keyPressEvent(QKeyEvent*);
    void labelRandMove(QLabel*);
    void B4_to_B3();

private:
    Ui::B4 *ui;

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

#endif // B4_H
