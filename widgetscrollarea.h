#ifndef WIDGETSCROLLAREA_H
#define WIDGETSCROLLAREA_H

#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

class WidgetScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    explicit WidgetScrollArea(const QString &caption, const QString hint, QWidget *parent = 0);
    virtual void append(QWidget *w);
signals:
    
public slots:

private:
    QLabel *m_heading;
    QLabel *m_helpLabel;
    QWidget *m_centralWidget;
    
};

#endif // WIDGETSCROLLAREA_H
