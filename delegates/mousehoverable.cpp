#include "mousehoverable.h"
#include <QWidget>
#include <QEvent>
#include <QDebug>
#include "../widgets.h"
#include "../Animator.h"


MouseHoverable::MouseHoverable(QWidget *composite) :
    QObject(composite)
{
    composite->setMouseTracking(true);
    m_mouseOverColor = QColor(MOUSEOVERCOLOR);
    m_alpha = 0.0;
    m_lastMouseEvent = QTime::currentTime();
    m_animTimer = new QTimer();
    m_animTimer->setSingleShot(true);
    connect(m_animTimer, SIGNAL(timeout()), this, SLOT(RecalculateAlpha()));
    m_composite = composite;
    m_composite->installEventFilter(this);
    connect(m_composite, SIGNAL(destroyed(QObject*)), Animator::Instance(), SLOT(OnObjectDestroyed(QObject*)));
}


void MouseHoverable::DrawMouseHoverRect(QPainter &painter) const
{
    qreal old = painter.opacity();
    painter.setOpacity(m_alpha);
    painter.fillRect(m_composite->rect(), m_mouseOverColor);
    painter.setOpacity(old);
}


void MouseHoverable::RecalculateAlpha()
{
    if (m_lastMouseEvent.msecsTo(QTime::currentTime()) < MOUSEOVERDURATION)
    {
        m_alpha = (qreal)(m_lastMouseEvent.msecsTo(QTime::currentTime()));
        m_alpha /= (qreal)(MOUSEOVERDURATION);
        if (!m_composite->underMouse())
            m_alpha = 1.0 - m_alpha;
        m_animTimer->start(FRAMETIME / 2);
        Animator::UpdateNextFrame(m_composite);
    }
    else
    {
        if (!m_composite->underMouse())
            m_alpha = 0.0;
        else
            m_alpha = 1.0;
        Animator::UpdateNextFrame(m_composite);
    }
}


bool MouseHoverable::eventFilter(QObject *o, QEvent *e)
{
    if ((e->type() == QEvent::Enter) || (e->type() == QEvent::Leave))
    {
        int diff = m_lastMouseEvent.msecsTo(QTime::currentTime()) - MOUSEOVERDURATION;
        if (diff < 0)
        {
            m_lastMouseEvent = QTime::currentTime().addMSecs(diff);
        }
        else
            m_lastMouseEvent = QTime::currentTime();
        m_animTimer->start(FRAMETIME / 2);
    }
    return false;
}
