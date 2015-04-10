LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

OPENCV_CAMERA_MODULES:=on
OPENCV_INSTALL_MODULES:=on
#OPENCV_LIB_TYPE:=SHARED

include /Users/jennifer/CS231m/android/OpenCV-2.4.8.2-Tegra-sdk/sdk/native/jni/OpenCV-tegra3.mk

LIB_PATH :=$(LOCAL_PATH)/../lib
LIB_PATH +=/usr/local/include

LOCAL_SRC_FILES  := ORBfeatureJNI.cpp
LOCAL_C_INCLUDES += $(LOCAL_PATH)
LOCAL_LDLIBS     += -llog -ldl

LOCAL_MODULE     := orb_feature

include $(BUILD_SHARED_LIBRARY)