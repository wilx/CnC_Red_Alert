#ifndef TEMPLATETYPECLASS_H
#define TEMPLATETYPECLASS_H

#include "ObjectTypeClass.h"

/****************************************************************************
**	The tile type objects are controlled by this class. It specifies the form
**	of the tile set for the specified object as well as other related datum.
**	It is derived from the ObjectTypeClass solely for the purpose of scenario
**	editing and creation.
*/
class TemplateTypeClass: public ObjectTypeClass
{
	public:
		/*
		**	What template is this.
		*/
		TemplateType Type;

		/*
		**	A bitfield container that indicates which theaters this template is allowed
		**	in. A bit set in the (1<<TheaterType) position indicates the template is legal
		**	in that particular theater.
		*/
		unsigned char Theater;

		/*
		**	Raw dimensions of this template (in icons).
		*/
		unsigned char Width,Height;

		//----------------------------------------------------------
		TemplateTypeClass(NoInitClass const & x) : ObjectTypeClass(x) {};
		TemplateTypeClass(
			TemplateType iconset,
			int theater,
			char const * ininame,
			int fullname);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static TemplateType From_Name(char const * name);
		static TemplateTypeClass & As_Reference(TemplateType type);
		static void Init(TheaterType theater);
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual COORDINATE Coord_Fixup(COORDINATE coord) const;
		virtual bool Create_And_Place(CELL cell, HousesType house=HOUSE_NONE) const;
		virtual ObjectClass * Create_One_Of(HouseClass *) const;
		virtual short const * Occupy_List(bool placement=false) const;
		LandType Land_Type(int icon) const;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house=HOUSE_NONE) const;
		#endif
};

#endif // TEMPLATETYPECLASS_H