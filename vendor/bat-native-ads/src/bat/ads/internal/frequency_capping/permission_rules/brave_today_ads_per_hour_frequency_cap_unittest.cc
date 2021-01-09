/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/frequency_capping/permission_rules/brave_today_ads_per_hour_frequency_cap.h"

#include "bat/ads/internal/frequency_capping/frequency_capping_unittest_util.h"
#include "bat/ads/internal/unittest_base.h"
#include "bat/ads/internal/unittest_util.h"
#include "bat/ads/pref_names.h"

// npm run test -- brave_unit_tests --filter=BatAds*

namespace ads {

namespace {
const char kCreativeInstanceId[] = "9aea9a47-c6a0-4718-a0fa-706338bb2156";
}  // namespace

class BatAdsBraveTodayAdsPerHourFrequencyCapTest : public UnitTestBase {
 protected:
  BatAdsBraveTodayAdsPerHourFrequencyCapTest() = default;

  ~BatAdsBraveTodayAdsPerHourFrequencyCapTest() override = default;
};

TEST_F(BatAdsBraveTodayAdsPerHourFrequencyCapTest,
    AllowAdIfThereIsNoAdsHistory) {
  // Arrange
  const AdEventList ad_events;

  // Act
  NewTabPageAdsPerHourFrequencyCap frequency_cap(ad_events);
  const bool is_allowed = frequency_cap.ShouldAllow();

  // Assert
  EXPECT_TRUE(is_allowed);
}

TEST_F(BatAdsBraveTodayAdsPerHourFrequencyCapTest,
    AllowAdIfDoesNotExceedCap) {
  // Arrange
  CreativeAdInfo ad;
  ad.creative_instance_id = kCreativeInstanceId;

  const AdEventInfo ad_event = GenerateAdEvent(AdType::kBraveTodayAd, ad,
      ConfirmationType::kViewed);

  const AdEventList ad_events(kBraveTodayAdsPerHourFrequencyCap - 1, ad_event);

  // Act
  NewTabPageAdsPerHourFrequencyCap frequency_cap(ad_events);
  const bool is_allowed = frequency_cap.ShouldAllow();

  // Assert
  EXPECT_TRUE(is_allowed);
}

TEST_F(BatAdsBraveTodayAdsPerHourFrequencyCapTest,
    AllowAdIfDoesNotExceedCapAfter1Hour) {
  // Arrange
  CreativeAdInfo ad;
  ad.creative_instance_id = kCreativeInstanceId;

  const AdEventInfo ad_event = GenerateAdEvent(AdType::kBraveTodayAd, ad,
      ConfirmationType::kViewed);

  const AdEventList ad_events(kBraveTodayAdsPerHourFrequencyCap, ad_event);

  FastForwardClockBy(base::TimeDelta::FromHours(1));

  // Act
  NewTabPageAdsPerHourFrequencyCap frequency_cap(ad_events);
  const bool is_allowed = frequency_cap.ShouldAllow();

  // Assert
  EXPECT_TRUE(is_allowed);
}

TEST_F(BatAdsBraveTodayAdsPerHourFrequencyCapTest,
    DoNotAllowAdIfExceedsCapWithin1Hour) {
  // Arrange
  CreativeAdInfo ad;
  ad.creative_instance_id = kCreativeInstanceId;

  const AdEventInfo ad_event = GenerateAdEvent(AdType::kBraveTodayAd, ad,
      ConfirmationType::kViewed);

  const AdEventList ad_events(kBraveTodayAdsPerHourFrequencyCap, ad_event);

  FastForwardClockBy(base::TimeDelta::FromMinutes(59));

  // Act
  NewTabPageAdsPerHourFrequencyCap frequency_cap(ad_events);
  const bool is_allowed = frequency_cap.ShouldAllow();

  // Assert
  EXPECT_FALSE(is_allowed);
}

TEST_F(BatAdsBraveTodayAdsPerHourFrequencyCapTest,
    AdsPerHour) {
  // Arrange

  // Act

  // Assert
  EXPECT_EQ(4UL, kBraveTodayAdsPerHourFrequencyCap);
}

}  // namespace ads
