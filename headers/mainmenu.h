#pragma once

#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class MainMenu : public QWidget {
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);

    QPushButton *resumeButton() const;
    QPushButton *newGameButton() const;
    QPushButton *optionsButton() const;
    QPushButton *exitButton() const;

public slots:

    // methods
private:
    void initLayoutsAndButtons();

    // fields
private:
    // Buttons
    QPushButton *resumeButton_;
    QPushButton *newGameButton_;
    QPushButton *optionsButton_;
    QPushButton *exitButton_;

    // Layouts
    QHBoxLayout *hLayout_;
    QVBoxLayout *vLayout_;
};
