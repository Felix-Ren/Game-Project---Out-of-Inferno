/** @file mainwindow.h
 *  @brief declaration for the main window of the program
 *
 *  Contains the declarations for the various member functions generated by Qt automatically
 * and customized slots functions.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPixmap>
#include <QMediaPlayer>
#include <QTimer>
#include "b5.h"
#include "b4.h"
#include "b3.h"
#include "instructiondialog.h"
#include "playerinfo.h"
//#include "debug.h"

/** @class MainWindow
 *  @brief Stores MainWindow class
 *
    This is main menu window which is shown to the user first whenever this program is run.
    This class stores slot functions and variable related to the functionality of buttons on
    the window and relevant pictures.
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//    void playMusic();
    ~MainWindow();

public slots:
    void translate_to_English();
    void translate_to_Chinese();
    void to_stage();
    void show_instructions();
//    void mute();

private:
    void repeatMusic();
    void resetLifeSpell();

    Ui::MainWindow *ui;
    bool isEnglish = 1; // Default language is English;

    // Pictures
    QPixmap* background_pic;
    QPixmap* mute_pic;

    // Music
    QMediaPlayer* background_music;

    QTimer* timer;

//    friend class SuccessDialog;
//    friend class DieDialog;
};

#endif // MAINWINDOW_H
