#ifndef FADABLEITEM_H
#define FADABLEITEM_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include "fadeitemdelegate.h"


class FadableItem : public QObject, public FadeItemDelegate
{
    Q_OBJECT
public:
    explicit FadableItem(QWidget *composite, QWidget *fader);

signals:

protected:

private slots:
    void FadableItemRecalculateAlpha();

private:
    bool eventFilter(QObject *, QEvent *);

private:
    qreal m_alpha;
    QTime m_lastMouseEvent;
    QTimer *m_animTimer;
    QWidget *m_composite;
    QWidget *m_fader;
    QGraphicsOpacityEffect *m_effect;
    bool m_visible;
};

#endif // MOUSEHOVERABLE_H
