#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QPushButton>
#include <QWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *but;
    QLabel *poin;
    int h=280,w=280, points =0, high=20+qrand()%600,weigh=20+qrand()%600;
    QPainter p;

    void prow();
    void paintEvent(QPaintEvent *);
    void pointS();


private slots:
   virtual void keyPressEvent(QKeyEvent *event);
    void butImage();

};

#endif // MAINWINDOW_H
