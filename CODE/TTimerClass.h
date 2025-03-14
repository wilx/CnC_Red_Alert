#ifndef TTIMERCLASS_H
#define TTIMERCLASS_H

#include "noinitclass.h"
#include "BasicTimerClass.h"

/*
**	This timer class functions similarly to the basic timer class. In addition to the
**	normal timer operation, this class has the ability to be stopped and started at
**	will. If you have no need to start or stop the timer, then use the basic timer
**	class instead.
*/
template<class T>
class TTimerClass : public BasicTimerClass<T> {
 	public:
		// Constructor allows assignment as if class was integral 'long' type.
		TTimerClass(unsigned long set=0);
		TTimerClass(NoInitClass const & x);

		~TTimerClass(void) {};

		// Fetches current value of timer.
		unsigned long Value(void) const;

		// Conversion operator to allow consistent treatment with integral types.
		operator unsigned long(void) const;

		// Function operator to allow timer object definition to be cascaded.
		unsigned long operator () (void) const;

		// Stops (pauses) the timer.
		void Stop(void);

		// Starts (resumes) the timer.
		void Start(void);

		// Queries whether the timer is currently active.
		bool Is_Active(void) const;

	private:
		unsigned long Accumulated;				//	Total accumulated ticks.
};


template<class T>
inline TTimerClass<T>::TTimerClass(NoInitClass const & x) :
	BasicTimerClass<T>(x)
{
}


/***********************************************************************************************
 * TTimerClass<T>::TTimerClass -- Constructor for timer class object.                          *
 *                                                                                             *
 *    This is the constructor for the advanced timer class object. This object class can start *
 *    or stop the timer under user control.                                                    *
 *                                                                                             *
 * INPUT:   set   -- The initial value to set the timer to. If no value is specified, then     *
 *                   the timer is assumed to start from zero.                                  *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline TTimerClass<T>::TTimerClass(unsigned long set) :
	BasicTimerClass<T>(set),
	Accumulated(0)
{
}


/***********************************************************************************************
 * TTimerClass<T>::Value -- Returns with the current value of the timer.                       *
 *                                                                                             *
 *    This routine will return with the current value of the timer. It takes into account      *
 *    whether the timer has stopped or not so as to always return the correct value regardless *
 *    of that condition.                                                                       *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the current value of the timer.                                       *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline unsigned long TTimerClass<T>::Value(void) const
{
	unsigned long value = Accumulated;
	if (this->Started != 0xFFFFFFFFU) {
		value += BasicTimerClass<T>::Value();
	}
	return(value);
}


/***********************************************************************************************
 * TTimerClass<T>::operator long -- Conversion operator for timer object.                      *
 *                                                                                             *
 *    This conversion operator allows this timer object to function as an "rvalue" of a "long" *
 *    type. This is consistent with the integral "long" value. It is possible to assign a      *
 *    timer object to a long and have the long initialized with the current value of the       *
 *    timer.                                                                                   *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the current time value expressed as a long.                           *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline TTimerClass<T>::operator unsigned long(void) const
{
	unsigned long value = Accumulated;
	if (this->Started != 0xFFFFFFFFU) {
		value += BasicTimerClass<T>::Value();
	}
	return(value);
}


/***********************************************************************************************
 * TTimerClass<T>::operator () -- Function operator for timer object.                          *
 *                                                                                             *
 *    This function operator for the timer class allows this timer class to be used as the     *
 *    template parameter for other timer class objects. With this ability, one can control     *
 *    several timers (e.g., start or stop them) by using a single controlling timer class      *
 *    that other timers are instantiated from.                                                 *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the current time expressed as a long.                                 *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline unsigned long TTimerClass<T>::operator () (void) const
{
	unsigned long value = Accumulated;
	if (this->Started != 0xFFFFFFFFU) {
		value += BasicTimerClass<T>::Value();
	}
	return(value);
}


/***********************************************************************************************
 * TTimerClass<T>::Stop -- Stops the current timer from incrementing.                          *
 *                                                                                             *
 *    This routine will stop (pause) the timer from further increments. To cause the timer     *
 *    to begin anew, call the Start() function.                                                *
 *                                                                                             *
 *                                                                                             *
 * INPUT:                                                                                      *
 *                                                                                             *
 * OUTPUT:                                                                                     *
 *                                                                                             *
 * WARNINGS:                                                                                   *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
void TTimerClass<T>::Stop(void)
{
	if (this->Started != 0xFFFFFFFFU) {
		Accumulated += BasicTimerClass<T>::operator unsigned long();
		this->Started = 0xFFFFFFFFU;
	}
}


/***********************************************************************************************
 * TTimerClass<T>::Start -- Starts (resumes) a stopped timer.                                  *
 *                                                                                             *
 *    This routine will resume a timer that was previously stopped with the Stop() function.   *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
void TTimerClass<T>::Start(void)
{
	if (this->Started == 0xFFFFFFFFU) {
		this->Started = this->Timer();
	}
}


/***********************************************************************************************
 * TTimerClass<T>::Is_Active -- Checks to see if the timer is counting.                        *
 *                                                                                             *
 *    Since this timer can be paused, this routine is used to examine the timer to see if it   *
 *    is currently paused or active. If the timer is active, then the return value will be     *
 *    true.                                                                                    *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  bool; Is this timer currently active?                                              *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline bool TTimerClass<T>::Is_Active(void) const
{
	return(this->Started != 0xFFFFFFFFU);
}


#endif // TTIMERCLASS_H
