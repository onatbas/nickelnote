#include "nickelnote.h"
//#include "note.h"

//Typedefs
typedef QObject OverDriveActionProxy;
void (*OverDriveActionProxy_setShowOverdrive)(OverDriveActionProxy *_this, bool setShow);



//Debug Info
void appendToFile(const QString &filePath, const QString &textToAppend)
{
    QFile file(filePath);
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream(&file) << textToAppend << "\n";
        file.close();
    }

}


extern "C" __attribute__((visibility("default"))) void _always_show_overdrive(OverDriveActionProxy *_this, bool setShow) {
	appendToFile(NICKEL_NOTE_DIR "logs.txt", "InterceptED!... _always_show_overdrive");
	OverDriveActionProxy_setShowOverdrive(_this, setShow);
}


struct nh_info NickelNote = {
    .name           = "NickelNote",
    .desc           = "show a note on the main screen during sleep.",
    .uninstall_flag = NICKEL_NOTE_DELETE_FILE,
};

struct nh_hook NickelNoteHook[] = {
	{
		.sym	= "_ZN20OverDriveActionProxy16setShowOverDriveEb",
		.sym_new = "_always_show_overdrive",
        .lib     = "libnickel.so.1.0.0",
		.out	= nh_symoutptr(OverDriveActionProxy_setShowOverdrive),
		.desc    = "Always show overdrive"
	}, 
    {0}
};


struct nh_dlsym NickelNoteDlsym[] = {
/*{
		.name = "_ZN20OverDriveActionProxy16setShowOverDriveEb",
		.out	= nh_symoutptr(OverDriveActionProxy_setShowOverdrive),
		.desc = "OverDriveActionProxy_setShowOverdrive"
	},*/	
	{0},
};



bool nn_uninstall()
{
    nh_delete_file(NICKEL_NOTE_TEMPLATE_FILE);
   // nh_delete_dir(NICKEL_NOTE_DIR);
    return true;
}
int nn_init()
{
  appendToFile(NICKEL_NOTE_DIR "logs.txt", "Init complete..5.. All functionality is commented out..");
	return 0;
}


NickelHook(
    .init  = &nn_init,
    .info  = &NickelNote,
    .hook  = NickelNoteHook,
    .dlsym = NickelNoteDlsym,
	.uninstall = &nn_uninstall
);
