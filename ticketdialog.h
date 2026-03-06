#ifndef TICKETDIALOG_H
#define TICKETDIALOG_H

#include <QDialog>

namespace Ui { class TicketDialog; }

class TicketDialog : public QDialog {
    Q_OBJECT
public:
    enum class Mode { View, Edit, New };
    explicit TicketDialog(Mode mode, QWidget *parent = nullptr);
    ~TicketDialog();

private slots:
    void onEditClicked();

private:
    Ui::TicketDialog *ui;
    Mode currentMode;
    void applyMode();
};
#endif
