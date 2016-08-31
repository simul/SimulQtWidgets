#ifndef QVECTOREDIT_H
#define QVECTOREDIT_H

#include <QWidget>
#include <QVector3D>
#include "GeneratedFiles/ui_QVectorEdit.h"
#ifndef _LIB
	#if defined(SIMUL_QT_WIDGETS)
		#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_EXPORT
	#else
		#define SIMUL_QT_WIDGETS_EXPORT Q_DECL_IMPORT
	#endif
#else
	#define SIMUL_QT_WIDGETS_EXPORT
#endif
#if defined(SIMUL_QT_WIDGETS)
#else
	#ifdef NDEBUG
		#pragma comment(lib,"SimulQtWidgets_MD")
	#else
		#pragma comment(lib,"SimulQtWidgets_MDd")
	#endif
#endif
class SIMUL_QT_WIDGETS_EXPORT QVectorEdit : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString title READ title WRITE setTitle DESIGNABLE true)
	Q_PROPERTY(bool colourEdit READ colourEdit WRITE setColourEdit DESIGNABLE true)
	Q_PROPERTY(bool liveUpdate READ liveUpdate WRITE setLiveUpdate DESIGNABLE true)
	Q_PROPERTY(int labelWidth READ labelWidth WRITE setLabelWidth DESIGNABLE true)
	Q_PROPERTY(int textWidth READ textWidth WRITE setTextWidth DESIGNABLE true)
	Q_PROPERTY(QString units READ units WRITE setUnits DESIGNABLE true)
	Q_PROPERTY(int unitsWidth READ unitsWidth WRITE setUnitsWidth DESIGNABLE true)
	Q_PROPERTY(QVector3D value READ value WRITE setValue DESIGNABLE true)
		
public:
	QVectorEdit(QWidget *parent = 0);
	~QVectorEdit();
	QVector3D value() const;
	void setValue(QVector3D f);
	void setValue(QVector3D f,bool single_valued);
	void setDefaultValue(QVector3D f)
	{
		defaultValue_ = f;
		setShowDefaultButton();
	}
	QVector3D defaultValue() const
	{
		return defaultValue_;
	}
	void setTitle(QString f);
	QString title() const;
	void setUnits(QString f);
	QString units() const;
	void setLiveUpdate(bool l);
	bool liveUpdate() const;
	void setColourEdit(bool l);
	bool colourEdit() const;
	int labelWidth() const
	{
		return labelWidth_;
	}
	void setLabelWidth(int w);
	int textWidth() const
	{
		return textWidth_;
	}
	void setTextWidth(int w);
	int unitsWidth() const
	{
		return unitsWidth_;
	}
	void setUnitsWidth(int w);
signals:
	void valueChanged();
public slots:
	void on_reset_clicked();
	void on_x_editingFinished();
	void on_y_editingFinished();
	void on_z_editingFinished();
protected:
	Ui::QVectorEdit ui;
	bool colourEdit_;
	int labelWidth_;
	int textWidth_;
	int unitsWidth_;
	bool liveUpdate_;
	QVector3D value_;
	QVector3D defaultValue_;
	void setShowDefaultButton();
};

#endif // QVECTOREDIT_H
