#ifndef MOUSEHOVERDELEGATE_H
#define MOUSEHOVERDELEGATE_H
#include <QPainter>
#include <QRect>
#include <QColor>


class MouseHoverDelegate
{
public:
    virtual ~MouseHoverDelegate() = 0;
    virtual void DrawMouseHoverRect(QPainter &painter) const = 0;
    virtual void setMouseHoverColor(QColor color) = 0;
};


inline MouseHoverDelegate::~MouseHoverDelegate()
{

}

#endif // MOUSEHOVERDELEGATE_H
