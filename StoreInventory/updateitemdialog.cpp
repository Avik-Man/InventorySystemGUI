#include "updateitemdialog.h"
#include "ui_updateitemdialog.h"
#include<QFileDialog>
#include<QMessageBox>
updateItemDialog::updateItemDialog(Item* currentItem,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateItemDialog)
{
    ui->setupUi(this);
    this->currentItem = currentItem;
    if(currentItem !=nullptr)
    {
        ui->lblItemName->setText(currentItem->getName());
        QPixmap pixmap(currentItem->getImageFIlePath());
        ui->lblImage->setPixmap(pixmap);
        ui->quantity->setValue(currentItem->getQuantity());
        imageFilePath = currentItem->getImageFIlePath();
    }
    connect(ui->btnconfirmEdit, &QPushButton::clicked, this, &updateItemDialog::confirmUpdate);
    connect(ui->btnLoadImage, &QPushButton::clicked, this, &updateItemDialog::loadItemImage);
}

updateItemDialog::~updateItemDialog()
{
    delete ui;
}

void updateItemDialog::confirmUpdate()
{
    int quantity = ui->quantity->value();
    if(quantity>=1)
    {
        currentItem->setQuantity(quantity);
        currentItem->setImageFIlePath(imageFilePath);
        this->close();
    }
    else
    {
        QMessageBox mb;
        mb.setText("Quantity should be more than 0");
        mb.exec();
    }
}


void updateItemDialog::loadItemImage()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Open Image","./","Image Files (*.png *.jpg)");

    if(filename != "")
    {
        int lastSlash= filename.lastIndexOf("/");
        QString shortName = filename.right(filename.size() - lastSlash -1);

        QFile::copy(filename, "./images/" +shortName);
        QPixmap pixmap("./images/" + shortName);
        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);
        ui->quantity->setValue(currentItem->getQuantity());


        imageFilePath = "./images/" + shortName;
    }
}
