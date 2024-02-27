/*
 * Copyright (c) 2024, auipc
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/WebAudio/GainNode.h>

namespace Web::WebAudio {
JS_DEFINE_ALLOCATOR(GainNode);

WebIDL::ExceptionOr<JS::NonnullGCPtr<GainNode>> GainNode::construct_impl(JS::Realm& realm, JS::NonnullGCPtr<BaseAudioContext> context, GainOptions const& gain_options)
{
    return realm.heap().allocate<GainNode>(realm, realm, context, realm.heap().allocate<AudioParam>(realm, realm, gain_options.gain));
}

GainNode::GainNode(JS::Realm& realm, JS::NonnullGCPtr<BaseAudioContext> context, JS::NonnullGCPtr<AudioParam> param)
    : AudioNode(realm, context)
    , m_gain(param)
{
}

void GainNode::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    set_prototype(&Bindings::ensure_web_prototype<Bindings::GainNodePrototype>(realm, "GainNode"_fly_string));
}
}

