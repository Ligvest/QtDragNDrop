#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent),
      mainLayout_(new QStackedLayout),
      menu_(new MainMenu),
      playArea_(new PlayArea) {
    mainLayout_->addWidget(menu_);
    mainLayout_->addWidget(playArea_);
    setLayout(mainLayout_);

    connectSignals();
}

Window::~Window() {}

void Window::resume() { throw std::logic_error("Not implemented"); }

void Window::newGame() { mainLayout_->setCurrentWidget(playArea_); }

void Window::options() { throw std::logic_error("Not implemented"); }

void Window::exit() { ::exit(0); }

void Window::menu() { mainLayout_->setCurrentWidget(menu_); }

void Window::connectSignals() {
    // connect keys from play area
    connect(playArea_, &PlayArea::signalEscPressed, this, &Window::menu);

    // connect buttons from main menu
    connect(menu_->resumeButton(), &QPushButton::clicked, this, &Window::resume);
    connect(menu_->newGameButton(), &QPushButton::clicked, this, &Window::newGame);
    connect(menu_->optionsButton(), &QPushButton::clicked, this, &Window::options);
    connect(menu_->exitButton(), &QPushButton::clicked, this, &Window::exit);
}
