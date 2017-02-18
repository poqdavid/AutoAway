// AutoAwayMonitorThread.cpp

#include <QtCore/QDebug>
#include <QtCore/QMutex>
#include "AutoAwayMonitorThread.h"
#include <ifunctions.h>

AutoAwayMonitorThread::AutoAwayMonitorThread() {
}

void AutoAwayMonitorThread::run()
{
	LASTINPUTINFO lastInput;
	lastInput.cbSize = sizeof(LASTINPUTINFO);

	while (!QThread::currentThread()->isInterruptionRequested())
	{
		if (GetLastInputInfo(&lastInput))
		{
			if (((GetTickCount() - lastInput.dwTime) / 1000) > settings.IdleTimeinSec)
			{
				tgAFK(true);
			}
			else if (isSetToAFK)
			{
				tgAFK(false);
			}
		}
		QThread::usleep(1000);
	}
}