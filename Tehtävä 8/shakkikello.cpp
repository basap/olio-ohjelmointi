#include "shakkikello.h"
#include "./ui_shakkikello.h"

shakkikello::shakkikello(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::shakkikello),
    player1Time(0),
    player2Time(0),
    currentPlayer(1),
    gameTime(0),
    pQTimer(new QTimer(this))
{
    ui->setupUi(this);

    // Napeille click handlerit
    connect(pQTimer, &QTimer::timeout, this, &shakkikello::timeout);
    connect(ui->playerOneButton, &QPushButton::clicked, this, &shakkikello::switchPlayer);
    connect(ui->playerTwoButton, &QPushButton::clicked, this, &shakkikello::switchPlayer);
    connect(ui->startButton, &QPushButton::clicked, this, &shakkikello::startGame);
    connect(ui->stopButton, &QPushButton::clicked, this, &shakkikello::stopGame);
    connect(ui->twoMinsButton, &QPushButton::clicked, this, [this](){ setGameTime(120); }); // 120 sekunnin nappi
    connect(ui->fiveMinsButton, &QPushButton::clicked, this, [this](){ setGameTime(300); }); // 5 minuutin nappi (300 sec)

    setGameInfoText("Select playtime and press 'Start game'", 14);
}

shakkikello::~shakkikello()
{
    delete ui;
}

void shakkikello::timeout()
{
    // Vähennetään nykyisen pelaajan aikaa ja päivitetään progress baria
    if (currentPlayer == 1)
        player1Time--;
    else
        player2Time--;

    updateProgressBar();
    checkGameOver();
}

void shakkikello::updateProgressBar()
{
    // Lasketaan, kuinka paljon alkuperäisestä ajasta on jäljellä prosentteina
    ui->playerOneBar->setValue((player1Time * 100) / gameTime);
    ui->playerTwoBar->setValue((player2Time * 100) / gameTime);
}

void shakkikello::setGameInfoText(QString text, short fontSize)
{
    QFont font = ui->label->font();
    font.setPointSize(fontSize);
    ui->label->setFont(font);
    ui->label->setText(text);
}

void shakkikello::switchPlayer()
{
    if (!pQTimer->isActive()) return;

    // Pelaajan vaihto: jos on 1, se muuttuu kakkoseksi ja toisinpäin
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void shakkikello::startGame()
{
    // Jos aikaa ei ole asetettu (valittu napista), näytetään tämä viesti
    if (gameTime == 0) {
        setGameInfoText("Select playtime!", 14);
        return;
    }

    pQTimer->start(1000);
    setGameInfoText("Game ongoing", 14);
}

void shakkikello::stopGame()
{
    // Pysäytetään ajastin
    pQTimer->stop();
    setGameInfoText("Game paused", 14);
}

void shakkikello::setGameTime(short time)
{
    // Asetetaan valittu aika molemmille pelaajille
    gameTime = time;
    player1Time = time;
    player2Time = time;
    updateProgressBar();
    setGameInfoText("Press 'Start game'", 14);
}

void shakkikello::checkGameOver()
{
    // Jos pelaaja 1:n aika menee nollille, julistetaan pelaaja 2 voittajaksi
    if (player1Time <= 0)
    {
        stopGame();
        setGameInfoText("Game over! Winner: Player 2", 0);

    // Jos pelaaja 2:n aika menee nollille, julistetaan pelaaja 1 voittajaksi
    } else if (player2Time <= 0) {
        stopGame();
        setGameInfoText("Game over! Winner: Player 1", 0);
    }
}
