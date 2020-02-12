#pragma once
#include <QByteArray>
#include <QDragEnterEvent>
#include <QHeaderView>
#include <QMimeData>
#include <QMouseEvent>
#include <QTableWidget>

#include "inventoryitem.h"

class Inventory : public QTableWidget {
    // ctors
public:
    Inventory();

    // methods
private:
    void fillTable();
    void decreaseItemsCount(InventoryItem* item, size_t subtrahend);

    // Slots
protected slots:
    void onContextMenuRequested(const QPoint& pos);

protected:
    // Center Qt::DecorationRole
    virtual QStyleOptionViewItem viewOptions() const override;

    // Implement dropping behavior
    virtual bool dropMimeData(int row, int column, const QMimeData* data,
                              Qt::DropAction action) override;
    virtual QStringList mimeTypes() const override;

    // Implement right click behavior
    virtual void mouseMoveEvent(QMouseEvent* ev) override;
};
