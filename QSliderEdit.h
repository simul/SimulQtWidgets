#ifndef QSliderEdit_H
#define QSliderEdit_H

#include <QWidget>
#include "../SimulQtWidgets/GeneratedFiles/ui_QSliderEdit.h"
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
class SIMUL_QT_WIDGETS_EXPORT QSliderEdit : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString title READ title WRITE setTitle DESIGNABLE true)
	Q_PROPERTY(bool liveUpdate READ liveUpdate WRITE setLiveUpdate DESIGNABLE true)
	Q_PROPERTY(int labelWidth READ labelWidth WRITE setLabelWidth DESIGNABLE true)
	Q_PROPERTY(int textWidth READ textWidth WRITE setTextWidth DESIGNABLE true)
	Q_PROPERTY(bool showButtons READ showButtons WRITE setShowButtons DESIGNABLE true)
	Q_PROPERTY(double minimum READ minimum WRITE setMinimum DESIGNABLE true)
	Q_PROPERTY(double maximum READ maximum WRITE setMaximum DESIGNABLE true)
	Q_PROPERTY(double defaultValue READ defaultValue WRITE setDefaultValue DESIGNABLE true)
	Q_PROPERTY(double step READ step WRITE setStep DESIGNABLE true)
	Q_PROPERTY(QVariant value READ value WRITE setValue DESIGNABLE true)
	Q_PROPERTY(bool logarithmic READ logarithmic WRITE setLogarithmic DESIGNABLE true)
	Q_PROPERTY(Qt::Orientation orientation READ orientation WRITE setOrientation DESIGNABLE true)
public:
	QSliderEdit(QWidget *parent = 0);
	~QSliderEdit();
	bool eventFilter(QObject *o, QEvent *e);
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
	Qt::Orientation	orientation() const;
	void setOrientation(Qt::Orientation);
	void setMinimum(double f)
	{
		minimum_=f;
	}
	double minimum() const
	{
		return minimum_;
	}
	void setMaximum(double f)
	{
		maximum_=f;
	}
	double maximum() const
	{
		return maximum_;
	}
	void setDefaultValue(double f)
	{
		defaultValue_ = f;
	}
	double defaultValue() const
	{
		return defaultValue_;
	}
	void setStep(double step);
	double step() const;
	void setLogarithmic(bool l);
	bool logarithmic() const;
	void setShowButtons(bool l);
	bool showButtons() const;
	void setLiveUpdate(bool l);
	bool liveUpdate() const;
	void setValue(QVariant f);
	void setValue(QVariant f,bool single_valued);
	QVariant value() const
	{
		return value_;
	}
	void setTitle(QString f);
	QString title() const;
	virtual QString valueToText(double value);
	virtual double textToValue(QString s,bool *ok);
	virtual void incrementDecrement(int step);
signals:
	void valueChanged();
public slots:
	void on_increment_clicked();
	void on_decrement_clicked();
	void on_reset_clicked();
	void on_slider_sliderMoved(int);
	void on_slider_valueChanged(int);
	void on_lineEdit_editingFinished();
protected:
	void updateSlider();
	Ui::QSliderEdit ui;
	int labelWidth_;
	int textWidth_;
	double minimum_;
	double maximum_;
	double defaultValue_;
	double value_;
	bool logarithmic_;
	bool liveUpdate_;
	bool showButtons_;
	double step_;
};

#endif // QSliderEdit_H
