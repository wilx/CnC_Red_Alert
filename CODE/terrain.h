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

/* $Header: /CounterStrike/TERRAIN.H 1     3/03/97 10:25a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : TERRAIN.H                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : April 29, 1994                                               *
 *                                                                                             *
 *                  Last Update : April 29, 1994   [JLB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef TERRAIN_H
#define TERRAIN_H

#include	"object.h"
#include	"type.h"

class TerrainTypeClass;

/****************************************************************************
**	Each type of terrain has certain pieces of static information associated
**	with it. This class elaborates this data.
*/
class TerrainClass : public ObjectClass, public StageClass
{
	public:
		/*
		**	This points to the constant terrain data (for this type) that gives this
		**	terrain object its character.
		*/
		CCPtr<TerrainTypeClass> Class;

  		/*
		**	Constructor for terrain object class.
		*/
		static void * operator new(size_t size)  throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void *ptr);
		TerrainClass(TerrainType id, CELL cell);
		TerrainClass(NoInitClass const & x) : ObjectClass(x), Class(x), StageClass(x) {};
		virtual ~TerrainClass(void);
		operator TerrainType(void) const;

		static void Init(void);

		/*
		**	Terrain specific support functions.
		*/
		void Start_To_Crumble(void);

		/*
		**	Query functions.
		*/
		virtual ObjectTypeClass const & Class_Of(void) const;

		/*
		**	Coordinate inquiry functions. These are used for both display and
		**	combat purposes.
		*/
		virtual COORDINATE Center_Coord(void) const;
		virtual COORDINATE Render_Coord(void) const {return Coord;};
		virtual COORDINATE Sort_Y(void) const;
		virtual COORDINATE Target_Coord(void) const;

		/*
		**	Object entry and exit from the game system.
		*/
		virtual bool Unlimbo(COORDINATE coord, DirType dir=DIR_N);
		virtual bool Limbo(void);
		virtual MoveType Can_Enter_Cell(CELL cell, FacingType facing = FACING_NONE) const;

		/*
		**	Display and rendering support functionality. Supports imagery and how
		**	object interacts with the map and thus indirectly controls rendering.
		*/
		virtual void Draw_It(int x, int y, WindowNumberType window) const;
		virtual bool Mark(MarkType mark=MARK_CHANGE);
		unsigned char *Radar_Icon(CELL cell);

		/*
		**	User I/O.
		*/
		virtual void Clicked_As_Target(int) {};

		/*
		**	Combat related.
		*/
		virtual void Fire_Out(void);
		virtual bool Catch_Fire(void);
		virtual ResultType Take_Damage(int & damage, int distance, WarheadType warhead, TechnoClass * source, bool forced=false);

		/*
		**	AI.
		*/
		virtual void AI(void);

		/*
		**	Scenario and debug support.
		*/
		#ifdef CHEAT_KEYS
		virtual void Debug_Dump(MonoClass *mono) const;
		#endif

		/*
		**	File I/O.
		*/
		static void Read_INI(CCINIClass & ini);
		static void Write_INI(CCINIClass & ini);
		static char const *INI_Name(void) {return "TERRAIN";};
		bool Load(Straw & file);
		bool Save(Pipe & file) const;

	private:

		/*
		**	If this terrain object is on fire, then this flag will be true.
		*/
		unsigned IsOnFire:1;

		/*
		**	Is this a terrain object that undergoes crumbling animation and it is
		**	in fact crumbling at this time?
		*/
		unsigned IsCrumbling:1;
};

#endif
