/** @file diedialog.h
 *  @brief Stores DieDialog class.
 *
 * Stores DieDialog class with self-defined slot function for buttons.
 */

#ifndef DIEDIALOG_H
#define DIEDIALOG_H

#include <QDialog>
//#include "debug.h"

/** @class DieDialog
 *  @brief Stores DieDialog class
 *
    Only contains a slot function for a button on the dialog in addition to Qt-generated codes.
    This is the dialog shown to the user when the character dies.
*/

namespace Ui {
class DieDialog;
}

class DieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DieDialog(QWidget *parent = 0);
    ~DieDialog();

public slots:
    void retry();

private:
    Ui::DieDialog *ui;
};

#endif // DIEDIALOG_H
