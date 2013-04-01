#include "QSliderEdit.h"
#include <math.h>

QSliderEdit::QSliderEdit(QWidget *parent)
	: QWidget(parent)
	,minimum_(0.0)
	,maximum_(1.0)
	,value_(0.0)
	,logarithmic_(false)
	,step_(0.0)
{
	ui.setupUi(this);
	ui.slider->setMinimum(0);
	ui.slider->setMaximum(1000);
	setValue(0.0);
}

QSliderEdit::~QSliderEdit()
{

}

Qt::Orientation	QSliderEdit::orientation() const
{
	return ui.slider->orientation();
}

void QSliderEdit::setOrientation(Qt::Orientation o)
{
	QLayout *l=layout();
	if(l)
	{
		l->removeWidget(ui.label);
		l->removeWidget(ui.slider);
		l->removeWidget(ui.lineEdit);
		setLayout(NULL);
		delete l;
	}
	if(o==Qt::Vertical)
	{
		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(ui.label);
		layout->addWidget(ui.slider);
		layout->addWidget(ui.lineEdit);
		setLayout(layout);
		layout->update();
	}
	else
	{
		QHBoxLayout *layout = new QHBoxLayout;
		layout->addWidget(ui.label);
		layout->addWidget(ui.slider);
		layout->addWidget(ui.lineEdit);
		setLayout(layout);
		layout->update();
	}
	ui.slider->setOrientation(o);
}

void QSliderEdit::setStep(double s)
{
	step_=s;
	if(step_>0)
	{
		int num_steps=(maximum_-minimum_)/step_;
		if(num_steps>10000)
			num_steps=10000;
		ui.slider->setMaximum(num_steps);
	}
}

double QSliderEdit::step() const
{
	return step_;
}

void QSliderEdit::setLogarithmic(bool l)
{
	logarithmic_=l;
	if(logarithmic_)
	{
		if(maximum_<=0)
			maximum_=1.0;
		if(minimum_<=0)
			minimum_=maximum_/100.0;
	}
	updateSlider();
}

bool QSliderEdit::logarithmic() const
{
	return logarithmic_;
}

void QSliderEdit::setValue(QVariant f)
{
	setValue(f,true);
}

void QSliderEdit::setValue(QVariant f,bool single_valued)
{
	bool ok;
	value_=f.toDouble(&ok);
	if(!ok)
		return;
	if(value_<minimum_)
		value_=minimum_;
	if(value_>maximum_)
		value_=maximum_;
	this->blockSignals(true);
	ui.slider->blockSignals(true);
	updateSlider();
	if(single_valued)
		ui.lineEdit->setText(QString("%1").arg(value_,0,'g',-1,(QChar)' '));
	else
		ui.lineEdit->setText("");
	ui.slider->blockSignals(false);
	this->blockSignals(false);
}

void QSliderEdit::setTitle(QString f)
{
	ui.label->setText(f);
}

QString QSliderEdit::title() const
{
	return ui.label->text();
}

void QSliderEdit::on_slider_sliderMoved(int pos)
{
	double val=(double)(pos-ui.slider->minimum())/(double)(ui.slider->maximum()-ui.slider->minimum());
	if(logarithmic_)
	{
		double logval=(log10(maximum_)-log10(minimum_))*val+log10(minimum_);
		val=pow(10.0,logval);
	}
	else
		val=(maximum_-minimum_)*val+minimum_;
	ui.lineEdit->blockSignals(true);
	ui.lineEdit->setText(QString("%1").arg(val,0,'g',-1,(QChar)' '));
	ui.lineEdit->blockSignals(false);
}

void QSliderEdit::on_slider_valueChanged(int pos)
{
	double val=(double)(pos-ui.slider->minimum())/(double)(ui.slider->maximum()-ui.slider->minimum());
	if(logarithmic_)
	{
		double logval=(log10(maximum_)-log10(minimum_))*val+log10(minimum_);
		val=pow(10.0,logval);
	}
	else
		val=(maximum_-minimum_)*val+minimum_;
	if(val<minimum_)
		val=minimum_;
	if(val>maximum_)
		val=maximum_;
	value_=val;
	ui.lineEdit->blockSignals(true);
	ui.lineEdit->setText(QString("%1").arg(value_,0,'g',-1,(QChar)' '));
	ui.lineEdit->blockSignals(false);
	emit valueChanged();
}

void QSliderEdit::on_lineEdit_editingFinished()
{
	bool ok=false;
	value_=ui.lineEdit->text().toDouble(&ok);
	if(!ok)
		return;
	ui.slider->blockSignals(true);
	updateSlider();
	ui.slider->blockSignals(false);
	emit valueChanged();
}

void QSliderEdit::updateSlider()
{
	if(value_<minimum_)
		value_=minimum_;
	if(value_>maximum_)
		value_=maximum_;
	double val=(value_-minimum_)/(maximum_-minimum_);
	if(logarithmic_)
		val=(log10(value_)-log10(minimum_))/(log10(maximum_)-log10(minimum_));
	double pos=ui.slider->minimum()+(double)(ui.slider->maximum()-ui.slider->minimum())*val;
	ui.slider->blockSignals(true);
	ui.slider->setValue((int)pos);
	ui.lineEdit->blockSignals(false);
	emit valueChanged();
}