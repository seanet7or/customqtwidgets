#include "pushbutton.h"
#include "delegates/mousehoverable.h"
#include <QWidget>


PushButton::PushButton(QWidget *parent) :
    QPushButton(parent),
    MouseHoverComposite(new MouseHoverable(this)),
    m_icon(),
    m_iconSize(128, 128)
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}


void PushButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing
                           | QPainter::TextAntialiasing
                           | QPainter::SmoothPixmapTransform,
                           true);
    DrawMouseHoverRect(painter);

    int iconHeight = 0;
    int textHeight = 0;
    int paintHeight = rect().height();
    iconHeight = ((qreal)paintHeight) * (((qreal)m_iconSize.height()) / ((qreal)m_size.height()));
    textHeight = ((qreal)paintHeight) * (((qreal)m_textSize.height()) / ((qreal)m_size.height()));
    if (textHeight > m_textSize.height() * 2)
    {
        textHeight = m_textSize.height() * 2;
        iconHeight = paintHeight - textHeight;
    }

    //yOff = std::min(iconHeight / 6, yOff);
    int length = std::min(iconHeight, rect().width());
    if (length > m_icon.width())
        length = m_icon.width();
    int xOff = (rect().width() - length) / 2;
    int yOff = (iconHeight - length) / 2;
    QRect target(xOff, yOff + textHeight,length, length);
    painter.drawPixmap(target,
                       m_icon,
                       m_icon.rect());
    painter.setFont(font());
    painter.drawText(0, 0, rect().width(), textHeight,
                     Qt::AlignCenter | Qt::TextWordWrap,
                     text());
}


void PushButton::setSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical)
{
    QPushButton::setSizePolicy(horizontal, vertical);
}


const QFont& PushButton::font() const
{
    return QPushButton::font();
}


void PushButton::RecalcSize()
{
    QRect textRect(0, 0, 0, 0);
    m_textSize = QSize(0, 0);
    if (text().length())
    {
        textRect = this->fontMetrics().boundingRect(0, 0, QWIDGETSIZE_MAX, QWIDGETSIZE_MAX,
                                                      Qt::AlignCenter, text());
        textRect.setWidth(textRect.width() + fontMetrics().averageCharWidth() * 4);
        textRect.setHeight(textRect.height() + fontMetrics().lineSpacing());
        m_textSize = textRect.size();
    }
    m_size = QSize(std::max(m_iconSize.width(), textRect.width()), m_iconSize.height() + textRect.height());

    setMinimumSize(m_size);
}


void PushButton::setFont(const QFont &f)
{
    QPushButton::setFont(f);
    RecalcSize();
    update();
}


void PushButton::setText(const QString &text)
{
    QPushButton::setText(text);
    RecalcSize();
    update();
}


void PushButton::setPixmap(QPixmap p)
{
    m_icon = p;
    RecalcSize();
    update();
}
