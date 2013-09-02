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

signals:

public slots:

private:
    QList<TabButtonWidget*> m_tabButtons;
    QVBoxLayout *m_tabLayout;
    QHBoxLayout *m_buttonLayout;

};

#endif // TABWIDGET_H
