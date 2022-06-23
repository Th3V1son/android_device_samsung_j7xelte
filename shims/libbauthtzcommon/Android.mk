#
# Copyright (C) 2022 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libbauthtzcommon.c
LOCAL_SHARED_LIBRARIES := liblog libui libutils
LOCAL_MODULE := libbauthtzcommon_shim
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_VENDOR_MODULE := true

include $(BUILD_SHARED_LIBRARY)
