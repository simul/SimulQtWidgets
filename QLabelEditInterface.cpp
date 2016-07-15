#include "QLabelEditInterface.h"
//#include <QtPlugin>
//#include <QDesignerFormEditorInterface>
//#include <QExtensionManager>
#include "QLabelEdit.h"


QLabelEditInterface::QLabelEditInterface(QObject *parent)
     : QObject(parent)
 {
     initialized = false;
 }

QLabelEditInterface::~QLabelEditInterface()
{

}

void QLabelEditInterface::initialize(QDesignerFormEditorInterface *formEditor)
{
	if(initialized)
		return;

////	QExtensionManager *manager = formEditor->extensionManager();
//	Q_ASSERT(manager != 0);

	//manager->registerExtensions(new QLabelFactory(manager),
	//							Q_TYPEID(QDesignerPropertySheetExtension));


	initialized = true;
}

 bool QLabelEditInterface::isInitialized() const
 {
     return initialized;
 }

 QWidget *QLabelEditInterface::createWidget(QWidget *parent)
 {
     return new QLabelEdit(parent);
 }

 QString QLabelEditInterface::name() const
 {
     return "QLabelEdit";
 }

 QString QLabelEditInterface::group() const
 {
     return "Simul";
 }

 QIcon QLabelEditInterface::icon() const
 {
     return QIcon();
 }

 QString QLabelEditInterface::toolTip() const
 {
     return "";
 }

 QString QLabelEditInterface::whatsThis() const
 {
     return "";
 }

 bool QLabelEditInterface::isContainer() const
 {
     return false;
 }

 QString QLabelEditInterface::domXml() const
 {
     return "<ui language=\"c++\">\n"
            " <widget class=\"QLabelEdit\" name=\"sliderEdit\">\n"
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

 QString QLabelEditInterface::includeFile() const
 {
     return "Simul/PlugIns/Qt/SimulQtWidgets/QLabelEdit.h";
 }
