#ifndef OVERLAYTYPECLASS_H
#define OVERLAYTYPECLASS_H

#include "ObjectTypeClass.h"

/****************************************************************************
**	This controls the overlay object types. These object types include walls
**	and concrete. They are always considered to be one icon in size and
**	are processed on an icon by icon basis. This is different from normal
**	templates which can be an arbitrary size. Other than this they are
**	mostly similar to normal templates but with some characteristics of
**	structures (they can be destroyed).
*/
class OverlayTypeClass: public ObjectTypeClass
{
	public:
		/*
		**	What overlay is this.
		*/
		OverlayType Type;

		/*
		**	What type of ground does this make the cell it occupies?
		*/
		LandType Land;

		/*
		** If this overlay is a wall, how many stages of destruction are there
		** for this wall type? i.e. sandbags = 2, concrete = 4, etc.
		*/
		int DamageLevels;

		/*
		** If this overlay is a wall, what amount of damage is necessary
		** before the wall takes damage?
		*/
		int DamagePoints;

		/*
		**	Is this overlay graphic theater specific. This means that if there is
		**	custom art for this overlay that varies between different theaters, then
		**	this flag will be true.
		*/
		unsigned IsTheater:1;

		/*
		**	Is this a wall type overlay?  Wall types change their shape
		**	depending on the existence of adjacent walls of the same type.
		*/
		unsigned IsWall:1;

		/*
		**	If this overlay is actually a wall and this wall type is tall enough that
		**	normal ground based straight line weapons will be blocked by it, then this
		**	flag will be true. Brick fences are typical of this type.
		*/
		unsigned IsHigh:1;

		/*
		**	If this overlay represents harvestable tiberium, then this flag
		**	will be true.
		*/
		unsigned IsTiberium:1;

		/*
		**	If this is a wall that is made of wood, then this flag will be
		**	true. Such walls are affected by fire damage.
		*/
		unsigned IsWooden:1;

		/*
		**	Is this a crate? If it is, then goodies may come out of it.
		*/
		unsigned IsCrate:1;

		/*
		**	If this is true, then the overlay will not show up on the radar map.
		*/
		unsigned IsRadarVisible:1;

		//----------------------------------------------------------
		OverlayTypeClass(NoInitClass const & x) : ObjectTypeClass(x) {}
		OverlayTypeClass(
			OverlayType iconset,
			char const * ininame,
			int  fullname,
			LandType ground,
			int  damagelevels,
			int  damagepoints,
			bool isradarinvisible,
			bool iswooden,
			bool istarget,
			bool iscrushable,
			bool istiberium,
			bool high,
			bool theater,
			bool iswall,
			bool iscrate);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static OverlayType From_Name(char const * name);
		static OverlayTypeClass & As_Reference(OverlayType type);
		static void Init(TheaterType);
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual COORDINATE Coord_Fixup(COORDINATE coord) const;
		virtual bool Create_And_Place(CELL cell, HousesType house=HOUSE_NONE) const;
		virtual ObjectClass * Create_One_Of(HouseClass *) const;
		virtual short const * Occupy_List(bool placement=false) const;
		virtual void Draw_It(int x, int y, int data) const;
		virtual unsigned char * Radar_Icon(int data) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house=HOUSE_NONE) const;
		#endif
};


#endif // OVERLAYTYPECLASS_H