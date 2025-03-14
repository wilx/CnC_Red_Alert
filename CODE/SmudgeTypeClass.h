#ifndef SMUDGETYPECLASS_H
#define SMUDGETYPECLASS_H

#include "ObjectTypeClass.h"

/****************************************************************************
**	This type elaborates the various "smudge" effects that can occur. Smudges are
**	those elements which are on top off all the ground icons, but below anything
**	that is "above" it. This includes scorch marks, craters, and infantry bodies.
**	Smudges, be definition, contain transparency. The are modifiers to underlying
**	terrain imagery.
*/
class SmudgeTypeClass : public ObjectTypeClass
{
	public:
		/*
		**	What overlay is this.
		*/
		SmudgeType Type;

		/*
		**	Some smudges are larger than one cell. If this is the case, then
		**	these dimensions specify the number of cells wide and tall the
		**	smudge is.
		*/
		int Width;
		int Height;

		/*
		**	Is this smudge a crater type? If so, then a second crater can be added to
		**	this smudge so that a more cratered landscape results.
		*/
		unsigned IsCrater:1;

		/*
		**	Is this overlay used as the attached road piece for buildings (bib)?
		*/
		unsigned IsBib:1;

		//----------------------------------------------------------
		SmudgeTypeClass(NoInitClass const & x) : ObjectTypeClass(x) {}
		SmudgeTypeClass(
			SmudgeType smudge,
			char const * ininame,
			int fullname,
			int width,
			int height,
			bool isbib,
			bool iscrater
			);

		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static void Init_Heap(void);
		static SmudgeType From_Name(char const * name);
		static SmudgeTypeClass & As_Reference(SmudgeType type);
		static void Init(TheaterType);
		static void One_Time(void);
		static void Prep_For_Add(void);

		virtual bool Create_And_Place(CELL cell, HousesType house=HOUSE_NONE) const;
		virtual ObjectClass * Create_One_Of(HouseClass *) const;
		virtual short const * Occupy_List(bool placement=false) const;
		virtual short const * Overlap_List(void) const {return Occupy_List();};
		virtual void Draw_It(int x, int y, int data) const ;

		#ifdef SCENARIO_EDITOR
		virtual void Display(int x, int y, WindowNumberType window, HousesType house=HOUSE_NONE) const;
		#endif
};

#endif // SMUDGETYPECLASS_H