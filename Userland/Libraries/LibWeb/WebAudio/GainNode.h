/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once
#include <LibWeb/Bindings/GainNodePrototype.h>
#include <LibWeb/WebAudio/AudioNode.h>
#include <LibWeb/WebAudio/AudioParam.h>

namespace Web::WebAudio {

struct GainOptions : public AudioNodeOptions {
    float gain = 1.0f;
};

class GainNode : public AudioNode {
    WEB_PLATFORM_OBJECT(GainNode, AudioNode);
    JS_DECLARE_ALLOCATOR(GainNode);

public:
    static WebIDL::ExceptionOr<JS::NonnullGCPtr<GainNode>> construct_impl(JS::Realm&, JS::NonnullGCPtr<BaseAudioContext>, GainOptions const& gain_options = {});

    JS::NonnullGCPtr<AudioParam> gain() const
    {
        return m_gain;
    }

protected:
    explicit GainNode(JS::Realm&, JS::NonnullGCPtr<BaseAudioContext>, JS::NonnullGCPtr<AudioParam>);

    virtual void initialize(JS::Realm&) override;

private:
    JS::NonnullGCPtr<AudioParam> m_gain;
};
}

