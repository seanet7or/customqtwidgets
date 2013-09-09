#ifndef WIDGETTOOLS_H
#define WIDGETTOOLS_H
#include <QPixmap>
#include <QApplication>


class WidgetTools
{
public:
    WidgetTools();
#ifdef Q_OS_ANDROID
    static QPixmap loadDensityPixmap(const QString &resName);
#else
    static QPixmap loadDensityPixmap(const QString &resName) { return QPixmap("mdpi-" + resName); }
#endif

private:
#ifdef Q_OS_ANDROID
    // will return ldpi, mdpi, hdpi, xhdpi, dependig on the screen
    // as described on http://developer.android.com/guide/practices/screens_support.html
    static const QString &screenGeneralizedDensity();
#endif

};

#endif // WIDGETTOOLS_H
