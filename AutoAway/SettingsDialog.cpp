#include "SettingsDialog.h"
#include "ifunctions.h"

SettingsDialog::SettingsDialog()
{
}

void SettingsDialog::SetupUi() {
	setupUi(this);
	this->dial->setValue(secondstomins(settings.IdleTimeinSec));
}

void SettingsDialog::accept() {
	settings.IdleTimeinSec = minstoseconds(this->dial->value());
	setJsonVal("IdleTimeinSec", settings.IdleTimeinSec);

	saveJSON(settingsData, settingPath);
	QDialog::accept();
}

void SettingsDialog::reject() {
	QDialog::reject();
}

SettingsDialog::~SettingsDialog()
{
}