#pragma once

#include <QHBoxLayout>
#include <QHeaderView>
#include <QKeyEvent>
#include <QTableWidget>
#include <QWidget>

#include "inventory.h"
#include "itemssource.h"

class PlayArea : public QWidget {
    Q_OBJECT
    // ctors
public:
    explicit PlayArea(QWidget* parent = nullptr);

signals:
    void signalEscPressed();

    // fields
private:
    QHBoxLayout* mainLayout_;
    Inventory* inventory_;
    ItemsSource* applesSource_;

    // overrided
private:
    virtual void keyPressEvent(QKeyEvent* event) override;
};
