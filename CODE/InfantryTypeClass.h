#ifndef INFANTRYTYPECLASS_H
#define INFANTRYTYPECLASS_H

#include "TechnoTypeClass.h"
#include "ccini.h"

/***************************************************************************
**	The various unit types need specific data that is unique to units as
**	opposed to buildings. This derived class elaborates these additional
**	data types.
*/
class InfantryTypeClass : public TechnoTypeClass
{
	public:

		/*
		**	If this civilian infantry type is female, then this flag
		**	will be true. This information is used to get the correct
		**	voice response.
		*/
		unsigned IsFemale:1;

		/*
		**	Does this infantry unit have crawling animation? If not, then this
		**	means that the "crawling" frames are actually running animation frames.
		*/
		unsigned IsCrawling:1;

		/*
		**	For those infantry types that can capture buildings, this flag
		**	will be set to true. Typically, this is the engineer.
		*/
		unsigned IsCapture:1;

		/*
		**	For infantry types that will run away from any damage causing
		**	events, this flag will be true. Typically, this is so for all
		**	civilians as well as the flame thrower guys.
		*/
		unsigned IsFraidyCat:1;

		/*
		**	This flags whether this infantry is actually a civilian. A
		**	civilian uses different voice responses, has less ammunition,
		**	and runs from danger more often.
		*/
		unsigned IsCivilian:1;

		/*
		**	If the infantry unit is equipped with C4 explosives, then this
		**	flag will be true. Such infantry can enter and destroy enemy
		**	buildings.
		*/
		unsigned IsBomber:1;

		/*
		** This flags whether this infantry is actually a dog.  A dog
		** uses different voice responses, has no ammo, and runs instead
		** of walks to attack.
		*/
		unsigned IsDog:1;

		/*
		** This flag specifies whether this infantry type should use the
		** override remap table, instead of the house remap table.  This is
		** used to turn the two civilian animations into a veritable smorgasbord
		** of civilian types, for example.
		*/
		unsigned IsRemapOverride:1;

		/*
		**	This value represents the unit class. It can serve as a unique
		**	identification number for this unit class.
		*/
		InfantryType Type;

		/*
		**	When this infantry unit is loaded onto a transport, then this
		**	is the pip shape to use. Primarily, this is a color control.
		*/
		PipEnum Pip;

		/*
		**	This is an array of the various animation frame data for the actions that
		**	the infantry may perform.
		*/
		DoInfoStruct const * DoControls;

		/*
		**	There are certain units with special animation sequences built into the
		**	shape file. These values tell how many frames are used for the firing animation.
		*/
		char FireLaunch;
		char ProneLaunch;

		/*
		** This is a pointer to the special override remap table, which is
		** used only in conjunction with the IsRemapOverride flag, and is
		** primarily used for the civilians.
		*/
		unsigned char const * OverrideRemap;

		/*
		**	This is the explicit unit class constructor.
		*/
		InfantryTypeClass(NoInitClass const & x) : TechnoTypeClass(x) {}
		InfantryTypeClass	(
						InfantryType type,
						int name,
						char const * ininame,
						int verticaloffset,
						int primaryoffset,
						bool is_female,
						bool is_crawling,
						bool is_civilian,
						bool is_remap_override,
						bool is_nominal,
						bool is_theater,
						PipEnum pip,
						DoInfoStruct const * controls,
						int firelaunch,
						int pronelaunch,
						unsigned char const * override_remap);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static InfantryType From_Name(char const * name);
		static InfantryTypeClass & As_Reference(InfantryType type);
		static void Init(TheaterType ) {};
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual bool Read_INI(CCINIClass & ini);
		virtual void Dimensions(int & width, int & height) const;
		virtual bool Create_And_Place(CELL cell, HousesType house) const;
		virtual ObjectClass * Create_One_Of(HouseClass * house) const;
		virtual short const * Occupy_List(bool placement=false) const;
		virtual int Full_Name(void) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house) const;
		#endif
};

#endif // INFANTRYTYPECLASS_H
