/*
**	Command & Conquer Red Alert(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Header: /CounterStrike/FTIMER.H 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : FTIMER.H                                                     *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 03/16/95                                                     *
 *                                                                                             *
 *                  Last Update : July 6, 1996 [JLB]                                           *
 *                                                                                             *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   BasicTimerClass<T>::BasicTimerClass -- Constructor for basic timer class.                 *
 *   BasicTimerClass<T>::operator () -- Function operator for timer object.                    *
 *   BasicTimerClass<T>::operator long -- Conversion to long operator.                         *
 *   BasicTimerClass<T>::~BasicTimerClass -- Destructor for basic timer object.                *
 *   TTimerClass<T>::Is_Active -- Checks to see if the timer is counting.                      *
 *   TTimerClass<T>::Start -- Starts (resumes) a stopped timer.                                *
 *   TTimerClass<T>::Stop -- Stops the current timer from incrementing.                        *
 *   TTimerClass<T>::TTimerClass -- Constructor for timer class object.                        *
 *   TTimerClass<T>::operator () -- Function operator for timer object.                        *
 *   TTimerClass<T>::operator long -- Conversion operator for timer object.                    *
 *   CDTimerClass<T>::CDTimerClass -- Constructor for count down timer.                        *
 *   CDTimerClass<T>::Is_Active -- Checks to see if the timer object is active.                *
 *   CDTimerClass<T>::Start -- Starts (resumes) the count down timer.                          *
 *   CDTimerClass<T>::Stop -- Stops (pauses) the count down timer.                             *
 *   CDTimerClass<T>::operator () -- Function operator for the count down timer.               *
 *   CDTimerClass<T>::operator long -- Conversion to long operator function.                   *
 *   CDTimerClass<T>::~CDTimerClass -- Destructor for the count down timer object.             *
 *   TTimerClass<T>::Value -- Returns with the current value of the timer.                     *
 *   CDTimerClass<T>::Value -- Fetches the current value of the countdown timer.               *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef FTIMER_H
#define FTIMER_H

#include "BasicTimerClass.h"
#include "TTimerClass.h"
#include "CDTimerClass.h"

#endif
