#ifndef WIDGETCOLLECTION_H
#define WIDGETCOLLECTION_H

#include <QDesignerCustomWidgetInterface>
#ifndef _LIB
	#if defined(SIMUL_QT_WIDGETS)
		#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_EXPORT
	#else
		#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_IMPORT
	#endif
#else
	#define SIMUL_QT_WIDGETS_EXPORT
#endif
 #include <QtDesigner/QtDesigner>
 #include <QtCore/qplugin.h>

class WidgetCollection: public QObject, public QDesignerCustomWidgetCollectionInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

public:
	WidgetCollection(QObject *parent = 0);
	virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;

private:
	QList<QDesignerCustomWidgetInterface*> widgets;
};

#endif // KeyframeEditWidgetInterface_H
