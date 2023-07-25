#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultwindow.h"
#include <QMessageBox>

int A[10000][10000];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    // Your implementation goes here
    // You can leave it empty for now if you don't have any logic to add
}


void PATTERN(int n, int c1, int c2, int k, int f)
{
    if (n == 1)
    {
        A[c1][c2] = n;
    }
    if (n > 1)
    {
        for (int i = c1, j = c2; j < k; j++)
        {
            A[i][j] = n;
        }
        for (int i = c1, j = c2; i < k; i++)
        {
            A[i][j] = n;
        }
        for (int j = c2, i = (k)-1; j < k; j++)
        {
            A[i][j] = n;
        }
        for (int i = c1, j = (k)-1; i < k; i++)
        {
            A[i][j] = n;
        }
        n--;
        c1++;
        c2++;
        k = 2 * n - 1;
        f++;
        k = k + f;
        PATTERN(n, c1, c2, k, f);
    }
    else
    {
        return;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString inputStr = ui->textEdit->toPlainText();
    bool ok;
    int n = inputStr.toInt(&ok);

    if (!ok || n <= 0)
    {
        QMessageBox::critical(this, "Error", "Invalid Number! Please enter a positive integer.");
        return;
    }

    PATTERN(n, 0, 0, 2 * n - 1, 0);

    resultWindow *resultWin = new resultWindow(this);
    resultWin->displayPattern(n, A);
    resultWin->show();
}
