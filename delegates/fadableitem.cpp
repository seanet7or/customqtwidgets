#include "fadableitem.h"
#include <qglobal.h>
#include <qplatformdefs.h>
#include <qsystemdetection.h>
#include <QWidget>
#include <QEvent>
#include <QDebug>
#include <QTouchEvent>
#include "../widgets.h"
#include "../Animator.h"


FadableItem::FadableItem(QWidget *composite, QWidget *fader) :
    QObject(composite),
    m_visible(false),
    m_fader(fader)
{
    fader->setMouseTracking(true);
    m_alpha = 0.0;
    m_lastMouseEvent = QTime::currentTime().addMSecs( - 2 * UI_MOUSEOVERDURATION);
    m_animTimer = new QTimer();
    m_animTimer->setSingleShot(true);
    connect(m_animTimer, SIGNAL(timeout()), this, SLOT(FadableItemRecalculateAlpha()));
    m_composite = composite;
    fader->installEventFilter(this);
    connect(m_composite, SIGNAL(destroyed(QObject*)), Animator::Instance(), SLOT(OnObjectDestroyed(QObject*)));
}


void FadableItem::DrawAlpha(QPainter *painter) const
{
    painter->setOpacity(m_alpha);
}


void FadableItem::FadableItemRecalculateAlpha()
{
    if (m_lastMouseEvent.msecsTo(QTime::currentTime()) < UI_MOUSEOVERDURATION)
    {
        m_alpha = (qreal)(m_lastMouseEvent.msecsTo(QTime::currentTime()));
        m_alpha /= (qreal)(UI_MOUSEOVERDURATION);
        if (!m_visible)
            m_alpha = 1.0 - m_alpha;
        m_animTimer->start(UI_FRAMETIME / 2);
        Animator::UpdateNextFrame(m_composite);
    }
    else
    {
        if (!m_visible)
            m_alpha = 0.0;
        else
            m_alpha = 1.0;
        Animator::UpdateNextFrame(m_composite);
    }
}


bool FadableItem::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::Enter)
    {
        m_visible = true;
    }
    if (e->type() == QEvent::Leave)
    {
        m_visible = false;
    }
    if ((e->type() == QEvent::Enter) || (e->type() == QEvent::Leave))
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
