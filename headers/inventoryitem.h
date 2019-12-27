#pragma once
#include <QTableWidgetItem>

class InventoryItem : public QTableWidgetItem {
    // ctors
public:
    InventoryItem();

public:
    size_t count();
    void setCount(size_t newCount);

    // fields
private:
    size_t count_;
};
