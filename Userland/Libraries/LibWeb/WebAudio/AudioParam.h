/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once
#include <LibWeb/Bindings/AudioParamPrototype.h>
#include <LibWeb/Bindings/PlatformObject.h>

namespace Web::WebAudio {
class AudioParam : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(AudioParam, Bindings::PlatformObject);
    JS_DECLARE_ALLOCATOR(AudioParam);

public:
    explicit AudioParam(JS::Realm&, float);
    void set_value(float value);
    float value() const
    {
        return m_value;
    }
    JS::NonnullGCPtr<AudioParam> set_value_at_time(float value, double startTime);

protected:
    virtual void initialize(JS::Realm&) override;

private:
    float m_value;
};
}

