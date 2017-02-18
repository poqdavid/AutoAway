#pragma once

#ifdef _WIN32
#pragma warning (disable : 4100)  /* Disable Unreferenced parameter warning */
#include <Windows.h>
#include <time.h>
#include <inttypes.h>
#include <math.h>
#include <sys\timeb.h>
#include <sys\utime.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>
#else
#include <unistd.h> // for usleep
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "teamspeak/public_errors.h"
#include "teamspeak/public_errors_rare.h"
#include "teamspeak/public_definitions.h"
#include "teamspeak/public_rare_definitions.h"
#include "teamspeak/clientlib_publicdefinitions.h"
#include "ts3_functions.h"
#include "AutoAwayMonitorThread.h"
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QString>

extern "C" {
	extern AutoAwayMonitorThread autoawaymonitorthread;
	extern TS3Functions ts3Functions;
	extern QJsonDocument settingsData;
	extern QString settingPath;
	void tgAFK(bool afkoption);
	int readJsonVal(QJsonDocument document, QString name);
	void setJsonVal(QString name, QJsonValue val2);
	QJsonDocument loadJSON(QString fileName);
	void saveJSON(QJsonDocument document, QString fileName);
	int secondstomins(int secs);
	int minstoseconds(int mins);
	extern struct Settings {
		int IdleTimeinSec;
	};

	extern Settings settings;
	extern bool isSetToAFK;
}
