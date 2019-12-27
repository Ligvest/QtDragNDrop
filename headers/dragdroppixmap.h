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
    DragDropPixmap(QString objectName, QString imagePath);

    // methods
private:
    void startDrag();

    // fields
private:
    QPoint dragBeginPos_;
    QString objectName_;

protected:
    // For dragging
    virtual void mousePressEvent(QMouseEvent* ev) override;
    virtual void mouseMoveEvent(QMouseEvent* ev) override;
};
