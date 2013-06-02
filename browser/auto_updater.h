// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_AUTO_UPDATER_H_
#define ATOM_BROWSER_AUTO_UPDATER_H_

#include "base/basictypes.h"

namespace auto_updater {

class AutoUpdaterDelegate;

class AutoUpdater {
 public:
  // Gets/Sets the delegate.
  static AutoUpdaterDelegate* GetDelegate();
  static void SetDelegate(AutoUpdaterDelegate* delegate);

  static void Init();

  static void SetAutomaticallyChecksForUpdates(bool yes);
  static void SetAutomaticallyDownloadsUpdates(bool yes);
  static void CheckForUpdatesInBackground();

 private:
  static AutoUpdaterDelegate* delegate_;

  DISALLOW_IMPLICIT_CONSTRUCTORS(AutoUpdater);
};

}  // namespace auto_updater

#endif  // ATOM_BROWSER_AUTO_UPDATER_H_
