#ifndef LASKIN_H
#define LASKIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Laskin;
}
QT_END_NAMESPACE

class Laskin : public QMainWindow
{
    Q_OBJECT

public:
    Laskin(QWidget *parent = nullptr);
    ~Laskin();

private:
    Ui::Laskin *ui;
    QString number1,number2;            // QString is handy as it can be printed easily to QLineEdit
    int state;                          // State variable is needed to know which number is being given
    float result;                       // Result is calculated when user presses enter
    short operand;                      // Operand is stored when user presses + or - or * or / buttons

    void numberClickedHandler();        // This function is called from all number QPushButton click handlers
    void clearAndEnterClickHandler();   // This handles clear and enter buttons
    void addSubMulDivClickHandler();    // And one handler for +,-,*,/ buttons also
    void resetLineEdits();              // This is handy for resetting all 3 QLineEdits
};
#endif // LASKIN_H
