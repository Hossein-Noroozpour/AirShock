# use this to select gcc instead of clang
NDK_TOOLCHAIN_VERSION := 4.8
# then enable c++11 extentions in source code
APP_CPPFLAGS += -std=c++11
#APP_CPPFLAGS := -std=gnu++11
APP_ABI := armeabi-v7a x86 mips
APP_OPTIM := release
#APP_STL := stlport_shared
APP_STL := c++_static
