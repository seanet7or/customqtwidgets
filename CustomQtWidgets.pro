QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../CustomQtWidgets
VPATH += ../CustomQtWidgets

SOURCES += widgetscrollarea.cpp \
	delegates/mousehoverable.cpp \
	Animator.cpp \
	dialog.cpp \
	pushbutton.cpp \
    tabwidget.cpp \
    tabbuttonwidget.cpp \
    widgettools.cpp \
	widgetsettings.cpp \
    ../CustomQtWidgets/delegates/fadableitem.cpp \
    ../CustomQtWidgets/IconButton.cpp

HEADERS  += ../CustomQtWidgets/widgetscrollarea.h \
	../CustomQtWidgets/widgets.h \
	../CustomQtWidgets/delegates/MouseHoverDelegate.h \
	../CustomQtWidgets/delegates/mousehovercomposite.h \
	../CustomQtWidgets/delegates/mousehoverable.h \
	../CustomQtWidgets/Animator.h \
	../CustomQtWidgets/dialog.h \
	../CustomQtWidgets/pushbutton.h \
    tabwidget.h \
    tabbuttonwidget.h \
    widgettools.h \
    ../CustomQtWidgets/widgetsettings.h \
    ../CustomQtWidgets/delegates/fadeitemdelegate.h \
    ../CustomQtWidgets/delegates/fadableitem.h \
    ../CustomQtWidgets/delegates/fadableitemcomposite.h \
    ../CustomQtWidgets/iconbutton.h
