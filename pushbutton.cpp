#include "pushbutton.h"
#include "delegates/mousehoverable.h"


PushButton::PushButton(QWidget *parent) :
    QPushButton(parent),
    MouseHoverComposite(new MouseHoverable(this))
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}


void PushButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    DrawMouseHoverRect(painter);

    painter.setFont(font());
    painter.drawText(rect(),
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
    QRect textRect = this->fontMetrics().boundingRect(0, 0, QWIDGETSIZE_MAX, QWIDGETSIZE_MAX,
                                                      Qt::AlignCenter, text());
    textRect.setWidth(textRect.width() + fontMetrics().averageCharWidth() * 4);
    textRect.setHeight(textRect.height() + fontMetrics().lineSpacing());
    m_size = QSize(textRect.width(), textRect.height());
    setMinimumSize(m_size);
}


void PushButton::setFont(const QFont &f)
{
    QPushButton::setFont(f);
    RecalcSize();
}


void PushButton::setText(const QString &text)
{
    QPushButton::setText(text);
    RecalcSize();
}


void PushButton::update()
{
    QPushButton::update();
}
