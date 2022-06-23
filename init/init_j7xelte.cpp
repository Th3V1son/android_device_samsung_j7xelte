/*

    Copyright (C) 2022 The LineageOS Project

    SPDX-License-Identifier: Apache-2.0

 */

#include <stdlib.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <sys/_system_properties.h>

#include "vendor_init.h"

using ::android::base::GetProperty;
using ::android::base::SetProperty;

void property_override(const std::string &name, const std::string &value) {
    size_t valuelen = value.size();
    prop_info *pi = (prop_info *)__system_property_find(name.c_str());
    if (pi != nullptr) {
        __system_property_update(pi, value.c_str(), valuelen);
    } else {
        int rc = __system_property_add(name.c_str(), name.size(), value.c_str(), valuelen);
        if (rc < 0) {
            LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                       << "__system_property_add failed";
        }
    }
}

void property_override_dual(char const system_prop[], char const vendor_prop[],
                            char const value[]) {
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void property_override_quad(const std::string &boot_prop, const std::string &product_prop,
                            const std::string &system_prop, const std::string &vendor_prop,
                            const std::string &value) {
    property_override(boot_prop, value);
    property_override(product_prop, value);
    property_override(system_prop, value);
    property_override(vendor_prop, value);
}

void init_dsds() {
    SetProperty("ro.vendor.multisim.set_audio_params", "true");
    SetProperty("ro.vendor.multisim.simslotcount", "2");
    SetProperty("persist.radio.multisim.config", "dsds");
}

void vendor_load_properties() {
    // Init a dummy BT MAC address, will be overwritten later
    SetProperty("ro.boot.btmacaddr", "00:00:00:00:00:00");

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("J710FX") == 0) {
        /* SM-J710F */
        property_override_quad("ro.product.model", "ro.product.odm.model",
                               "ro.product.system.model", "ro.product.vendor.model", "SM-J710F");
        property_override_quad("ro.product.name", "ro.product.odm.name", "ro.product.system.name",
                               "ro.product.vendor.name", "j7xeltexx");

        init_dsds();

    } else if (bootloader.find("J710FN") == 0) {
        /* SM-J710FN */
        property_override_quad("ro.product.model", "ro.product.odm.model",
                               "ro.product.system.model", "ro.product.vendor.model", "SM-J710FN");
        property_override_quad("ro.product.name", "ro.product.odm.name", "ro.product.system.name",
                               "ro.product.vendor.name", "j7xelte");

        init_dsds();

    } else if (bootloader.find("J710K") == 0) {
        /* SM-J710K */
        property_override_quad("ro.product.model", "ro.product.odm.model",
                               "ro.product.system.model", "ro.product.vendor.model", "SM-J710K");
        property_override_quad("ro.product.name", "ro.product.odm.name", "ro.product.system.name",
                               "ro.product.vendor.name", "j7xeltekk");

        init_dsds();

    } else if (bootloader.find("J710GN") == 0) {
        /* SM-J710GN */
        property_override_quad("ro.product.model", "ro.product.odm.model",
                               "ro.product.system.model", "ro.product.vendor.model", "SM-J710GN");
        property_override_quad("ro.product.name", "ro.product.odm.name", "ro.product.system.name",
                               "ro.product.vendor.name", "j7xeltedx");

        init_dsds();

    } else if (bootloader.find("J710MN") == 0) {
        /* SM-J710MN */
        property_override_quad("ro.product.model", "ro.product.odm.model",
                               "ro.product.system.model", "ro.product.vendor.model", "SM-J710MN");
        property_override_quad("ro.product.name", "ro.product.odm.name", "ro.product.system.name",
                               "ro.product.vendor.name", "j7xelteub");

        init_dsds();
    }

    /* Common properties*/
    property_override("ro.build.description",
                      "samsung/j7xeltexx/j7xelte:8.1.0/M1AJQ/J710FXXU6CSG2:user/release-keys");
    property_override_quad("ro.product.device", "ro.product.odm.device",
                           "ro.product.system.device", "ro.product.vendor.device", "j7xelte");

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id %s setting build properties for %s device\n"
               << bootloader.c_str() << device.c_str();
}
