#ifndef QVectorEditInterface_H
#define QVectorEditInterface_H

#include <QWidget>
#include "CustomWidget.h"
#if defined(SIMUL_QT_WIDGETS)
#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_EXPORT
#else
#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_IMPORT
#endif

class SIMUL_QT_WIDGETS_EXPORT QVectorEditInterface : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
	QVectorEditInterface(QObject *parent);
	~QVectorEditInterface();

     bool isContainer() const;
     bool isInitialized() const;
     QIcon icon() const;
     QString domXml() const;
     QString group() const;
     QString includeFile() const;
     QString name() const;
     QString toolTip() const;
     QString whatsThis() const;
     QWidget *createWidget(QWidget *parent);
     void initialize(QDesignerFormEditorInterface *core);

 private:
     bool initialized;
};

#endif // QVectorEditInterface_H
