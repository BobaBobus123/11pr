#include "ticketdialog.h"
#include "ui_ticketdialog.h"

TicketDialog::TicketDialog(Mode mode, QWidget *parent)
    : QDialog(parent), ui(new Ui::TicketDialog), currentMode(mode) {
    ui->setupUi(this);
    applyMode();

    connect(ui->btnEdit, &QPushButton::clicked, this, &TicketDialog::onEditClicked);
    connect(ui->btnClose, &QPushButton::clicked, this, &QDialog::close);
    connect(ui->btnCancel, &QPushButton::clicked, this, &QDialog::close);
}

void TicketDialog::applyMode() {
    bool isReadOnly = (currentMode == Mode::View);

    // Встановлення станів полів [cite: 59, 61, 108]
    ui->editTitle->setReadOnly(isReadOnly);
    ui->editDescription->setReadOnly(isReadOnly);
    ui->comboPriority->setEnabled(!isReadOnly);
    ui->comboStatus->setEnabled(!isReadOnly);

    // Керування кнопками [cite: 62, 116, 117]
    ui->btnEdit->setVisible(isReadOnly);
    ui->btnClose->setVisible(isReadOnly);
    ui->btnSave->setVisible(!isReadOnly);
    ui->btnCancel->setVisible(!isReadOnly);

    // Заголовок вікна згідно Рис. 2 [cite: 150]
    if (currentMode == Mode::View) setWindowTitle("View Ticket");
    else if (currentMode == Mode::Edit) setWindowTitle("Edit Ticket");
    else setWindowTitle("New Ticket");
}

void TicketDialog::onEditClicked() {
    currentMode = Mode::Edit;
    applyMode();
}

TicketDialog::~TicketDialog() { delete ui; }
