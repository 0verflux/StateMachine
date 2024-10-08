#include <Arduino.h>
#include "FooContext.hpp"

static void enter(FooContext* const ctx)
{

}

static void update(FooContext* const ctx)
{
    ctx->current = millis();
    
    if (digitalRead(4) == LOW)
        ctx->hsm->transitionTo(FooContext::sOff);
}

HState<FooContext> FooContext::sOnGroup(nullptr, enter, update, nullptr);