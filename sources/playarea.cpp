#include "playarea.h"

PlayArea::PlayArea(QWidget *parent) : QWidget(parent) {
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(Qt::GlobalColor::magenta)));
    setFocusPolicy(Qt::StrongFocus);
}

void PlayArea::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        emit signalEscPressed();
    }
}
