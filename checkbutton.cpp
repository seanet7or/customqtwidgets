#include "checkbutton.h"


CheckButton::CheckButton(QWidget *parent) :
    PushButton(parent)
{
    setCheckable(true);
    m_checkedSvg.load(QString(":/checked"));
    m_uncheckedSvg.load(QString(":/unchecked"));
    setChecked(true);
    m_svgRenderer.load(QString(":/checked"));
}


void CheckButton::setSVG(const QString &name)
{

}
