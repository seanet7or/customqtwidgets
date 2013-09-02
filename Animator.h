#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <QObject>
#include <QTimer>
#include <QSet>
#include "widgets.h"

// This will repaint the widgets given to UpdateNextFrame only once in FRAMETIME ms
// Singleton, as it is useful only once per application
class Animator : public QObject
{
    Q_OBJECT
public:
    // Paint when its time to draw the next frame
    // Widgets that are given to this method should connect their
    // destroyed() SIGNAL to the OnObjectDestroyed SLOT to prevent crashs
    static void UpdateNextFrame(QWidget *w);

    static Animator *Instance();

    ~Animator();
public slots:
    void OnObjectDestroyed(QObject *o);

private slots:
    void OnFrameTimerTimeout();

private:
    Q_DISABLE_COPY(Animator)

private:
    Animator();
    QTimer *m_frameTimer;
    QSet<QWidget*> m_dirtyWidgets;

};

#endif // ANIMATOR_H
