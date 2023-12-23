#pragma once

#include <cstddef>
#include <cstdlib>

#include <NickelHook.h>

#include <Qt>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QFile>
#include <QLabel>
#include <QVariant>
#include <QSettings>
#include <QMargins>
#include <QScreen>
#include <QFile>
#include <QTextStream>



#ifndef NICKEL_NOTE_DIR
    #define NICKEL_NOTE_DIR "/mnt/onboard/.adds/nickelnote/"
#endif

#ifndef NICKEL_NOTE_TEMPLATE_FILE
    #define NICKEL_NOTE_TEMPLATE_FILE "/mnt/onboard/.adds/nickelnote/content.template"
#endif

#ifndef NICKEL_NOTE_PIN_TEMPLATE_FILE
    #define NICKEL_NOTE_PIN_TEMPLATE_FILE "/mnt/onboard/.adds/nickelnote/pin.template"
#endif

#ifndef NICKEL_NOTE_STYLE_FILE
    #define NICKEL_NOTE_STYLE_FILE "/mnt/onboard/.adds/nickelnote/style.template"
#endif

#ifndef NICKEL_NOTE_DELETE_FILE
	#define NICKEL_NOTE_DELETE_FILE "/mnt/onboard/nn_uninstall"
#endif
