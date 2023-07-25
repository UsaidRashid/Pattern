#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>

namespace Ui {
class resultWindow;
}

class resultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit resultWindow(QWidget *parent = nullptr);
    ~resultWindow();
    void displayPattern(int n, int A[][10000]);

private:
    Ui::resultWindow *ui;
};

#endif // RESULTWINDOW_H
