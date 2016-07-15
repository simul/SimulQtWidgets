#include "QVectorEditInterface.h"
//#include <QtPlugin>
//#include <QDesignerFormEditorInterface>
//#include <QExtensionManager>
#include "QVectorEdit.h"


QVectorEditInterface::QVectorEditInterface(QObject *parent)
     : QObject(parent)
 {
     initialized = false;
 }

QVectorEditInterface::~QVectorEditInterface()
{

}

void QVectorEditInterface::initialize(QDesignerFormEditorInterface *formEditor)
{
	if(initialized)
		return;

////	QExtensionManager *manager = formEditor->extensionManager();
//	Q_ASSERT(manager != 0);

	//manager->registerExtensions(new QVectorFactory(manager),
	//							Q_TYPEID(QDesignerPropertySheetExtension));


	initialized = true;
}

 bool QVectorEditInterface::isInitialized() const
 {
     return initialized;
 }

 QWidget *QVectorEditInterface::createWidget(QWidget *parent)
 {
     return new QVectorEdit(parent);
 }

 QString QVectorEditInterface::name() const
 {
     return "QVectorEdit";
 }

 QString QVectorEditInterface::group() const
 {
     return "Simul";
 }

 QIcon QVectorEditInterface::icon() const
 {
     return QIcon();
 }

 QString QVectorEditInterface::toolTip() const
 {
     return "";
 }

 QString QVectorEditInterface::whatsThis() const
 {
     return "";
 }

 bool QVectorEditInterface::isContainer() const
 {
     return false;
 }

 QString QVectorEditInterface::domXml() const
 {
     return "<ui language=\"c++\">\n"
            " <widget class=\"QVectorEdit\" name=\"VectorEdit\">\n"
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

 QString QVectorEditInterface::includeFile() const
 {
     return "Simul/PlugIns/Qt/SimulQtWidgets/QVectorEdit.h";
 }
