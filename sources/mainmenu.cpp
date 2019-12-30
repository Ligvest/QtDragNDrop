#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent), hLayout_(new QHBoxLayout), vLayout_(new QVBoxLayout) {

    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::GlobalColor::cyan)));

    initLayoutsAndButtons();
}

void MainMenu::initLayoutsAndButtons() {
    vLayout_->addStretch();
    vLayout_->addWidget(resumeButton_ = new QPushButton("Resume"));
    vLayout_->addWidget(newGameButton_ = new QPushButton("New game"));
    vLayout_->addWidget(optionsButton_ = new QPushButton("Options"));
    vLayout_->addWidget(exitButton_ = new QPushButton("Exit"));
    vLayout_->addStretch();
    vLayout_->setSpacing(30);

    hLayout_->addStretch();
    hLayout_->addLayout(vLayout_);
    hLayout_->addStretch();
    hLayout_->setSpacing(0);
    this->setLayout(hLayout_);
}

// getters
QPushButton *MainMenu::exitButton() const { return exitButton_; }
QPushButton *MainMenu::optionsButton() const { return optionsButton_; }
QPushButton *MainMenu::newGameButton() const { return newGameButton_; }
QPushButton *MainMenu::resumeButton() const { return resumeButton_; }
