#if 0
#include "SimulQtWidgets.h"

#include <QtCore/QtPlugin>
#include "SimulQtWidgets.h"


SimulQtWidgetsPlugin::SimulQtWidgetsPlugin(QObject *parent)
	: QObject(parent)
{
	initialized = false;
}

void SimulQtWidgetsPlugin::initialize(QDesignerFormEditorInterface *)
{
	if (initialized)
		return;

	initialized = true;
}

bool SimulQtWidgetsPlugin::isInitialized() const
{
	return initialized;
}

QWidget *SimulQtWidgetsPlugin::createWidget(QWidget *parent)
{
	return new SimulQtWidgetsPlugin(parent);
}

QString SimulQtWidgetsPlugin::name() const
{
	return "SimulQtWidgets";
}

QString SimulQtWidgetsPlugin::group() const
{
	return "Simul";
}

QIcon SimulQtWidgetsPlugin::icon() const
{
	return QIcon();
}

QString SimulQtWidgetsPlugin::toolTip() const
{
	return QString();
}

QString SimulQtWidgetsPlugin::whatsThis() const
{
	return QString();
}

bool SimulQtWidgetsPlugin::isContainer() const
{
	return false;
}

QString SimulQtWidgetsPlugin::domXml() const
{
	return "<widget class=\"SimulQtWidgets\" name=\"simulQtWidgets\">\n"
		" <property name=\"geometry\">\n"
		"  <rect>\n"
		"   <x>0</x>\n"
		"   <y>0</y>\n"
		"   <width>100</width>\n"
		"   <height>100</height>\n"
		"  </rect>\n"
		" </property>\n"
		"</widget>\n";
}

QString SimulQtWidgetsPlugin::includeFile() const
{
	return "SimulQtWidgets.h";
}

Q_EXPORT_PLUGIN2(SimulQtWidgets, SimulQtWidgetsPlugin)
#endif