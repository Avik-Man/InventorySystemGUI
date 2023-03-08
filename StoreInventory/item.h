#ifndef ITEM_H
#define ITEM_H

#include<QString>

class Item{
    private:
        QString name;
        int quantity;
        QString imageFilePath;
    public:
        Item(QString name, int quantity,QString imageFilePath= "none.png");


        void setName(QString name);
        QString getName() const;

        void setQuantity(int quantity);
        int getQuantity() const;

        void setImageFIlePath(QString imageFilePath);
        QString getImageFIlePath() const;
};

#endif // ITEM_H
