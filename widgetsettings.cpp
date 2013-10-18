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
        font.setPointSize(defaultFontSize());
        font.setWeight(QFont::Normal);
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
        font.setPointSize(defaultFontSize() + 3);
        font.setStyle(QFont::StyleNormal);
        font.setWeight(QFont::DemiBold);
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
        font.setPointSize(defaultFontSize());
        font.setWeight(QFont::Normal);
        font.setStyle(QFont::StyleNormal);
        font.setCapitalization(QFont::AllUppercase);
    }
    return font;
}


QLabel *WidgetSettings::newHelpLabel(const QString &text)
{
    QLabel *label = new QLabel;
    label->setFont(helpTextFont());
    label->setContentsMargins(8, 6, 8, 6);
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignCenter);
    label->setText(text);
    return label;
}


int WidgetSettings::pushButtonLeftRightMargins()
{
    return 4;
}


int WidgetSettings::pushButtonTopBottomMargins()
{
    return 3;
}


int WidgetSettings::pushButtonIconTopBottomMargins()
{
    return 2;
}


int WidgetSettings::pushButtonIconLeftRightMargins()
{
    return 2;
}


int WidgetSettings::pushButtonTextLeftRightMargins()
{
    return 8;
}


int WidgetSettings::pushButtonTextTopBottomMargins()
{
    return 6;
}


QLabel *WidgetSettings::newHeading3Label()
{
    QLabel *h3 = new QLabel();
    h3->setFont(heading3Font());
    h3->setContentsMargins(8, 8, 16, 8);
    h3->setAlignment(Qt::AlignHCenter);
    h3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    return h3;
}


int WidgetSettings::iconButtonMargins()
{
    return 5;
}


QSize WidgetSettings::minimalIconSize()
{
    return QSize(16, 16);
}


QColor WidgetSettings::iconButtonMouseOverColor()
{
    return QColor(255, 255, 255, 128);
}


QSharedPointer<QLabel> WidgetSettings::newTextLabel(QWidget *p)
{
    QSharedPointer<QLabel> label = QSharedPointer<QLabel>(new QLabel(p));
    label->setFont(textFont());
    label->setContentsMargins(8, 6, 8, 6);
    label->setWordWrap(false);
    label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    return label;
}


const QFont &WidgetSettings::textFont()
{
    static bool init = false;
    static QFont font;
    if (!init)
    {
        init = true;
        font.setPointSize(defaultFontSize() + 1);
        font.setWeight(QFont::Normal);
    }
    return font;
}


int WidgetSettings::defaultFontSize()
{
    return 10;
}
