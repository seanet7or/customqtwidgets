#include "iconbutton.h"
#include "delegates/fadableitemcomposite.h"
#include "delegates/fadableitem.h"
#include "widgetsettings.h"
#include "delegates/mousehoverable.h"


IconButton::IconButton(QWidget *fader) :
    FadableItemComposite(this, fader),
    MouseHoverComposite(new MouseHoverable(this))
{
    setMouseHoverColor(WidgetSettings::iconButtonMouseOverColor());
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    RecalcSize();
}


QSize IconButton::sizeHint() const
{
    return m_size;
}


QSize IconButton::minimumSizeHint() const
{
    return m_size;
}


void IconButton::paintEvent(QPaintEvent *)
{
    int xOff = (rect().width() - m_size.width()) / 2;
    int yOff = (rect().height() - m_size.height()) / 2;
    QRect target(xOff + WidgetSettings::iconButtonMargins(),
                 yOff + WidgetSettings::iconButtonMargins(),
                 m_size.width() - WidgetSettings::iconButtonMargins() * 2,
                 m_size.height() - WidgetSettings::iconButtonMargins() * 2);
    QPainter painter(this);
    DrawMouseHoverRect(painter);
    m_svgRenderer.render(&painter, target);
}


void IconButton::resizeEvent(QResizeEvent *)
{
    RecalcSize();
}


void IconButton::RecalcSize()
{
    int h = rect().height();
    if (h < (WidgetSettings::minimalIconSize().width() + 2 * WidgetSettings::iconButtonMargins()))
    {
        h = WidgetSettings::minimalIconSize().width() + 2 * WidgetSettings::iconButtonMargins();
    }
    m_size = QSize(h, h);
    setFixedSize(m_size);
}


void IconButton::setSVG(const QString &name)
{
    m_svgRenderer.load(name);
}
