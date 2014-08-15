LOCAL_PATH := $(call my-dir)
#Beginning of LibPNG
include $(CLEAR_VARS)
LOCAL_MODULE    := libpng
LOCAL_SRC_FILES := dependencies/LibPNG/StaticLib/$(TARGET_ARCH_ABI)/libpng.a
include $(PREBUILT_STATIC_LIBRARY)
#End of LibPNG
include $(CLEAR_VARS)
LOCAL_STATIC_LIBRARIES := png
LOCAL_C_INCLUDES := $(LOCAL_PATH)/dependencies/LibPNG/Source
LOCAL_LDLIBS := -lGLESv2
LOCAL_CPPFLAGS  := -std=c++11
LOCAL_MODULE    := hge
LOCAL_SRC_FILES :=  hge-camera-unit.cpp \
					hge-geometry-unit.cpp \
					hge-main.cpp \
					hge-mesh-unit.cpp \
					hge-model-unit.cpp \
					hge-perspective-unit.cpp \
					hge-scene-unit.cpp \
					hge-shader-engine.cpp \
					hge-shader-unit.cpp \
					hge-skybox-shader-unit.cpp \
					hge-skybox-unit.cpp \
					hge-sun-shader.cpp \
					hge-terrain-sun-shader.cpp \
					hge-terrain-unit.cpp \
					hge-texture-unit.cpp \
					hge-white-shader.cpp
include $(BUILD_SHARED_LIBRARY)
