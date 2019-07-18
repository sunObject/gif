#include "SMainWindow.h"
#include <QApplication>
#include<QSplashScreen>
#include<QLabel>
#include<QMovie>
#include<QThread>
#include<QDebug>
#include<QScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

      QPixmap pix(":/new/res/start.gif");

      QSplashScreen splash;
      QList<QScreen *> scr = QGuiApplication::screens();
      pix.scaled(splash.size(), Qt::IgnoreAspectRatio);
      splash.setFixedSize(scr[0]->size());
//      splash.setGeometry(scr[0]->geometry());
      splash.setWindowOpacity(0.5);// 设置窗口透明度

      QLabel label(&splash);
      label.setFixedSize(splash.size());

      QMovie mv(":/new/res/start.gif");
      mv.setScaledSize(label.size());
      label.setMovie(&mv);
      mv.start();
      splash.showMaximized();
      splash.setCursor(Qt::BlankCursor);
      qDebug()<<mv.speed();
//      a.processEvents();
      for(int i=0; i<500; i+=mv.speed())
      {
        QCoreApplication::processEvents();
        QThread::msleep(static_cast<unsigned int>(mv.speed()));
      }


    SMainWindow w;
    w.show();
   splash.finish(&w);

    return a.exec();
}
//      splash.show();
//      for(int i=0;i<200000;i++)
//      {
//          splash.repaint();
//      }
