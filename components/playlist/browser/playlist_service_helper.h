/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_PLAYLIST_BROWSER_PLAYLIST_SERVICE_HELPER_H_
#define BRAVE_COMPONENTS_PLAYLIST_BROWSER_PLAYLIST_SERVICE_HELPER_H_

namespace base {
class Value;
}

namespace playlist {

struct PlaylistInfo;

base::Value GetValueFromPlaylistInfo(const PlaylistInfo& info);

}  // namespace playlist

#endif  // BRAVE_COMPONENTS_PLAYLIST_BROWSER_PLAYLIST_SERVICE_HELPER_H_