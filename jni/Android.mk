LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    := hge
LOCAL_SRC_FILES :=  hge-camera-unit.cpp \
					hge-geometry-unit.cpp \
					hge-main.cpp \
					hge-mesh-unit.cpp \
					hge-modle-unit.cpp \
					hge-perspective-unit.cpp \
					hge-scene-unit.cpp \
					hge-shader-unit.cpp \
					hge-skybox-unit.cpp
include $(BUILD_SHARED_LIBRARY)