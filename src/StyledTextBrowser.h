#pragma once

#include <QApplication>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>

//const char *STYLE = 
//#include "style.qss"
//;


class StyledTextBrowser : public QTextBrowser {
public:
    StyledTextBrowser() : QTextBrowser(nullptr)
    {
        setupUI();
    }

private:
    void setupUI()
    {
		QFile file(NICKEL_NOTE_TEMPLATE_FILE);
		QFile styleFile(NICKEL_NOTE_STYLE_FILE); 
		if (file.open(QIODevice::ReadOnly | QIODevice::Text) &&
			styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {

			QTextStream in(&file);
			QString richText = in.readAll();
			file.close();

			QTextStream instyle(&styleFile);
			QString styleText = instyle.readAll();
			styleFile.close();


			QWidget *infoWidget = this;
			auto *outerLayout = new QVBoxLayout(infoWidget);
			infoWidget->setObjectName("infoWidget");

			QWidget *infoFrame = new QWidget(infoWidget);
			auto *innerLayout = new QHBoxLayout(infoFrame);
			infoFrame->setObjectName("infoFrame");

			outerLayout->addWidget(infoFrame, 0, Qt::AlignLeft);


			QLabel* label = new QLabel(infoFrame);
			label->setText(richText);
			label->setAlignment(Qt::AlignLeft);

			infoWidget->setStyleSheet(styleText);
			infoFrame->setStyleSheet(styleText);

			infoWidget->setContentsMargins(0, 0, 0, 0);
			infoFrame->setContentsMargins(0, 0, 0, 0);
			outerLayout->setSpacing(0);
			innerLayout->setSpacing(0);


    		innerLayout->addWidget(label, 0, Qt::AlignLeft);

		}
    }
};