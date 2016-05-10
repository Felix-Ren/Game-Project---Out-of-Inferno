/** @mainpage
 *  @title Game Project: Out of Inferno
    @author Fei Ren
    @date March 10th, 2016

    @brief This program runs a cat-and-mouse game with a zombie theme.
*/

/** @file main.cpp
 *  @brief Creates the main window, changes the title of the window, and runs the program.
 *
 * Declare the window, change the title of the window, and make the window visible.
 */

#include "mainwindow.h"
#include <QApplication>
//#include <random>
//#include <chrono>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Out of Inferno");
    w.show();

//    // Create seed and random number generator for random movements of\
//    characters
//    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
//    std::default_random_engine generator(seed);

//    // Define and show the stage window
//    Stage s;
//    s.setWindowTitle("B5");
//    //s.show();
   // std::cout << "Hello!";

    return a.exec();
}
