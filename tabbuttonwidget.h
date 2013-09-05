#ifndef TABBUTTONWIDGET_H
#define TABBUTTONWIDGET_H
#include <QPixmap>
#include <QWidget>
#include <QPushButton>

class TabWidget;


class TabButtonWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit TabButtonWidget(TabWidget *parent);
    void setPixmap(QPixmap p);
    void setText(const QString &text);

signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);

private slots:
    void onClicked();
    void recalcSize();

private:
    virtual QSize sizeHint();

private:
    QPixmap m_pixmap;
    QSize m_minSize;
    TabWidget *m_tabWidget;
};

#endif // TABBUTTONWIDGET_H
