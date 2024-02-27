/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/WebAudio/AudioNode.h>

namespace Web::WebAudio {
AudioNode::AudioNode(JS::Realm& realm, JS::NonnullGCPtr<BaseAudioContext> context)
    : DOM::EventTarget(realm)
    , m_context(context)
{
}

AudioNode::~AudioNode() = default;

JS::NonnullGCPtr<AudioNode> AudioNode::connect(JS::NonnullGCPtr<AudioNode> destination_node, unsigned long output, unsigned long input)
{
    (void)output;
    (void)input;
    return destination_node;
}

void AudioNode::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    set_prototype(&Bindings::ensure_web_prototype<Bindings::AudioNodePrototype>(realm, "AudioNode"_fly_string));
}

};
