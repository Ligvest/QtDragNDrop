#include "playarea.h"

PlayArea::PlayArea(QWidget *parent)
    : QWidget(parent),
      mainLayout_(new QHBoxLayout),
      inventory_(new QTableWidget),
      source_(new DragDropPixmap("apple", ":/images/resources/apple.png")) {
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::GlobalColor::magenta)));
    setFocusPolicy(Qt::StrongFocus);

    initInventory();
    this->setLayout(mainLayout_);
    mainLayout_->addWidget(inventory_);
    mainLayout_->addWidget(source_);
}

void PlayArea::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        emit signalEscPressed();
    }
}

void PlayArea::initInventory() {
    // Set the default size of cells
    //    inventory_->horizontalHeader()->setDefaultSectionSize(200);
    //    inventory_->verticalHeader()->setDefaultSectionSize(200);
    inventory_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    inventory_->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    inventory_->setRowCount(3);
    inventory_->setColumnCount(3);

    // Fill table with items
    for (size_t row = 0; row < inventory_->rowCount(); ++row) {
        for (size_t col = 0; col < inventory_->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(*source_->pixmap(), "x1");
            item->setTextAlignment(Qt::AlignRight | Qt::AlignBottom);
            inventory_->setItem(row, col, item);
        }
    }
}
