LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := BlockForceMenu

# Tüm dosyalar artık aynı jni klasöründe olduğu için doğrudan isimlerini yazıyoruz
LOCAL_SRC_FILES := main.cpp \
                   imgui.cpp \
                   imgui_draw.cpp \
                   imgui_widgets.cpp \
                   imgui_tables.cpp \
                   imgui_impl_android.cpp \
                   imgui_impl_opengl3.cpp

LOCAL_LDLIBS := -llog -lGLESv2 -landroid
LOCAL_C_INCLUDES := $(LOCAL_PATH)

include $(BUILD_SHARED_LIBRARY)
