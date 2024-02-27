/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Bindings/AudioNodePrototype.h>
#include <LibWeb/DOM/EventTarget.h>

namespace Web::WebAudio {

struct AudioNodeOptions {
};

// https://webaudio.github.io/web-audio-api/#AudioNode
class AudioNode : public DOM::EventTarget {
    WEB_PLATFORM_OBJECT(AudioNode, DOM::EventTarget);
    JS_DECLARE_ALLOCATOR(AudioNode);

public:
    virtual ~AudioNode() override;

    JS::NonnullGCPtr<AudioNode> connect(JS::NonnullGCPtr<AudioNode>, unsigned long output = 0, unsigned long input = 0);

    JS::NonnullGCPtr<BaseAudioContext> context() { return m_context; }

protected:
    explicit AudioNode(JS::Realm&, JS::NonnullGCPtr<BaseAudioContext>);

    virtual void initialize(JS::Realm&) override;

private:
    JS::NonnullGCPtr<BaseAudioContext> m_context;
};

};

