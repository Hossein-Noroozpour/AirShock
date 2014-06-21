LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := hge
LOCAL_SRC_FILES := hge-main.cpp
include $(BUILD_SHARED_LIBRARY)