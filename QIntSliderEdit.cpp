#include "QIntSliderEdit.h"
#include <math.h>

static int log2(int val)
{
	double l=log((double)val)/log(2.0);
	return (int)(l+0.5);
}

QIntSliderEdit::QIntSliderEdit(QWidget *parent)
	: QWidget(parent)
	,labelWidth_(80)
	,textWidth_(80)
	,minimum_(0)
	,maximum_(100)
	,value_(0)
	,power_of_two_(false)
	,readonly_text(false)
{
	ui.setupUi(this);
	int h=this->height();
	this->setMinimumHeight(h);
}

QIntSliderEdit::~QIntSliderEdit()
{
}

Qt::Orientation QIntSliderEdit::orientation() const
{
	return ui.slider->orientation();
}

void QIntSliderEdit::setOrientation(Qt::Orientation o)
{
	ui.slider->setOrientation(o);
	QBoxLayout *l=(QBoxLayout*)this->layout();
	if(o==Qt::Horizontal)
	{
		l->setDirection(QBoxLayout::LeftToRight);
		ui.lineEdit->setMinimumWidth(64);
		ui.lineEdit->setMaximumWidth(64);
		ui.slider->setMinimumWidth(32);
		ui.slider->setMinimumHeight(8);
		ui.label->setAlignment(Qt::AlignLeft);
		ui.lineEdit->setAlignment(Qt::AlignLeft);
	}
	else
	{
		l->setDirection(QBoxLayout::TopToBottom);
		ui.slider->setMinimumWidth(8);
		ui.slider->setMinimumHeight(32);
		ui.lineEdit->setMinimumWidth(labelWidth_);
		ui.lineEdit->setMaximumWidth(labelWidth_);
		ui.label->setAlignment(Qt::AlignHCenter);
		ui.lineEdit->setAlignment(Qt::AlignHCenter);
	}
	update();
}

void QIntSliderEdit::setLabelWidth(int w)
{
	labelWidth_=w;
	ui.label->setMinimumWidth(w);
	ui.label->setMaximumWidth(w);
	QSize s=ui.label->minimumSize();
	s.setWidth(w);
	ui.label->setMinimumSize(s);
	s=ui.label->maximumSize();
	s.setWidth(w);
	ui.label->setMaximumSize(s);
	update();
}

void QIntSliderEdit::setTextWidth(int w)
{
	textWidth_=w;
	QSize s=ui.lineEdit->minimumSize();
	s.setWidth(w);
	ui.lineEdit->setMinimumSize(s);
	s=ui.lineEdit->maximumSize();
	s.setWidth(w);
	ui.lineEdit->setMaximumSize(s);
	update();
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


void QIntSliderEdit::setReadOnlyText(bool l)
{
	readonly_text=l;
	ui.lineEdit->setReadOnly(readonly_text);
}

bool QIntSliderEdit::readOnlyText() const
{
	return readonly_text;
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
	ui.slider->blockSignals(false);
	emit valueChanged();
}