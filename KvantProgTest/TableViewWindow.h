#ifndef TABLEVIEWWINDOW_H
#define TABLEVIEWWINDOW_H

#include <QWidget>
#include <QTableView>

namespace Ui {
class TableViewWindow;
}

class TableViewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TableViewWindow(QWidget *parent = nullptr);
    ~TableViewWindow();

    QTableView* getTableView() const;

private:
    Ui::TableViewWindow *ui;
};

#endif // TABLEVIEWWINDOW_H
