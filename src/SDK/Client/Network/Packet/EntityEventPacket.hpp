#include <cstdint>
#include "Packet.hpp"

enum class ActorEvent : unsigned char {
    None                     = 0x0,
    Jump                     = 0x1,
    Hurt                     = 0x2,
    Death                    = 0x3,
    StartAttacking           = 0x4,
    StopAttacking            = 0x5,
    TamingFailed             = 0x6,
    TamingSucceeded          = 0x7,
    ShakeWetness             = 0x8,
    EatGrass                 = 0xA,
    FishhookBubble           = 0xB,
    FishhookFishpos          = 0xC,
    FishhookHooktime         = 0xD,
    FishhookTease            = 0xE,
    SquidFleeing             = 0xF,
    ZombieConverting         = 0x10,
    PlayAmbient              = 0x11,
    SpawnAlive               = 0x12,
    StartOfferFlower         = 0x13,
    StopOfferFlower          = 0x14,
    LoveHearts               = 0x15,
    VillagerAngry            = 0x16,
    VillagerHappy            = 0x17,
    WitchHatMagic            = 0x18,
    FireworksExplode         = 0x19,
    InLoveHearts             = 0x1A,
    SilverfishMergeAnim      = 0x1B,
    GuardianAttackSound      = 0x1C,
    DrinkPotion              = 0x1D,
    ThrowPotion              = 0x1E,
    PrimeTntcart             = 0x1F,
    PrimeCreeper             = 0x20,
    AirSupply                = 0x21,
    AddPlayerLevels          = 0x22,
    GuardianMiningFatigue    = 0x23,
    AgentSwingArm            = 0x24,
    DragonStartDeathAnim     = 0x25,
    GroundDust               = 0x26,
    Shake                    = 0x27,
    Feed                     = 0x39,
    BabyEat                  = 0x3C,
    InstantDeath             = 0x3D,
    NotifyTrade              = 0x3E,
    LeashDestroyed           = 0x3F,
    CaravanUpdated           = 0x40,
    TalismanActivate         = 0x41,
    UpdateStructureFeature   = 0x42,
    PlayerSpawnedMob         = 0x43,
    Puke                     = 0x44,
    UpdateStackSize          = 0x45,
    StartSwimming            = 0x46,
    BalloonPop               = 0x47,
    TreasureHunt             = 0x48,
    SummonAgent              = 0x49,
    FinishedChargingCrossbow = 0x4A,
    LandedOnGround           = 0x4B,
    ActorGrowUp              = 0x4C,
    VibrationDetected        = 0x4D,
    DrinkMilk                = 0x4E,
};

class EntityEventPacket : public Packet {
public:
    int64_t RuntimeID;
    ActorEvent EventID;
    int Data;

    EntityEventPacket() = default;
};