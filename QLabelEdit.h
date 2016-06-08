#ifndef QLABELEDIT_H
#define QLABELEDIT_H

#include <QWidget>
#include "GeneratedFiles/ui_QLabelEdit.h"
#include "Export.h"

class SIMUL_QT_WIDGETS_EXPORT QLabelEdit : public QWidget
{
	Q_OBJECT

	Q_PROPERTY(bool showDefaultButton READ showDefaultButton WRITE setShowDefaultButton DESIGNABLE true)
	Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly DESIGNABLE true)
	Q_PROPERTY(QString defaultValue READ defaultValue WRITE setDefaultValue DESIGNABLE true)
	Q_PROPERTY(QString title READ title WRITE setTitle DESIGNABLE true)
	Q_PROPERTY(int labelWidth READ labelWidth WRITE setLabelWidth DESIGNABLE true)
	Q_PROPERTY(QString units READ units WRITE setUnits DESIGNABLE true)
	Q_PROPERTY(int unitsWidth READ unitsWidth WRITE setUnitsWidth DESIGNABLE true)

public:
	QLabelEdit(QWidget *parent = 0);
	~QLabelEdit();
	void setShowDefaultButton(bool l);
	bool showDefaultButton() const;
	void setReadOnly(bool l);
	bool readOnly() const;
	void setValue(QString f);
	int labelWidth() const
	{
		return labelWidth_;
	}
	void setLabelWidth(int w);
	
	int unitsWidth() const
	{
		return unitsWidth_;
	}
	void setUnitsWidth(int w);
	void setDefaultValue(QString f)
	{
		defaultValue_ = f;
		setShowDefaultButton(true);
	}
	QString defaultValue() const
	{
		return defaultValue_;
	}
	void setTitle(QString f);
	QString title() const;
	void setUnits(QString f);
	QString units() const;
public slots:
	void on_lineEdit_editingFinished();
	void on_reset_clicked();
signals:
   void valueChanged();
private:
	Ui::QLabelEdit ui;
	
	int labelWidth_;
	int unitsWidth_;
	QString value_,defaultValue_;

	bool showDefaultButton_;
};

#endif // QLABELEDIT_H
