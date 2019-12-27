#pragma once
#include <QByteArray>
#include <QDragEnterEvent>
#include <QHeaderView>
#include <QMimeData>
#include <QMouseEvent>
#include <QTableWidget>

#include "inventoryitem.h"

class Inventory : public QTableWidget {
public:
    Inventory();

protected:
    // For dropping
    virtual void dragEnterEvent(QDragEnterEvent* ev) override;
    virtual bool dropMimeData(int row, int column, const QMimeData* data,
                              Qt::DropAction action) override;
    virtual QStringList mimeTypes() const override;

    // Implement right click behavior
    virtual void mousePressEvent(QMouseEvent* ev) override;
};
