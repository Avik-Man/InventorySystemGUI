#include "additemdialog.h"
#include "ui_additemdialog.h"

#include<QDir>
#include<QMessageBox>
#include<QFileDialog>
#include<QFile>

AddItemDialog::AddItemDialog(Item*& newItem,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
    this->newItem = &newItem;
    imageFilePath = "none.png";
    connect(ui->btnAddItem, &QPushButton::clicked, this, &AddItemDialog::confirmAdd);
    connect(ui->btnLoadImage, &QPushButton::clicked, this, &AddItemDialog::loadItemImage);
    QDir pathDir("./images");
    if(!pathDir.exists())
    {
        QDir().mkdir("./images");
    }
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}


void AddItemDialog::confirmAdd()
{
    QString productName = ui->productName->text();

    int quantity = ui->quantity->value();
    if(productName.trimmed()!= "" && quantity >=1)
    {
        *newItem = new Item(productName,quantity,imageFilePath);
        this->close();
    }
    else
    {
        QMessageBox mb;
        mb.setText("Enter valid product details!!!");
        mb.exec();
    }
}

void AddItemDialog::loadItemImage()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Open Image", "./","Image Files (*.png *.jpg)");
    if(filename != "")
    {
        int lastSlash= filename.lastIndexOf("/");
        QString shortName = filename.right(filename.size() - lastSlash -1);

        QFile::copy(filename, "./images/" +shortName);
        QPixmap pixmap("./images/" + shortName);
        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);


        imageFilePath = "./images/" + shortName;
    }
}













