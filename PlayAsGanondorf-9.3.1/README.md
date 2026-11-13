# Play as Ganondorf: the first version (archive)

Copyright © 2026 Grimsfrost. All rights reserved. See `AI-POLICY.md` in the repository root.

> **This folder is out of date.** It holds the very first version of Play as Ganondorf, made as a patch for Ship of
> Harkinian 9.3.1 ("Dewey Bravo"). It's kept for history only.
>
> - **To play**, download the latest build from this repository's
>   [Releases](https://github.com/bluearchive249-dev/ganondorf-invasion-public/releases): extract it, add your own
>   ROM, and play. No building needed.
> - **For the current controls and features**, see the [main README](../README.md).
> - **For the current source**, see the repository itself. Everything in this folder has long since been replaced
>   there.

## What this first version was

It replaced Link with Ganondorf from the Ganon's Tower fight, with his boss moveset instead of Link's. It used the
boss actor itself (`BossGanon`) in a new player-controlled mode, so the model, animations, cloth cape, light balls,
Big Magic, lightning and shockwave were all the real ones from the fight.

It had:
- light balls on B, with **Big Magic** when B was held through the charge;
- the cape block on R;
- the floor pound on R + B;
- attacks that counted as every damage type in the game, so they broke rocks, hit switches and opened bombable walls.

## What has changed since

The current version goes far beyond this first one. Among other things it now has:
- **Stances:** the insta-kill dark aura and the trident, with its combo, dash thrust, spin, throw and secret
  fireball ring.
- **Levitation** on L and Z, a sprint on A, Z-targeting on R3, and first person on C-Up.
- **The throat grab and slam**, the Triforce taunt, the Suavemente dance, the strut walk and his organ.
- **Transforming into Ganon.**
- **Invasion mode:** online play with Ganondorf against up to six Links, with the **Dark Arts**, curses, Resolve and
  a shared world.
- **His own dialogue** with every NPC, the Gerudo guard captain and his bodyguards.
- **Builds for Windows and Linux** in Releases, with the `mods` folder included.

## What's in this folder

- `PlayAsGanondorf.patch`: the first version as a single commit, for SoH `develop` at 2827fc2a0.
- `files/`: the same changes as complete files at their repo paths.

They're kept as they were and aren't maintained. They won't apply to the current Ship of Harkinian.
