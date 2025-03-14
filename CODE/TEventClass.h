#ifndef TEVENTCLASS_H
#define TEVENTCLASS_H

#include "TEventType.h"
#include "ccptr.h"
#include "noinitclass.h"
#include "TDEventClass.h"

/*
**	This elaborates the information necessary to trigger
**	an event.
*/
class TeamTypeClass;
struct TEventClass {

	/*
	**	This is the event that will controls how this event gets triggered.
	*/
	TEventType Event;

	/*
	**	If this event needs to reference a team type, then this is the pointer
	**	to the team type object. This must be separated from the following
	**	union because Watcom compiler won't allow a class that has a
	**	constructor to be declared in a union.
	*/
	CCPtr<TeamTypeClass> Team;

	union {
		StructType				Structure;	// Used for structure type checking.
		UnitType					Unit;			// Used for unit type checking.
		InfantryType			Infantry;	//	Used for infantry type checking.
		AircraftType			Aircraft;	// Used for aircraft type checking.
		HousesType				House;		// Used for house specific events.
		long	Value;							// Used for other events that need data.
	} Data;

	TEventClass(void) : Event(TEVENT_NONE) {Data.Value = 0;};
	TEventClass(TEventType event) : Event(event) {Data.Value = 0;};
	TEventClass(NoInitClass const & x) : Team(x) {};

	void Code_Pointers(void);
	void Decode_Pointers(void);
	void Reset(TDEventClass & td) const;
	bool operator () (TDEventClass & td, TEventType event, HousesType house, ObjectClass const * object, bool forced);
	void Read_INI(void);
	void Build_INI_Entry(char * buffer) const;
};

#endif // TEVENTCLASS_H
