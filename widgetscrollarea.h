#ifndef WIDGETSCROLLAREA_H
#define WIDGETSCROLLAREA_H

#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class WidgetScrollArea : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetScrollArea(const QString &caption, const QString hint, QWidget *parent = 0);
    virtual void append(QWidget *w);
    void addButton(QWidget* b);
signals:
    
public slots:

protected:
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *);

private:
    QLabel *m_heading;
    QLabel *m_helpLabel;
    QWidget *m_centralWidget;
    QVBoxLayout *m_buttonLayout;
    QScrollArea *m_scrollArea;
};

#endif // WIDGETSCROLLAREA_H
