#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QWidget>
#include <QPushButton>
#include "delegates/mousehovercomposite.h"


class PushButton : protected QPushButton, private MouseHoverComposite
{
    Q_OBJECT
public:
    PushButton(QWidget *parent = 0);
    virtual void setSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical);
    virtual const QFont &font() const;
    virtual void setFont(const QFont &);
    virtual QSize sizeHint() const { return m_size; }
    virtual void setText(const QString &text);
    QWidget *Widget() { return this; }
signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    Q_DISABLE_COPY(PushButton)
    void RecalcSize();

private:
    QSize m_size;

};

#endif // PUSHBUTTON_H
