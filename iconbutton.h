#ifndef ICONBUTTON_H
#define ICONBUTTON_H
#include "delegates/fadableitemcomposite.h"
#include "delegates/mousehovercomposite.h"
#include <QWidget>
#include <QSvgRenderer>
#include <QPushButton>

class IconButton : public QPushButton, MouseHoverComposite
{
    Q_OBJECT
public:
    IconButton(QWidget *fader);
    virtual QSize sizeHint() const;
    virtual QSize minimumSizeHint() const;
    virtual void setSVG(const QString &name);

public slots:

signals:


protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);

private:
    Q_DISABLE_COPY(IconButton)
    void RecalcSize();

private:
    QSize m_size;
    QSvgRenderer m_svgRenderer;

signals:

public slots:

};

#endif // ICONBUTTON_H
