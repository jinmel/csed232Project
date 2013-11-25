#pragma once

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setApplication(QApplication* app);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *logo;
    QApplication *app;

};
