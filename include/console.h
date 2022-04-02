#ifndef __Console_H
#define __Console_H

#include <QWidget>
#include <QAtomicInt>
#include <QDateTime>

#include "ui_console.h"


static class Console* console = nullptr;
void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg);


class Console
    : public QWidget
    , private Ui::DebugConsole
{
public:
    Console(QWidget* pWgt = 0);
    ~Console();

    void add(const QString& text);

    static void init();
};


inline Console::Console(QWidget* pWgt/* = 0*/) : QWidget(pWgt)
{
    DebugConsole::setupUi(this); 
}


inline Console::~Console()
{}


inline void Console::init()
{
    if (nullptr == console)
    {
        console = new Console();
        console->show();
        qInstallMessageHandler(messageHandler);

        qInfo() << "Debug console started";
    }
}

inline void Console::add(const QString& text)
{
    qtbConsole->append(text);
}


void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    static QAtomicInt message_id = 1;


    static auto getMessageTypeName = [](QtMsgType type) {
        switch (type)
        {
        case QtDebugMsg:    return "[DEBUG]";
        case QtInfoMsg:     return "[INFO]";
        case QtWarningMsg:  return "[WARNING]";
        case QtCriticalMsg: return "[CRITICAL]";
        case QtFatalMsg:    return "[FATAL]";
        default:            return "[unknown message type]";
        }
    };


    static auto getMessageIdString = [&]() {
        QString num_str = QString::number(message_id++);
        return QString("[%1 %2]")
            .arg(QString(10 - num_str.size(), '0'))
            .arg(num_str);
    };


    static auto getCurrentDateTime = []() {
        return QDateTime::currentDateTime().toString("hh:mm:ss");
    };


    console->add(QString("%1 %2 %3: %4")
        .arg(getMessageIdString())
        .arg(getMessageTypeName(type))
        .arg(getCurrentDateTime())
        .arg(msg)
    );
}


#endif /*__Console_H*/
