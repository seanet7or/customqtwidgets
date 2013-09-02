#ifndef MOUSEHOVERDELEGATE_H
#define MOUSEHOVERDELEGATE_H
#include <QPainter>
#include <QRect>


class MouseHoverDelegate
{
public:
    virtual void DrawMouseHoverRect(QPainter &painter) const = 0;
};

#endif // MOUSEHOVERDELEGATE_H
