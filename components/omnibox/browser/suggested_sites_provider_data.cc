/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/binance/browser/regions.h"
#include "brave/components/ntp_widget_utils/browser/ntp_widget_utils_region.h"
#include "brave/components/omnibox/browser/suggested_sites_provider.h"

#include "base/strings/utf_string_conversions.h"

namespace {

const char binance_host[] = "binance.com";
const char binance_host_full[] = "wwww.binance.com";
const char buy_sell_path[] = "/buy-sell-crypto/";

std::string GetLocalizedURL(const std::string& query_params, bool str_display) {
  const std::string url_locale =
      ntp_widget_utils::FindLocale(::binance::supported_locales, "en");
  const std::string path = "/" + url_locale + std::string(buy_sell_path);
  const std::string protocol =
      !str_display ? (std::string(url::kHttpsScheme) + "://") : std::string();
  const std::string host = str_display ? binance_host : binance_host_full;
  const std::string url = protocol + host + path + query_params;
  return url;
}

}  // namespace

const std::vector<SuggestedSitesMatch>&
SuggestedSitesProvider::GetSuggestedSites() {
  static const std::vector<SuggestedSitesMatch> suggested_sites = {
      {
          SuggestedSitesMatch(
              "bitcoin",
              GURL(GetLocalizedURL(
                  "?fiat=USD&crypto=BTC&ref=39346846&utm_source=brave", false)),
              GURL(GetLocalizedURL("?crypto=BTC", false)),
              base::ASCIIToUTF16(GetLocalizedURL("?crypto=BTC&ref=39346846",
                                                 true)))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "btc",
              GURL(GetLocalizedURL(
                  "?fiat=USD&crypto=BTC&ref=39346846&utm_source=brave", false)),
              GURL(GetLocalizedURL("?crypto=BTC", false)),
              base::ASCIIToUTF16(GetLocalizedURL("?crypto=BTC&ref=39346846",
                                                 true)))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "ethereum",
              GURL(GetLocalizedURL(
                  "?fiat=USD&crypto=ETH&ref=39346846&utm_source=brave", false)),
              GURL(GetLocalizedURL("?crypto=ETH", false)),
              base::ASCIIToUTF16(GetLocalizedURL("?crypto=ETH&ref=39346846",
                                                 true)))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "eth",
              GURL(GetLocalizedURL(
                  "?fiat=USD&crypto=ETH&ref=39346846&utm_source=brave", false)),
              GURL(GetLocalizedURL("?crypto=ETH", false)),
              base::ASCIIToUTF16(GetLocalizedURL("?crypto=ETH&ref=39346846",
                                                 true)))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "litecoin",
              GURL(GetLocalizedURL(
                  "?fiat=USD&crypto=LTC&ref=39346846&utm_source=brave", false)),
              GURL(GetLocalizedURL("?crypto=LTC", false)),
              base::ASCIIToUTF16(GetLocalizedURL("?crypto=LTC&ref=39346846",
                                                 true)))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "ltc",
              GURL(GetLocalizedURL(
                  "?fiat=USD&crypto=LTC&ref=39346846&utm_source=brave", false)),
              GURL(GetLocalizedURL("?crypto=LTC", false)),
              base::ASCIIToUTF16(GetLocalizedURL("?crypto=LTC&ref=39346846",
                                                 true)))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "bnb",
              GURL(GetLocalizedURL(
                  "?fiat=USD&crypto=BNB&ref=39346846&utm_source=brave", false)),
              GURL(GetLocalizedURL("?crypto=BNB", false)),
              base::ASCIIToUTF16(GetLocalizedURL("?crypto=BNB&ref=39346846",
                                                 true)))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "bitcoin",
              GURL("https://www.binance.us/en/buy-sell-crypto"
                   "?fiat=USD&crypto=BTC&ref=35089877&utm_source=brave"),
              GURL("https://www.binance.us/en/buy-sell-crypto?crypto=BTC"),
              base::ASCIIToUTF16(
                  "binance.us/en/"
                  "buy-sell-crypto?crypto=BTC&ref=35089877"))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "btc",
              GURL("https://www.binance.us/en/buy-sell-crypto"
                   "?fiat=USD&crypto=BTC&ref=35089877&utm_source=brave"),
              GURL("https://www.binance.us/en/buy-sell-crypto?crypto=BTC"),
              base::ASCIIToUTF16(
                  "binance.us/en/"
                  "buy-sell-crypto?crypto=BTC&ref=35089877"))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "ethereum",
              GURL("https://www.binance.us/en/buy-sell-crypto"
                   "?fiat=USD&crypto=ETH&ref=35089877&utm_source=brave"),
              GURL("https://www.binance.us/en/buy-sell-crypto?crypto=ETH"),
              base::ASCIIToUTF16(
                  "binance.us/en/"
                  "buy-sell-crypto?crypto=ETH&ref=35089877"))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "eth",
              GURL("https://www.binance.us/en/buy-sell-crypto"
                   "?fiat=USD&crypto=ETH&ref=35089877&utm_source=brave"),
              GURL("https://www.binance.us/en/buy-sell-crypto?crypto=ETH"),
              base::ASCIIToUTF16(
                  "binance.us/en/"
                  "buy-sell-crypto?crypto=ETH&ref=35089877"))  // NOLINT
      },
      {
          SuggestedSitesMatch(
              "bnb",
              GURL("https://www.binance.us/en/buy-sell-crypto"
                   "?fiat=USD&crypto=BNB&ref=35089877&utm_source=brave"),
              GURL("https://www.binance.us/en/buy-sell-crypto?crypto=BNB"),
              base::ASCIIToUTF16(
                  "binance.us/en/"
                  "buy-sell-crypto?crypto=BNB&ref=35089877"))  // NOLINT
      }};

  return suggested_sites;
}
