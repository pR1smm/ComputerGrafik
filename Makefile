#############################################################################
# Makefile for building: ModelsTextured
# Generated by qmake (3.0) (Qt 5.7.0)
# Project:  ModelsTextured.pro
# Template: app
# Command: C:\Qt\5.7\mingw53_32\bin\qmake.exe -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" -o Makefile ModelsTextured.pro
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = C:\Qt\5.7\mingw53_32\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: ModelsTextured.pro ../../../Qt/5.7/mingw53_32/mkspecs/win32-g++/qmake.conf ../../../Qt/5.7/mingw53_32/mkspecs/features/spec_pre.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/qdevice.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/features/device_config.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/common/angle.conf \
		../../../Qt/5.7/mingw53_32/mkspecs/qconfig.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3drender.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axbase.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axserver.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_core.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_help.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_location.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_location_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_network.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_script.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scxml.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_winextras.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt/5.7/mingw53_32/mkspecs/features/qt_functions.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/qt_config.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/win32/qt_config.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/win32-g++/qmake.conf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/spec_post.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/exclusive_builds.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/default_pre.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/win32/default_pre.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/resolve_config.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/exclusive_builds_post.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/default_post.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/win32/console.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/qml_debug.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/win32/rtti.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/precompile_header.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/warn_on.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/qt.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/resources.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/moc.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/win32/opengl.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/uic.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/file_copies.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/testcase_targets.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/exceptions.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/yacc.prf \
		../../../Qt/5.7/mingw53_32/mkspecs/features/lex.prf \
		ModelsTextured.pro \
		../../../Qt/5.7/mingw53_32/lib/Qt5OpenGL.prl \
		../../../Qt/5.7/mingw53_32/lib/Qt5Widgets.prl \
		../../../Qt/5.7/mingw53_32/lib/Qt5Multimedia.prl \
		../../../Qt/5.7/mingw53_32/lib/Qt5Gui.prl \
		../../../Qt/5.7/mingw53_32/lib/Qt5Network.prl \
		../../../Qt/5.7/mingw53_32/lib/Qt5Core.prl
	$(QMAKE) -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" -o Makefile ModelsTextured.pro
../../../Qt/5.7/mingw53_32/mkspecs/features/spec_pre.prf:
../../../Qt/5.7/mingw53_32/mkspecs/qdevice.pri:
../../../Qt/5.7/mingw53_32/mkspecs/features/device_config.prf:
../../../Qt/5.7/mingw53_32/mkspecs/common/angle.conf:
../../../Qt/5.7/mingw53_32/mkspecs/qconfig.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3drender.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axbase.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axserver.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_clucene_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_core.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_core_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_dbus.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_designer.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gui.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_help.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_help_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_location.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_location_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_network.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_network_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_nfc.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_opengl.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_positioning.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qml.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quick.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_script.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_script_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scxml.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sensors.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialport.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sql.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_svg.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_testlib.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_uitools.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_websockets.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_widgets.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_winextras.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xml.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../Qt/5.7/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../Qt/5.7/mingw53_32/mkspecs/features/qt_functions.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/qt_config.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/win32/qt_config.prf:
../../../Qt/5.7/mingw53_32/mkspecs/win32-g++/qmake.conf:
../../../Qt/5.7/mingw53_32/mkspecs/features/spec_post.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/exclusive_builds.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/default_pre.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/win32/default_pre.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/resolve_config.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/exclusive_builds_post.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/default_post.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/win32/console.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/qml_debug.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/win32/rtti.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/precompile_header.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/warn_on.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/qt.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/resources.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/moc.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/win32/opengl.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/uic.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/file_copies.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/testcase_targets.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/exceptions.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/yacc.prf:
../../../Qt/5.7/mingw53_32/mkspecs/features/lex.prf:
ModelsTextured.pro:
../../../Qt/5.7/mingw53_32/lib/Qt5OpenGL.prl:
../../../Qt/5.7/mingw53_32/lib/Qt5Widgets.prl:
../../../Qt/5.7/mingw53_32/lib/Qt5Multimedia.prl:
../../../Qt/5.7/mingw53_32/lib/Qt5Gui.prl:
../../../Qt/5.7/mingw53_32/lib/Qt5Network.prl:
../../../Qt/5.7/mingw53_32/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug" -o Makefile ModelsTextured.pro

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
