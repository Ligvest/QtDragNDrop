#include "../headers/dragdroppixmap.h"

DragDropPixmap::DragDropPixmap(QString objectName, QString imagePath) {
    setPixmap(QPixmap(imagePath).scaled(100, 100));
    objectName_ = objectName;
}

void DragDropPixmap::startDrag() {
    QMimeData* mimeData = new QMimeData;
    mimeData->setText(objectName_);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(*pixmap());
    drag->exec();
}

void DragDropPixmap::mousePressEvent(QMouseEvent* ev) {
    if (ev->button() == Qt::LeftButton) {
        dragBeginPos_ = ev->pos();
    }
    QWidget::mousePressEvent(ev);
}

void DragDropPixmap::mouseMoveEvent(QMouseEvent* ev) {
    int distance = (ev->pos() - dragBeginPos_).manhattanLength();
    if (distance > QApplication::startDragDistance()) {
        startDrag();
    }
    QWidget::mouseMoveEvent(ev);
}
