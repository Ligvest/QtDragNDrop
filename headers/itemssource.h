#pragma once

#include <QApplication>
#include <QDrag>
#include <QLabel>
#include <QMimeData>
#include <QMouseEvent>
#include <QPixmap>
#include <QTableWidgetItem>

class ItemsSource : public QLabel, public QTableWidgetItem {
    Q_OBJECT

public:
    ItemsSource(QString objectName, QString imagePath);
    ItemsSource(QString objectName);

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
