#ifndef CHECKBUTTON_H
#define CHECKBUTTON_H
#include <QWidget>
#include <QCheckBox>
#include <QSvgRenderer>
#include "pushbutton.h"


class CheckButton : public PushButton
{
    Q_OBJECT
public:
    explicit CheckButton(QWidget *parent = 0);

signals:

public slots:

protected:
    virtual void setSVG(const QString &name);

private:
    QSvgRenderer m_checkedSvg;
    QSvgRenderer m_uncheckedSvg;
};

#endif // CHECKBUTTON_H
