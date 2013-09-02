#ifndef MOUSEHOVERCOMPOSITE_H
#define MOUSEHOVERCOMPOSITE_H

#include "MouseHoverDelegate.h"

class MouseHoverComposite : public MouseHoverDelegate
{
public:
    MouseHoverComposite(MouseHoverDelegate *delegate);
    void DrawMouseHoverRect(QPainter &painter) const { m_mouseHoverDelegate->DrawMouseHoverRect(painter); }
private:
    MouseHoverDelegate *m_mouseHoverDelegate;
};


inline MouseHoverComposite::MouseHoverComposite(MouseHoverDelegate *delegate) : m_mouseHoverDelegate(delegate)
{
}

#endif // MOUSEHOVERCOMPOSITE_H
