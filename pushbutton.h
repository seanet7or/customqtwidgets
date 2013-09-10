#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QWidget>
#include <QPushButton>
#include <QtSvg/QSvgRenderer>
#include "delegates/mousehovercomposite.h"


class PushButton : public QPushButton, protected MouseHoverComposite
{
    Q_OBJECT
public:
    PushButton(QWidget *parent = 0);
    virtual void setSVG(const QString &name);
    virtual void setPixmap(QPixmap p);
    virtual void setSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical);
    virtual const QFont &font() const;
    virtual void setFont(const QFont &);
    virtual QSize sizeHint() const { return m_size; }
    virtual void setText(const QString &text);
    QWidget *Widget() { return this; }

public slots:
signals:


protected:
    virtual void paintEvent(QPaintEvent *);

private:
    Q_DISABLE_COPY(PushButton)
    void RecalcSize();

private:
    QSize m_size;
    QPixmap m_icon;
    QSize m_textSize;
    QSize m_iconSize;
    QSvgRenderer m_svgRenderer;
};

#endif // PUSHBUTTON_H
