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

#ifndef BUILDINGTYPECLASS_H
#define BUILDINGTYPECLASS_H

#include "AnimControlType.h"
#include "TechnoTypeClass.h"
#include "building.h"

/***************************************************************************
**	Building types need some special information custom to buildings. This
**	is a derived class that elaborates these additional data elements.
*/
class BuildingTypeClass : public TechnoTypeClass {
	public:
		/*
		**	Is this building allowed to be considered for building adjacency
		**	checking? If false, then building off of (or adjacent to) this building
		**	is not considered.
		*/
		unsigned IsBase:1;

		/*
		** If this building is a fake, this flag will be set.
		*/
		unsigned IsFake:1;

		/*
		**	This flag controls whether the building is equiped with a dirt
		**	bib or not. A building with a bib has a dirt patch automatically
		**	attached to the structure when it is placed.
		*/
		unsigned IsBibbed:1;

		/*
		**	If this building is a special wall type, such that it exists as a building
		**	for purposes of construction but transforms into an overlay wall object when
		**	it is placed on the map, then this flag will be true.
		*/
		unsigned IsWall:1;

		/*
		**	Buildings can have either simple or complex damage stages. If simple,
		**	then the second to the last frame is the half damage stage, and the last
		**	frame is the complete damage stage. For non-simple damage, buildings
		**	have a complete animation set for damaged as well as undamaged condition.
		**	Turrets, oil pumps, and repair facilities are a few examples.
		*/
		unsigned IsSimpleDamage:1;

		/*
		**	Certain building types can be captures by enemy infantry. For those
		**	building types, this flag will be true. Typically, military or hardened
		**	structures such as turrets cannot be captured.
		*/
		unsigned IsCaptureable:1;

		/*
		**	If this building really only has cosmetic idle animation, then this flag will be
		**	true if this animation should run at a relatively constant rate regardless of game
		**	speed setting.
		*/
		unsigned IsRegulated:1;

		/*
		**	Does this building require power to function? Usually, this isn't the case. The building
		**	normally either has no effect by power level or is gradually reduced in effectiveness. This
		**	flag is for those buildings that completely cease to function when the power drops below
		**	full.
		*/
		unsigned IsPowered:1;

		/*
		**	If this flag is true, then the building cannot be sold even if it could have been built. This
		**	is especially useful for mines which can be built but cannot be sold.
		*/
		unsigned IsUnsellable:1;

		/*
		**	This is the direction (from the center cell) of the building in order to find a
		**	legitimate foundation square. This location will be used for targeting and capture
		**	move destination purposes.
		*/
		FacingType FoundationFace;

		/*
		**	Adjacent distance for building next to.
		*/
		int Adjacent;

		/*
		**	This flag specifies the type of object this factory building can "produce". For non
		**	factory buildings, this value will be RTTI_NONE.
		*/
		RTTIType ToBuild;

		/*
		**	For building that produce ground units (infantry and vehicles), there is a default
		**	exit point defined. This point is where the object is first placed on the map.
		**	Typically, this is located next to a door. The unit will then travel on to a clear
		**	terrain area and enter normal game processing.
		*/
		COORDINATE ExitCoordinate;

		/*
		**	When determine which cell to head toward when exiting a building, use the
		**	list elaborated by this variable. There are directions of exit that are
		**	more suitable than others. This list is here to inform the system which
		**	directions those are.
		*/
		short const * ExitList;

		/*
		**	This is the structure type identifier. It can serve as a unique
		**	identification number for building types.
		*/
		StructType Type;

		/*
		**	This is the starting facing to give this building when it first
		**	gets constructed. The facing matches the final stage of the
		**	construction animation.
		*/
		DirType StartFace;

		/*
		**	This is the Tiberium storage capacity of the building. The sum of all
		**	building's storage capacity is used to determine how much Tiberium can
		**	be accumulated.
		*/
		int Capacity;

		/*
		**	Each building type produces and consumes power. These values tell how
		**	much.
		*/
		int Power;
		int Drain;

		/*
		**	This is the size of the building. This size value is a rough indication
		**	of the building's "footprint".
		*/
		BSizeType Size;

        using AnimControlType = ::AnimControlType;

		AnimControlType Anims[BSTATE_COUNT];

		/*---------------------------------------------------------------------------
		**	This is the building type explicit constructor.
		*/
		BuildingTypeClass(NoInitClass const & x) : TechnoTypeClass(x) {}
		BuildingTypeClass	(
						StructType type,
						int name,
						char const * ininame,
						FacingType foundation,
						COORDINATE exitpoint,
						RemapType remap,
						int verticaloffset,
						int primaryoffset,
						int primarylateral,
						bool is_fake,
						bool is_regulated,
						bool is_nominal,
						bool is_wall,
						bool is_simpledamage,
						bool is_stealthy,
						bool is_selectable,
						bool is_legal_target,
						bool is_insignificant,
						bool is_theater,
						bool is_turret_equipped,
						bool is_remappable,
						RTTIType tobuild,
						DirType sframe,
						BSizeType size,
						short const * exitlist,
						short const * sizelist,
						short const * overlap
						);
		operator StructType(void) const {return(Type);};

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static BuildingTypeClass & As_Reference(StructType type);
		static StructType From_Name(char const * name);
		static void Init(TheaterType theater);
		static void One_Time(void);
		static void Prep_For_Add(void);

		int Width(void) const;
		int Height(bool bib=false) const;

		virtual int Full_Name(void) const;
		virtual bool Read_INI(CCINIClass & ini);
		bool Flush_For_Placement(CELL cell, HouseClass * house) const;
		virtual int Cost_Of(void) const;
		virtual COORDINATE Coord_Fixup(COORDINATE coord) const;
		virtual int Max_Pips(void) const;
		virtual void Dimensions(int &width, int &height) const;
		virtual bool Create_And_Place(CELL cell, HousesType house) const;
		virtual BuildingClass * Create_One_Of(HouseClass * house) const;
		virtual short const * Occupy_List(bool placement=false) const;
		virtual short const * Overlap_List(void) const;
		virtual void const * Get_Buildup_Data(void) const {return(BuildupData);};

		bool Is_Factory(void) const {return(ToBuild != RTTI_NONE);}
		virtual int Raw_Cost(void) const;
		bool Bib_And_Offset(SmudgeType & bib, CELL & cell) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house) const;
		#endif

		/*
		**	Special overlay for the weapons factory.
		*/
		static void const * WarFactoryOverlay;

	private:

		/*
		**	This is a pointer to a list of offsets (from the upper left corner) that
		**	are used to indicate the building's "footprint". This footprint is used
		**	to determine building placement legality and terrain passibility.
		*/
		short const * OccupyList;

		/*
		**	Buildings can often times overlap a cell but not actually "occupy" it for
		**	purposes of movement. This points to a list of offsets that indicate which
		**	cells the building has visual overlap but does not occupy.
		*/
		short const * OverlapList;

		/*
		**	The construction animation graphic data pointer is
		**	pointed to by this element.
		*/
		void const * BuildupData;

		void Init_Anim(BStateType state, int start, int count, int rate) const;
};

#endif // BUILDINGTYPECLASS_H