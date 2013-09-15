#ifndef FADABLEITEMCOMPOSITE_H
#define FADABLEITEMCOMPOSITE_H

#include "fadeitemdelegate.h"

class FadableItemComposite : public FadeItemDelegate
{
public:
    FadableItemComposite(FadeItemDelegate *delegate);
    ~FadableItemComposite();
    void DrawAlpha(QPainter *painter) const { m_fadeItemDelegate->DrawAlpha(painter); }
private:
    FadeItemDelegate *m_fadeItemDelegate;
};


inline FadableItemComposite::FadableItemComposite(FadeItemDelegate *delegate) : m_fadeItemDelegate(delegate)
{
}


inline FadableItemComposite::~FadableItemComposite()
{
    delete m_fadeItemDelegate;
}

#endif // FADABLEITEMCOMPOSITE_H
