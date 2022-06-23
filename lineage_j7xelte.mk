#
# Copyright (C) 2022 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/product_launched_with_m.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from j7xelte device
$(call inherit-product, device/samsung/j7xelte/device.mk)

# Inherit some common lineage stuff.
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := j7xelte
PRODUCT_NAME := lineage_j7xelte
PRODUCT_BRAND := samsung
PRODUCT_MODEL := Galaxy J7 2016
PRODUCT_MANUFACTURER := samsung

TARGET_VENDOR := samsung
PRODUCT_GMS_CLIENTID_BASE := android-samsung
