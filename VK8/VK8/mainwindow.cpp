#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , state(ChooseTime)
    , totalSeconds(0)
    , player1Seconds(0)
    , player2Seconds(0)
    , currentPlayer(1)
{
    ui->setupUi(this);

    ui->progressBarPlayer1->setRange(0, 100);
    ui->progressBarPlayer2->setRange(0, 100);
    ui->progressBarPlayer1->setFormat("%p%");
    ui->progressBarPlayer2->setFormat("%p%");

    connect(&timer, &QTimer::timeout, this, &MainWindow::timeout);

    updateProgress();
    setInfo("Select playtime and press start game!", 18);
    updateUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn120Sec_clicked()
{
    selectTime(120);
}

void MainWindow::on_btn5Min_clicked()
{
    selectTime(300);
}

void MainWindow::on_btnStartGame_clicked()
{
    startGame();
}

void MainWindow::on_btnStopGame_clicked()
{
    stopGame();
}

void MainWindow::on_btnSwitchPlayer1_clicked()
{
    switchPlayer(1);
}

void MainWindow::on_btnSwitchPlayer2_clicked()
{
    switchPlayer(2);
}

void MainWindow::selectTime(int seconds)
{
    if (state == Running) {
        return;
    }

    totalSeconds = seconds;
    player1Seconds = seconds;
    player2Seconds = seconds;
    currentPlayer = 1;

    state = Ready;

    updateProgress();
    setInfo("ready to play", 18);
    updateUi();
}

void MainWindow::startGame()
{
    if (state != Ready) {
        return;
    }
    if (totalSeconds <= 0) {
        return;
    }

    state = Running;
    currentPlayer = 1;

    setInfo("Game ongoing", 18);
    updateUi();

    timer.start(1000);
}

void MainWindow::stopGame()
{
    if (timer.isActive()) {
        timer.stop();
    }

    totalSeconds = 0;
    player1Seconds = 0;
    player2Seconds = 0;
    currentPlayer = 1;

    state = Stopped;

    updateProgress();
    setInfo("New game via start button", 16);
    updateUi();
}

void MainWindow::finishGame(int winnerPlayer)
{
    if (timer.isActive()) {
        timer.stop();
    }

    state = Finished;

    if (winnerPlayer == 1) {
        setInfo("Player 1 WON!!", 22);
    } else {
        setInfo("Player 2 WON!!", 22);
    }

    updateProgress();
    updateUi();
}

void MainWindow::switchPlayer(int pressedByPlayer)
{
    if (state != Running) {
        return;
    }
    if (pressedByPlayer != currentPlayer) {
        return;
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }

    updateUi();
}

void MainWindow::timeout()
{
    if (state != Running) {
        return;
    }

    if (currentPlayer == 1) {
        if (player1Seconds > 0) {
            player1Seconds -= 1;
        }
        if (player1Seconds <= 0) {
            updateProgress();
            finishGame(2);
            return;
        }
    } else {
        if (player2Seconds > 0) {
            player2Seconds -= 1;
        }
        if (player2Seconds <= 0) {
            updateProgress();
            finishGame(1);
            return;
        }
    }

    updateProgress();
}

int MainWindow::percent(int seconds) const
{
    if (totalSeconds <= 0) {
        return 0;
    }

    double p = (double(seconds) * 100.0) / double(totalSeconds);
    int v = int(p + 0.5);

    if (v < 0) {
        v = 0;
    }
    if (v > 100) {
        v = 100;
    }
    return v;
}

void MainWindow::updateProgress()
{
    ui->progressBarPlayer1->setValue(percent(player1Seconds));
    ui->progressBarPlayer2->setValue(percent(player2Seconds));
}

void MainWindow::setInfo(const QString &text, int pointSize)
{
    ui->labelInfo->setText(text);

    QFont f = ui->labelInfo->font();
    f.setPointSize(pointSize);
    f.setBold(true);
    ui->labelInfo->setFont(f);

    ui->labelInfo->setAlignment(Qt::AlignCenter);
}

void MainWindow::updateUi()
{
    bool canChooseTime = (state == ChooseTime || state == Ready || state == Finished || state == Stopped);

    ui->btn120Sec->setEnabled(canChooseTime);
    ui->btn5Min->setEnabled(canChooseTime);

    ui->btnStartGame->setEnabled(state == Ready);
    ui->btnStopGame->setEnabled(state == Running);

    if (state == Running) {
        ui->btnSwitchPlayer1->setEnabled(currentPlayer == 1);
        ui->btnSwitchPlayer2->setEnabled(currentPlayer == 2);
    } else {
        ui->btnSwitchPlayer1->setEnabled(false);
        ui->btnSwitchPlayer2->setEnabled(false);
    }
}
