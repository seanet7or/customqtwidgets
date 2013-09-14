#include "pushbutton.h"
#include "delegates/mousehoverable.h"
#include <QWidget>
#include <QDebug>
#include "widgetsettings.h"
#include "widgets.h"
#include "delegates/fadableitem.h"


PushButton::PushButton(QWidget *fader, QWidget *parent) :
    QPushButton(parent),
    MouseHoverComposite(new MouseHoverable(this)),
    FadableItemComposite(new FadableItem(this, fader)),
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
    FadableItemComposite::DrawAlpha(&painter);
    painter.setPen(QPen(QColor(132, 132, 132)));
    int xMargin = WidgetSettings::pushButtonLeftRightMargins();
    int yMargin = WidgetSettings::pushButtonTopBottomMargins();
    painter.drawRect(rect().x() + xMargin,
                     rect().y() + yMargin,
                     rect().width() - xMargin * 2,
                     rect().height() - yMargin * 2);
    int yIconMargin = WidgetSettings::pushButtonIconTopBottomMargins();
    int xIconMargin = WidgetSettings::pushButtonIconLeftRightMargins();
    int yTextMargin = WidgetSettings::pushButtonTextTopBottomMargins();
    int xTextMargin = WidgetSettings::pushButtonTextLeftRightMargins();

    int freeXSpace = rect().width() - m_textSize.width() - m_iconSize.width()
            - 2 * xMargin - 2 * xIconMargin - 2 * xTextMargin;
    QRect target(xMargin + xIconMargin + (freeXSpace * 3) / 8,
                 yMargin + yIconMargin,
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
                     yMargin + yTextMargin,
                     m_textSize.width(),
                     m_textSize.height(),
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
        textRect.setWidth(textRect.width() + fontMetrics().averageCharWidth() * 2);
        textRect.setHeight(fontMetrics().lineSpacing());
        m_textSize = textRect.size();
    }
    int iconLength = m_textSize.height()
            + 2 * WidgetSettings::pushButtonTextTopBottomMargins()
            - 2 * WidgetSettings::pushButtonIconTopBottomMargins();
    m_iconSize = QSize(iconLength, iconLength);
    m_size = QSize(m_textSize.width() + 2 * WidgetSettings::pushButtonTextLeftRightMargins()
                   + m_iconSize.width() + 2 * WidgetSettings::pushButtonIconLeftRightMargins()
                   + 2 * WidgetSettings::pushButtonLeftRightMargins(),
                   textRect.height()
                   + WidgetSettings::pushButtonTextTopBottomMargins() * 2
                   + WidgetSettings::pushButtonTopBottomMargins() * 2);
    setMinimumSize(m_size);
    QSize maxSize(m_size.width() * 0.8, m_size.height() * 0.8);
    setMaximumSize(maxSize);
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

