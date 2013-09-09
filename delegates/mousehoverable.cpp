#include "mousehoverable.h"
#include <qglobal.h>
#include <qplatformdefs.h>
#include <qsystemdetection.h>#include <QWidget>
#include <QEvent>
#include <QDebug>
#include <QTouchEvent>
#include "../widgets.h"
#include "../Animator.h"
#include "mainwindow.h"


MouseHoverable::MouseHoverable(QWidget *composite) :
    QObject(composite),
    m_hovered(false)
{
#ifdef Q_OS_ANDROID
    composite->setAttribute(Qt::WA_AcceptTouchEvents, true);
#endif
    composite->setMouseTracking(true);
    m_mouseOverColor = QColor(UI_MOUSEOVERCOLOR);
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
    if (m_lastMouseEvent.msecsTo(QTime::currentTime()) < UI_MOUSEOVERDURATION)
    {
        m_alpha = (qreal)(m_lastMouseEvent.msecsTo(QTime::currentTime()));
        m_alpha /= (qreal)(UI_MOUSEOVERDURATION);
        if (!m_composite->underMouse())
            m_alpha = 1.0 - m_alpha;
        m_animTimer->start(UI_FRAMETIME / 2);
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
    bool prevHovered = m_hovered;
    if (m_composite->underMouse())
    {
        m_hovered = true;
    }
    else
    {
        m_hovered = false;
    }
    if (prevHovered == m_hovered)
    {
        return false;
    }
    else
    {
        int diff = m_lastMouseEvent.msecsTo(QTime::currentTime()) - UI_MOUSEOVERDURATION;
        if (diff < 0)
        {
            m_lastMouseEvent = QTime::currentTime().addMSecs(diff);
        }
        else
            m_lastMouseEvent = QTime::currentTime();
        m_animTimer->start(UI_FRAMETIME / 2);
    }
    return false;

    QTouchEvent *te = static_cast<QTouchEvent*>(e);
    if ((!m_hovered) && (e->type() == QEvent::TouchBegin))
    {
        if (te->touchPoints().size() == 1)
        {
            QTouchEvent::TouchPoint p = te->touchPoints().at(0);
            if (m_composite->rect().contains(p.pos().x(), p.pos().y()))
            {
                m_hovered = true;
            }
        }
    }
    else if (e->type() == QEvent::TouchUpdate)
    {
        if (te->touchPoints().size() == 1)
        {
            QTouchEvent::TouchPoint p = te->touchPoints().at(0);
            if (m_composite->rect().contains(p.pos().x(), p.pos().y()))
            {
                m_hovered = true;
            }
            else
            {
                m_hovered = false;
            }
        }
    }
    else if (e->type() == QEvent::TouchCancel)
    {
        m_hovered = false;
    }
    else if (e->type() == QEvent::TouchEnd)
    {
        if (te->touchPoints().size() == 1)
        {
            m_hovered = false;
        }
    }
#ifndef Q_OS_ANDROID
    if (e->type() == QEvent::Enter)
    {
        m_hovered = true;
    }
    if (e->type() == QEvent::Leave)
    {
        m_hovered = false;
    }
#endif
    if (prevHovered == m_hovered)
    {
        return false;
    }
    if ((e->type() == QEvent::Enter) || (e->type() == QEvent::Leave)
            || (e->type() == QEvent::TouchBegin) || (e->type() == QEvent::TouchEnd))
    {
        int diff = m_lastMouseEvent.msecsTo(QTime::currentTime()) - UI_MOUSEOVERDURATION;
        if (diff < 0)
        {
            m_lastMouseEvent = QTime::currentTime().addMSecs(diff);
        }
        else
            m_lastMouseEvent = QTime::currentTime();
        m_animTimer->start(UI_FRAMETIME / 2);
    }
    return false;
}
