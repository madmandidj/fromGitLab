#ifndef __CONFIGMODULE_H__
#define __CONFIGMODULE_H__

typedef struct LogType
{
	Log* m_log;
	LogLevel m_level;
	char* m_moduleName;
}LogType;

enum LogLevel {
    T = 0,
    D,
    I,
    W,
    E,
    C,
    S,
    F
};





#endif /* #ifndef __CONFIGMODULE_H__ */
