// AutoAwayMonitorThread.h

#ifndef AUTOAWAYMONITORTHREAD_H
#define AUTOAWAYMONITORTHREAD_H
#include <QtCore/QThread>
#include <QtCore/QString>

class AutoAwayMonitorThread : public QThread
{
	Q_OBJECT
public:
	explicit AutoAwayMonitorThread();
	void run();
};

#endif // AUTOAWAYMONITORTHREAD_H