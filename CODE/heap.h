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

/* $Header: /CounterStrike/HEAP.H 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : HEAP.H                                                       *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 02/18/95                                                     *
 *                                                                                             *
 *                  Last Update : February 18, 1995 [JLB]                                      *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef HEAP_H
#define HEAP_H

#include "vector.h"

#include "FixedHeapClass.h"


/**************************************************************************
**	This template serves only as an interface to the heap manager class. By
**	using this template, the object pointers are automatically converted
**	to the correct type without any code overhead.
*/
template<class T>
class TFixedHeapClass : public FixedHeapClass
{
	public:
		TFixedHeapClass(void) : FixedHeapClass(sizeof(T)) {};
		virtual ~TFixedHeapClass(void) {};


		virtual int ID(T const * pointer) const {return FixedHeapClass::ID(pointer);};
		virtual T * Alloc(void) {return (T*)FixedHeapClass::Allocate();};
		virtual int Free(T * pointer) {return(FixedHeapClass::Free(pointer));};

		T & operator[](int index) {return *(T *)(((char *)Buffer) + (index * Size));};
		T const & operator[](int index) const {return *(T*)(((char *)Buffer) + (index * Size));};
};


/**************************************************************************
**	This is a derivative of the fixed heap class. This class adds the
**	ability to quickly iterate through the active (allocated) objects. Since the
**	active array is a sequence of pointers, the overhead of this class
**	is 4 bytes per potential allocated object (be warned).
*/
class FixedIHeapClass : public FixedHeapClass
{
	public:
		FixedIHeapClass(int size) : FixedHeapClass(size) {};
		virtual ~FixedIHeapClass(void) {};

		virtual int Set_Heap(int count, void * buffer=0);
		virtual void * Allocate(void);
		virtual void Clear(void);
		virtual int Free(void * pointer);
		virtual int Free_All(void);
		virtual int Logical_ID(void const * pointer) const;
		virtual int Logical_ID(int id) const {return(Logical_ID((*this)[id]));}

		virtual void * Active_Ptr(int index) {return ActivePointers[index];};
		virtual void const * Active_Ptr(int index) const {return ActivePointers[index];};

		/*
		**	This is an array of pointers to allocated objects. Using this array
		**	to control iteration through the objects ensures a minimum of processing.
		**	It also allows access to this array so that custom sorting can be
		**	performed.
		*/
		DynamicVectorClass<void *> ActivePointers;
};


/**************************************************************************
**	This template serves only as an interface to the iteratable heap manager
**	class. By using this template, the object pointers are automatically converted
**	to the correct type without any code overhead.
*/
class FileClass;
template<class T>
class TFixedIHeapClass : public FixedIHeapClass
{
	public:
		TFixedIHeapClass(void) : FixedIHeapClass(sizeof(T)) {};
		virtual ~TFixedIHeapClass(void) {};

		virtual int ID(T const * pointer) const {return FixedIHeapClass::ID(pointer);};
		virtual int Logical_ID(T const * pointer) const {return(FixedIHeapClass::Logical_ID(pointer));}
		virtual int Logical_ID(int id) const {return(FixedIHeapClass::Logical_ID(id));}
		virtual T * Alloc(void) {return (T*)FixedIHeapClass::Allocate();};
		virtual int Free(T * pointer) {return FixedIHeapClass::Free(pointer);};
		virtual int Free(void * pointer) {return FixedIHeapClass::Free(pointer);};
		virtual int Save(Pipe & file) const;
		virtual int Load(Straw & file);
		virtual void Code_Pointers(void);
		virtual void Decode_Pointers(void);

		virtual T * Ptr(int index) const {return (T*)FixedIHeapClass::ActivePointers[index];};
		virtual T * Raw_Ptr(int index) {return (T*)((*this)[index]);};
};


#endif


