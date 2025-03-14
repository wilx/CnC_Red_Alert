#ifndef BASICTIMERCLASS_H
#define BASICTIMERCLASS_H

#include "noinitclass.h"

/*
**	This is a timer class that watches a constant rate timer (specified by the parameter
**	type class) and provides basic timer functionality. It is possible to set the start value
**	WITHOUT damaging or otherwise affecting any other timer that may be built upon the same
**	specified timer class object. Treat an object of this type as if it were a "magic" integral
**	long that automatically advances at the speed of the timer class object controlling it.
*/
// Let lint know that non-virtual destructor is OK for this class.
//lint -esym(1509,BasicTimerClass)
template<class T>
class BasicTimerClass {
 	public:
		// Constructor allows assignment as if class was integral 'long' type.
		BasicTimerClass(unsigned long set=0);
		BasicTimerClass(NoInitClass const & );

		~BasicTimerClass(void);

		// Fetch current value of timer.
		unsigned long Value(void) const;

		// Conversion operator to allow consistent treatment with integral types.
		operator unsigned long(void) const;

		// Function operator to allow timer object definition to be cascaded.
		unsigned long operator () (void) const;

	protected:
		T Timer;			// Timer regulator (ticks at constant rate).
		unsigned long Started;	// Time started.
};


template<class T>
inline BasicTimerClass<T>::BasicTimerClass(NoInitClass const & )
{
}


/***********************************************************************************************
 * BasicTimerClass<T>::BasicTimerClass -- Constructor for basic timer class.                   *
 *                                                                                             *
 *    This is the constructor for the basic timer class object. It sets the timer counting     *
 *    up from zero at the rate of the controlling timer class object.                          *
 *                                                                                             *
 * INPUT:   set   -- Alternate initial start value for the counter. If not specified, then     *
 *                   the timer is assumed to start at zero and count upwards.                  *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
//lint -esym(1403,BasicTimerClass<class FrameTimerClass>::Timer)
//lint -esym(1403,BasicTimerClass<class SystemTimerClass>::Timer)
template<class T>
inline BasicTimerClass<T>::BasicTimerClass(unsigned long set) :
	Started(Timer()-set)
{
}


/***********************************************************************************************
 * BasicTimerClass<T>::~BasicTimerClass -- Destructor for basic timer object.                  *
 *                                                                                             *
 *    The destructor for the basic timer object doesn't have to do anything.                   *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline BasicTimerClass<T>::~BasicTimerClass(void)
{
}


template<class T>
inline unsigned long BasicTimerClass<T>::Value(void) const
{
	return(Timer()-Started);
}


/***********************************************************************************************
 * BasicTimerClass<T>::operator long -- Conversion to long operator.                           *
 *                                                                                             *
 *    This conversion operator allows the basic timer object to function in much the same      *
 *    manner as the integral "long" type. One can assign a long with a timer object and the    *
 *    actual value of the timer is extracted from the object and used.                         *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the timer value expressed as a long.                                  *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline BasicTimerClass<T>::operator unsigned long(void) const
{
	return(Timer()-Started);
}


/***********************************************************************************************
 * BasicTimerClass<T>::operator () -- Function operator for timer object.                      *
 *                                                                                             *
 *    This function operator allows the timer to also serve as the parameter type class for    *
 *    additional timer objects. This allows one to instantiate a controlling timer class that  *
 *    can control (e.g., turn on or off) all timers that are based upon it.                    *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns the current timer value expressed as a long.                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/05/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline unsigned long BasicTimerClass<T>::operator () (void) const
{
	return(Timer()-Started);
}


#endif // BASICTIMERCLASS_H
