#ifndef OBJECTYTPECLASS_H
#define OBJECTYTPECLASS_H

#include "AbstractTypeClass.h"
#include "ex_string.h"
#include "rect.h"
#include "noinitclass.h"
#include "object.h"

/***************************************************************************
**	This the the common base class of game objects. Since these values
**	represent the unchanging object TYPES, this data is initialized at game
**	start and not changed during play. It is "const" data.
*/
class ObjectTypeClass : public AbstractTypeClass
{
	public:
		/*
		**	This is the base name of the graphic data associated with this object
		**	type. If the graphic name is a null string, then there is no graphic
		**	associated with this object type.
		*/
		char GraphicName[_MAX_FNAME];

		/*
		**	Is this object squashable by heavy vehicles?  If it is, then the vehicle
		**	can travel over this object and destroy it in the process.
		*/
		unsigned IsCrushable:1;

		/*
		**	Does this object type NOT show up on radar scans?  If true, then in any
		**	radar display, only the underlying ground will be show, not this object.
		**	Most terrain falls into this category, but only a few special real units/buildings
		**	do.
		*/
		unsigned IsStealthy:1;

		/*
		**	It is legal to "select" some objects in the game. If it is legal to select this
		**	object type then this flag will be true. Selected game objects typically display
		**	a floating health bar and allows special user I/O control.
		*/
		unsigned IsSelectable:1;

		/*
		**	Can this object be the target of an attack or move command?  Typically, only objects
		**	that take damage or can be destroyed are allowed to be a target.
		*/
		unsigned IsLegalTarget:1;

		/*
		**	"Insignificant" objects will not be announced when they are destroyed or when they
		**	appear. Terrain elements and some lesser vehicles have this characteristic.
		*/
		unsigned IsInsignificant:1;

		/*
		**	Is this object immune to normal combat damage?  Rocks and other inert type terrain
		**	object are typically of this type.
		*/
		unsigned IsImmune:1;

		/*
		**	"Sentient" objects are ones that have logic AI processing performed on them. All
		**	vehicles, buildings, infantry, and aircraft are so flagged. Terrain elements also
		**	fall under this category, but only because certain animation effects require this.
		*/
		unsigned IsSentient:1;

		/*
		**	If this object type affects the occupation and collision logic associated with
		**	cells, then this flag will be true. Typically, this characteristic is limited
		**	to buildings, units, terrain objects, and landed aircraft.
		*/
		unsigned IsFootprint:1;

		/*
		**	The defense of this object is greatly affected by the type of armor
		**	it possesses. This value specifies the type of armor.
		*/
		ArmorType Armor;

		/*
		**	This is the maximum strength of this object type.
		*/
		unsigned short MaxStrength;

		/*
		**	These point to the shape imagery for this object type. Since the shape imagery
		**	exists in a separate file, the data is filled in after this object is constructed.
		**	The "mutable" keyword allows easy modification to this otherwise const object.
		*/
		void const * ImageData;

		/*
		**	Points to the dimension data for each shape in the image list. By using this
		**	data, the minimum number of cells will be redrawn when the object changes shape.
		*/
		Rect * DimensionData;

		/*
		**	This points to the radar imagery for this object.
		*/
		void const * RadarIcon;

		//--------------------------------------------------------------------
		ObjectTypeClass(NoInitClass const & x) : AbstractTypeClass(x) {}
		ObjectTypeClass(	RTTIType rtti,
								int id,
								bool is_sentient,
								bool is_stealthy,
								bool is_selectable,
								bool is_legal_target,
								bool is_insignificant,
								bool is_immune,
								bool is_footprint,
								int fullname,
								char const * name
								);

		static void One_Time(void);

		bool Is_Foot(void) const {return(RTTI == RTTI_INFANTRYTYPE || RTTI == RTTI_UNITTYPE || RTTI == RTTI_VESSELTYPE || RTTI == RTTI_AIRCRAFTTYPE);};
		char const * Graphic_Name(void) const {if (GraphicName[0] != '\0') return(GraphicName); return(Name());}
		virtual int Max_Pips(void) const;
		virtual void Dimensions(int &width, int &height) const;
		virtual bool Create_And_Place(CELL , HousesType =HOUSE_NONE) const = 0;
		virtual int Cost_Of(void) const;
		virtual int Time_To_Build(void) const;
		virtual ObjectClass * Create_One_Of(HouseClass *) const = 0;
		virtual short const * Occupy_List(bool placement=false) const;
		virtual short const * Overlap_List(void) const;
		virtual BuildingClass * Who_Can_Build_Me(bool intheory, bool legal, HousesType house) const;
		virtual void const * Get_Cameo_Data(void) const;
		void const * Get_Image_Data(void) const {return ImageData;};
		void const * Get_Radar_Data(void) const {return RadarIcon;};

		#ifdef SCENARIO_EDITOR
		virtual void Display(int, int, WindowNumberType, HousesType) const {};
		#endif

		static void const * SelectShapes;
		static void const * PipShapes;
};


#endif // OBJECTYTPECLASS_H