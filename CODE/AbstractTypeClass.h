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

#ifndef ABSTRACTTYPECLASS_H
#define ABSTRACTTYPECLASS_H

#include "defines.h"
#include <cstring>

/***************************************************************************
**	This is the abstract type class. It holds information common to all
**	objects that might exist. This contains the name of the object type.
*/
class AbstractTypeClass
{
	public:

		/*
		**	This serves to identify the object class. The ID corresponds to the
		**	variation number (e.g., UNIT_TANK1, UNIT_TANK2, etc.).
		*/
		RTTIType RTTI;
		int ID;

		/*
		**	This is the internal control name of the object. This name does
		**	not change regardless of language specified. This is the name
		**	used in scenario control files and for other text based unique
		**	identification purposes.
		*/
		char IniName[24];

		/*
		**	The translated (language specific) text name number of this object.
		**	This number is used to fetch the object's name from the language
		**	text file. Whenever the name of the object needs to be displayed,
		**	this is used to determine the text string.
		*/
		int FullName;

		AbstractTypeClass(RTTIType rtti, int id, int name, char const * ini);
		AbstractTypeClass(NoInitClass const & ) {};
		~AbstractTypeClass(void) {};

		RTTIType What_Am_I(void) const {return(RTTI);};
		TARGET As_Target(void) const {return(Build_Target(RTTI, ID));};

		virtual COORDINATE Coord_Fixup(COORDINATE coord) const;
		virtual int Full_Name(void) const;
		char const * Name(void) const {return(IniName);}
		void Set_Name(char const * buf) const {
			std::strncpy((char *)IniName, buf, sizeof(IniName));
			((char &)IniName[sizeof(IniName)-1]) = '\0';
		};
		virtual int Get_Ownable(void) const;

		void Code_Pointers(void) {}
		void Decode_Pointers(void) {}
};


#endif // ABSTRACTTYPECLASS_H