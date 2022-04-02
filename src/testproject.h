#ifndef __TestProject_H
#define __TestProject_H

#include <QObject>

class TestProject : public QObject
{
public:
    TestProject(QObject* pObj = 0);
    ~TestProject();
};


#endif /*__TestProject_H*/
