#include "TableViewWindow.h"
#include "ui_TableViewWindow.h"

TableViewWindow::TableViewWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableViewWindow)
{
    ui->setupUi(this);
}

TableViewWindow::~TableViewWindow()
{
    delete ui;
}

QTableView *TableViewWindow::getTableView() const
{
    return ui->tableView;
}
