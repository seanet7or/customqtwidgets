#ifndef FADEITEMDELEGATE_H
#define FADEITEMDELEGATE_H
#include <QPainter>
#include <QRect>


class FadeItemDelegate
{
public:
    virtual void DrawAlpha(QPainter *p) const = 0;
    virtual ~FadeItemDelegate() {}
};

#endif // MOUSEHOVERDELEGATE_H
