#include "playarea.h"

PlayArea::PlayArea(QWidget *parent) : QWidget(parent), mainLayout_(new QHBoxLayout) {
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::GlobalColor::magenta)));
    setFocusPolicy(Qt::StrongFocus);

    //    inventory_->setRowCount(1);
    //    inventory_->setColumnCount(1);

    //    QTableWidgetItem *item =
    //        new QTableWidgetItem(QIcon(QPixmap(":/images/resources/apple.png")), "Apple");
    //    inventory_->setItem(0, 0, item);

    //    mainLayout_ = new QHBoxLayout(this);
    this->setLayout(mainLayout_);
    //    inventory_ = new QTableWidget(this);
    //    QWidget *someWidget = new QWidget;
    //    mainLayout_->addWidget(someWidget);
}

void PlayArea::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        emit signalEscPressed();
    }
}
