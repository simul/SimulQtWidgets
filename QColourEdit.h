#ifndef QCOLOUREDIT_H
#define QCOLOUREDIT_H

#include <QWidget>
#include "../SimulQtWidgets/GeneratedFiles/ui_QColourEdit.h"

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

class QColourEdit : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString label READ label WRITE setLabel DESIGNABLE true)
	Q_PROPERTY(int labelWidth READ labelWidth WRITE setLabelWidth DESIGNABLE true)
	Q_PROPERTY(bool showAlpha READ showAlpha WRITE setShowAlpha DESIGNABLE true)
public:
	QColourEdit(QWidget *parent = 0);
	~QColourEdit();
	void setLabel(QString f);
	QString label() const;
	int labelWidth() const;
	void setLabelWidth(int w);
	bool showAlpha() const;
	void setShowAlpha(bool w);
	void setColour(const double *c);
	void setColour(double r,double g,double b,double a=1.0);
signals:
	void valueChanged();
	/// Emit startedEdit to e.g. store for undo.
	void startedEdit();			
public slots:
	void on_red_editingFinished();
	void on_green_editingFinished();
	void on_blue_editingFinished();
	void on_alpha_editingFinished();
private:
	int labelWidth_;
	Ui::QColourEdit ui;
	double red,green,blue,alpha;
};

#endif // QCOLOUREDIT_H
