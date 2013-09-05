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
    connect(this, SIGNAL(clicked()), this, SLOT(onClicked()));
}


QSize TabButtonWidget::sizeHint()
{
    return m_minSize;
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
    int textYPos = 0;
    if (!m_pixmap.isNull()) {
        int xOff = ((rect().width() - m_pixmap.width()) / 2);
        painter.drawPixmap(rect().x() + xOff, rect().y() + TABBUTTON_ICONTOPMARGIN,
                           m_pixmap.width(), m_pixmap.height(), m_pixmap);
        textYPos += m_pixmap.height() + TABBUTTON_ICONTOPMARGIN;
    }
    // Text
    painter.setPen(QColor(TABTEXTCOLOR));
    painter.setFont(font());
    painter.drawText(rect().x(),
                     rect().y() + textYPos,
                     rect().width(),
                     rect().height() - textYPos,
                     Qt::AlignCenter | Qt::TextWordWrap,
                     text());
}


void TabButtonWidget::onClicked()
{
    if (m_tabWidget->activeButton() != this) {
        m_tabWidget->setActiveButton(this);
    }
}


void TabButtonWidget::setPixmap(QPixmap p)
{
    m_pixmap = p;
    recalcSize();
}


void TabButtonWidget::recalcSize()
{
    m_minSize = QSize(0, 0);
    if (text().length())
    {
        QRect textRect = this->fontMetrics().boundingRect(0, 0, QWIDGETSIZE_MAX, QWIDGETSIZE_MAX,
                                                          Qt::AlignCenter, text());
        textRect.setWidth(textRect.width() + fontMetrics().averageCharWidth() * 4);
        textRect.setHeight(textRect.height());
        m_minSize.setHeight(m_minSize.height() + textRect.height());
        m_minSize.setWidth(std::max(m_minSize.width(), m_pixmap.width()));
    }
    if (!(m_pixmap.isNull()))
    {
        m_minSize.setWidth(std::max(m_minSize.width(), m_pixmap.width()));
        m_minSize.setHeight(m_minSize.height() + TABBUTTON_ICONTOPMARGIN + m_pixmap.height());
    }
    setMinimumSize(m_minSize);
}


void TabButtonWidget::setText(const QString &text)
{
    QPushButton::setText(text);
    recalcSize();
}
