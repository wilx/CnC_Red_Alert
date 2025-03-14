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

#ifndef HOUSETYPECLASS_H
#define HOUSETYPECLASS_H

#include "AbstractTypeClass.h"
#include "ex_string.h"
#include "fixed.h"
#include "noinitclass.h"
#include "ccini.h"

/**********************************************************************
**	Each house has certain unalienable characteristics. This structure
**	elaborates these.
*/
class HouseTypeClass : public AbstractTypeClass
{
	public:
		/*
		**	This is the house number (enum). This is a unique identification
		**	number for the house.
		*/
		HousesType House;

		/*
		**	This is the filename suffix to use when creating a house specific
		**	file name. It is three characters long.
		*/
		char Suffix[_MAX_EXT];

		/*
		**	This is the "lemon percentage" to use when determining if a particular
		**	object owned by this house is to be flagged as a "lemon". Objects so
		**	flagged have a greater break-down chance. The percentage is expressed
		**	as a fixed point number with 0x000 meaning 0% and 0x100 meaning 100%.
		*/
		unsigned Lemon;

		/*
		**	This points to the default remap table for this house.
		*/
		PlayerColorType RemapColor;

		/*
		**	This is a unique ASCII character used when constructing filenames. It
		**	serves a similar purpose as the "Suffix" element, but is only one
		**	character long.
		*/
		char Prefix;

		/*
		**	This controls the various general adjustments to the house owned
		**	unit and building ratings. The default value for these ratings is
		**	a fixed point number of 1.0.
		*/
		fixed FirepowerBias;
		fixed GroundspeedBias;
		fixed AirspeedBias;
		fixed ArmorBias;
		fixed ROFBias;
		fixed CostBias;
		fixed BuildSpeedBias;

		//------------------------------------------------------------------------
		HouseTypeClass(NoInitClass const & x) : AbstractTypeClass(x) {}
		HouseTypeClass(HousesType house,
							char const * ini,
							int fullname,
							char const * ext,
							int lemon,
							PlayerColorType remapcolor,
							char prefix);

		unsigned char const * Remap_Table(void) const;

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static HousesType From_Name(char const * name);
		static HouseTypeClass & As_Reference(HousesType house);
		static void One_Time(void);
		static void Init_Heap(void);

		virtual bool Read_INI(CCINIClass & ini);
};

#endif // HOUSETYPECLASS_H