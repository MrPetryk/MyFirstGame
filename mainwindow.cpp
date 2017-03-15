#include "mainwindow.h"
#include <QRectF>
#include <QString>
#include <thread>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
  srand(time(NULL));
  but=new QPushButton(this);
  poin=new QLabel(this);
  poin->setText("Points "+QString::number(points));
  but->move(w,h);
  but->setFixedSize(30,30);
  poin->setFixedWidth(400);
  this->setFixedSize(630,630);
  connect(but,SIGNAL(clicked(bool)),this,SLOT(butImage()));

}

MainWindow::~MainWindow(){}

void MainWindow::keyPressEvent(QKeyEvent *event){


    int key=event->key();

    switch (key) {
    case Qt::Key_A:
        w-=20;
        prow();
        but->move(w,h);
        pointS();
        break;
    case Qt::Key_W:
        h-=20;
        prow();
        but->move(w,h);
        pointS();
        break;
    case Qt::Key_D:
        w+=20;
        prow();
        but->move(w,h);
        pointS();
        break;
    case Qt::Key_S:
        h+=20;
        prow();
        but->move(w,h);
        pointS();
        break;
    default:
        break;
    }

}

void MainWindow::prow(){
    if(w<=0){w=600;}
    if(w>600){w=0;}
    if(h<20){h=600;}
    if(h>600){h=20;}
}

void MainWindow::paintEvent(QPaintEvent *)
{
    p.begin(this);
    p.setBrush(Qt::red);
    p.setPen(Qt::red);
    p.drawEllipse(weigh,high,10,10);        // drawing code
    p.end();}

void MainWindow::pointS(){
    if((high>=h-5)&&(high<=h+25)&&(weigh>=w-5)&&(weigh<=w+25))
    {
        weigh=qrand()%600;
        high=20+qrand()%600;
    points++;
    poin->setText("Points "+QString::number(points));
    repaint();
    }
}

void MainWindow::butImage(){
    switch (qrand()%3) {
    case 1:
        but->setIcon(QIcon(":/new/images_button/images.svg"));
        but->setIconSize(QSize(35,35));
        break;
    case 2:
        but->setIcon(QIcon(":/new/images_button/images2.png"));
        but->setIconSize(QSize(35,35));
        break;
    case 3:
        but->setIcon(QIcon(":/new/images_button/images3.svg"));
        but->setIconSize(QSize(35,35));
        break;
    default:
        break;
    }
}

