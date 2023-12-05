#pragma once

#include <QApplication>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>

//const char *STYLE = 
//#include "style.qss"
//;


class StyledTextBrowser : public QFrame {
public:
    StyledTextBrowser() : QFrame(nullptr)
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
			infoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			infoWidget->setStyleSheet(styleText);
			infoWidget->setContentsMargins(0, 0, 0, 0);

			QWidget *infoFrame = new QFrame(infoWidget);
			auto *innerLayout = new QHBoxLayout(infoFrame);
			infoFrame->setObjectName("infoFrame");
			infoFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			outerLayout->addWidget(infoFrame, 0, Qt::AlignLeft);
			infoFrame->setStyleSheet(styleText);
			infoFrame->setContentsMargins(0, 0, 0, 0);


			QLabel* label = new QLabel(infoFrame);
			label->setText(richText);
			label->setAlignment(Qt::AlignLeft);
    		innerLayout->addWidget(label, 0, Qt::AlignLeft);

		}
    }
};