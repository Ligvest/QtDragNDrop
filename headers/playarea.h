#pragma once

#include <QHBoxLayout>
#include <QHeaderView>
#include <QKeyEvent>
#include <QTableWidget>
#include <QWidget>

#include "dragdroppixmap.h"

class PlayArea : public QWidget {
    Q_OBJECT
public:
    explicit PlayArea(QWidget* parent = nullptr);

signals:
    void signalEscPressed();

public slots:

    // methods
private:
    void initInventory();

    // fields
private:
    QHBoxLayout* mainLayout_;
    QTableWidget* inventory_;
    DragDropPixmap* source_;

    // overrided
private:
    virtual void keyPressEvent(QKeyEvent* event) override;
};
