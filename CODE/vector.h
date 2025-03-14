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

/* $Header: /CounterStrike/VECTOR.H 1     3/03/97 10:26a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : VECTOR.H                                                     *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 02/19/95                                                     *
 *                                                                                             *
 *                  Last Update : March 13, 1995 [JLB]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   VectorClass<T>::VectorClass -- Constructor for vector class.                              *
 *   VectorClass<T>::~VectorClass -- Default destructor for vector class.                      *
 *   VectorClass<T>::VectorClass -- Copy constructor for vector object.                        *
 *   VectorClass<T>::operator = -- The assignment operator.                                    *
 *   VectorClass<T>::operator == -- Equality operator for vector objects.                      *
 *   VectorClass<T>::Clear -- Frees and clears the vector.                                     *
 *   VectorClass<T>::Resize -- Changes the size of the vector.                                 *
 *   DynamicVectorClass<T>::DynamicVectorClass -- Constructor for dynamic vector.              *
 *   DynamicVectorClass<T>::Resize -- Changes the size of a dynamic vector.                    *
 *   DynamicVectorClass<T>::Add -- Add an element to the vector.                               *
 *   DynamicVectorClass<T>::Delete -- Remove the specified object from the vector.             *
 *   DynamicVectorClass<T>::Delete -- Deletes the specified index from the vector.             *
 *   VectorClass<T>::ID -- Pointer based conversion to index number.                           *
 *   VectorClass<T>::ID -- Finds object ID based on value.                                     *
 *   DynamicVectorClass<T>::ID -- Find matching value in the dynamic vector.                   *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef VECTOR_H
#define VECTOR_H

#ifdef NEVER
#ifndef false
#define false 0
#endif
#ifndef true
#define true 1
#endif
#endif

#include	<stdlib.h>
#include	<stddef.h>

#include "noinitclass.h"


/**************************************************************************
**	This is a general purpose vector class. A vector is defined by this
**	class, as an array of arbitrary objects where the array can be dynamically
**	sized. Because is deals with arbitrary object types, it can handle everything.
**	As a result of this, it is not terribly efficient for integral objects (such
**	as char or int). It will function correctly, but the copy constructor and
**	equality operator could be highly optimized if the integral type were known.
**	This efficiency can be implemented by deriving an integral vector template
**	from this one in order to supply more efficient routines.
*/
template<class T>
class VectorClass
{
	public:
		VectorClass(NoInitClass const & ) {};
		VectorClass(unsigned size=0, T const * array=0);
		VectorClass(VectorClass<T> const &);		// Copy constructor.
		virtual ~VectorClass(void);

		T & operator[](unsigned index) {return(Vector[index]);};
		T const & operator[](unsigned index) const {return(Vector[index]);};
		virtual VectorClass<T> & operator =(VectorClass<T> const &); // Assignment operator.
		virtual int operator == (VectorClass<T> const &) const;	// Equality operator.
		virtual int Resize(unsigned newsize, T const * array=0);
		virtual void Clear(void);
		unsigned Length(void) const {return VectorMax;};
		virtual int ID(T const * ptr);	// Pointer based identification.
		virtual int ID(T const & ptr);	// Value based identification.

	protected:

		/*
		**	This is a pointer to the allocated vector array of elements.
		*/
		T * Vector;

		/*
		**	This is the maximum number of elements allowed in this vector.
		*/
		unsigned VectorMax;

		/*
		**	Does the vector data pointer refer to memory that this class has manually
		**	allocated? If so, then this class is responsible for deleting it.
		*/
		unsigned IsAllocated:1;
};


#include "DynamicVectorClass.h"
#include "BooleanVectorClass.h"

#endif
