#include "SliderEditInterface.h"
//#include <QtPlugin>
//#include <QDesignerFormEditorInterface>
//#include <QExtensionManager>
#include "QSliderEdit.h"


QSliderEditInterface::QSliderEditInterface(QObject *parent)
     : QObject(parent)
 {
     initialized = false;
 }

QSliderEditInterface::~QSliderEditInterface()
{

}

void QSliderEditInterface::initialize(QDesignerFormEditorInterface *formEditor)
{
	if(initialized)
		return;

	//QExtensionManager *manager = formEditor->extensionManager();
	//Q_ASSERT(manager != 0);

	//manager->registerExtensions(new QSliderFactory(manager),
	//							Q_TYPEID(QDesignerPropertySheetExtension));


	initialized = true;
}

 bool QSliderEditInterface::isInitialized() const
 {
     return initialized;
 }

 QWidget *QSliderEditInterface::createWidget(QWidget *parent)
 {
     return new QSliderEdit(parent);
 }

 QString QSliderEditInterface::name() const
 {
     return "QSliderEdit";
 }

 QString QSliderEditInterface::group() const
 {
     return "Simul";
 }

 QIcon QSliderEditInterface::icon() const
 {
     return QIcon();
 }

 QString QSliderEditInterface::toolTip() const
 {
     return "";
 }

 QString QSliderEditInterface::whatsThis() const
 {
     return "";
 }

 bool QSliderEditInterface::isContainer() const
 {
     return false;
 }

 QString QSliderEditInterface::domXml() const
 {
     return "<ui language=\"c++\">\n"
            " <widget class=\"QSliderEdit\" name=\"sliderEdit\">\n"
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

 QString QSliderEditInterface::includeFile() const
 {
     return "Simul/PlugIns/Qt/SimulQtWidgets/QSliderEdit.h";
 }
