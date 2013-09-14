#ifndef FADABLEITEMCOMPOSITE_H
#define FADABLEITEMCOMPOSITE_H

#include "fadeitemdelegate.h"

class FadableItemComposite : public FadeItemDelegate
{
public:
    FadableItemComposite(FadeItemDelegate *delegate);
    void DrawAlpha(QPainter *painter) const { m_fadeItemDelegate->DrawAlpha(painter); }
private:
    FadeItemDelegate *m_fadeItemDelegate;
};


inline FadableItemComposite::FadableItemComposite(FadeItemDelegate *delegate) : m_fadeItemDelegate(delegate)
{
}

#endif // FADABLEITEMCOMPOSITE_H
