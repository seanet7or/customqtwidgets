#ifndef APPLICATIONCONSTANTS_H
#define APPLICATIONCONSTANTS_H

#include <QFont>
#include <QLabel>


// Manages all settings that are constant for the whole application
class WidgetSettings
{
public:
    WidgetSettings();
    static const QFont &buttonFont();
    static const QFont &helpTextFont();
    // "lowest" heading group we have
    static const QFont &heading3Font();
    // minimal Icon size
    static QSize iconSize();
    static QLabel *newHelpLabel();
};

#endif // APPLICATIONCONSTANTS_H
