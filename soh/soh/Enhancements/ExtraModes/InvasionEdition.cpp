// Ganondorf: Invasion, the multiplayer edition of "Play as Ganondorf".
//
// The online Invasion mode (up to six Links against one Ganondorf, over Anchor) with Ganondorf's full moveset and
// fixes, plus these single-player extras: Hyrule Castle's interior (its drawbridge lowers for him), the guards' fear of
// him, the song player, his bodyguards (recruited from the captain in the Gerudo Fortress), and his title screen and
// logo. The rest (the Gerudo start and intro, killing people) and the game's other extra modes (Rupee Dash, Shadow Tag,
// traps, the enemy randomizer, ...) are off, and out of the menu. Invasion mode is on.

#include <ship/Context.h>
#include <ship/window/Window.h>
#include <libultraship/bridge/consolevariablebridge.h>

#include "soh/ShipInit.hpp"
#include "soh/cvar_prefixes.h"

static void ApplyInvasionEdition() {
    static const char* sOff[] = {
        CVAR_ENHANCEMENT("PlayAsGanondorf.GerudoStart"), CVAR_ENHANCEMENT("PlayAsGanondorf.GerudoIntro"),
        CVAR_ENHANCEMENT("PlayAsGanondorf.KillNpcs"),    CVAR_ENHANCEMENT("RupeeDash"),
        CVAR_ENHANCEMENT("ShadowTag"),                   CVAR_ENHANCEMENT("HurtContainer"),
        CVAR_ENHANCEMENT("ExtraTraps.Enabled"),          CVAR_ENHANCEMENT("RandomizedEnemies"),
        CVAR_ENHANCEMENT("RandomizedEnemySizes"),        CVAR_ENHANCEMENT("MirroredWorldMode"),
        CVAR_ENHANCEMENT("BounceOffWalls"),              CVAR_ENHANCEMENT("IvanCoopModeEnabled"),
        CVAR_ENHANCEMENT("DogFollowsEverywhere"),
    };
    // (on: earlier versions of this edition turned them off)
    static const char* sOn[] = {
        CVAR_ENHANCEMENT("PlayAsGanondorf.CastleInterior"), CVAR_ENHANCEMENT("PlayAsGanondorf.GuardsFear"),
        CVAR_ENHANCEMENT("PlayAsGanondorf.Songs.Enabled"),
        CVAR_ENHANCEMENT("PlayAsGanondorf.TitleScreen"),    CVAR_ENHANCEMENT("PlayAsGanondorf.TitleLogo"),
    };

    for (const char* cvar : sOff) {
        if (CVarGetInteger(cvar, 0) != 0) {
            CVarSetInteger(cvar, 0);
        }
    }
    for (const char* cvar : sOn) {
        CVarSetInteger(cvar, 1);
    }
    // His bodyguards are recruited in play (the captain in the Gerudo Fortress calls them to his side, or sends them
    // back), so they start off and are left as the player sets them. (Once only: an earlier version turned them on.)
    if (!CVarGetInteger(CVAR_ENHANCEMENT("PlayAsGanondorf.Invasion.BodyguardsReset"), 0)) {
        CVarSetInteger(CVAR_ENHANCEMENT("PlayAsGanondorf.Bodyguards"), 0);
        CVarSetInteger(CVAR_ENHANCEMENT("PlayAsGanondorf.Invasion.BodyguardsReset"), 1);
    }
    CVarSetInteger(CVAR_ENHANCEMENT("PlayAsGanondorf.Invasion.Enabled"), 1);
    Ship::Context::GetRawInstance()->GetWindow()->GetGui()->SaveConsoleVariablesNextFrame();
}

static RegisterShipInitFunc initFunc(ApplyInvasionEdition, {});
