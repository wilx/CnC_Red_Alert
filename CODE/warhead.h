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

/* $Header: /CounterStrike/WARHEAD.H 1     3/03/97 10:26a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : WARHEAD.H                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 05/17/96                                                     *
 *                                                                                             *
 *                  Last Update : May 17, 1996 [JLB]                                           *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef WARHEAD_H
#define WARHEAD_H

#include "defines.h"
#include "noinitclass.h"
#include "fixed.h"

/**********************************************************************
**	Each of the warhead types has specific characteristics. This structure
**	holds these characteristics.
*/
class WarheadTypeClass
{
	public:
		WarheadTypeClass(char const * name);
		WarheadTypeClass(NoInitClass const &) {}

		void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		void operator delete(void * pointer);

		void Code_Pointers(void) {}
		void Decode_Pointers(void) {}
		char const * Name(void) const {return(IniName);}
		bool Read_INI(CCINIClass & ini);
		static WarheadTypeClass * As_Pointer(WarheadType weapon);

		/*
		**	This is the ID number of the weapon type. It is the weapon
		**	type ID enum as well as the index number into the weapon
		**	heap.
		*/
		int ID;

		/*
		**	This is the identifying name of this warhead type.
		*/
		char const * IniName;

		/*
		**	This value control how damage from this warhead type will reduce
		**	over distance. The larger the number, the less the damage is reduced
		**	the further the distance from the source of the damage.
		*/
		int SpreadFactor;

		/*
		**	If this warhead type can destroy walls, then this flag will be true.
		*/
		bool IsWallDestroyer:1;

		/*
		**	If this warhead can destroy wooden walls, then this flag will be true.
		*/
		bool IsWoodDestroyer:1;

		/*
		**	Does this warhead damage tiberium?
		*/
		bool IsTiberiumDestroyer:1;

		/*
		**	Only effective against infantry?
		*/
		bool IsOrganic:1;

		/*
		**	The warhead damage is reduced depending on the the type of armor the
		**	defender has. This table is what gives weapons their "character".
		*/
		fixed Modifier[ARMOR_COUNT];

		/*
		**	Which explosion set to use for warhead impact.
		*/
		int ExplosionSet;

		/*
		**	This specifies the infantry death animation to use if the infantry dies as
		**	a result of a warhead of this type.
		*/
		int InfantryDeath;
};


#endif
