#include "tabwidget.h"
#include <QDebug>


TabWidget::TabWidget(QWidget *parent, int numOfTabs) :
    QWidget(parent),
    m_tabLayout(new QVBoxLayout()),
    m_buttonLayout(new QHBoxLayout()),
    m_activeButton(NULL)
{
    m_tabLayout->addLayout(m_buttonLayout);
    this->setLayout(m_tabLayout);
    layout()->setContentsMargins(0, 0, 0, 0);
    layout()->setSpacing(0);
    m_tabLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    m_buttonLayout->setContentsMargins(0, 0, 0, 0);
    m_buttonLayout->setSpacing(0);
    for (int i = 0; i < numOfTabs; i++)
    {
        TabButtonWidget *button(new TabButtonWidget(this));
        if (!m_activeButton) {
            m_activeButton = button;
        }
        button->setText(QString(tr("Tab %1")).arg(QString::number(i)));
        m_buttonLayout->addWidget(button);
        m_tabButtons << button;
    }
    //qDebug() << width() << height();
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}


TabWidget::~TabWidget()
{
    if (m_tabLayout)
        delete m_tabLayout;
}


void TabWidget::resizeEvent(QResizeEvent *e)
{
    int totalWidth = width();
    int buttonWidth = 0;

}


TabButtonWidget *TabWidget::activeButton() const
{
    return m_activeButton;
}


void TabWidget::setActiveButton(TabButtonWidget *bn)
{
    if (bn != activeButton()) {
        if (m_tabButtons.contains(bn)) {
            TabButtonWidget *prev = activeButton();
            m_activeButton = bn;
            prev->update();
            bn->update();
        }
    }
}
