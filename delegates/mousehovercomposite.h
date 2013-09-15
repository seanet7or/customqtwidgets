#ifndef MOUSEHOVERCOMPOSITE_H
#define MOUSEHOVERCOMPOSITE_H

#include "MouseHoverDelegate.h"

class MouseHoverComposite : public MouseHoverDelegate
{
public:
    MouseHoverComposite(MouseHoverDelegate *delegate);
    ~MouseHoverComposite() { delete m_mouseHoverDelegate; }
    void DrawMouseHoverRect(QPainter &painter) const { m_mouseHoverDelegate->DrawMouseHoverRect(painter); }
    void setMouseHoverColor(QColor color) { m_mouseHoverDelegate->setMouseHoverColor(color); }
private:
    MouseHoverDelegate *m_mouseHoverDelegate;
};


inline MouseHoverComposite::MouseHoverComposite(MouseHoverDelegate *delegate) : m_mouseHoverDelegate(delegate)
{
}

#endif // MOUSEHOVERCOMPOSITE_H
