#include "ifunctions.h"
#include "AutoAway.h"

DWORD secondsForIdle;
bool isSetToAFK;

void setAFK(uint64 serverID, bool afkoption)
{
	enum AwayStatus AfkST;
	if (afkoption)
	{
		AfkST = AWAY_ZZZ;
	}
	else
	{
		AfkST = AWAY_NONE;
	}
	ts3Functions.setClientSelfVariableAsInt(serverID, CLIENT_AWAY, AfkST);
	ts3Functions.flushClientSelfUpdates(serverID, NULL);
}

void tgAFK(bool afkoption)
{
	uint64* cons;

	if (ts3Functions.getServerConnectionHandlerList(&cons) != ERROR_ok)
	{
		ts3Functions.logMessage("[AutoAFK] Error retrieving server list - cannot set AFK", LogLevel_ERROR, "Plugin", 0);
		return;
	}

	for (int i = 0; cons[i]; i++)
	{
		setAFK(cons[i], afkoption);
	}

	ts3Functions.freeMemory(cons);
	isSetToAFK = afkoption;
}

QJsonDocument loadJSON(QString fileName) {
	QFile jsonFile(fileName);
	jsonFile.open(QFile::ReadOnly);
	return QJsonDocument().fromJson(jsonFile.readAll());
}

int readJsonVal(QJsonDocument document, QString name) {
	return document.object()[name].toInt();
}

void setJsonVal(QString name, QJsonValue val2) {
	QJsonObject obj = settingsData.object();
	QJsonValue val = obj[name];
	val = val2;
	obj[name] = val;
	settingsData.setObject(obj);
}

void saveJSON(QJsonDocument document, QString fileName) {
	QFile jsonFile(fileName);
	jsonFile.open(QFile::WriteOnly);
	jsonFile.write(document.toJson());
}

int secondstomins(int secs) { return (secs / 60); }
int minstoseconds(int mins) { return (mins * 60); }