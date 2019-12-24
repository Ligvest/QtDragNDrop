#pragma once

#include <QKeyEvent>
#include <QWidget>

class PlayArea : public QWidget {
    Q_OBJECT
public:
    explicit PlayArea(QWidget *parent = nullptr);

signals:
    void signalEscPressed();

public slots:

private:
    void keyPressEvent(QKeyEvent *event) override;
};
