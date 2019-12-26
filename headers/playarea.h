#pragma once

#include <QHBoxLayout>
#include <QKeyEvent>
#include <QTableWidget>
#include <QWidget>

class PlayArea : public QWidget {
    Q_OBJECT
public:
    explicit PlayArea(QWidget* parent = nullptr);

signals:
    void signalEscPressed();

public slots:

    // fields
private:
    QTableWidget* inventory_;
    QHBoxLayout* mainLayout_;

    // overrided
private:
    virtual void keyPressEvent(QKeyEvent* event) override;
};
