#include "inventory.h"
#include <QDebug>

#include <QMessageBox>

Inventory::Inventory() {
    // Right click behavior
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QTableWidget::customContextMenuRequested, this,
            &Inventory::onContextMenuRequested);

    // Set cells display policy and hide indices
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);

    // Forbid editing
    setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Allow drag and drop
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);

    // Set size of table
    setRowCount(3);
    setColumnCount(3);

    // Fill table with items
    fillTable();
}

void Inventory::fillTable() {
    for (size_t row = 0; row < rowCount(); ++row) {
        for (size_t col = 0; col < columnCount(); ++col) {
            InventoryItem *item = new InventoryItem();
            item->setText("x0");
            item->setTextAlignment(Qt::AlignRight | Qt::AlignBottom);
            setItem(row, col, item);
        }
    }
}

void Inventory::decreaseItemsCount(InventoryItem *item, size_t subtrahend) {
    if (item == nullptr) {
        return;
    }
    if (item->count() < 1) {
        return;
    }
    item->setCount(item->count() - subtrahend);
}

void Inventory::onContextMenuRequested(const QPoint &pos) {
    InventoryItem *currentItem = static_cast<InventoryItem *>(itemAt(pos));
    decreaseItemsCount(currentItem, 1);
}

QStyleOptionViewItem Inventory::viewOptions() const
{
    QStyleOptionViewItem options = QTableWidget::viewOptions();
//    options.decorationPosition = QStyleOptionViewItem::Top; //above the text
    options.decorationAlignment = Qt::AlignTop;
    return options;
}

void Inventory::mouseMoveEvent(QMouseEvent *ev) {
    // disable possibility to drag by right mouse button
    if (ev->buttons() & Qt::RightButton) {
        // do nothing
    } else {
        QTableView::mouseMoveEvent(ev);
    }
}

QStringList Inventory::mimeTypes() const {
    return QTableWidget::mimeTypes() << QString("text/plain");
}

//make square cells
//change size on change window size (or table size) (redraw all images)
bool Inventory::dropMimeData(int row, int column, const QMimeData *data, Qt::DropAction action) {
    // Item on which we drop
    InventoryItem *destinationItem = static_cast<InventoryItem *>(item(row, column));

    // If we dragged from outside of the table view
    if (data->hasText()) {
        QPixmap image(":/images/resources/apple.png");
        int cellWidth = columnWidth(0);
        int cellHeight = rowHeight(0);
        destinationItem->setCount(destinationItem->count() + 1);
        destinationItem->setData(Qt::DecorationRole, image.scaled(cellWidth,cellHeight, Qt::KeepAspectRatio));
        return true;
    }

    // Do nothing if we drop to the cell from which we dragged
    if (currentRow() == row && currentColumn() == column) {
        return true;
    }


    // Item we dragged
    InventoryItem *sourceItem = static_cast<InventoryItem *>(item(currentRow(), currentColumn()));
    if (sourceItem->count() > 0) {
        // Move all objects from source to destination
        destinationItem->setCount(destinationItem->count() + sourceItem->count());
        destinationItem->setData(Qt::DecorationRole,sourceItem->data(Qt::DecorationRole));
        // Clear source cell
        decreaseItemsCount(sourceItem, sourceItem->count());
    }

    // Clear selection
    setCurrentCell(-1, -1);
    clearSelection();
    return true;
}
