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

FullScreenDragonPowerView *(*setupUi)(FullScreenDragonPowerView *);

extern "C" __attribute__((visibility("default"))) FullScreenDragonPowerView* _fullScreenDragonPowerView_constructor(FullScreenDragonPowerView *_this){

	auto view = setupUi(_this);
    QWidget* widget = qobject_cast<QWidget*>(view);

    if (widget) {
		QBoxLayout* layout = dynamic_cast<QBoxLayout*>(widget->layout());
		if (layout){
			layout->insertWidget(0, new StyledTextBrowser());
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
		.out = nh_symoutptr(setupUi),
		.desc= "Play with the Dragon!"
	} ,
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
