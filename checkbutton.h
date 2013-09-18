#ifndef CHECKBUTTON_H
#define CHECKBUTTON_H
#include <QWidget>
#include <QCheckBox>
#include <QSvgRenderer>
#include "pushbutton.h"
#include "delegates/fadableitemcomposite.h"


class CheckButton : public PushButton, public FadableItemComposite
{
    Q_OBJECT
public:
    explicit CheckButton(QWidget *parent = 0);

signals:

public slots:

protected:
    virtual void setSVG(const QString &name);

private slots:
    void onToggled(bool checked);

private:
};

#endif // CHECKBUTTON_H
