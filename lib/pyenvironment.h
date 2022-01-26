#ifndef PYENVIRONMENT_H
#define PYENVIRONMENT_H

#include "pyrunner.h"
#include <QMap>

struct PyEnvModule
{
    QString moduleName;
    QString modulePath;
    PyRunner * module;
};

Q_DECLARE_METATYPE(PyEnvModule)

class PyEnvironment
{
    bool m_initialized;

private:
    PyEnvironment();
    PyEnvironment(PyEnvironment const& copy);
    PyEnvironment & operator = (PyEnvironment const&copy);
    QMap<QString, PyRunner*> m_modules;

public:
    static PyEnvironment &getInstance();
    bool start();
    bool stop();
    ~PyEnvironment();

    PyRunner * getInstanceModule(QString modulePath, QStringList dependecies = QStringList());
    void unloadModule(PyRunner* runner);
};

#endif // PYENVIRONMENT_H
