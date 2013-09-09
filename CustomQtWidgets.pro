QT       += core gui

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
    widgettools.cpp

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
    widgettools.h
