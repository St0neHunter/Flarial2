#include "Mob.hpp"
#include "Actor.hpp"

void Mob::setSprinting(bool state) {
    Memory::CallVFunc<256, void, bool>(this, state);
}

template <typename Component>
Component* Mob::tryGetAllah(uintptr_t addr) {
    auto a1 = **(uintptr_t***)(this + 0x8);
    auto a2 = *(uintptr_t*)(this + 0x10);

    using efunc = Component* (__thiscall*)(uintptr_t, uintptr_t*);
    auto func = reinterpret_cast<efunc>(addr);
    return func(reinterpret_cast<uintptr_t>(a1), &a2);
}

MobBodyRotationComponent* Mob::getBodyRotationComponent() {
    static  uintptr_t sig;

    if (sig == NULL) {
        sig = Memory::findSig("40 53 48 83 EC 20 48 8B DA BA 2F B8 31 03");
    }

    return tryGetAllah<MobBodyRotationComponent>(sig);

}