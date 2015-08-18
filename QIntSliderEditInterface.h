#ifndef QSLIDEREDITINTERFACE_H
#define QSLIDEREDITINTERFACE_H

#include <QWidget>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#ifndef _LIB
	#if defined(SIMUL_QT_WIDGETS)
	#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_EXPORT
	#else
	#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_IMPORT
	#endif
#else
	#define SIMUL_QT_WIDGETS_EXPORT
#endif

class SIMUL_QT_WIDGETS_EXPORT QIntSliderEditInterface : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
	QIntSliderEditInterface(QObject *parent);
	~QIntSliderEditInterface();

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

#endif // QSliderEditInterface_H
