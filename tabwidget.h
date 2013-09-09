#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "tabbuttonwidget.h"

class TabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent, int numOfTabs);
    ~TabWidget();
    TabButtonWidget* activeButton();
    void setActiveButton(TabButtonWidget *bn);
    TabButtonWidget *getButton(int index);
    int numOfTabs() const;

signals:

public slots:

protected:
    virtual void resizeEvent(QResizeEvent *);

private:
    QList<TabButtonWidget*> m_tabButtons;
    QVBoxLayout *m_tabLayout;
    QHBoxLayout *m_buttonLayout;
    TabButtonWidget *m_activeButton;

};

#endif // TABWIDGET_H
