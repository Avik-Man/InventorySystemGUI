#include "item.h"

Item::Item(QString name, int quantity,QString imageFilePath)
{
    this->name = name;
    this->quantity = quantity;
    this->imageFilePath= imageFilePath;
}
void Item::setName(QString name)
{
    this->name = name;
}
QString Item::getName() const
{
    return name;
}

void Item::setQuantity(int quantity)
{
    this->quantity = quantity;
}
int Item::getQuantity() const
{
    return quantity;
}

void Item::setImageFIlePath(QString imageFilePath)
{
    this->imageFilePath = imageFilePath;
}
QString Item::getImageFIlePath() const
{
    return imageFilePath;
}
