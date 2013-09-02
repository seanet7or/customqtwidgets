#include "tabbuttonwidget.h"
#include <QPainter>
#include <QDebug>
#include "tabwidget.h"
#include "widgets.h"


TabButtonWidget::TabButtonWidget(TabWidget *parent) :
    QPushButton(parent),
    m_minSize(size()),
    m_tabWidget(parent)
{
    sizeHint();
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
}


QSize TabButtonWidget::sizeHint()
{
    QRect textRect = this->fontMetrics().boundingRect(0, 0, QWIDGETSIZE_MAX, QWIDGETSIZE_MAX,
                                                      Qt::AlignCenter, text());
    textRect.setWidth(textRect.width() + fontMetrics().averageCharWidth() * 4);
    textRect.setHeight(textRect.height() + fontMetrics().lineSpacing());
    m_minSize = QSize(textRect.width(), textRect.height());
    setMinimumSize(m_minSize);
}


void TabButtonWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if (m_tabWidget->activeButton() == this) {
        painter.fillRect(rect(), QColor(TABACTIVEBNCOLOR));
        painter.fillRect(rect().x(), rect().y(), 1, rect().height(), QColor(TABBORDERCOLOR1));
        painter.fillRect(rect().x() + 1, rect().y() + 1, 2, rect().height() - 1, QColor(TABBORDERCOLOR2));
        painter.fillRect(rect().right(), rect().y(), 1, rect().height(), QColor(TABBORDERCOLOR1));
        painter.fillRect(rect().right() - 2, rect().y() + 1, 2, rect().height() - 1, QColor(TABBORDERCOLOR2));
        painter.fillRect(rect().x(), (rect().y()), rect().width(), 1, QColor(TABBORDERCOLOR1));
        painter.fillRect(rect().x() + 1, (rect().y() + 1), rect().width() - 2, 2, QColor(TABBORDERCOLOR2));
    } else {
        painter.fillRect(rect(), QColor(TABINACTIVEBNCOLOR));
        painter.fillRect(rect().x(), (rect().bottom()), rect().width(), 1, QColor(TABBORDERCOLOR1));
        painter.fillRect(rect().x(), (rect().bottom() - 2), rect().width(), 2, QColor(TABBORDERCOLOR2));
    }
    painter.setPen(QColor(TABTEXTCOLOR));
    painter.setFont(font());
    painter.drawText(rect(),
                     Qt::AlignCenter | Qt::TextWordWrap,
                     text());
}
