#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "tickettablemodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onActionNew();
    void onActionView();
    void onActionEdit();
    void onActionDelete();
    void updateActions();
    void onClearFilters();

private:
    Ui::MainWindow *ui;
    TicketTableModel *model;
    QLabel *lblStats;
};
#endif
