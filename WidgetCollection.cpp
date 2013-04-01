#include "WidgetCollection.h"

#include <QtCore/QtPlugin>
#include "SliderEditInterface.h"
#include "QIntSliderEditInterface.h"


 WidgetCollection::WidgetCollection(QObject *parent)
         : QObject(parent)
 {
     widgets.append(new QSliderEditInterface(this));
     widgets.append(new QIntSliderEditInterface(this));
 }

 QList<QDesignerCustomWidgetInterface*> WidgetCollection::customWidgets() const
 {
     return widgets;
 }

 Q_EXPORT_PLUGIN2(SimulQtWidgets, WidgetCollection)