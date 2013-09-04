#include "widgettools.h"
#include <QScreen>
#include <QDebug>


WidgetTools::WidgetTools()
{
}


#ifdef Q_OS_ANDROID
// will return ldpi, mdpi, hdpi, xhdpi, dependig on the screen
// as described on http://developer.android.com/guide/practices/screens_support.html
const QString &WidgetTools::screenGeneralizedDensity()
{
    static bool initDone(false);
    static QMap<int, QString> densityMap;
    static QString density;
    if (!initDone)
    {
        densityMap.insert(120, QString("ldpi"));
        densityMap.insert(160, "mdpi");
        densityMap.insert(240, "hdpi");
        densityMap.insert(320, "xhdpi");
        int devDpi = QApplication::primaryScreen()->physicalDotsPerInch();
        int minDiff = INT_MAX;
        density = densityMap.value(120);
        foreach (int k, densityMap.keys()) {
            if (std::abs(k - devDpi) < minDiff)
            {
                minDiff = std::abs(k - devDpi);
                density = densityMap.value(k);
            }
        }
        initDone = true;
        qDebug() << "Generalized screen density is " << density;
    }
    return density;
}

#endif

