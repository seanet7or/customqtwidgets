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
    static int defaultFontSize();
    static const QFont &buttonFont();
    static const QFont &helpTextFont();
    // "lowest" heading group we have
    static const QFont &heading3Font();
    static const QFont &textFont();

    /**
     * Icons
     */
    // standard Icon size
    static QSize iconSize();
    // minimal icon icon size (eg for IconButtons)
    static QSize minimalIconSize();

    /**
     * Margins
     */
    static int pushButtonLeftRightMargins();
    static int pushButtonTopBottomMargins();
    static int pushButtonIconLeftRightMargins();
    static int pushButtonIconTopBottomMargins();
    static int pushButtonTextLeftRightMargins();
    static int pushButtonTextTopBottomMargins();

    static int iconButtonMargins();

    /**
     * Widgets
     */
    static QLabel *newHelpLabel(const QString &text = QString());
    static QLabel *newHeading3Label();
    static QSharedPointer<QLabel> newTextLabel(QWidget *p);

    /**
     * Colors
     */
    static QColor iconButtonMouseOverColor();
};

#endif // APPLICATIONCONSTANTS_H
