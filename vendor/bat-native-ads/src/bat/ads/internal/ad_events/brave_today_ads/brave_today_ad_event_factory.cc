/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/ad_events/brave_today_ads/brave_today_ad_event_factory.h"

#include "bat/ads/internal/ad_events/brave_today_ads/brave_today_ad_event_clicked.h"
#include "bat/ads/internal/ad_events/brave_today_ads/brave_today_ad_event_viewed.h"
#include "bat/ads/brave_today_ad_info.h"

namespace ads {
namespace brave_today_ads {

std::unique_ptr<AdEvent<BraveTodayAdInfo>> AdEventFactory::Build(
    const BraveTodayAdEventType event_type) {
  switch (event_type) {
    case BraveTodayAdEventType::kViewed: {
      return std::make_unique<AdEventViewed>();
    }

    case BraveTodayAdEventType::kClicked: {
      return std::make_unique<AdEventClicked>();
    }
  }
}

}  // namespace brave_today_ads
}  // namespace ads
