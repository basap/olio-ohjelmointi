#include "laskin.h"
#include "ui_laskin.h"
#include <QDebug>

Laskin::Laskin(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Laskin), state(1), operand(-1), result(0.0)
{
    ui->setupUi(this);

    // Jokaisen numeronäppäimen click handleriin kutsu numberClickedHandler() funktioon
    connect(ui->N0, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N1, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked, this, &Laskin::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked, this, &Laskin::numberClickedHandler);

    // Operaattoreiden click handleriin kutsu addSubMulDivClickHandler() funktioon
    connect(ui->add, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &Laskin::addSubMulDivClickHandler);

    // clear, enter näppäinten click handleriin kutsu clearAndEnterClickHandler() funktioon
    connect(ui->clear, &QPushButton::clicked, this, &Laskin::clearAndEnterClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &Laskin::clearAndEnterClickHandler);
}

Laskin::~Laskin()
{
    delete ui;
}

void Laskin::numberClickedHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString value = button->text();

    // Kun state == 1, muokataan num1 lineEdittiä
    if (state == 1) {
        number1 += value;
        ui->num1->setText(number1);

    // Kun state == 2, muokataan num2 lineEdittiä
    } else if (state == 2) {
        number2 += value;
        ui->num2->setText(number2);
    }

    // Debuggausta varten, valitut numerot näkyy application outputissa
    qDebug() << "Number 1:" << number1 << "Number 2:" << number2;
}

void Laskin::addSubMulDivClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    // Käyttäjä valitsee operaattorin napilla ja muutetaan operand sitä vastaavaksi
    if (button == ui->add) operand = '+';
    else if (button == ui->sub) operand = '-';
    else if (button == ui->mul) operand = '*';
    else if (button == ui->div) operand = '/';

    // Muutetaan state = 2 operaattorin valinnan jälkeen jolloin toinen luku voidaan syöttää
    state = 2;
}

void Laskin::clearAndEnterClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    // Clear-nappi nollaa valinnat ja palauttaa state == 1
    if (button == ui->clear) {
        number1.clear();
        number2.clear();
        result = 0;
        operand = -1;
        state = 1;
        resetLineEdits();

    // Enter-napilla siirrytään suorittamaan laskutoimitus
    } else if (button == ui->enter) {
        if (number1.isEmpty() || number2.isEmpty()) return;

        float num1 = number1.toFloat();
        float num2 = number2.toFloat();

        // Suoritetaan laskutoimitus valitun operaattorin mukaan
        switch (operand) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = (num2 != 0) ? num1 / num2 : 0; // varmistus ettei jaeta nollalla
            break;
        default: return;
        }

        ui->result->setText(QString::number(result)); // Laskutoimituksen tulos ilmestyy result-kenttään
    }
}

void Laskin::resetLineEdits() // Funktio tyhjentää kaikki tekstikentät
{
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}
