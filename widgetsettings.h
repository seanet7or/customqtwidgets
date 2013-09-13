#ifndef APPLICATIONCONSTANTS_H
#define APPLICATIONCONSTANTS_H

#include <QFont>
#include <QLabel>


// Manages all settings that are constant for the whole application
class WidgetSettings
{
public:
    WidgetSettings();

    /**
     * Fonts
     */
    static const QFont &buttonFont();
    static const QFont &helpTextFont();
    // "lowest" heading group we have
    static const QFont &heading3Font();

    /**
     * Icons
     */
    // minimal Icon size
    static QSize iconSize();

    /**
     * Margins
     */
    static int pushButtonLeftRightMargins();
    static int pushButtonTopBottomMargins();
    static int pushButtonIconLeftRightMargins();
    static int pushButtonIconTopBottomMargins();
    static int pushButtonTextLeftRightMargins();
    static int pushButtonTextTopBottomMargins();

    /**
     * Widgets
     */
    static QLabel *newHelpLabel();
    static QLabel *newHeading3Label();
};

#endif // APPLICATIONCONSTANTS_H
