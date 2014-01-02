#############################################################################
# Makefile for building: FtpClient
# Generated by qmake (2.01a) (Qt 4.7.4) on: ?? ?? 28 13:09:27 2013
# Project:  FtpClient.pro
# Template: app
# Command: e:\qtsdk\desktop\qt\4.7.4\mingw\bin\qmake.exe -spec e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\win32-g++ -o Makefile FtpClient.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = e:\qtsdk\desktop\qt\4.7.4\mingw\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: FtpClient.pro  e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/win32-g++/qmake.conf e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/qconfig.pri \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/modules/qt_webkit_version.pri \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/qt_functions.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/qt_config.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/exclusive_builds.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/default_pre.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/win32/default_pre.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/debug.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/debug_and_release.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/default_post.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/win32/default_post.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/win32/rtti.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/win32/exceptions.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/win32/stl.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/shared.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/warn_on.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/qt.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/win32/thread.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/moc.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/win32/windows.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/resources.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/uic.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/yacc.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/lex.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/mkspecs/features/include_source_dir.prf \
		e:/QtSDK/Desktop/Qt/4.7.4/mingw/lib/qtmaind.prl
	$(QMAKE) -spec e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\win32-g++ -o Makefile FtpClient.pro
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\qconfig.pri:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\modules\qt_webkit_version.pri:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\qt_functions.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\qt_config.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\exclusive_builds.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\default_pre.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\win32\default_pre.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\debug.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\debug_and_release.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\default_post.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\win32\default_post.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\win32\rtti.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\win32\exceptions.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\win32\stl.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\shared.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\warn_on.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\qt.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\win32\thread.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\moc.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\win32\windows.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\resources.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\uic.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\yacc.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\lex.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\features\include_source_dir.prf:
e:\QtSDK\Desktop\Qt\4.7.4\mingw\lib\qtmaind.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec e:\QtSDK\Desktop\Qt\4.7.4\mingw\mkspecs\win32-g++ -o Makefile FtpClient.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first

debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
