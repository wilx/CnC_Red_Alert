#ifndef TERRAINTYPECLASS_H
#define TERRAINTYPECLASS_H

#include "ObjectTypeClass.h"
#include "terrain.h"

/****************************************************************************
**	These are the different TYPES of terrain objects. Every terrain object must
**	be one of these types.
*/
class TerrainTypeClass : public ObjectTypeClass
{
	public:
		/*
		**	Which terrain object does this class type represent.
		*/
		TerrainType Type;

		/*
		**	This is the coordinate offset (from upper left) of where the center base
		**	position of the terrain object lies. For trees, this would be the base of
		**	the trunk. This is used for sorting purposes.
		*/
		COORDINATE CenterBase;

		/*
		**	This is the bitfield control that tells which theater this terrain object is
		**	valid for. If the bit (1 << TheaterType) is true, then this terrain object
		**	is allowed.
		*/
		int Theater;

		/*
		**	Does this terrain object get placed on the water instead of the ground?
		*/
		unsigned IsWaterBased:1;

		//----------------------------------------------------------------
		TerrainTypeClass(NoInitClass const & x) : ObjectTypeClass(x) {}
		TerrainTypeClass(
				TerrainType terrain,
				int theater,
				COORDINATE centerbase,
				bool is_immune,
				bool is_water,
				char const * ininame,
				int fullname,
				short const * occupy,
				short const * overlap);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static TerrainType From_Name(char const * name);
		static TerrainTypeClass & As_Reference(TerrainType type);
		static void Init(TheaterType theater = THEATER_TEMPERATE);
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual COORDINATE Coord_Fixup(COORDINATE coord) const;
		virtual bool Create_And_Place(CELL cell, HousesType house) const;
		virtual TerrainClass * Create_One_Of(HouseClass *) const;
		virtual short const * Occupy_List(bool placement=false) const;
		virtual short const * Overlap_List(void) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house=HOUSE_NONE) const;
		#endif

	private:
		short const * Occupy;
		short const * Overlap;
};

#endif // TERREINTYPECLASS_H