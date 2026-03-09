#include "ticketdialog.h"
#include "ui_ticketdialog.h"
#include <QDateTime> // Додано для QDateTime
#include <QRandomGenerator> // Додано для заміни qrand

TicketDialog::TicketDialog(Mode mode, const Ticket &ticket, QWidget *parent)
    : QDialog(parent), ui(new Ui::TicketDialog), currentMode(mode) {
    ui->setupUi(this);

    // Виправлено: у Qt 6 замість qrand використовуємо QRandomGenerator
    if (mode == Mode::New) {
        m_id = QRandomGenerator::global()->bounded(1000);
        ui->valID->setText("NEW");
    } else {
        m_id = ticket.id;
        ui->valID->setText(QString::number(ticket.id));
        ui->editTitle->setText(ticket.title);
        ui->comboPriority->setCurrentText(ticket.priority);
        ui->comboStatus->setCurrentText(ticket.status);
        ui->editDescription->setPlainText(ticket.description);
    }

    applyMode();

    connect(ui->btnEdit, &QPushButton::clicked, this, &TicketDialog::onEditClicked);
    connect(ui->btnSave, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->btnClose, &QPushButton::clicked, this, &QDialog::reject);
}

Ticket TicketDialog::getTicket() const {
    Ticket t;
    t.id = m_id;
    t.title = ui->editTitle->text();
    t.priority = ui->comboPriority->currentText();
    t.status = ui->comboStatus->currentText();
    t.description = ui->editDescription->toPlainText();
    t.createdAt = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm");
    return t;
}

void TicketDialog::applyMode() {
    bool isReadOnly = (currentMode == Mode::View);
    ui->editTitle->setReadOnly(isReadOnly);
    ui->editDescription->setReadOnly(isReadOnly);
    ui->comboPriority->setEnabled(!isReadOnly);
    ui->comboStatus->setEnabled(!isReadOnly);

    ui->btnEdit->setVisible(isReadOnly);
    ui->btnSave->setVisible(!isReadOnly);
    ui->btnCancel->setVisible(!isReadOnly);
    ui->btnClose->setVisible(isReadOnly);

    if (currentMode == Mode::View) setWindowTitle("View Ticket");
    else if (currentMode == Mode::Edit) setWindowTitle("Edit Ticket");
    else setWindowTitle("New Ticket");
}

void TicketDialog::onEditClicked() {
    currentMode = Mode::Edit;
    applyMode();
}

TicketDialog::~TicketDialog() { delete ui; }
