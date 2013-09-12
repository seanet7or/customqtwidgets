#include "widgetsettings.h"
#include <QSize>


WidgetSettings::WidgetSettings()
{
}


const QFont &WidgetSettings::helpTextFont()
{
    static bool init = false;
    static QFont font;
    if (!init)
    {
        init = true;
        font.setPointSize(12);
        font.setWeight(QFont::DemiBold);
        font.setStyle(QFont::StyleOblique);
    }
    return font;
}


const QFont &WidgetSettings::heading3Font()
{
    static bool init = false;
    static QFont font;
    if (!init)
    {
        init = true;
        font.setPointSize(14);
        font.setStyle(QFont::StyleNormal);
        font.setCapitalization(QFont::Capitalize);
    }
    return font;
}


QSize WidgetSettings::iconSize()
{
    return QSize(64, 64);
}


const QFont &WidgetSettings::buttonFont()
{
    static bool init = false;
    static QFont font;
    if (!init)
    {
        init = true;
        font.setPointSize(16);
        font.setWeight(QFont::Bold);
        font.setStyle(QFont::StyleNormal);
        font.setCapitalization(QFont::AllUppercase);
    }
    return font;
}


QLabel *WidgetSettings::newHelpLabel()
{
    QLabel *label = new QLabel;
    label->setFont(helpTextFont());
    label->setContentsMargins(12, 12, 12, 12);
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignCenter);
    return label;
}
