QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += ../CustomQtWidgets
VPATH += ../CustomQtWidgets

SOURCES += ../CustomQtWidgets/widgetscrollarea.cpp \
	../CustomQtWidgets/delegates/mousehoverable.cpp \
	../CustomQtWidgets/Animator.cpp \
	../CustomQtWidgets/dialog.cpp \
	../CustomQtWidgets/pushbutton.cpp \
    tabwidget.cpp \
    tabbuttonwidget.cpp

HEADERS  += ../CustomQtWidgets/widgetscrollarea.h \
	../CustomQtWidgets/widgets.h \
	../CustomQtWidgets/delegates/MouseHoverDelegate.h \
	../CustomQtWidgets/delegates/mousehovercomposite.h \
	../CustomQtWidgets/delegates/mousehoverable.h \
	../CustomQtWidgets/Animator.h \
	../CustomQtWidgets/dialog.h \
	../CustomQtWidgets/pushbutton.h \
    tabwidget.h \
    tabbuttonwidget.h
