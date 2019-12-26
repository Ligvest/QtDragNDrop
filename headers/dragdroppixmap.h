#pragma once

#include <QApplication>
#include <QDrag>
#include <QLabel>
#include <QMimeData>
#include <QMouseEvent>
#include <QPixmap>

class DragDropPixmap : public QLabel {
    Q_OBJECT

public:
    DragDropPixmap(QString objectName, QPixmap image);

    // methods
private:
    void startDrag();

    // fields
private:
    QPoint dragBeginPos_;
    QString objectName_;
    QPixmap image_;

protected:
    // For dragging
    virtual void mousePressEvent(QMouseEvent* ev) override;
    virtual void mouseMoveEvent(QMouseEvent* ev) override;
};
