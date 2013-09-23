#include <QWidget>
#include <QDebug>
#include "widgetsettings.h"
#include "widgets.h"
#include "delegates/fadableitem.h"
#include "pushbutton.h"
#include "delegates/mousehoverable.h"


PushButton::PushButton(QWidget *parent) :
    QPushButton(parent),
    MouseHoverComposite(new MouseHoverable(this)),
    m_icon()
{
    setFont(WidgetSettings::buttonFont());
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    setContentsMargins(WidgetSettings::pushButtonLeftRightMargins(),
                       WidgetSettings::pushButtonTopBottomMargins(),
                       WidgetSettings::pushButtonLeftRightMargins(),
                       WidgetSettings::pushButtonTopBottomMargins());
}


void PushButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing
                           | QPainter::TextAntialiasing
                           | QPainter::SmoothPixmapTransform,
                           true);
    DrawMouseHoverRect(painter);
    painter.setPen(QPen(QColor(132, 132, 132)));
    painter.drawRect(rect().x() + contentsMargins().left(),
                     rect().y() + contentsMargins().top(),
                     rect().width() - (contentsMargins().left() + contentsMargins().left()),
                     rect().height() - (contentsMargins().top() + contentsMargins().bottom()));
    int xIconMargin = WidgetSettings::pushButtonIconLeftRightMargins();
    int xTextMargin = WidgetSettings::pushButtonTextLeftRightMargins();

    int freeXSpace = rect().width() - m_textSize.width() - m_iconSize.width()
            - (contentsMargins().left() + contentsMargins().left()) - 2 * xIconMargin - 2 * xTextMargin;
    QRect target(contentsMargins().left() + xIconMargin + (freeXSpace * 3) / 8,
                 (rect().height() - m_iconSize.height()) / 2,
                 m_iconSize.width(),
                 m_iconSize.height());
    if (m_svgRenderer.isValid())
    {
        m_svgRenderer.render(&painter, target);
    }
    painter.setFont(font());
    painter.setPen(QPen(QColor(0, 0, 0)));

    painter.drawText(target.x() + xIconMargin + m_iconSize.width()
                     + (freeXSpace * 2) / 8 + xTextMargin,
                     0,
                     m_textSize.width(),
                     rect().height(),
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

    textRect = this->fontMetrics().boundingRect(0, 0, QWIDGETSIZE_MAX, QWIDGETSIZE_MAX,
                                                      Qt::AlignCenter, text());
    textRect.setWidth(textRect.width() + fontMetrics().averageCharWidth() * 2);
    if (!text().length())
    {
        textRect.setWidth(0);
    }
    textRect.setHeight(fontMetrics().lineSpacing());
    m_textSize = textRect.size();

    int iconLength = m_textSize.height()
            + 2 * WidgetSettings::pushButtonTextTopBottomMargins()
            - 2 * WidgetSettings::pushButtonIconTopBottomMargins();
    m_iconSize = QSize(iconLength, iconLength);
    if (!text().length())
    {
        m_size = QSize(m_iconSize.width() + 2 * WidgetSettings::pushButtonIconLeftRightMargins()
                   + (contentsMargins().left() + contentsMargins().right()),
                   textRect.height()
                   + WidgetSettings::pushButtonTextTopBottomMargins() * 2
                   + (contentsMargins().top() + contentsMargins().bottom()));
    }
    else
    {
        m_size = QSize(m_textSize.width() + 2 * WidgetSettings::pushButtonTextLeftRightMargins()
                   + m_iconSize.width() + 2 * WidgetSettings::pushButtonIconLeftRightMargins()
                   + (contentsMargins().left() + contentsMargins().right()),
                   textRect.height()
                   + WidgetSettings::pushButtonTextTopBottomMargins() * 2
                   + (contentsMargins().top() + contentsMargins().bottom()));
    }
    setMinimumSize(m_size);
    //QSize maxSize(m_size.width() * 0.8, m_size.height() * 0.8);
    //setMaximumSize(maxSize);
}


void PushButton::setFont(const QFont &f)
{
    QPushButton::setFont(f);
    RecalcSize();
    update();
}


QSize PushButton::sizeHint() const
{
    return m_size;
}


QSize PushButton::minimumSizeHint() const
{
    return m_size;
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

