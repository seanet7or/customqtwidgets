#include "Animator.h"
#include <QWidget>


Animator::Animator() : QObject(), m_frameTimer(new QTimer(this))
{
    connect(m_frameTimer, SIGNAL(timeout()), this, SLOT(OnFrameTimerTimeout()));
}


Animator::~Animator()
{
    m_frameTimer->blockSignals(true);
    m_frameTimer->disconnect();
    delete m_frameTimer;
}


Animator *Animator::Instance()
{
    static Animator inst;
    return &inst;
}


void Animator::OnObjectDestroyed(QObject *o)
{
    QWidget *w = qobject_cast<QWidget*>(o);
    if (w)
    {
        m_dirtyWidgets.remove(w);
    }
}


void Animator::OnFrameTimerTimeout()
{
    if (m_dirtyWidgets.isEmpty())
    {
        m_frameTimer->stop();
    }
    else
    {
        foreach (QWidget *w, m_dirtyWidgets)
        {
            w->update();
        }
        m_dirtyWidgets.clear();
    }
}


void Animator::UpdateNextFrame(QWidget *w)
{
    Animator *inst = Animator::Instance();
    if (!inst->m_frameTimer->isActive())
    {
        inst->m_frameTimer->start(UI_FRAMETIME);
    }
    inst->m_dirtyWidgets.insert(w);
}
