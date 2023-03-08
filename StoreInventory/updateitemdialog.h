#ifndef UPDATEITEMDIALOG_H
#define UPDATEITEMDIALOG_H

#include <QDialog>
#include "item.h"
namespace Ui {
class updateItemDialog;
}

class updateItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit updateItemDialog(Item* currentItem ,QWidget *parent = nullptr);
    ~updateItemDialog();

    void confirmUpdate();
    void loadItemImage();

private:
    Ui::updateItemDialog *ui;
    Item* currentItem;
    QString imageFilePath;
};

#endif // UPDATEITEMDIALOG_H
