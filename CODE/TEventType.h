#ifndef TDEVENTTYPE_H
#define TDEVENTTYPE_H

#include "defines.h"

/*
**	These are the trigger events that are checked for and if qualified, they will signal
**	a successful trigger event. This might result in the trigger action being performed.
*/
typedef enum TEventType {
	TEVENT_NONE,
	TEVENT_PLAYER_ENTERED,					// player enters this square
	TEVENT_SPIED,								// Spied by.
	TEVENT_THIEVED,							// Thieved by (raided or stolen vehicle).
	TEVENT_DISCOVERED,						// player discovers this object
	TEVENT_HOUSE_DISCOVERED,				// House has been discovered.
	TEVENT_ATTACKED,							// player attacks this object
	TEVENT_DESTROYED,							// player destroys this object
	TEVENT_ANY,									// Any object event will cause the trigger.
	TEVENT_UNITS_DESTROYED,					// all house's units destroyed
	TEVENT_BUILDINGS_DESTROYED,			// all house's buildings destroyed
	TEVENT_ALL_DESTROYED,					// all house's units & buildings destroyed
	TEVENT_CREDITS,							// house reaches this many credits
	TEVENT_TIME,								// Scenario elapsed time from start.
	TEVENT_MISSION_TIMER_EXPIRED,			// Pre expired mission timer.
	TEVENT_NBUILDINGS_DESTROYED,			// Number of buildings destroyed.
	TEVENT_NUNITS_DESTROYED,				// Number of units destroyed.
	TEVENT_NOFACTORIES,						// No factories left.
	TEVENT_EVAC_CIVILIAN,					// Civilian has been evacuated.
	TEVENT_BUILD,								// Specified building has been built.
	TEVENT_BUILD_UNIT,						// Specified unit has been built.
	TEVENT_BUILD_INFANTRY,					// Specified infantry has been built.
	TEVENT_BUILD_AIRCRAFT,					// Specified aircraft has been built.
	TEVENT_LEAVES_MAP,						// Specified team member leaves map.
	TEVENT_ENTERS_ZONE,						// Enters same zone as waypoint 'x'.
	TEVENT_CROSS_HORIZONTAL,				// Crosses horizontal trigger line.
	TEVENT_CROSS_VERTICAL,					// Crosses vertical trigger line.
	TEVENT_GLOBAL_SET,						// If specified global has been set.
	TEVENT_GLOBAL_CLEAR,						// If specified global has been cleared.
	TEVENT_FAKES_DESTROYED,					// If all fake structures are gone.
	TEVENT_LOW_POWER,							// When power drops below 100%.
	TEVENT_ALL_BRIDGES_DESTROYED,			// All bridges destroyed.
	TEVENT_BUILDING_EXISTS,					// Check for building existing.

	TEVENT_COUNT,
	TEVENT_FIRST=0
} TEventType;

TEventType Event_From_Name(char const * name);
NeedType Event_Needs(TEventType event);
char const * Name_From_Event(TEventType event);

#endif // TDEVENTTYPE_H
