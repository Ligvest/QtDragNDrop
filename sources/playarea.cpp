#include "playarea.h"

PlayArea::PlayArea(QWidget *parent)
    : QWidget(parent),
      mainLayout_(new QHBoxLayout),
      inventory_(new Inventory),
      applesSource_(new DragDropPixmap("apple", ":/images/resources/apple.png")) {
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::GlobalColor::magenta)));
    setFocusPolicy(Qt::StrongFocus);

    this->setLayout(mainLayout_);
    mainLayout_->addWidget(inventory_);
    mainLayout_->addWidget(applesSource_);
}

void PlayArea::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        emit signalEscPressed();
    }
}
