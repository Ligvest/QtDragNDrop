#include "sourceitem.h"

#include <QBuffer>
#include <QMessageBox>

ItemsSource::ItemsSource(QString objectName, QString imagePath) {
    image_ = QPixmap(imagePath);
    setPixmap(image_.scaled(100, 100));
    objectName_ = objectName;
}

void ItemsSource::startDrag() {
    QByteArray data;
    QBuffer buf(&data);
    QMimeData* mimeData = new QMimeData;
    buf.open(QIODevice::WriteOnly);
    image_.save(&buf, "PNG");
    mimeData->setData("image/png", data);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(*pixmap());
    drag->exec(Qt::MoveAction);
}

void ItemsSource::mousePressEvent(QMouseEvent* ev) {
    if (ev->button() == Qt::LeftButton) {
        dragBeginPos_ = ev->pos();
    }
    QWidget::mousePressEvent(ev);
}

void ItemsSource::mouseMoveEvent(QMouseEvent* ev) {
    int distance = (ev->pos() - dragBeginPos_).manhattanLength();
    if (distance > QApplication::startDragDistance()) {
        startDrag();
    }
    QWidget::mouseMoveEvent(ev);
}
