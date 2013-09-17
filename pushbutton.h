#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QWidget>
#include <QPushButton>
#include <QtSvg/QSvgRenderer>
#include "delegates/mousehovercomposite.h"
#include "delegates/fadableitemcomposite.h"


class PushButton : public QPushButton, protected MouseHoverComposite
{
    Q_OBJECT
public:
    PushButton(QWidget *parent);
    virtual void setSVG(const QString &name);
    virtual void setPixmap(QPixmap p);
    virtual void setSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical);
    virtual const QFont &font() const;
    virtual void setFont(const QFont &);
    virtual QSize sizeHint() const;
    virtual QSize minimumSizeHint() const;
    virtual void setText(const QString &text);
    QWidget *Widget() { return this; }

public slots:

signals:


protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);

protected:
    QSvgRenderer m_svgRenderer;

private:
    Q_DISABLE_COPY(PushButton)
    void RecalcSize();

private:
    QPixmap m_icon;
    QSize m_textSize;
    QSize m_iconSize;
    QSize m_size;
};

#endif // PUSHBUTTON_H
