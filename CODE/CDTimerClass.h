#ifndef CDTIMERCLASS_H
#define CDTIMERCLASS_H

#include "noinitclass.h"
#include "BasicTimerClass.h"

/*
**	This timer counts down from the specified (or constructed) value down towards zero.
**	The countdown rate is controlled by the timer object specified. This timer object can
**	be started or stopped. It can also be tested to see if it has expired or not. An expired
**	count down timer is one that has value of zero. You can treat this class object as if it
**	were an integral "magic" long that automatically counts down toward zero.
*/
template<class T>
class CDTimerClass : public BasicTimerClass<T> {
	public:
		// Constructor allows assignment as if class was integral 'long' type.
		CDTimerClass(unsigned long set=0);
		CDTimerClass(NoInitClass const & x);

		~CDTimerClass(void);

		// Fetches current value of count down timer.
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
		unsigned long DelayTime;			// Ticks remaining before countdown timer expires.
};


template<class T>
inline CDTimerClass<T>::CDTimerClass(NoInitClass const & x) :
	BasicTimerClass<T>(x)
{
}


/***********************************************************************************************
 * CDTimerClass<T>::CDTimerClass -- Constructor for count down timer.                          *
 *                                                                                             *
 *    This is the constructor for the count down timer object. The optional starting value     *
 *    can be used to initiate the timer. Because of this constructor it is possible to assign  *
 *    a long to a count down timer object in order to begin the countdown process.             *
 *                                                                                             *
 * INPUT:   set   -- The initial starting value for the countdown timer.                       *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline CDTimerClass<T>::CDTimerClass(unsigned long set) :
	BasicTimerClass<T>(0),
	DelayTime(set)
{
}


/***********************************************************************************************
 * CDTimerClass<T>::~CDTimerClass -- Destructor for the count down timer object.               *
 *                                                                                             *
 *    The destructor for the count down timer object does nothing.                             *
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
inline CDTimerClass<T>::~CDTimerClass(void)
{
}


/***********************************************************************************************
 * CDTimerClass<T>::Value -- Fetches the current value of the countdown timer.                 *
 *                                                                                             *
 *    Use this routine to fetch the current value of the timer. It takes into consideration    *
 *    whether the timer has been stopped or not. It returns the correct value regardless of    *
 *    this condition.                                                                          *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the correct value of this count down timer.                           *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline unsigned long CDTimerClass<T>::Value(void) const
{
	unsigned long remain = DelayTime;
	if (this->Started != 0xFFFFFFFFU) {
		unsigned long value = BasicTimerClass<T>::Value();
		if (value < remain) {
			return(remain - value);
		} else {
			return(0);
		}
	}
	return(remain);
}


/***********************************************************************************************
 * CDTimerClass<T>::operator long -- Conversion to long operator function.                     *
 *                                                                                             *
 *    This conversion operator allows the count down timer object to be used as if it were     *
 *    a "magic" long that automatically counted downward at the controller class tick rate.    *
 *    The count down object can be used in any place that an rvalue long could be used.        *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the current count down time expressed in the form of a long value.    *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline CDTimerClass<T>::operator unsigned long(void) const
{
	unsigned long remain = DelayTime;
	if (this->Started != 0xFFFFFFFFU) {
		unsigned long value = BasicTimerClass<T>::Value();
		if (value < remain) {
			return(remain - value);
		} else {
			return(0);
		}
	}
	return(remain);
}


/***********************************************************************************************
 * CDTimerClass<T>::operator () -- Function operator for the count down timer.                 *
 *                                                                                             *
 *    This is the function operator for the count down timer object. By supporting this        *
 *    function operator, this class (or one derived from this class) could be used as the      *
 *    controlling timer to the timer templates.                                                *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the current count down time expressed in the form of a long.          *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline unsigned long CDTimerClass<T>::operator () (void) const
{
	unsigned long remain = DelayTime;
	if (this->Started != 0xFFFFFFFFU) {
		unsigned long value = BasicTimerClass<T>::Value();
		if (value < remain) {
			return(remain - value);
		} else {
			return(0);
		}
	}
	return(remain);
}


/***********************************************************************************************
 * CDTimerClass<T>::Stop -- Stops (pauses) the count down timer.                               *
 *                                                                                             *
 *    This routine is used to stop (pause) the count down timer object. A timer object paused  *
 *    in this fashion will be resumed by a call to Start() or by assigning a new count down    *
 *    value to the timer.                                                                      *
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
void CDTimerClass<T>::Stop(void)
{
	if (this->Started != 0xFFFFFFFFU) {
		DelayTime = *this;
		this->Started = 0xFFFFFFFFU;
	}
}


/***********************************************************************************************
 * CDTimerClass<T>::Start -- Starts (resumes) the count down timer.                            *
 *                                                                                             *
 *    This routine is used to start (resume) the count down timer that was previously stopped  *
 *    with the Stop() function. The timer will also resume when a new timer value is assigned. *
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
void CDTimerClass<T>::Start(void)
{
	if (this->Started == 0xFFFFFFFFU) {
		this->Started = this->Timer();
	}
}


/***********************************************************************************************
 * CDTimerClass<T>::Is_Active -- Checks to see if the timer object is active.                  *
 *                                                                                             *
 *    Because the timer object counting can be stopped, this routine is used to determine      *
 *    if the timer is currently paused or active.                                              *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  bool; Is the timer currently active?                                               *
 *                                                                                             *
 * WARNINGS:   Note that if the timer has counted down to zero, then it may be active, but     *
 *             the value will, naturally, not change.                                          *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/06/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
template<class T>
inline bool CDTimerClass<T>::Is_Active(void) const
{
	return(this->Started != 0xFFFFFFFFU);
}


#endif // CDTIMERCLASS_H
