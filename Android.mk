LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    gui.cpp  layout.cpp  QButton.cpp  QFont.cpp  QHBoxLayout.cpp  QVBoxLayout.cpp  QWidget.cpp  QWindow.cpp  text.cpp

LOCAL_C_INCLUDES := /home/shane/pro/libsdl/SDL-1.2.14/include
LOCAL_C_INCLUDES += /home/shane/source/include/ /home/shane/source/include/freetype2
LOCAL_C_INCLUDES += external/sdl_ttf
LOCAL_STATIC_LIBRARIES := libSDL_ttf libSDL libfreetype
LOCAL_SHARED_LIBRARIES := libts

LOCAL_CFLAGS += -std=gnu++0x -O2

LOCAL_MODULE:= gui

LOCAL_PRELINK_MODULE:=false

include $(BUILD_EXECUTABLE)

