#ifndef WIDGETTOOLS_H
#define WIDGETTOOLS_H
#include <QPixmap>
#include <QApplication>


class WidgetTools
{
public:
    WidgetTools();

private:
#ifdef Q_OS_ANDROID
    // will return ldpi, mdpi, hdpi, xhdpi, dependig on the screen
    // as described on http://developer.android.com/guide/practices/screens_support.html
    static const QString &screenGeneralizedDensity();
#endif

};

#endif // WIDGETTOOLS_H
