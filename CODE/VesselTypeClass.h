#ifndef VESSELTYPECLASS_H
#define VESSELTYPECLASS_H

#include "TechnoTypeClass.h"
#include "face.h"
#include "vessel.h"

/***************************************************************************
**	This specifies the constant attribute data associated with naval
**	vessels.
*/
class VesselTypeClass : public TechnoTypeClass
{
	public:
		/*
		**	Does this unit have only 8 facings? Special test units have limited
		**	facings.
		*/
		unsigned IsPieceOfEight:1;

		/*
		**	This value represents the unit class. It can serve as a unique
		**	identification number for this unit class.
		*/
		VesselType Type;

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
		VesselTypeClass(NoInitClass const & x) : TechnoTypeClass(x) {}
		VesselTypeClass	(
						VesselType type,
						int name,
						char const * ininame,
						AnimType exp,
						int verticaloffset,
						int primaryoffset,
						int primarylateral,
						int secondaryoffset,
						int secondarylateral,
						bool is_eight,
						bool is_nominal,
						bool is_turret_equipped,
						int rotation,
						int toffset
						);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static VesselType From_Name(char const * name);
		static VesselTypeClass & As_Reference(VesselType type);
		static void Init(TheaterType ) {};
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual void Dimensions(int &width, int &height) const;
		virtual bool Create_And_Place(CELL cell, HousesType house) const;
		virtual VesselClass * Create_One_Of(HouseClass * house) const;
		virtual int Max_Pips(void) const;
		virtual short const * Overlap_List(void) const;

		void Turret_Adjust(DirType dir, int & x, int & y) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house) const;
		#endif
};

#endif // VESSELTYPECLASS_H