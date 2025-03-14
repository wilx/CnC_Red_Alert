#ifndef UNITTYPECLASS_H
#define UNITTYPECLASS_H

#include "TechnoTypeClass.h"
#include "ccini.h"
#include "face.h"
#include "unit.h"

/***************************************************************************
**	The various unit types need specific data that is unique to units as
**	opposed to buildings. This derived class elaborates these additional
**	data types.
*/
class UnitTypeClass : public TechnoTypeClass
{
	public:
		/*
		**	If this unit can appear out of a crate, then this flag will be true.
		*/
		unsigned IsCrateGoodie:1;

		/*
		**	Can this unit squash infantry?  If it can then if the player selects
		**	an (enemy) infantry unit as the movement target, it will ride over and
		**	squish the infantry unit.
		*/
		unsigned IsCrusher:1;

		/*
		**	Does this unit go into harvesting mode when it stops on a tiberium
		**	field?  Typically, only one unit does this and that is the harvester.
		*/
		unsigned IsToHarvest:1;

		/*
		**	Some units are equipped with a rotating radar dish. These units have special
		**	animation processing. The rotating radar dish is similar to a turret, but
		**	always rotates and does not affect combat.
		*/
		unsigned IsRadarEquipped:1;

		/*
		**	If this unit has a firing animation, this flag is true. Infantry and some special
		**	vehicles are the ones with firing animations.
		*/
		unsigned IsFireAnim:1;

		/*
		**	Many vehicles have a turret with restricted motion. These vehicles must move the
		**	turret into a locked down position while travelling. Rocket launchers and artillery
		**	are good examples of this kind of unit.
		*/
		unsigned IsLockTurret:1;

		/*
		**	Is this unit of the humongous size?  Harvesters and mobile construction vehicles are
		**	of this size. If the vehicle is greater than 24 x 24 but less than 48 x 48, it is
		**	considered "Gigundo".
		*/
		unsigned IsGigundo:1;

		/*
		** Does this unit have a constant animation (like Visceroid?)
		*/
		unsigned IsAnimating:1;

		/*
		** Does this unit have the ability to jam radar facilities?
		*/
		unsigned IsJammer:1;

		/*
		** Is this unit a mobile gap generator?
		*/
		unsigned IsGapper:1;

		/*
		**	If this unit cannot fire while moving, then this flag will be
		**	true. Such a unit must stop and stabilize for a bit before it
		**	can fire.
		*/
		unsigned IsNoFireWhileMoving:1;

		/*
		**	This value represents the unit class. It can serve as a unique
		**	identification number for this unit class.
		*/
		UnitType Type;

		/*
		**	This is the distance along the centerline heading in the direction the body
		**	is facing used to reach the center point of the turret. This distance is
		**	in leptons.
		*/
		signed char TurretOffset;

		/*
		**	This value is used to provide the unit with a default mission order when
		**	first created. Usually, this is a resting or idle type of order.
		*/
		MissionType Mission;

		/*
		**	This is the default explosion to use when this vehicle is destroyed.
		*/
		AnimType Explosion;

		/*
		**	The width or height of the largest dimension for this unit.
		*/
		int MaxSize;

		/*
		**	This is the explicit unit class constructor.
		*/
		UnitTypeClass(NoInitClass const & x) : TechnoTypeClass(x) {}
		UnitTypeClass	(
						UnitType type,
						int name,
						char const * ininame,
						AnimType exp,
						RemapType remap,
						int verticaloffset,
						int primaryoffset,
						int primarylateral,
						int secondaryoffset,
						int secondarylateral,
						bool is_goodie,
						bool is_nominal,
						bool is_crusher,
						bool is_harvest,
						bool is_stealthy,
						bool is_insignificant,
						bool is_turret_equipped,
						bool is_radar_equipped,
						bool is_fire_anim,
						bool is_lock_turret,
						bool is_gigundo,
						bool is_animating,
						bool is_jammer,
						bool is_gapper,
						int rotation,
						int toffset,
						MissionType order
						);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static UnitType From_Name(char const * name);
		static UnitTypeClass & As_Reference(UnitType type);
		static void Init(TheaterType ) {};
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual bool Read_INI(CCINIClass & ini);
		virtual void Dimensions(int &width, int &height) const;
		virtual bool Create_And_Place(CELL cell, HousesType house) const;
		virtual UnitClass * Create_One_Of(HouseClass * house) const;
		virtual int Max_Pips(void) const;

		void Turret_Adjust(DirType dir, int & x, int & y) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house) const;
		#endif

		/*
		**	The animation stage list for harvester dumping into the refinery.
		*/
		static const int Harvester_Dump_List[22];

		/*
		**	The animatino stage list for harvester loading up on ore.
		*/
		static const int Harvester_Load_List[9];

		/*
		**	The number of animation stages when the harvester is loading
		**	up on ore in the field.
		*/
		static const int Harvester_Load_Count;
};

#endif // UNITTYPECLASS_H