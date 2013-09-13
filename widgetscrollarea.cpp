#include "widgetscrollarea.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QFontMetrics>
#include <QSpacerItem>
#include "widgets.h"
#include "widgetsettings.h"


WidgetScrollArea::WidgetScrollArea(const QString &caption,
                                   const QString hint,
                                   QWidget *parent) :
    QScrollArea(parent),
    m_helpLabel(WidgetSettings::newHelpLabel()),
    m_buttonLayout(new QHBoxLayout())
{
    m_helpLabel->setText(hint);
    m_centralWidget = new QWidget(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(m_centralWidget);
    m_centralWidget->setLayout(centralLayout);
    centralLayout->setContentsMargins(UI_LIST_LEFTMARGIN,
                                      UI_LIST_BOTTOMTOPMARGIN,
                                      UI_LIST_RIGHTMARGIN,
                                      UI_LIST_BOTTOMTOPMARGIN);
    centralLayout->setSpacing(0);
    centralLayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    m_buttonLayout->setContentsMargins(0, 0, 0, 0);
    m_buttonLayout->setSpacing(0);
    m_buttonLayout->setAlignment(m_buttonLayout, Qt::AlignRight | Qt::AlignVCenter);
    m_centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_heading = WidgetSettings::newHeading3Label();
    m_heading->setText(caption);

    centralLayout->addWidget(m_heading);
    centralLayout->addLayout(m_buttonLayout);
    this->setWidget(m_centralWidget);
    this->setWidgetResizable(true);
    this->setFrameRect(QRect(0, 0, 0, 0));
    this->setFrameShape(QFrame::NoFrame);
    append(m_helpLabel);
}


void WidgetScrollArea::append(QWidget *w)
{
    m_centralWidget->layout()->addWidget(w);
}


void WidgetScrollArea::addButton(QWidget *b)
{
    for (int i = 0; i < m_buttonLayout->count(); i++)
    {
        QSpacerItem *si = m_buttonLayout->itemAt(i)->spacerItem();
        if (si)
        {
            m_buttonLayout->removeItem(si);
            delete si;
            i--;
        }
    }
    m_buttonLayout->insertItem(0, new QSpacerItem(0, 10,
                                                  QSizePolicy::Expanding,
                                                  QSizePolicy::Ignored));
    m_buttonLayout->addWidget(b);
    m_buttonLayout->addSpacerItem(new QSpacerItem(0, 10,
                                                  QSizePolicy::Expanding,
                                                  QSizePolicy::Ignored));
}
