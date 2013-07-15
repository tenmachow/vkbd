/*
	Author: shiroki@www.cuteqt.com
	License: GPLv2
*/

#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "imframe.h"
#include "inputwidget.h"

IMFrame::IMFrame()
{
	inputwidget = new InputWidget(this);
	inputwidget->show();
}

IMFrame::~IMFrame()
{
}

void IMFrame::sendContent(const QString& newcontent)
{
	content += newcontent;
	sendPreeditString(content,0);
}

void IMFrame::confirmContent()
{
	sendCommitString(content);
	content.clear();
}

void IMFrame::updateHandler(int type)
{
	QWidget *active;
	switch(type)
	{
	case QWSInputMethod::FocusOut:
	{
		active = qApp->activeWindow();
		active->setGeometry(0, 0, 800, 480);
		content.clear();
		inputwidget->hide();
		break;
	}
	case QWSInputMethod::FocusIn:
	{
		content.clear();
		active = qApp->activeWindow();
		active->setGeometry(0, 0, 800, 380);
		inputwidget->setGeometry(0, 380, 800, 100);
		inputwidget->show();
		break;
	}
	default:
		break;
	}
}
