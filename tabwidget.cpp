#include "tabwidget.h"
#include <QDebug>


TabWidget::TabWidget(QWidget *parent, int numOfTabs) :
    QWidget(parent),
    m_tabLayout(new QVBoxLayout()),
    m_buttonLayout(new QHBoxLayout())
{
    m_tabLayout->addLayout(m_buttonLayout);
    this->setLayout(m_tabLayout);
    for (int i = 0; i < numOfTabs; i++)
    {
        TabButtonWidget *button(new TabButtonWidget());
        button->setText(QString(tr("Tab %1")).arg(QString::number(i)));
        m_buttonLayout->addWidget(button);
    }
    qDebug() << width() << height();
}


TabWidget::~TabWidget()
{
    if (m_tabLayout)
        delete m_tabLayout;
}
