#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidgetItem>
#include "item.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void handleMenuItemNew();
    void removeSelectedProduct();
    void handleItemClick(QListWidgetItem* item);
    void handleMenuItemEdit();
    void handleSaveItem();
    void handleLoadItems();

private:
    Ui::MainWindow *ui;
    QVector<Item*> productList;
};
#endif // MAINWINDOW_H
