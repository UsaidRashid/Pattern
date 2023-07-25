#include "resultwindow.h"
#include "ui_resultwindow.h"
#include <QString>

resultWindow::resultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultWindow)
{
    ui->setupUi(this);
}

resultWindow::~resultWindow()
{
    delete ui;
}

void resultWindow::displayPattern(int n, int A[][10000])
{
    QString patternStr;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        patternStr += "\n";
        for (int j = 0; j < 2 * n - 1; j++)
        {
            patternStr += QString::number(A[i][j]);
        }
    }
    ui->textEdit->setText(patternStr);
}
