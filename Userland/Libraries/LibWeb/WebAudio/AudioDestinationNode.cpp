/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/WebAudio/AudioDestinationNode.h>

namespace Web::WebAudio {
JS_DEFINE_ALLOCATOR(AudioDestinationNode);

AudioDestinationNode::AudioDestinationNode(JS::Realm& realm, BaseAudioContext& context)
    : AudioNode(realm, context)
{
}

AudioDestinationNode::~AudioDestinationNode() = default;

// FIXME: This shouldn't be hardcoded. Instead, it should be sourced from the hardware.
unsigned long AudioDestinationNode::max_channel_count() const
{
    return 2;
}

void AudioDestinationNode::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    set_prototype(&Bindings::ensure_web_prototype<Bindings::AudioDestinationNodePrototype>(realm, "AudioDestinationNode"_fly_string));
}
}
