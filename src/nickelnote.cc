#include "nickelnote.h"
#include "StyledTextBrowser.h"


#include <QApplication>
#include <QWidget>
#include <QLayout>
#include <QDomDocument>
#include <QDomElement>


#include <QWidget>
#include <QPixmap>
#include <QScreen>
#include <QFile>


//typedef
typedef QWidget FullScreenDragonPowerView;
typedef QWidget PinInputDialog;

FullScreenDragonPowerView *(*powerViewConstructor)(FullScreenDragonPowerView *);
PinInputDialog *(*pinInputConstructor)(PinInputDialog *);

extern "C" __attribute__((visibility("default"))) FullScreenDragonPowerView* _fullScreenDragonPowerView_constructor(FullScreenDragonPowerView *_this){

	auto view = powerViewConstructor(_this);

	if (view)
	{
		QBoxLayout *layout = dynamic_cast<QBoxLayout *>(view->layout());
		if (layout)
		{
			layout->insertWidget(0, new StyledTextBrowser());
		}
	}
	return view;
}

extern "C" __attribute__((visibility("default"))) PinInputDialog* _pinCodeInputDialog_constructor(PinInputDialog *_this){

	auto view = pinInputConstructor(_this);
	QFile file(NICKEL_NOTE_PIN_TEMPLATE_FILE);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		QString richText = in.readAll();
		file.close();

		if (view)
		{
			QWidget *forgotPin = view->findChild<QWidget *>("lblForgotPin");
			if (forgotPin)
			{
				QLabel *label = new QLabel(richText);
				label->setAlignment(Qt::AlignCenter);
				forgotPin->parentWidget()->layout()->replaceWidget(forgotPin, label);
				delete forgotPin;
			}
		}

		QWidget *signout = view->findChild<QWidget *>("lblSignOut");
		if (signout)
		{
			signout->setParent(nullptr);
			delete signout;
		}
	}
	return view;
}


struct nh_info NickelNote = {
    .name           = "NickelNote",
    .desc           = "show a note on the main screen during sleep.",
    .uninstall_flag = NICKEL_NOTE_DELETE_FILE,
};

struct nh_hook NickelNoteHook[] = {

	{
		.sym = "_ZN25FullScreenDragonPowerViewC1Ev",
		.sym_new = "_fullScreenDragonPowerView_constructor",
		.lib	= "libnickel.so.1.0.0",
		.out = nh_symoutptr(powerViewConstructor),
		.desc= "Change power down sleep view."
	},
	{
		.sym = "_ZN18PinCodeInputDialogC1EP7QWidget",
		.sym_new = "_pinCodeInputDialog_constructor",
		.lib	= "libnickel.so.1.0.0",
		.out = nh_symoutptr(pinInputConstructor),
		.desc= "Change input pin dialog."
	},
    {0}
};


struct nh_dlsym NickelNoteDlsym[] = {
	{0},
};

bool nn_uninstall()
{
    nh_delete_file(NICKEL_NOTE_TEMPLATE_FILE);
    nh_delete_dir(NICKEL_NOTE_DIR);
    return true;
}
int nn_init()
{
	return 0;
}


NickelHook(
    .init  = &nn_init,
    .info  = &NickelNote,
    .hook  = NickelNoteHook,
    .dlsym = NickelNoteDlsym,
	.uninstall = &nn_uninstall
);
