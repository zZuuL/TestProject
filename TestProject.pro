TEMPLATE = app

CONFIG   += qt
QT       += widgets

CONFIG(debug, debug|release) {
	TARGET   = TestProjectD
} else {
	TARGET   = TestProject
}

RESOURCES = res/resources.qrc

INCLUDEPATH += include
INCLUDEPATH += gen/.ui

MOC_DIR = gen/.moc
RCC_DIR = gen/.rcc
UI_DIR  = gen/.ui

CONFIG(debug, debug|release) {
	DESTDIR     = gen/.debug
	OBJECTS_DIR = gen/.debug/.obj
} else {
	DESTDIR     = gen/.release
	OBJECTS_DIR = gen/.release/.obj
}

FORMS   = ui/console.ui
HEADERS = src/testproject.h
SOURCES = src/main.cpp src/testproject.cpp
