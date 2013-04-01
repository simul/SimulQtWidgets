#include "QIntSliderEdit.h"
#include <math.h>

static int log2(int val)
{
	double l=log((double)val)/log(2.0);
	return (int)(l+0.5);
}

QIntSliderEdit::QIntSliderEdit(QWidget *parent)
	: QWidget(parent)
	,minimum_(0)
	,maximum_(100)
	,value_(0)
	,power_of_two_(false)
{
	ui.setupUi(this);
}

QIntSliderEdit::~QIntSliderEdit()
{

}

void QIntSliderEdit::setMinimum(int f)
{
	minimum_=f;
	if(power_of_two_)
	{
		if(minimum_<=0)
			minimum_=1;
		ui.slider->setMinimum(log2(minimum_));
	}
	else
		ui.slider->setMinimum(minimum_);
}

void QIntSliderEdit::setMaximum(int f)
{
	maximum_=f;
	if(power_of_two_)
	{
		if(maximum_<=minimum_)
			maximum_=minimum_*2;
		ui.slider->setMaximum(log2(maximum_));
	}
	else
		ui.slider->setMaximum(maximum_);
}

void QIntSliderEdit::setPowerOfTwo(bool l)
{
	power_of_two_=l;
	setMinimum(minimum_);
	setMaximum(maximum_);
	updateSlider();
}

bool QIntSliderEdit::powerOfTwo() const
{
	return power_of_two_;
}

void QIntSliderEdit::setValue(QVariant f)
{
	setValue(f,true);
}

void QIntSliderEdit::setValue(QVariant f,bool single_valued)
{
	bool ok;
	value_=f.toInt(&ok);
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
		ui.lineEdit->setText(QString("%1").arg(value_));
	else
		ui.lineEdit->setText("");
	ui.slider->blockSignals(false);
	this->blockSignals(false);
}

void QIntSliderEdit::setTitle(QString f)
{
	ui.label->setText(f);
}

QString QIntSliderEdit::title() const
{
	return ui.label->text();
}


void QIntSliderEdit::on_slider_sliderMoved(int pos)
{
	int val=pos;
	if(power_of_two_)
	{
		val=1<<pos;
	}
	else
		val=pos;
	ui.lineEdit->blockSignals(true);
	ui.lineEdit->setText(QString("%1").arg(val));
	ui.lineEdit->blockSignals(false);
}

void QIntSliderEdit::on_slider_valueChanged(int pos)
{
	int val=pos;
	if(power_of_two_)
	{
		val=1<<pos;
	}
	if(val<minimum_)
		val=minimum_;
	if(val>maximum_)
		val=maximum_;
	value_=val;
	ui.lineEdit->blockSignals(true);
	ui.lineEdit->setText(QString("%1").arg(value_));
	ui.lineEdit->blockSignals(false);
	emit valueChanged();
}

void QIntSliderEdit::on_lineEdit_editingFinished()
{
	bool ok=false;
	value_=ui.lineEdit->text().toInt(&ok);
	if(power_of_two_)
		value_=1<<(log2(value_));
	if(!ok)
		return;
	ui.slider->blockSignals(true);
	updateSlider();
	ui.slider->blockSignals(false);
	emit valueChanged();
}

void QIntSliderEdit::updateSlider()
{
	if(value_<minimum_)
		value_=minimum_;
	if(value_>maximum_)
		value_=maximum_;
	int val=(value_-minimum_);
	if(power_of_two_)
		val=log2(value_)-log2(minimum_);
	int pos=ui.slider->minimum()+val;
	ui.slider->blockSignals(true);
	ui.slider->setValue((int)pos);
	ui.lineEdit->blockSignals(false);
	emit valueChanged();
}