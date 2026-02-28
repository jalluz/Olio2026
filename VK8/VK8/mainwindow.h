#pragma once

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void timeout();

private slots:
    void on_btn120Sec_clicked();
    void on_btn5Min_clicked();
    void on_btnStartGame_clicked();
    void on_btnStopGame_clicked();
    void on_btnSwitchPlayer1_clicked();
    void on_btnSwitchPlayer2_clicked();

private:
    enum GameState
    {
        ChooseTime,
        Ready,
        Running,
        Finished,
        Stopped
    };

    void selectTime(int seconds);
    void startGame();
    void stopGame();
    void finishGame(int winnerPlayer);
    void switchPlayer(int pressedByPlayer);

    void updateUi();
    void updateProgress();
    int percent(int seconds) const;
    void setInfo(const QString &text, int pointSize);

    Ui::MainWindow *ui;

    QTimer timer;
    GameState state;

    int totalSeconds;
    int player1Seconds;
    int player2Seconds;
    int currentPlayer;
};
