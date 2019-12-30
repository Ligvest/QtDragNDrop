#include "playarea.h"

PlayArea::PlayArea(QWidget *parent)
    : QWidget(parent),
      mainLayout_(new QHBoxLayout),
      inventory_(new Inventory),
      applesSource_(new ItemsSource("apple", ":/images/resources/apple.png")) {

    // Set background color
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::GlobalColor::magenta)));

    // Keyboard focus
    setFocusPolicy(Qt::StrongFocus);

    // Init layout
    this->setLayout(mainLayout_);
    mainLayout_->addWidget(inventory_);
    mainLayout_->addWidget(applesSource_);
}

void PlayArea::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        emit signalEscPressed();
    }
}
