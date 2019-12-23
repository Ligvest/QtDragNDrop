#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class Window : public QMainWindow {
    Q_OBJECT

   public:
    Window(QWidget *parent = nullptr);
    ~Window();

   private:
    QWidget menuWidget_;
    QPushButton button_;
};
#endif  // MAINWINDOW_H
