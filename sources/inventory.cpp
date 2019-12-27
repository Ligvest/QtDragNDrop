#include "inventory.h"

#include <QMessageBox>

Inventory::Inventory() {
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Allow drag and drop
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);

    // Hide indices
    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);

    // Set size of table
    setRowCount(3);
    setColumnCount(3);

    // Fill table with items
    for (size_t row = 0; row < rowCount(); ++row) {
        for (size_t col = 0; col < columnCount(); ++col) {
            InventoryItem *item = new InventoryItem();
            item->setText("x0");
            item->setTextAlignment(Qt::AlignRight | Qt::AlignBottom);
            setItem(row, col, item);
        }
    }
}

void Inventory::dragEnterEvent(QDragEnterEvent *ev) { ev->acceptProposedAction(); }

void Inventory::mousePressEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::RightButton) {
    }
    QTableWidget::mousePressEvent(ev);
}

bool Inventory::dropMimeData(int row, int column, const QMimeData *data, Qt::DropAction action) {
    if (currentRow() != row || currentColumn() != column) {
        // Item we dragged
        InventoryItem *sourceItem =
            static_cast<InventoryItem *>(item(currentRow(), currentColumn()));

        // Item on which we drop
        InventoryItem *destinationItem = static_cast<InventoryItem *>(item(row, column));

        if (sourceItem == nullptr) {
            destinationItem->setCount(destinationItem->count() + 1);
            QPixmap image;
            image.loadFromData(data->data("image/png"));
            destinationItem->setIcon(image);
        } else {
            destinationItem->setCount(destinationItem->count() + sourceItem->count());
            destinationItem->setIcon(sourceItem->icon());
            sourceItem->setCount(0);
            sourceItem->setIcon(QIcon());
        }

        // Clear selection
        setCurrentCell(-1, -1);
        clearSelection();
    }
    return true;
}

QStringList Inventory::mimeTypes() const {
    return QTableWidget::mimeTypes() << QString("image/png");
}
