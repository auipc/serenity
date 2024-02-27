/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/WebAudio/AudioParam.h>

namespace Web::WebAudio {
JS_DEFINE_ALLOCATOR(AudioParam);

AudioParam::AudioParam(JS::Realm& realm, float value)
    : Bindings::PlatformObject(realm)
    , m_value(value)
{
}

void AudioParam::set_value(float value)
{
    m_value = value;
}

// FIXME: Actually respect startTime
JS::NonnullGCPtr<AudioParam> AudioParam::set_value_at_time(float value, double startTime)
{
    (void)startTime;
    m_value = value;
    return *this;
}

void AudioParam::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    set_prototype(&Bindings::ensure_web_prototype<Bindings::AudioParamPrototype>(realm, "AudioParam"_fly_string));
}
}

