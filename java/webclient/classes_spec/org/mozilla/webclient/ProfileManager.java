/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * 
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is RaptorCanvas.
 *
 * The Initial Developer of the Original Code is Kirk Baker and
 * Ian Wilkinson. Portions created by Kirk Baker and Ian Wilkinson are
 * Copyright (C) 1999 Kirk Baker and Ian Wilkinson. All
 * Rights Reserved.
 *
 * Contributor(s):  Ashu Kulkarni <ashuk@eng.sun.com>
 */

package org.mozilla.webclient;

public interface ProfileManager
{
public int GetProfileCount();

public String [] GetProfileList(int [] length);

public boolean ProfileExists(String profileName);

public String GetCurrentProfile();

public void SetCurrentProfile(String profileName);

public void CreateNewProfile(String profileName, String nativeProfileDir, String langcode, boolean useExistingDir);

public void RenameProfile(String currName, String newName);

public void DeleteProfile(String profileName, boolean canDeleteFiles);

public void CloneProfile(String currName);
}
