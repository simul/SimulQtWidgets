#include "QColourEdit.h"

QColourEdit::QColourEdit(QWidget *parent)
	: QWidget(parent)
	,red(0.0)
	,green(0.0)
	,blue(0.0)
	,alpha(0.0)
{
	ui.setupUi(this);
}

QColourEdit::~QColourEdit()
{

}

void QColourEdit::setColour(const double *c)
{
	red=*c++;
	green=*c++;
	blue=*c++;
	alpha=*c++;
}

void QColourEdit::setColour(double r,double g,double b,double a)
{
	red=r;
	green=g;
	blue=b;
	alpha=a;
}


void QColourEdit::setLabel(QString f)
{
	ui.label->setText(f);
}

QString QColourEdit::label() const
{
	return ui.label->text();
}

int QColourEdit::labelWidth() const
{
	return labelWidth_;
}

void QColourEdit::setLabelWidth(int w)
{
	labelWidth_=w;
	QSize s=ui.label->minimumSize();
	s.setWidth(w);
	ui.label->setMinimumSize(s);
	s=ui.label->maximumSize();
	s.setWidth(w);
	ui.label->setMaximumSize(s);
	update();
}

bool QColourEdit::showAlpha() const
{
	return ui.alpha->isVisible();
}

void QColourEdit::setShowAlpha(bool w)
{
	ui.alpha->setVisible(w);
}

void QColourEdit::on_red_editingFinished()
{
	bool ok=false;
	double value_=ui.red->text().toDouble(&ok);
	if(!ok)
		return;
	red=value_;
	emit valueChanged();
}

void QColourEdit::on_green_editingFinished()
{
	bool ok=false;
	double value_=ui.green->text().toDouble(&ok);
	if(!ok)
		return;
	green=value_;
	emit valueChanged();
}

void QColourEdit::on_blue_editingFinished()
{
	bool ok=false;
	double value_=ui.blue->text().toDouble(&ok);
	if(!ok)
		return;
	blue=value_;
	emit valueChanged();
}

void QColourEdit::on_alpha_editingFinished()
{
	bool ok=false;
	double value_=ui.alpha->text().toDouble(&ok);
	if(!ok)
		return;
	alpha=value_;
	emit valueChanged();
}