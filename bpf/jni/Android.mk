LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := bpf_test
LOCAL_SRC_FILES := bpf_test.c
LOCAL_C_INCLUDES += /home/hacksang/Documents/kernel/bpf/jni/mylib/
LOCAL_C_INCLUDES += /home/hacksang/Documents/kernel/private/msm-google/include/linux/bpf.h

include $(BUILD_EXECUTABLE)
