#include "QLabelEdit.h"

QLabelEdit::QLabelEdit(QWidget *parent)
	: QWidget(parent)
	,labelWidth_(80)
	,unitsWidth_(40)
	,showDefaultButton_(true)
{
	ui.setupUi(this);
}

QLabelEdit::~QLabelEdit()
{

}

void QLabelEdit::setShowDefaultButton(bool l)
{
	showDefaultButton_=l;
	if(!showDefaultButton_||value_==defaultValue_)
		ui.reset->setDisabled(true);
	else
		ui.reset->setDisabled(false);
}

bool QLabelEdit::showDefaultButton() const
{
	return showDefaultButton_;
}

void QLabelEdit::setReadOnly(bool l)
{
	ui.lineEdit->setReadOnly(l);
}

bool QLabelEdit::readOnly() const
{
	return ui.lineEdit->isReadOnly();
}

void QLabelEdit::on_lineEdit_editingFinished()
{
	value_=ui.lineEdit->text();
	emit valueChanged();
}

void QLabelEdit::on_reset_clicked()
{
	setValue(defaultValue_);
	emit valueChanged();
}

void QLabelEdit::setValue(QString f)
{
	value_=f;
	setShowDefaultButton(showDefaultButton_);
	blockSignals(true);
	ui.lineEdit->setText(f);
	blockSignals(false);
}

QString QLabelEdit::value() const
{
	return value_;
}

void QLabelEdit::setTitle(QString f)
{
	ui.label->setText(f);
}

QString QLabelEdit::title() const
{
	return ui.label->text();
}


void QLabelEdit::setLabelWidth(int w)
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


void QLabelEdit::setUnitsWidth(int w)
{
	unitsWidth_=w;
	ui.units->setMinimumWidth(w);
	ui.units->setMaximumWidth(w);
	QSize s=ui.units->minimumSize();
	s.setWidth(w);
	ui.units->setMinimumSize(s);
	s=ui.units->maximumSize();
	s.setWidth(w);
	ui.units->setMaximumSize(s);
	update();
}

void QLabelEdit::setUnits(QString f)
{
	ui.units->setText(f);
}

QString QLabelEdit::units() const
{
	return ui.units->text();
}