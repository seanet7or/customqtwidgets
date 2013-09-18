#ifndef FADABLEITEMCOMPOSITE_H
#define FADABLEITEMCOMPOSITE_H

#include "fadeitemdelegate.h"
#include "fadableitem.h"

class FadableItemComposite : public FadeItemDelegate
{
public:
    FadableItemComposite(QWidget *composite, QWidget *fader);
    ~FadableItemComposite();
private:
    FadeItemDelegate *m_fadeItemDelegate;
};


inline FadableItemComposite::FadableItemComposite(QWidget *composite, QWidget *fader)
    : m_fadeItemDelegate(new FadableItem(composite, fader))
{
}


inline FadableItemComposite::~FadableItemComposite()
{
    delete m_fadeItemDelegate;
}

#endif // FADABLEITEMCOMPOSITE_H
