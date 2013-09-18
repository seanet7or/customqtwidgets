#include "checkbutton.h"


CheckButton::CheckButton(QWidget *parent) :
    PushButton(parent),
    FadableItemComposite(this, parent)
{
    setCheckable(true);
    setChecked(true);
    m_svgRenderer.load(QString(":/checked"));
    connect(this,
            SIGNAL(toggled(bool)),
            this,
            SLOT(onToggled(bool)));
}


void CheckButton::setSVG(const QString &name)
{

}


void CheckButton::onToggled(bool checked)
{
    if (checked)
    {
        m_svgRenderer.load(QString(":/checked"));
    }
    else
    {
        m_svgRenderer.load(QString(":/unchecked"));
    }
}
