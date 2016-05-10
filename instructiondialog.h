/** @file instructiondialog.h
 *  @brief Stores InstructionDialog class.
 *
 * Stores InstructionDialog class used for displaying instructions and background stories.
 */

#ifndef INSTRUCTIONDIALOG_H
#define INSTRUCTIONDIALOG_H

#include <QDialog>

/** @class InstructionDialog
 *  @brief Stores InstructionDialog class
 *
    This is the dialog is shown to the user when the user clicks the button called "Instructions."
*/
namespace Ui {
class InstructionDialog;
}

class InstructionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InstructionDialog(QWidget *parent = 0);
    ~InstructionDialog();

private:
    Ui::InstructionDialog *ui;
};

#endif // INSTRUCTIONDIALOG_H
