#include "pushbutton.h"
#include "delegates/mousehoverable.h"
#include <QWidget>
#include <QDebug>
#include "widgetsettings.h"


PushButton::PushButton(QWidget *parent) :
    QPushButton(parent),
    MouseHoverComposite(new MouseHoverable(this)),
    m_icon()
{
    setFont(WidgetSettings::buttonFont());
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
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
    if (!(m_icon.isNull()) || (m_svgRenderer.isValid()))
    {
        if (true) //(m_textSize.width() <= (rect().width() / 2))
        {
            int length = rect().height();
            if (length > (rect().width() - m_textSize.width()))
            {
                length = rect().width() - m_textSize.width();
            }
            if (length > m_textSize.height() * 1.5)
                length = m_textSize.height() * 1.5;
            int freeXSpace = rect().width() - m_textSize.width() - length;
            QRect target((freeXSpace * 3) / 8,
                         (rect().height() - length) / 2,
                         length,
                         length);
            if (m_svgRenderer.isValid())
            {
                m_svgRenderer.render(&painter, target);
            }
            else if (!m_icon.isNull())
            {
                painter.drawPixmap(target,
                                   m_icon,
                                   m_icon.rect());
            }
            painter.setFont(font());
            painter.drawText(target.x() + length + (freeXSpace * 2) / 8,
                             0,
                             m_textSize.width(),
                             rect().height(),
                             Qt::AlignCenter | Qt::TextWordWrap,
                             text());
        }
        else
        {
            QSize iconSize(WidgetSettings::iconSize());
            iconHeight = ((qreal)paintHeight) * (((qreal)iconSize.height()) / ((qreal)m_size.height()));
            textHeight = ((qreal)paintHeight) * (((qreal)m_textSize.height()) / ((qreal)m_size.height()));
            if (textHeight > m_textSize.height() * 2)
            {
                textHeight = m_textSize.height() * 2;
                iconHeight = paintHeight - textHeight;
            }

            //yOff = std::min(iconHeight / 6, yOff);
            int length = std::min(iconHeight, rect().width());
            int xOff = (rect().width() - length) / 2;
            int yOff = (iconHeight - length) / 2;
            QRect target(xOff, yOff + textHeight,length, length);
            if (m_svgRenderer.isValid())
            {
                m_svgRenderer.render(&painter, target);
            }
            else if (!m_icon.isNull())
            {
                if (length > m_icon.width())
                {
                    length = m_icon.width();
                    xOff = (rect().width() - length) / 2;
                    yOff = (iconHeight - length) / 2;
                    target.setRect(xOff, yOff + textHeight, length, length);
                }
                painter.drawPixmap(target,
                                   m_icon,
                                   m_icon.rect());
            }
            painter.setFont(font());
            painter.drawText(0, 0, rect().width(), textHeight,
                             Qt::AlignCenter | Qt::TextWordWrap,
                             text());
        }
    }
    else
    {

    }
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
        textRect.setWidth(textRect.width() + fontMetrics().averageCharWidth() * 2);
        textRect.setHeight(textRect.height() + fontMetrics().lineSpacing());
        m_textSize = textRect.size();
    }
    m_size = QSize(textRect.width() + textRect.height(), textRect.height());
    setMinimumSize(m_size);
}


void PushButton::setFont(const QFont &f)
{
    QPushButton::setFont(f);
    RecalcSize();
    update();
}

QSize PushButton::sizeHint()
{
    return WidgetSettings::iconSize();
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


void PushButton::setSVG(const QString &name)
{
    m_svgRenderer.load(name);
    if (m_svgRenderer.isValid())
    {
        m_icon = QPixmap();
        RecalcSize();
        update();
    }
    else
    {
        qDebug() << "ERROR: Could not load svg " << name;
    }
}


void PushButton::resizeEvent(QResizeEvent *)
{
    RecalcSize();
}
