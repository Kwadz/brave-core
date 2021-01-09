/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/catalog/catalog_brave_today_ad_payload_info.h"

namespace ads {

CatalogBraveTodayAdPayloadInfo::CatalogBraveTodayAdPayloadInfo() = default;

CatalogBraveTodayAdPayloadInfo::CatalogBraveTodayAdPayloadInfo(
    const CatalogBraveTodayAdPayloadInfo& info) = default;

CatalogBraveTodayAdPayloadInfo::~CatalogBraveTodayAdPayloadInfo() = default;

bool CatalogBraveTodayAdPayloadInfo::operator==(
    const CatalogBraveTodayAdPayloadInfo& rhs) const {
  return company_name == rhs.company_name &&
      alt == rhs.alt &&
      target_url == rhs.target_url;
}

bool CatalogBraveTodayAdPayloadInfo::operator!=(
    const CatalogBraveTodayAdPayloadInfo& rhs) const {
  return !(*this == rhs);
}

}  // namespace ads
