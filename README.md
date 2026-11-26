# omp-3dtext

Lightweight, ergonomic Pawn wrapper for Incognito's Streamer 3D TextLabels (`STREAMER_TYPE_3D_TEXT_LABEL`) targeting open.mp and SA-MP.

## Features

- Sensible defaults for `O3D_Create` and `O3D_CreateEx`.
- Scoped helper `O3D_CreateForPlayer`.
- Type-safe getters and setters for position, draw/stream distance, interior, world, area, LOS, priority, and metadata.
- Clean attachment controls (`O3D_AttachToPlayer`, `O3D_AttachToVehicle`, `O3D_Detach`).
- Variadic format helpers (`O3D_Createf`, `O3D_CreateForPlayerf`, `O3D_UpdateTextf`).
- Guarded ID validation against invalid handles.

## Installation

Using `sampctl`:
```bash
sampctl package install RaihanPrnwd/omp-3dtext
```

Manual:
Drop `include/omp_3dtext.inc` into your server's include folder. Ensure `streamer` is included first.

```pawn
#include <open.mp>
#include <streamer>
#include <omp_3dtext>
```

## API Reference

### Creation & Deletion
- `O3D_Create(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance = 20.0, ...)`
- `O3D_CreateEx(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance = 20.0, ...)`
- `O3D_CreateForPlayer(playerid, const text[], color, Float:x, Float:y, Float:z, ...)`
- `O3D_Destroy(STREAMER_TAG_3D_TEXT_LABEL:id)`
- `O3D_IsValid(STREAMER_TAG_3D_TEXT_LABEL:id)`
- `O3D_DestroyAll(serverwide = 1)`
- `O3D_Count()`

### Formatted Text
- `O3D_Createf(Float:drawdistance, color, Float:x, Float:y, Float:z, const formatText[], ...)`
- `O3D_CreateForPlayerf(playerid, Float:drawdistance, color, Float:x, Float:y, Float:z, const formatText[], ...)`
- `O3D_UpdateTextf(STREAMER_TAG_3D_TEXT_LABEL:id, color, const formatText[], ...)`

### Text & Color
- `O3D_GetText(STREAMER_TAG_3D_TEXT_LABEL:id, dest[], maxlength = sizeof dest)`
- `O3D_SetText(STREAMER_TAG_3D_TEXT_LABEL:id, const text[])`
- `O3D_SetColor(STREAMER_TAG_3D_TEXT_LABEL:id, color)`
- `O3D_GetColor(STREAMER_TAG_3D_TEXT_LABEL:id)`
- `O3D_UpdateText(STREAMER_TAG_3D_TEXT_LABEL:id, color, const text[])`

### Position & Properties
- `O3D_GetPos(STREAMER_TAG_3D_TEXT_LABEL:id, &Float:x, &Float:y, &Float:z)`
- `O3D_SetPos(STREAMER_TAG_3D_TEXT_LABEL:id, Float:x, Float:y, Float:z)`
- `O3D_GetDrawDistance(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetDrawDistance(...)`
- `O3D_GetStreamDistance(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetStreamDistance(...)`
- `O3D_GetWorld(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetWorld(...)`
- `O3D_GetInterior(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetInterior(...)`
- `O3D_GetArea(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetArea(...)`
- `O3D_GetTestLOS(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetTestLOS(...)`
- `O3D_GetPriority(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetPriority(...)`
- `O3D_GetExtraID(STREAMER_TAG_3D_TEXT_LABEL:id)` / `O3D_SetExtraID(...)`

### Attachments & Per-Player Controls
- `O3D_AttachToPlayer(STREAMER_TAG_3D_TEXT_LABEL:id, playerid, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0)`
- `O3D_AttachToVehicle(STREAMER_TAG_3D_TEXT_LABEL:id, vehicleid, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0)`
- `O3D_Detach(STREAMER_TAG_3D_TEXT_LABEL:id)`
- `O3D_GetAttachedPlayer(STREAMER_TAG_3D_TEXT_LABEL:id)`
- `O3D_GetAttachedVehicle(STREAMER_TAG_3D_TEXT_LABEL:id)`
- `O3D_GetAttachOffsets(STREAMER_TAG_3D_TEXT_LABEL:id, &Float:offsetX, &Float:offsetY, &Float:offsetZ)`
- `O3D_ToggleForPlayer(playerid, STREAMER_TAG_3D_TEXT_LABEL:id, toggle)`
- `O3D_IsToggleForPlayer(playerid, STREAMER_TAG_3D_TEXT_LABEL:id)`
- `O3D_UpdateForPlayer(playerid, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, compensatedtime = -1, freezeplayer = 1)`

## License

MIT License. See [LICENSE](LICENSE) file.
