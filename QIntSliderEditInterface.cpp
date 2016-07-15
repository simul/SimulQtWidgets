#include "QIntSliderEditInterface.h"
//#include <QtPlugin>
//#include <QDesignerFormEditorInterface>
//#include <QExtensionManager>
#include "QIntSliderEdit.h"


QIntSliderEditInterface::QIntSliderEditInterface(QObject *parent)
     : QObject(parent)
 {
     initialized = false;
 }

QIntSliderEditInterface::~QIntSliderEditInterface()
{

}

void QIntSliderEditInterface::initialize(QDesignerFormEditorInterface *formEditor)
{
	if(initialized)
		return;

	//QExtensionManager *manager = formEditor->extensionManager();
	//Q_ASSERT(manager != 0);

	//manager->registerExtensions(new QSliderFactory(manager),
	//							Q_TYPEID(QDesignerPropertySheetExtension));


	initialized = true;
}

 bool QIntSliderEditInterface::isInitialized() const
 {
     return initialized;
 }

 QWidget *QIntSliderEditInterface::createWidget(QWidget *parent)
 {
     return new QIntSliderEdit(parent);
 }

 QString QIntSliderEditInterface::name() const
 {
     return "QIntSliderEdit";
 }

 QString QIntSliderEditInterface::group() const
 {
     return "Simul";
 }

 QIcon QIntSliderEditInterface::icon() const
 {
     return QIcon();
 }

 QString QIntSliderEditInterface::toolTip() const
 {
     return "";
 }

 QString QIntSliderEditInterface::whatsThis() const
 {
     return "";
 }

 bool QIntSliderEditInterface::isContainer() const
 {
     return false;
 }

 QString QIntSliderEditInterface::domXml() const
 {
     return "<ui language=\"c++\">\n"
            " <widget class=\"QIntSliderEdit\" name=\"intSliderEdit\">\n"
            "  <property name=\"geometry\">\n"
            "   <rect>\n"
            "    <x>0</x>\n"
            "    <y>0</y>\n"
            "    <width>100</width>\n"
            "    <height>24</height>\n"
            "   </rect>\n"
            "  </property>\n"
            "  <property name=\"toolTip\" >\n"
            "   <string></string>\n"
            "  </property>\n"
            "  <property name=\"whatsThis\" >\n"
            "   <string>.</string>\n"
            "  </property>\n"
            " </widget>\n"
            "</ui>\n";
 }

 QString QIntSliderEditInterface::includeFile() const
 {
     return "Simul/PlugIns/Qt/SimulQtWidgets/QIntSliderEdit.h";
 }
