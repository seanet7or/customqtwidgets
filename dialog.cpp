#include "dialog.h"
#include <QVBoxLayout>


Dialog::Dialog(QWidget *p) : QDialog(p)
{
    this->setContentsMargins(0, 0, 0, 0);
    if (!layout())
    {
        this->setLayout(new QVBoxLayout(this));
        layout()->setContentsMargins(0, 0, 0, 0);
        layout()->setSpacing(0);
    }
}
