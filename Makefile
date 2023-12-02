include NickelHook/NickelHook.mk


override PKGCONF += Qt5Widgets Qt5Xml
override LIBRARY  := libnickelnote.so
override SOURCES  += src/nickelnote.cc
override MOCS     += src/nickelnote.h
override CFLAGS   += -Wall -Werror
override CXXFLAGS += -Wall -Wextra -Werror -Wno-missing-field-initializers

include NickelHook/NickelHook.mk
