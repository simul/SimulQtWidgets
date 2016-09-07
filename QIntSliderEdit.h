#ifndef QINTSLIDEREDIT_H
#define QINTSLIDEREDIT_H

#include <QWidget>
#include "../SimulQtWidgets/GeneratedFiles/ui_QIntSliderEdit.h"
#include "Export.h"

class SIMUL_QT_WIDGETS_EXPORT QIntSliderEdit : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString title READ title WRITE setTitle DESIGNABLE true)
	Q_PROPERTY(int labelWidth READ labelWidth WRITE setLabelWidth DESIGNABLE true)
	Q_PROPERTY(int textWidth READ textWidth WRITE setTextWidth DESIGNABLE true)
	Q_PROPERTY(QString units READ units WRITE setUnits DESIGNABLE true)
	Q_PROPERTY(int unitsWidth READ unitsWidth WRITE setUnitsWidth DESIGNABLE true)
	Q_PROPERTY(int minimum READ minimum WRITE setMinimum DESIGNABLE true)
	Q_PROPERTY(int maximum READ maximum WRITE setMaximum DESIGNABLE true)
	Q_PROPERTY(int defaultValue READ defaultValue WRITE setDefaultValue DESIGNABLE true)
	Q_PROPERTY(bool showDefaultButton READ showDefaultButton WRITE setShowDefaultButton DESIGNABLE true)
	Q_PROPERTY(QVariant value READ value WRITE setValue DESIGNABLE true)
	Q_PROPERTY(bool powerOfTwo READ powerOfTwo WRITE setPowerOfTwo DESIGNABLE true)
    Q_PROPERTY(Qt::Orientation orientation READ orientation WRITE setOrientation DESIGNABLE true)
	Q_PROPERTY(bool readOnlyText READ readOnlyText WRITE setReadOnlyText DESIGNABLE true)
	Q_PROPERTY(QStringList enums READ enums WRITE setEnums DESIGNABLE true)
public:
	QIntSliderEdit(QWidget *parent = 0);
	~QIntSliderEdit();
	bool eventFilter(QObject *o, QEvent *e);

    Qt::Orientation orientation() const;
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
	void setMinimum(int f);
	int minimum() const
	{
		return minimum_;
	}
	int maximum() const
	{
		return maximum_;
	}
	void setDefaultValue(int f)
	{
		defaultValue_ = f;
		setShowDefaultButton(true);
	}
	int defaultValue() const
	{
		return defaultValue_;
	}
	void setMaximum(int f);
	void setPowerOfTwo(bool l);
	bool powerOfTwo() const;
	void setShowDefaultButton(bool l);
	bool showDefaultButton() const;
	void setEnums(QStringList e);
	QStringList enums() const;
	void setReadOnlyText(bool l);
	bool readOnlyText() const;
	void setValue(QVariant f);
	void setValue(QVariant f,bool single_valued);
	QVariant value() const
	{
		return value_;
	}
	void setTitle(QString f);
	QString title() const;
	void setUnits(QString f);
	QString units() const;
	virtual QString valueToText(int value);
	virtual int textToValue(QString s);
signals:
	void valueChanged();
public slots:
	void setOrientation(Qt::Orientation);
	void on_reset_clicked();
	void on_slider_sliderMoved(int);
	void on_slider_valueChanged(int);
	void on_lineEdit_editingFinished();
private:
	void updateSlider();
	Ui::QIntSliderEdit ui;
	int labelWidth_;
	int textWidth_;
	int unitsWidth_;
	int minimum_;
	int maximum_;
	int defaultValue_;
	int value_;
	bool power_of_two_;
	bool readonly_text;
	QStringList enums_;
	bool showDefaultButton_;
};

#endif // QINTSLIDEREDIT_H
