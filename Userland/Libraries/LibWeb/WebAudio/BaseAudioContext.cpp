/*
 * Copyright (c) 2023, Luke Wilde <lukew@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/HTML/EventNames.h>
#include <LibWeb/WebAudio/AudioDestinationNode.h>
#include <LibWeb/WebAudio/AudioParam.h>
#include <LibWeb/WebAudio/BaseAudioContext.h>
#include <LibWeb/WebAudio/GainNode.h>

namespace Web::WebAudio {

JS_DEFINE_ALLOCATOR(BaseAudioContext);

BaseAudioContext::BaseAudioContext(JS::Realm& realm)
    : DOM::EventTarget(realm)
    , m_destination(realm.heap().allocate<AudioDestinationNode>(realm, realm, *this))
{
}

BaseAudioContext::~BaseAudioContext() = default;

void BaseAudioContext::initialize(JS::Realm& realm)
{
    Base::initialize(realm);
    set_prototype(&Bindings::ensure_web_prototype<Bindings::BaseAudioContextPrototype>(realm, "BaseAudioContext"_fly_string));
}

JS::NonnullGCPtr<GainNode> BaseAudioContext::create_gain()
{
    return realm().heap().allocate<GainNode>(realm(), realm(), *this, realm().heap().allocate<AudioParam>(realm(), realm(), 1.0f));
}

void BaseAudioContext::set_onstatechange(WebIDL::CallbackType* event_handler)
{
    set_event_handler_attribute(HTML::EventNames::statechange, event_handler);
}

WebIDL::CallbackType* BaseAudioContext::onstatechange()
{
    return event_handler_attribute(HTML::EventNames::statechange);
}

}

