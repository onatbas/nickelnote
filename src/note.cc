#include "note.h"

/*
NickelNote::NickelNote(const QString &filePath, QWidget *parent = nullptr) : QWidget(parent) {
	setWindowTitle("Qt Grey Box with Bordered Box");
	setGeometry(100, 100, 500, 500);

	// Create a layout and set it as the main layout for the widget
	QVBoxLayout *layout = new QVBoxLayout(this);
	setLayout(layout);

	// Create a grey box QLabel
	QLabel *greyBox = new QLabel(this);
	greyBox->setStyleSheet("background-color: rgba(169, 169, 169, 0.2);"); // 20% opacity
	greyBox->setFixedWidth(width() * 0.8); // 80% width
	greyBox->setFixedHeight(200); // 200 pixels height

	// Create a bordered box within the grey box QLabel
	QLabel *borderedBox = new QLabel(greyBox);
	borderedBox->setStyleSheet("border: 1px solid black; background-color: transparent;");
	borderedBox->setGeometry(10, 10, greyBox->width() - 20, greyBox->height() - 20); // 20px smaller on all edges

	// Read HTML content from file or use default text
	QString labelText = readHtmlFromFile(filePath);

	QLabel *titleLabel = new QLabel(labelText, borderedBox);
	titleLabel->setTextFormat(Qt::RichText);
	titleLabel->setAlignment(Qt::AlignCenter);

	// Add title label to the bordered box
	QVBoxLayout *borderedBoxLayout = new QVBoxLayout(borderedBox);
	borderedBoxLayout->addWidget(titleLabel);

	// Add the grey box to the layout
	layout->addWidget(greyBox, 0, Qt::AlignCenter);
}

QString NickelNote::readHtmlFromFile(const QString &filePath) {
        QFile file(filePath);
        QString content;

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            content = in.readAll();
            file.close();
        } else {
            // Use default text if file reading fails
            content = "<div align='center'><b>Bordered Box Title</b></div><br/>"
                      "<div align='center'>This is a bordered box with title and description.</div>";
        }

        return content;
}

//------------------------------------------------
//------------------------------------------------
//------------------------------------------------

typedef QWidget DragonPowerView;
typedef QObject OverDriveActionProxy;




NickelNote *nickelnote = nullptr;

void (*DragonPowerView_updateView)(DragonPowerView *_this);

*/
