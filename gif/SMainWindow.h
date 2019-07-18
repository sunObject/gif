#ifndef SMAINWINDOW_H
#define SMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SMainWindow;
}

class SMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SMainWindow(QWidget *parent = nullptr);
    ~SMainWindow();

private:
    Ui::SMainWindow *ui;
     QMovie *mv;
};

#endif // SMAINWINDOW_H
