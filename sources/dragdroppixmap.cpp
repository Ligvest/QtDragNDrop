#include "../headers/dragdroppixmap.h"

DragDropPixmap::DragDropPixmap(QString objectName, QPixmap image) {
    image_ = image;
    objectName_ = objectName;
}

void DragDropPixmap::startDrag() {
    QMimeData* mimeData = new QMimeData;
    mimeData->setText(objectName_);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(QPixmap(":/images/resources/" + objectName_ + ".png"));
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
