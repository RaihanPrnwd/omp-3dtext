#if defined _omp_3dtext_included
	#endinput
#endif
#define _omp_3dtext_included

/**
 * ============================================================================
 * omp_3dtext - Modern, Ergonomic Dynamic 3D TextLabel Wrapper for open.mp & SA-MP
 * Built on Incognito's Streamer Plugin
 *
 * Maintainer: RaihanPrnwd
 * Repository: https://github.com/RaihanPrnwd/omp-3dtext
 * License: MIT
 * ============================================================================
 */

#if !defined _streamer_included
	#tryinclude <streamer>
	#if !defined _streamer_included
		#error [omp_3dtext] Please include <streamer> before <omp_3dtext>.
	#endif
#endif

// ----------------------------------------------------------------------------
// Constants & Configuration
// ----------------------------------------------------------------------------

#if !defined INVALID_PLAYER_ID
	#define INVALID_PLAYER_ID (0xFFFF)
#endif

#if !defined INVALID_VEHICLE_ID
	#define INVALID_VEHICLE_ID (0xFFFF)
#endif

#if !defined MAX_O3D_TEXT_LENGTH
	#define MAX_O3D_TEXT_LENGTH (1024)
#endif

const O3D_BUFFER_SIZE = MAX_O3D_TEXT_LENGTH;

// ----------------------------------------------------------------------------
// Core Creation & Destruction Wrappers
// ----------------------------------------------------------------------------

/// <summary>Creates a dynamic 3D text label with streamlined defaults.</summary>
/// <param name="text">The initial display text.</param>
/// <param name="color">RGBA or ARGB color integer.</param>
/// <param name="x">World X position.</param>
/// <param name="y">World Y position.</param>
/// <param name="z">World Z position.</param>
/// <param name="drawdistance">Visibility distance for rendering text (default: 20.0).</param>
/// <param name="attachedplayer">Player ID to attach to, or INVALID_PLAYER_ID (default: INVALID_PLAYER_ID).</param>
/// <param name="attachedvehicle">Vehicle ID to attach to, or INVALID_VEHICLE_ID (default: INVALID_VEHICLE_ID).</param>
/// <param name="testlos">1 to test line-of-sight against world geometry, 0 otherwise (default: 1).</param>
/// <param name="worldid">Virtual world ID (-1 for all, default: -1).</param>
/// <param name="interiorid">Interior ID (-1 for all, default: -1).</param>
/// <param name="playerid">Player ID (-1 for all, default: -1).</param>
/// <param name="streamdistance">Streaming distance radius (default: STREAMER_3D_TEXT_LABEL_SD).</param>
/// <param name="areaid">Streamer area ID boundary, or STREAMER_TAG_AREA:-1 (default: STREAMER_TAG_AREA:-1).</param>
/// <param name="priority">Streamer processing priority (default: 0).</param>
/// <returns>STREAMER_TAG_3D_TEXT_LABEL ID on success, or STREAMER_TAG_3D_TEXT_LABEL:0 on failure.</returns>
stock STREAMER_TAG_3D_TEXT_LABEL:O3D_Create(
	const text[],
	color,
	Float:x,
	Float:y,
	Float:z,
	Float:drawdistance = 20.0,
	attachedplayer = INVALID_PLAYER_ID,
	attachedvehicle = INVALID_VEHICLE_ID,
	testlos = 1,
	worldid = -1,
	interiorid = -1,
	playerid = -1,
	Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD,
	STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1,
	priority = 0
)
{
	return CreateDynamic3DTextLabel(
		text,
		color,
		x,
		y,
		z,
		drawdistance,
		attachedplayer,
		attachedvehicle,
		testlos,
		worldid,
		interiorid,
		playerid,
		streamdistance,
		areaid,
		priority
	);
}

/// <summary>Creates an extended dynamic 3D text label across multiple worlds, interiors, or players.</summary>
/// <returns>STREAMER_TAG_3D_TEXT_LABEL ID.</returns>
stock STREAMER_TAG_3D_TEXT_LABEL:O3D_CreateEx(
	const text[],
	color,
	Float:x,
	Float:y,
	Float:z,
	Float:drawdistance = 20.0,
	attachedplayer = INVALID_PLAYER_ID,
	attachedvehicle = INVALID_VEHICLE_ID,
	testlos = 1,
	Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD,
	const worlds[] = { -1 },
	const interiors[] = { -1 },
	const players[] = { -1 },
	const STREAMER_TAG_AREA:areas[] = { STREAMER_TAG_AREA:-1 },
	priority = 0,
	maxworlds = sizeof worlds,
	maxinteriors = sizeof interiors,
	maxplayers = sizeof players,
	maxareas = sizeof areas
)
{
	return CreateDynamic3DTextLabelEx(
		text,
		color,
		x,
		y,
		z,
		drawdistance,
		attachedplayer,
		attachedvehicle,
		testlos,
		streamdistance,
		worlds,
		interiors,
		players,
		areas,
		priority,
		maxworlds,
		maxinteriors,
		maxplayers,
		maxareas
	);
}

/// <summary>Creates a dynamic 3D text label visible strictly to a single player.</summary>
/// <param name="playerid">Target player ID.</param>
/// <param name="text">The display text.</param>
/// <param name="color">RGBA or ARGB color integer.</param>
/// <param name="x">World X position.</param>
/// <param name="y">World Y position.</param>
/// <param name="z">World Z position.</param>
/// <param name="drawdistance">Visibility distance (default: 20.0).</param>
/// <param name="attachedplayer">Player ID to attach to (default: INVALID_PLAYER_ID).</param>
/// <param name="attachedvehicle">Vehicle ID to attach to (default: INVALID_VEHICLE_ID).</param>
/// <param name="testlos">1 for line-of-sight test, 0 otherwise (default: 1).</param>
/// <param name="worldid">Virtual world ID (-1 for all, default: -1).</param>
/// <param name="interiorid">Interior ID (-1 for all, default: -1).</param>
/// <param name="streamdistance">Streaming distance radius (default: STREAMER_3D_TEXT_LABEL_SD).</param>
/// <param name="areaid">Streamer area ID boundary (default: STREAMER_TAG_AREA:-1).</param>
/// <param name="priority">Streamer priority (default: 0).</param>
/// <returns>STREAMER_TAG_3D_TEXT_LABEL ID.</returns>
stock STREAMER_TAG_3D_TEXT_LABEL:O3D_CreateForPlayer(
	playerid,
	const text[],
	color,
	Float:x,
	Float:y,
	Float:z,
	Float:drawdistance = 20.0,
	attachedplayer = INVALID_PLAYER_ID,
	attachedvehicle = INVALID_VEHICLE_ID,
	testlos = 1,
	worldid = -1,
	interiorid = -1,
	Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD,
	STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1,
	priority = 0
)
{
	return CreateDynamic3DTextLabel(
		text,
		color,
		x,
		y,
		z,
		drawdistance,
		attachedplayer,
		attachedvehicle,
		testlos,
		worldid,
		interiorid,
		playerid,
		streamdistance,
		areaid,
		priority
	);
}

/// <summary>Destroys a dynamic 3D text label safely.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <returns>1 on success, 0 if label ID is invalid or destruction failed.</returns>
stock O3D_Destroy(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return DestroyDynamic3DTextLabel(id);
}

/// <summary>Checks whether a dynamic 3D text label ID is valid.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <returns>1 if valid, 0 otherwise.</returns>
stock O3D_IsValid(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	return IsValidDynamic3DTextLabel(id);
}

/// <summary>Destroys all dynamic 3D text labels created in the streamer.</summary>
/// <param name="serverwide">1 to destroy serverwide, 0 otherwise (default: 1).</param>
/// <returns>1 on success, 0 on failure.</returns>
stock O3D_DestroyAll(serverwide = 1)
{
	#if defined DestroyAllDynamic3DTextLabels
		if (serverwide)
		{
			return DestroyAllDynamic3DTextLabels();
		}
	#endif
	return Streamer_DestroyAllItems(STREAMER_TYPE_3D_TEXT_LABEL, serverwide);
}

/// <summary>Returns the total number of dynamic 3D text labels registered in the streamer.</summary>
/// <returns>Count of dynamic 3D text labels.</returns>
stock O3D_Count()
{
	#if defined CountDynamic3DTextLabels
		return CountDynamic3DTextLabels();
	#else
		return Streamer_GetItemInternalData(STREAMER_TYPE_3D_TEXT_LABEL);
	#endif
}

// ----------------------------------------------------------------------------
// Text & Color Manipulation
// ----------------------------------------------------------------------------

/// <summary>Retrieves the text of a dynamic 3D text label.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="dest">Output string destination array.</param>
/// <param name="maxlength">Maximum buffer capacity (default: sizeof dest).</param>
/// <returns>1 on success, 0 on invalid ID.</returns>
stock O3D_GetText(STREAMER_TAG_3D_TEXT_LABEL:id, dest[], maxlength = sizeof dest)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		dest[0] = '\0';
		return 0;
	}
	return GetDynamic3DTextLabelText(id, dest, maxlength);
}

/// <summary>Updates text and color of a dynamic 3D text label.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="color">New color integer.</param>
/// <param name="text">New text string.</param>
/// <returns>1 on success, 0 on invalid ID.</returns>
stock O3D_UpdateText(STREAMER_TAG_3D_TEXT_LABEL:id, color, const text[])
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return UpdateDynamic3DTextLabelText(id, color, text);
}

/// <summary>Updates text while preserving the existing label color.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="text">New text string.</param>
/// <returns>1 on success, 0 on invalid ID.</returns>
stock O3D_SetText(STREAMER_TAG_3D_TEXT_LABEL:id, const text[])
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	new color = Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_COLOR);
	return UpdateDynamic3DTextLabelText(id, color, text);
}

/// <summary>Updates color while preserving the existing label text.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="color">New color integer.</param>
/// <returns>1 on success, 0 on invalid ID.</returns>
stock O3D_SetColor(STREAMER_TAG_3D_TEXT_LABEL:id, color)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	new currentText[MAX_O3D_TEXT_LENGTH];
	if (!GetDynamic3DTextLabelText(id, currentText, sizeof currentText))
	{
		return 0;
	}
	return UpdateDynamic3DTextLabelText(id, color, currentText);
}

/// <summary>Retrieves the current color integer of a dynamic 3D text label.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <returns>Color integer value, or 0 if invalid.</returns>
stock O3D_GetColor(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_COLOR);
}

// ----------------------------------------------------------------------------
// Position, Distance, World, Interior & Area Helpers
// ----------------------------------------------------------------------------

/// <summary>Retrieves the 3D position coordinates of a label.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="x">Output Float X.</param>
/// <param name="y">Output Float Y.</param>
/// <param name="z">Output Float Z.</param>
/// <returns>1 on success, 0 on failure.</returns>
stock O3D_GetPos(STREAMER_TAG_3D_TEXT_LABEL:id, &Float:x, &Float:y, &Float:z)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
		return 0;
	}
	Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_X, x);
	Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_Y, y);
	Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_Z, z);
	return 1;
}

/// <summary>Updates the 3D position coordinates of a label.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="x">New Float X.</param>
/// <param name="y">New Float Y.</param>
/// <param name="z">New Float Z.</param>
/// <returns>1 on success, 0 on failure.</returns>
stock O3D_SetPos(STREAMER_TAG_3D_TEXT_LABEL:id, Float:x, Float:y, Float:z)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_X, x);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_Y, y);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_Z, z);
	return 1;
}

/// <summary>Retrieves the draw distance of a label.</summary>
stock Float:O3D_GetDrawDistance(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	new Float:distance = 0.0;
	if (IsValidDynamic3DTextLabel(id))
	{
		Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_DRAW_DISTANCE, distance);
	}
	return distance;
}

/// <summary>Sets the draw distance of a label.</summary>
stock O3D_SetDrawDistance(STREAMER_TAG_3D_TEXT_LABEL:id, Float:distance)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_DRAW_DISTANCE, distance);
}

/// <summary>Retrieves the streaming distance of a label.</summary>
stock Float:O3D_GetStreamDistance(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	new Float:distance = 0.0;
	if (IsValidDynamic3DTextLabel(id))
	{
		Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_STREAM_DISTANCE, distance);
	}
	return distance;
}

/// <summary>Sets the streaming distance of a label.</summary>
stock O3D_SetStreamDistance(STREAMER_TAG_3D_TEXT_LABEL:id, Float:distance)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_STREAM_DISTANCE, distance);
}

/// <summary>Retrieves the primary virtual world ID of a label.</summary>
stock O3D_GetWorld(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return -1;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_WORLD_ID);
}

/// <summary>Sets the primary virtual world ID of a label.</summary>
stock O3D_SetWorld(STREAMER_TAG_3D_TEXT_LABEL:id, worldid)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_WORLD_ID, worldid);
}

/// <summary>Retrieves the interior ID of a label.</summary>
stock O3D_GetInterior(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return -1;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_INTERIOR_ID);
}

/// <summary>Sets the interior ID of a label.</summary>
stock O3D_SetInterior(STREAMER_TAG_3D_TEXT_LABEL:id, interiorid)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_INTERIOR_ID, interiorid);
}

/// <summary>Retrieves the area ID constraint of a label.</summary>
stock STREAMER_TAG_AREA:O3D_GetArea(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return STREAMER_TAG_AREA:-1;
	}
	return STREAMER_TAG_AREA:Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_AREA_ID);
}

/// <summary>Sets the area ID constraint of a label.</summary>
stock O3D_SetArea(STREAMER_TAG_3D_TEXT_LABEL:id, STREAMER_TAG_AREA:areaid)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_AREA_ID, _:areaid);
}

/// <summary>Retrieves whether line-of-sight testing is enabled for a label.</summary>
stock O3D_GetTestLOS(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_TEST_LOS);
}

/// <summary>Enables or disables line-of-sight testing for a label.</summary>
stock O3D_SetTestLOS(STREAMER_TAG_3D_TEXT_LABEL:id, testlos)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_TEST_LOS, testlos);
}

/// <summary>Retrieves streamer priority of a label.</summary>
stock O3D_GetPriority(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_PRIORITY);
}

/// <summary>Sets streamer priority of a label.</summary>
stock O3D_SetPriority(STREAMER_TAG_3D_TEXT_LABEL:id, priority)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_PRIORITY, priority);
}

/// <summary>Retrieves custom extra ID attached to a label.</summary>
stock O3D_GetExtraID(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_EXTRA_ID);
}

/// <summary>Sets custom extra ID attached to a label.</summary>
stock O3D_SetExtraID(STREAMER_TAG_3D_TEXT_LABEL:id, extraid)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_EXTRA_ID, extraid);
}

// ----------------------------------------------------------------------------
// Attachments
// ----------------------------------------------------------------------------

/// <summary>Attaches a dynamic 3D text label to a player with specific positional offsets.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="playerid">Target player ID to attach to.</param>
/// <param name="offsetX">Local offset X (default: 0.0).</param>
/// <param name="offsetY">Local offset Y (default: 0.0).</param>
/// <param name="offsetZ">Local offset Z (default: 0.0).</param>
/// <returns>1 on success, 0 on invalid ID.</returns>
stock O3D_AttachToPlayer(STREAMER_TAG_3D_TEXT_LABEL:id, playerid, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_PLAYER, playerid);
	Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_VEHICLE, INVALID_VEHICLE_ID);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_X, offsetX);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Y, offsetY);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Z, offsetZ);
	return 1;
}

/// <summary>Attaches a dynamic 3D text label to a vehicle with specific positional offsets.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <param name="vehicleid">Target vehicle ID to attach to.</param>
/// <param name="offsetX">Local offset X (default: 0.0).</param>
/// <param name="offsetY">Local offset Y (default: 0.0).</param>
/// <param name="offsetZ">Local offset Z (default: 0.0).</param>
/// <returns>1 on success, 0 on invalid ID.</returns>
stock O3D_AttachToVehicle(STREAMER_TAG_3D_TEXT_LABEL:id, vehicleid, Float:offsetX = 0.0, Float:offsetY = 0.0, Float:offsetZ = 0.0)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_VEHICLE, vehicleid);
	Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_PLAYER, INVALID_PLAYER_ID);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_X, offsetX);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Y, offsetY);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Z, offsetZ);
	return 1;
}

/// <summary>Detaches a dynamic 3D text label from any attached player or vehicle.</summary>
/// <param name="id">The dynamic label ID.</param>
/// <returns>1 on success, 0 on invalid ID.</returns>
stock O3D_Detach(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_PLAYER, INVALID_PLAYER_ID);
	Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_VEHICLE, INVALID_VEHICLE_ID);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_X, 0.0);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Y, 0.0);
	Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Z, 0.0);
	return 1;
}

/// <summary>Gets the attached player ID of a dynamic 3D text label.</summary>
stock O3D_GetAttachedPlayer(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return INVALID_PLAYER_ID;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_PLAYER);
}

/// <summary>Gets the attached vehicle ID of a dynamic 3D text label.</summary>
stock O3D_GetAttachedVehicle(STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return INVALID_VEHICLE_ID;
	}
	return Streamer_GetIntData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACHED_VEHICLE);
}

/// <summary>Gets the attachment offsets of a dynamic 3D text label.</summary>
stock O3D_GetAttachOffsets(STREAMER_TAG_3D_TEXT_LABEL:id, &Float:offsetX, &Float:offsetY, &Float:offsetZ)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		offsetX = 0.0;
		offsetY = 0.0;
		offsetZ = 0.0;
		return 0;
	}
	Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_X, offsetX);
	Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Y, offsetY);
	Streamer_GetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, id, E_STREAMER_ATTACH_OFFSET_Z, offsetZ);
	return 1;
}

// ----------------------------------------------------------------------------
// Player-Specific Streaming Toggles & Updates
// ----------------------------------------------------------------------------

/// <summary>Toggles streaming of a dynamic 3D text label for a specific player.</summary>
stock O3D_ToggleForPlayer(playerid, STREAMER_TAG_3D_TEXT_LABEL:id, toggle)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_ToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, id, toggle);
}

/// <summary>Checks whether a dynamic 3D text label is toggled for streaming for a player.</summary>
stock O3D_IsToggleForPlayer(playerid, STREAMER_TAG_3D_TEXT_LABEL:id)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}
	return Streamer_IsToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, id);
}

/// <summary>Forces an immediate streamer update for a player at specified coordinates.</summary>
stock O3D_UpdateForPlayer(playerid, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, compensatedtime = -1, freezeplayer = 1)
{
	return Streamer_UpdateEx(playerid, x, y, z, worldid, interiorid, STREAMER_TYPE_3D_TEXT_LABEL, compensatedtime, freezeplayer);
}

// ----------------------------------------------------------------------------
// Variadic Formatted Text Helpers
// ----------------------------------------------------------------------------

/// <summary>Creates a dynamic 3D text label using a formatted string.</summary>
stock STREAMER_TAG_3D_TEXT_LABEL:O3D_Createf(
	Float:drawdistance,
	color,
	Float:x,
	Float:y,
	Float:z,
	const formatText[],
	{Float,_}:...
)
{
	new buffer[MAX_O3D_TEXT_LENGTH];
	static const STATIC_ARGS = 6;
	new n = (numargs() - STATIC_ARGS) * 4;

	if (n)
	{
		new arg_ptr, arg_top;
		#emit CONST.alt            STATIC_ARGS
		#emit SHL.C.alt            2
		#emit LCTRL                5
		#emit ADD
		#emit ADD.C                8
		#emit LOAD.I
		#emit STOR.S.pri           arg_ptr
		#emit LOAD.S.alt           n
		#emit ADD
		#emit STOR.S.pri           arg_top
		while (arg_top != arg_ptr)
		{
			#emit LOAD.S.pri       arg_top
			#emit CONST.alt        4
			#emit SUB
			#emit STOR.S.pri       arg_top
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S               formatText
		#emit CONST.pri            O3D_BUFFER_SIZE
		#emit PUSH.pri
		#emit PUSH.ADR             buffer
		#emit LOAD.S.pri           n
		#emit ADD.C                12
		#emit PUSH.pri
		#emit SYSREQ.C             format
		#emit LCTRL                4
		#emit LOAD.S.alt           n
		#emit ADD.C                16
		#emit ADD
		#emit SCTRL                4
	}
	else
	{
		format(buffer, sizeof buffer, "%s", formatText);
	}

	return CreateDynamic3DTextLabel(
		buffer,
		color,
		x,
		y,
		z,
		drawdistance,
		INVALID_PLAYER_ID,
		INVALID_VEHICLE_ID,
		1,
		-1,
		-1,
		-1,
		STREAMER_3D_TEXT_LABEL_SD,
		STREAMER_TAG_AREA:-1,
		0
	);
}

/// <summary>Creates a player-scoped dynamic 3D text label using a formatted string.</summary>
stock STREAMER_TAG_3D_TEXT_LABEL:O3D_CreateForPlayerf(
	playerid,
	Float:drawdistance,
	color,
	Float:x,
	Float:y,
	Float:z,
	const formatText[],
	{Float,_}:...
)
{
	new buffer[MAX_O3D_TEXT_LENGTH];
	static const STATIC_ARGS = 7;
	new n = (numargs() - STATIC_ARGS) * 4;

	if (n)
	{
		new arg_ptr, arg_top;
		#emit CONST.alt            STATIC_ARGS
		#emit SHL.C.alt            2
		#emit LCTRL                5
		#emit ADD
		#emit ADD.C                8
		#emit LOAD.I
		#emit STOR.S.pri           arg_ptr
		#emit LOAD.S.alt           n
		#emit ADD
		#emit STOR.S.pri           arg_top
		while (arg_top != arg_ptr)
		{
			#emit LOAD.S.pri       arg_top
			#emit CONST.alt        4
			#emit SUB
			#emit STOR.S.pri       arg_top
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S               formatText
		#emit CONST.pri            O3D_BUFFER_SIZE
		#emit PUSH.pri
		#emit PUSH.ADR             buffer
		#emit LOAD.S.pri           n
		#emit ADD.C                12
		#emit PUSH.pri
		#emit SYSREQ.C             format
		#emit LCTRL                4
		#emit LOAD.S.alt           n
		#emit ADD.C                16
		#emit ADD
		#emit SCTRL                4
	}
	else
	{
		format(buffer, sizeof buffer, "%s", formatText);
	}

	return CreateDynamic3DTextLabel(
		buffer,
		color,
		x,
		y,
		z,
		drawdistance,
		INVALID_PLAYER_ID,
		INVALID_VEHICLE_ID,
		1,
		-1,
		-1,
		playerid,
		STREAMER_3D_TEXT_LABEL_SD,
		STREAMER_TAG_AREA:-1,
		0
	);
}

/// <summary>Updates text of a dynamic 3D text label using a formatted string.</summary>
stock O3D_UpdateTextf(
	STREAMER_TAG_3D_TEXT_LABEL:id,
	color,
	const formatText[],
	{Float,_}:...
)
{
	if (!IsValidDynamic3DTextLabel(id))
	{
		return 0;
	}

	new buffer[MAX_O3D_TEXT_LENGTH];
	static const STATIC_ARGS = 3;
	new n = (numargs() - STATIC_ARGS) * 4;

	if (n)
	{
		new arg_ptr, arg_top;
		#emit CONST.alt            STATIC_ARGS
		#emit SHL.C.alt            2
		#emit LCTRL                5
		#emit ADD
		#emit ADD.C                8
		#emit LOAD.I
		#emit STOR.S.pri           arg_ptr
		#emit LOAD.S.alt           n
		#emit ADD
		#emit STOR.S.pri           arg_top
		while (arg_top != arg_ptr)
		{
			#emit LOAD.S.pri       arg_top
			#emit CONST.alt        4
			#emit SUB
			#emit STOR.S.pri       arg_top
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S               formatText
		#emit CONST.pri            O3D_BUFFER_SIZE
		#emit PUSH.pri
		#emit PUSH.ADR             buffer
		#emit LOAD.S.pri           n
		#emit ADD.C                12
		#emit PUSH.pri
		#emit SYSREQ.C             format
		#emit LCTRL                4
		#emit LOAD.S.alt           n
		#emit ADD.C                16
		#emit ADD
		#emit SCTRL                4
	}
	else
	{
		format(buffer, sizeof buffer, "%s", formatText);
	}

	return UpdateDynamic3DTextLabelText(id, color, buffer);
}

// ----------------------------------------------------------------------------
// ALS Hooking & Player Disconnect Cleanup
// ----------------------------------------------------------------------------

#if !defined O3D_DISABLE_AUTOCLEANUP

public OnPlayerDisconnect(playerid, reason)
{
	#if defined O3D_OnPlayerDisconnect
		return O3D_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect O3D_OnPlayerDisconnect

#if defined O3D_OnPlayerDisconnect
	forward O3D_OnPlayerDisconnect(playerid, reason);
#endif

#endif // !defined O3D_DISABLE_AUTOCLEANUP
