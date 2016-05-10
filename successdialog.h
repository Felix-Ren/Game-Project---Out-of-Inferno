/** @file successdialog.h
 *  @brief Stores SuccessDialog class.
 *
 *  Codes in this file are related to the dialog poped up when the user completes all stages.
 */

#ifndef SUCCESSDIALOG_H
#define SUCCESSDIALOG_H

#include <QDialog>

/** @class SuccessDialog
 *  @brief stores SuccessDialog class
 *
 *  This is the dialog shown to the user when the user completes all levels.
 */
namespace Ui {
class SuccessDialog;
}

class SuccessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SuccessDialog(QWidget *parent = 0);
    ~SuccessDialog();

public slots:
    void back_to_main_menu();

private:
    Ui::SuccessDialog *ui;
};

#endif // SUCCESSDIALOG_H
