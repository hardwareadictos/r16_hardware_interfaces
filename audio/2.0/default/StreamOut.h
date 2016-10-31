/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HIDL_GENERATED_android_hardware_audio_V2_0_StreamOut_H_
#define HIDL_GENERATED_android_hardware_audio_V2_0_StreamOut_H_

#include <android/hardware/audio/2.0/IStreamOut.h>
#include <hidl/Status.h>

#include <hidl/MQDescriptor.h>

#include "Stream.h"

namespace android {
namespace hardware {
namespace audio {
namespace V2_0 {
namespace implementation {

using ::android::hardware::audio::common::V2_0::AudioChannelMask;
using ::android::hardware::audio::common::V2_0::AudioDevice;
using ::android::hardware::audio::common::V2_0::AudioFormat;
using ::android::hardware::audio::V2_0::AudioDrain;
using ::android::hardware::audio::V2_0::DeviceAddress;
using ::android::hardware::audio::V2_0::IStream;
using ::android::hardware::audio::V2_0::IStreamOut;
using ::android::hardware::audio::V2_0::IStreamOutCallback;
using ::android::hardware::audio::V2_0::ParameterValue;
using ::android::hardware::audio::V2_0::Result;
using ::android::hardware::audio::V2_0::TimeSpec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_vec;
using ::android::hardware::hidl_string;
using ::android::sp;

struct StreamOut : public IStreamOut {
    StreamOut(audio_hw_device_t* device, audio_stream_out_t* stream);

    // Methods from ::android::hardware::audio::V2_0::IStream follow.
    Return<uint64_t> getFrameSize()  override;
    Return<uint64_t> getFrameCount()  override;
    Return<uint64_t> getBufferSize()  override;
    Return<uint32_t> getSampleRate()  override;
    Return<void> getSupportedSampleRates(getSupportedSampleRates_cb _hidl_cb)  override;
    Return<Result> setSampleRate(uint32_t sampleRateHz)  override;
    Return<AudioChannelMask> getChannelMask()  override;
    Return<void> getSupportedChannelMasks(getSupportedChannelMasks_cb _hidl_cb)  override;
    Return<Result> setChannelMask(AudioChannelMask mask)  override;
    Return<AudioFormat> getFormat()  override;
    Return<void> getSupportedFormats(getSupportedFormats_cb _hidl_cb)  override;
    Return<Result> setFormat(AudioFormat format)  override;
    Return<void> getAudioProperties(getAudioProperties_cb _hidl_cb)  override;
    Return<Result> addEffect(uint64_t effectId)  override;
    Return<Result> removeEffect(uint64_t effectId)  override;
    Return<Result> standby()  override;
    Return<AudioDevice> getDevice()  override;
    Return<Result> setDevice(const DeviceAddress& address)  override;
    Return<Result> setConnectedState(const DeviceAddress& address, bool connected)  override;
    Return<Result> setHwAvSync(uint32_t hwAvSync)  override;
    Return<void> getParameters(
            const hidl_vec<hidl_string>& keys, getParameters_cb _hidl_cb)  override;
    Return<Result> setParameters(const hidl_vec<ParameterValue>& parameters)  override;
    Return<void> debugDump(const native_handle_t* fd)  override;

    // Methods from ::android::hardware::audio::V2_0::IStreamOut follow.
    Return<uint32_t> getLatency()  override;
    Return<Result> setVolume(float left, float right)  override;
    Return<void> write(const hidl_vec<uint8_t>& data, write_cb _hidl_cb)  override;
    Return<void> getRenderPosition(getRenderPosition_cb _hidl_cb)  override;
    Return<void> getNextWriteTimestamp(getNextWriteTimestamp_cb _hidl_cb)  override;
    Return<Result> setCallback(const sp<IStreamOutCallback>& callback)  override;
    Return<void> supportsPauseAndResume(supportsPauseAndResume_cb _hidl_cb)  override;
    Return<Result> pause()  override;
    Return<Result> resume()  override;
    Return<bool> supportsDrain()  override;
    Return<Result> drain(AudioDrain type)  override;
    Return<Result> flush()  override;
    Return<void> getPresentationPosition(getPresentationPosition_cb _hidl_cb)  override;

  private:
    audio_hw_device_t *mDevice;
    audio_stream_out_t *mStream;
    sp<Stream> mStreamCommon;
    // Do not store sp<> to avoid creating a reference loop if the entity that holds
    // onto the output stream owns or implements the callback.
    wp<IStreamOutCallback> mCallback;

    virtual ~StreamOut();

    static int asyncCallback(stream_callback_event_t event, void *param, void *cookie);
};

}  // namespace implementation
}  // namespace V2_0
}  // namespace audio
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_android_hardware_audio_V2_0_StreamOut_H_
