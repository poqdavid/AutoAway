#pragma once

#include <QtWidgets/QDialog>
#include "ui_SettingsDialog.h"

class SettingsDialog : public QDialog, public Ui::SettingsDialog
{
	Q_OBJECT

public:
	SettingsDialog();
	void SetupUi();
	~SettingsDialog();
private:
	Ui::SettingsDialog ui;
	protected slots:
	void accept();
	void reject();
};
