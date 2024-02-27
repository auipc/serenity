/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once
#include <LibWeb/Bindings/AudioDestinationNodePrototype.h>
#include <LibWeb/WebAudio/AudioNode.h>

namespace Web::WebAudio {

// https://webaudio.github.io/web-audio-api/#AudioDestinationNode
class AudioDestinationNode : public AudioNode {
    WEB_PLATFORM_OBJECT(AudioDestinationNode, AudioNode);
    JS_DECLARE_ALLOCATOR(AudioDestinationNode);

public:
    virtual ~AudioDestinationNode() override;

    unsigned long max_channel_count() const;

protected:
    explicit AudioDestinationNode(JS::Realm&, BaseAudioContext& context);

    virtual void initialize(JS::Realm&) override;
};
}
