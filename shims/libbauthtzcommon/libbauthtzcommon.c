/*

    Copyright (C) 2022 The LineageOS Project

    SPDX-License-Identifier: Apache-2.0

*/

#define LOG_TAG "libbauthtzcommon_shim"
#define LOG_NDEBUG 0

#include <cutils/log.h>

int BAuth_Hat_OP(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    ALOGW("SHIM: hijacking %s!", __func__);

    /*
     * This function is supposed to pass the hardware authentication token
     * (HAT) to the mobicore trustlet.
     */

    return 0;
}

