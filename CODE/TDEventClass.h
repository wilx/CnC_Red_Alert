#ifndef TDEVENTCLASS_H
#define TDEVENTCLASS_H

#include "CDTimerClass.h"
#include "jshell.h"
#include "noinitclass.h"


/*
**	This holds the changable data that is associated with an event as
**	it relates to a trigger.
*/
struct TDEventClass {
	/*
	**	If this event has been triggered by something that is temporal, then
	**	this flag will be set to true so that subsequent trigger examination
	**	will return a successful event trigger flag. Typical use of this is
	**	for when objects of a specific type are built.
	*/
	unsigned IsTripped:1;

	/*
	**	Timer based events require a special timer control handler.
	*/
	CDTimerClass<FrameTimerClass> Timer;

	TDEventClass(void) : IsTripped(false), Timer(0) {};
	TDEventClass(NoInitClass const & x) : Timer(x) {};
};

#endif // TDEVENCLASS_H
