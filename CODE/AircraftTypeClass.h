#ifndef AIRCRAFTTYPECLASS_H
#define AIRCRAFTTYPECLASS_H

#include "TechnoTypeClass.h"
#include "aircraft.h"

/****************************************************************************
**	The various aircraft types are controlled by object types of
**	this class.
*/
class AircraftTypeClass : public TechnoTypeClass
{
	public:

		/*
		**	Fixed wing aircraft (ones that cannot hover) have this flag set to true.
		**	Such aircraft will not vary speed while it is flying.
		*/
		unsigned IsFixedWing:1;

		/*
		**	Can this aircraft land?  If it can land it is presumed to be controllable by the player.
		*/
		unsigned IsLandable:1;

		/*
		**	Does this aircraft have a rotor blade (helicopter) type propulsion?
		*/
		unsigned IsRotorEquipped:1;	// Is a rotor attached?

		/*
		**	Is there a custom rotor animation stage set for each facing of the aircraft?
		*/
		unsigned IsRotorCustom:1;	// Custom rotor sets for each facing?

		/*
		**	This is the kind of aircraft identifier number.
		*/
		AircraftType Type;

		/*
		**	This specifies the default mission order for this aircraft. Some aircraft default
		**	to guard mode (e.g., helicopters) while some default to attack mode (e.g., bombers).
		*/
		MissionType Mission;

		/*
		**	This is the preferred landing building. The aircraft will try to land at the
		**	building of this type.
		*/
		StructType Building;

		/*
		** This is the final approach speed of this aircraft type for landing
		** at an airfield.  Most aircraft hit it at full speed, but the MIG is
		** an example of a plane that needs a slower approach speed to hit the
		** airfield.
		*/
		int LandingSpeed;

		AircraftTypeClass(NoInitClass const & x) : TechnoTypeClass(x) {}
		AircraftTypeClass(
				AircraftType airtype,
				int name,
				char const * ininame,
				int verticaloffset,
				int primaryoffset,
				int primarylateral,
				bool is_fixedwing,
				bool is_rotorequipped,
				bool is_rotorcustom,
				bool is_landable,
				bool is_stealthy,
				bool is_selectable,
				bool is_legal_target,
				bool is_insignificant,
				bool is_immune,
				StructType building,
				int landingspeed,
				int rotation,
				MissionType deforder);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static AircraftType From_Name(char const * name);
		static AircraftTypeClass & As_Reference(AircraftType a);
		static void Init(TheaterType ) {};
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual void Dimensions(int &width, int &height) const;
		virtual bool Create_And_Place(CELL, HousesType) const;
		virtual AircraftClass * Create_One_Of(HouseClass * house) const;
		virtual short const * Occupy_List(bool placement=false) const;
		virtual short const * Overlap_List(void) const;
		virtual int Max_Pips(void) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house) const;
		#endif

		static void const * LRotorData;
		static void const * RRotorData;
};

#endif // AIRCRAFTTYPECLASS_H