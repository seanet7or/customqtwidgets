#ifndef MOUSEHOVERABLE_H
#define MOUSEHOVERABLE_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include "MouseHoverDelegate.h"


class MouseHoverable : public QObject, public MouseHoverDelegate
{
    Q_OBJECT
public:
    explicit MouseHoverable(QWidget *composite);
    void DrawMouseHoverRect(QPainter &painter) const;

signals:

protected:

private slots:
    void RecalculateAlpha();

private:
    bool eventFilter(QObject *, QEvent *);

private:
    QColor m_mouseOverColor;
    qreal m_alpha;
    QTime m_lastMouseEvent;
    QTimer *m_animTimer;
    QWidget *m_composite;
    bool m_hovered;
};

#endif // MOUSEHOVERABLE_H
