#pragma once

#include "../EntityContext.hpp"

struct ActorEquipmentComponent {
    class SimpleContainer* mOffhandContainer;
    class SimpleContainer* mArmorContainer;
};
static_assert(sizeof(ActorEquipmentComponent) == 0x10);