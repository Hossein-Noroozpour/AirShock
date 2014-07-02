LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
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
					hge-vertex-data.cpp \
					hge-white-shader.cpp
include $(BUILD_SHARED_LIBRARY)
