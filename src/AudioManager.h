#pragma once
/*
 *      Copyright (C) 2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "JNIBase.h"

#include "AudioDeviceInfo.h"
#include "AudioFocusRequest.h"

class CJNIAudioManagerAudioFocusChangeListener : virtual public CJNIBase
{
public:
  virtual void onAudioFocusChange(int focusChange) = 0;

};

class CJNIAudioManager : public CJNIBase
{
public:
  CJNIAudioManager(const jni::jhobject &object) : CJNIBase(object) {};
  ~CJNIAudioManager() {};

  // Note removal of streamType param.
  int  getStreamMaxVolume();
  int  getStreamVolume();
  void setStreamVolume(int index = 0, int flags = 0);

  int requestAudioFocus(const jni::CJNIAudioFocusRequestClass& request);
  int requestAudioFocus(const CJNIAudioManagerAudioFocusChangeListener& listener, int streamType, int durationHint);
  int abandonAudioFocusRequest(const jni::CJNIAudioFocusRequestClass& request);
  int abandonAudioFocus (const CJNIAudioManagerAudioFocusChangeListener& listener);
  bool isBluetoothA2dpOn();
  bool isWiredHeadsetOn();

  CJNIAudioDeviceInfos getDevices(int flags);

  static void PopulateStaticFields();
  static int STREAM_MUSIC;

  static int AUDIOFOCUS_GAIN;
  static int AUDIOFOCUS_GAIN_TRANSIENT;
  static int AUDIOFOCUS_GAIN_TRANSIENT_EXCLUSIVE;
  static int AUDIOFOCUS_GAIN_TRANSIENT_MAY_DUCK;
  static int AUDIOFOCUS_LOSS;
  static int AUDIOFOCUS_LOSS_TRANSIENT;
  static int AUDIOFOCUS_LOSS_TRANSIENT_CAN_DUCK;
  static int AUDIOFOCUS_REQUEST_GRANTED;
  static int AUDIOFOCUS_REQUEST_FAILED;

  static int GET_DEVICES_ALL;
  static int GET_DEVICES_INPUTS;
  static int GET_DEVICES_OUTPUTS;

  static int AUDIO_SESSION_ID_GENERATE;

private:
  CJNIAudioManager();
};

