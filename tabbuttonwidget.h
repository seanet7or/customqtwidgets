#ifndef TABBUTTONWIDGET_H
#define TABBUTTONWIDGET_H

#include <QWidget>
#include <QPushButton>

class TabWidget;


class TabButtonWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit TabButtonWidget(TabWidget *parent);

signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *);

private slots:
    void onClicked();

private:
    virtual QSize sizeHint();

private:
    QSize m_minSize;
    TabWidget *m_tabWidget;
};

#endif // TABBUTTONWIDGET_H
