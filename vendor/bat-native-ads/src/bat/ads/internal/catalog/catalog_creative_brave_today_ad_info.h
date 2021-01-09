/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_CATALOG_CATALOG_CREATIVE_BRAVE_TODAY_AD_INFO_H_
#define BAT_ADS_INTERNAL_CATALOG_CATALOG_CREATIVE_BRAVE_TODAY_AD_INFO_H_

#include <vector>

#include "bat/ads/internal/catalog/catalog_creative_info.h"
#include "bat/ads/internal/catalog/catalog_brave_today_ad_payload_info.h"

namespace ads {

struct CatalogCreativeBraveTodayAdInfo : CatalogCreativeInfo {
  CatalogCreativeBraveTodayAdInfo();
  CatalogCreativeBraveTodayAdInfo(
      const CatalogCreativeBraveTodayAdInfo& info);
  ~CatalogCreativeBraveTodayAdInfo();

  bool operator==(
      const CatalogCreativeBraveTodayAdInfo& rhs) const;
  bool operator!=(
      const CatalogCreativeBraveTodayAdInfo& rhs) const;

  CatalogBraveTodayAdPayloadInfo payload;
};

using CatalogCreativeBraveTodayAdList =
    std::vector<CatalogCreativeBraveTodayAdInfo>;

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_CATALOG_CATALOG_CREATIVE_BRAVE_TODAY_AD_INFO_H_
