#ifndef WIDGETSCROLLAREA_H
#define WIDGETSCROLLAREA_H

#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class WidgetScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit WidgetScrollArea(const QString &caption, const QString hint, QWidget *parent = 0);
    virtual void append(QWidget *w);
    void addButton(QWidget *b);
signals:
    
public slots:

private:
    QLabel *m_heading;
    QLabel *m_helpLabel;
    QWidget *m_centralWidget;
    QHBoxLayout *m_buttonLayout;
};

#endif // WIDGETSCROLLAREA_H
