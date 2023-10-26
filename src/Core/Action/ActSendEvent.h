#ifndef ___ACTSENDEVENT_H___
#define ___ACTSENDEVENT_H___

#include "Core/Object.h"
#include "EmitGase/AtomBox.h"
#include "Core/Action/Action.h"
#include "Core/Event/Event.h"

class ActSendEvent : public Action {
public:
    ActSendEvent(Event* event, Object* object) 
                : event_(event)
                , object_(object) {}

    virtual void operator()() override;

private:
    Object* object_;

public:
    std::shared_ptr<Event> event_;
};

#endif // ___ACTSENDEVENT_H___