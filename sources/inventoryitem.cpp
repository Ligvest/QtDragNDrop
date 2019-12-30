#include "inventoryitem.h"

InventoryItem::InventoryItem() { setCount(0); }

size_t InventoryItem::count() { return count_; }

void InventoryItem::setCount(size_t newCount) {
    count_ = newCount;
    setText("x" + QString::number(count_));
    if (count_ < 1) {
        setIcon(QIcon());
    }
}
