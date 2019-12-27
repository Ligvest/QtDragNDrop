#pragma once

#include <QHBoxLayout>
#include <QHeaderView>
#include <QKeyEvent>
#include <QTableWidget>
#include <QWidget>

#include "dragdroppixmap.h"
#include "inventory.h"

class PlayArea : public QWidget {
    Q_OBJECT
public:
    explicit PlayArea(QWidget* parent = nullptr);

signals:
    void signalEscPressed();

    // fields
private:
    QHBoxLayout* mainLayout_;
    Inventory* inventory_;
    DragDropPixmap* applesSource_;

    // overrided
private:
    virtual void keyPressEvent(QKeyEvent* event) override;
};
