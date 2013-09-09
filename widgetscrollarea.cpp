#include "widgetscrollarea.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QFontMetrics>
#include "widgets.h"


WidgetScrollArea::WidgetScrollArea(QWidget *parent) :
    QScrollArea(parent)
{
    m_centralWidget = new QWidget(this);
    QVBoxLayout *centralLayout = new QVBoxLayout(m_centralWidget);
    m_centralWidget->setLayout(centralLayout);
    centralLayout->setContentsMargins(UI_LIST_LEFTMARGIN,
                                      UI_LIST_BOTTOMTOPMARGIN,
                                      UI_LIST_RIGHTMARGIN,
                                      UI_LIST_BOTTOMTOPMARGIN);
    centralLayout->setSpacing(0);
    centralLayout->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    m_centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_heading = new QLabel(tr("Backup Plans"));
    QFont f = m_heading->font();
    f.setPointSize(16);
    m_heading->setFont(f);
    m_heading->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    m_heading->setFixedHeight(m_heading->fontMetrics().lineSpacing() * 1.5);
    m_heading->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    centralLayout->addWidget(m_heading);
    this->setWidget(m_centralWidget);
    this->setWidgetResizable(true);
    this->setFrameRect(QRect(0, 0, 0, 0));
    this->setFrameShape(QFrame::NoFrame);
}


void WidgetScrollArea::append(QWidget *w)
{
    m_centralWidget->layout()->addWidget(w);
}
