#pragma once

#include <QMainWindow>
#include <QStackedLayout>
#include <stdexcept>

#include "mainmenu.h"
#include "playarea.h"

class Window : public QWidget {
    Q_OBJECT

public:
    Window(QWidget* parent = nullptr);
    ~Window();

private slots:
    void resume();
    void newGame();
    void options();
    void exit();
    void menu();

    // methods
private:
    void connectSignals();

    // fields
private:
    QStackedLayout* mainLayout_;
    MainMenu* menu_;
    PlayArea* playArea_;
};
