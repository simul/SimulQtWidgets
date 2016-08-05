#include "QVectorEdit.h"

QVectorEdit::QVectorEdit(QWidget *parent)
	:QWidget(parent)
	,value_(0,0,0)
	,colourEdit_(false)
	,labelWidth_(80)
	,textWidth_(80)
	,unitsWidth_(40)
	,liveUpdate_(false)
{
	ui.setupUi(this);
	ui.reset->setDisabled(true);
	int h=this->height();
	this->setMinimumHeight(h);
	ui.x->setWhatsThis(whatsThis());
	ui.y->setWhatsThis(whatsThis());
	ui.z->setWhatsThis(whatsThis());
	ui.label->setWhatsThis(whatsThis());
	setTextWidth(textWidth_);
	setValue(defaultValue_);
	setColourEdit(colourEdit_);
}

QVectorEdit::~QVectorEdit()
{

}

void QVectorEdit::setTextWidth(int w)
{
	textWidth_=w;
	QSize s=ui.x->minimumSize();
	s.setWidth(w);
	ui.x->setMinimumSize(s);
	ui.y->setMinimumSize(s);
	ui.z->setMinimumSize(s);
	s=ui.x->maximumSize();
	s.setWidth(w);
	ui.x->setMaximumSize(s);
	ui.y->setMaximumSize(s);
	ui.z->setMaximumSize(s);
	update();
}

void QVectorEdit::on_reset_clicked()
{
	emit startedEdit();
	setValue(defaultValue_);
	emit valueChanged();
}

void QVectorEdit::on_x_editingFinished()
{
	bool ok=false;
	double x=ui.x->text().toDouble(&ok);
	if(!ok)
		return;
	emit startedEdit();
	value_.setX((float)x);
	setShowDefaultButton();
	emit valueChanged();
}

void QVectorEdit::on_y_editingFinished()
{
	bool ok=false;
	double y=ui.y->text().toDouble(&ok);
	if(!ok)
		return;
	emit startedEdit();
	value_.setY((float)y);
	setShowDefaultButton();
	emit valueChanged();
}

void QVectorEdit::on_z_editingFinished()
{
	bool ok=false;
	double z=ui.z->text().toDouble(&ok);
	if(!ok)
		return;
	emit startedEdit();
	value_.setZ((float)z);
	setShowDefaultButton();
	emit valueChanged();
}

void QVectorEdit::setValue(QVector3D f)
{
	setValue(f,true);
}

void QVectorEdit::setShowDefaultButton()
{
	if(value_==defaultValue_)
		ui.reset->setDisabled(true);
	else
		ui.reset->setDisabled(false);
}
QString valueToText(double value)
{
	return QString("%1").arg(value,0,'g',-1,(QChar)' ');
}

QVector3D QVectorEdit::value() const
{
	return value_;
}

void QVectorEdit::setValue(QVector3D f,bool single_valued)
{
	value_=f;
	setShowDefaultButton();
	blockSignals(true);
	if(single_valued)
	{
		ui.x->setText(valueToText(value_.x()));
		ui.y->setText(valueToText(value_.y()));
		ui.z->setText(valueToText(value_.z()));
	}
	else
	{
		ui.x->setText("");
		ui.y->setText("");
		ui.z->setText("");
	}
	blockSignals(false);
	update();
}

void QVectorEdit::setLiveUpdate(bool l)
{
	liveUpdate_=l;
}

bool QVectorEdit::liveUpdate() const
{
	return liveUpdate_;
}

void QVectorEdit::setColourEdit(bool l)
{
	colourEdit_=l;
	if(colourEdit_)
	{
		ui.xLabel->setText("R");
		ui.yLabel->setText("G");
		ui.zLabel->setText("B");
	}
	else
	{
		ui.xLabel->setText("X");
		ui.yLabel->setText("Y");
		ui.zLabel->setText("Z");
	}
}

bool QVectorEdit::colourEdit() const
{
	return colourEdit_;
}

void QVectorEdit::setLabelWidth(int w)
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

void QVectorEdit::setTitle(QString f)
{
	ui.label->setText(f);
}

QString QVectorEdit::title() const
{
	return ui.label->text();
}

void QVectorEdit::setUnitsWidth(int w)
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

void QVectorEdit::setUnits(QString f)
{
	ui.units->setText(f);
}

QString QVectorEdit::units() const
{
	return ui.units->text();
}