#ifndef TECHNOTYPECLASS_H
#define TECHNOTYPECLASS_H

#include "ObjectTypeClass.h"
#include "weapon.h"

/***************************************************************************
**	This class is the common data for all objects that can be owned, produced,
** or delivered as reinforcements. These are objects that typically contain
**	crews and weapons -- the fighting objects of the game.
*/
class TechnoTypeClass : public ObjectTypeClass
{
	public:

		/*
		**	This controls how this object type is remapped when it is displayed
		**	in the sidebar.
		*/
		RemapType Remap;

		/*
		**	Is this object ownable by all sides in a multiplayer game? There are some
		**	special case objects that need this override ability.
		*/
		unsigned IsDoubleOwned:1;

		/*
		**	If this object should be completely and always invisible to the enemy, then
		**	this flag will be true.
		*/
		unsigned IsInvisible:1;

		/*
		**	If this object can serve as a good leader for a group selected
		**	series of objects, then this flag will be true. Unarmed or
		**	ability challenged units do not make good leaders. This flag is
		**	also used to indicate the primary factory when dealing with
		**	buildings.
		*/
		unsigned IsLeader:1;

		/*
		**	Does this object have the ability to detect the presence of a nearby
		**	cloaked object?
		*/
		unsigned IsScanner:1;

		/*
		**	If this object is always given its proper name rather than a generic
		**	name, then this flag will be true. Typically, civilians and Dr. Moebius
		**	fall under this category.
		*/
		unsigned IsNominal:1;

		/*
		**	If the artwork for this object (only for generics) is theater specific, then
		**	this flag will be true. Civilian buildings are a good example of this.
		*/
		unsigned IsTheater:1;

		/*
		**	Does this object type contain a rotating turret?  Gun emplacements, SAM launchers,
		**	and many vehicles contain a turret. If a turret is present, special rendering and
		**	combat logic must be performed.
		*/
		unsigned IsTurretEquipped:1;

		/*
		**	Certain objects can be repaired. For buildings, they repair "in place". For units,
		**	they must travel to a repair center to be repaired. If this flag is true, then
		**	allow the player or computer AI to repair the object.
		*/
		unsigned IsRepairable:1;

		/*
		**	Does this object contain a crew?  If it does, then when the object is destroyed, there
		**	is a distinct possibility that infantry will "pop out". Only units with crews can
		**	become "heros".
		*/
		unsigned IsCrew:1;

		/*
		**	This tells whether this unit should EVER be remapped when it is displayed
		**	on the tactical map. Normally, the unit is remapped, but for certain civilian
		**	object, remapping is not to be performed, regardless of owner.
		*/
		unsigned IsRemappable:1;

		/*
		** Is the unit capable of cloaking?  Only Stealth Tank can do so now.
		*/
		unsigned IsCloakable:1;

		/*
		**	Can this object self heal up to half strength? Mammoth tanks from C&C had this
		**	feature.
		*/
		unsigned IsSelfHealing:1;

		/*
		**	If this object explodes violently when destroyed, then this flag will be true.
		**	The type of explosion is based on the warhead type and the damage generated
		**	corresponds to the full strength of the object.
		*/
		unsigned IsExploding:1;

		/*
		**	This specifies the zone that an object of this type should recognize. Zones
		**	of this type or lower will be considered "possible to travel to".
		*/
		MZoneType MZone;

		/*
		**	When determining threat, the range can be overridden to be the value
		**	specified here. Otherwise, the range for enemy scan is equal to the
		**	longest weapon range the object has. If the value is zero, then the
		**	weapon range is used.
		*/
		LEPTON ThreatRange;

		/*
		**	If this is a transporter object (e.g., hovercraft, chinook, APC), then this
		**	value specifies the maximum number of passengers it may carry.
		*/
		int MaxPassengers;

		/*
		**	Most objects have the ability to reveal the terrain around themselves.
		**	This sight range (expressed in cell distance) is specified here. If
		**	this value is 0, then this unit never reveals terrain. Bullets are
		**	typically of this nature.
		*/
		int SightRange;

		/*
		**	This is the credit cost to produce this object (presuming production is
		**	allowed).
		*/
		int Cost;

		/*
		**	The tech level that this object can be produced at.
		*/
		unsigned Level;

		/*
		**	This specifies the building prerequisites required before an object
		**	of this type can be produced.
		*/
		long Prerequisite;

		/*
		**	The risk and reward values are used to determine targets and paths
		**	toward targets. When heading toward a target, a path of least
		**	risk will be followed. When picking a target, the object of
		**	greatest reward will be selected. The values assigned are
		** arbitrary.
		*/
		int Risk,Reward;

		/*
		**	This value indicates the maximum speed that this object can achieve.
		*/
		MPHType MaxSpeed;

		/*
		**	This indicates the speed (locomotion) type for this unit. Through this
		**	value the movement capabilities are deduced.
		*/
		SpeedType Speed;

		/*
		**	This is the maximum number of ammo shots this object can hold. If
		**	this number is -1, then this indicates unlimited ammo.
		*/
		int MaxAmmo;

		/*
		**	This is a bit field representing the houses that are allowed to
		**	own (by normal means) this particular object type. This value is
		**	typically used in production contexts. It is possible for a side
		**	to take possession of an object type otherwise not normally allowed.
		**	This event usually occurs as a result of capture.
		*/
		long Ownable;

		/*
		**	This is the small icon image that is used to display the object in
		**	the sidebar for construction selection purposes.
		*/
		void const * CameoData;

		/*
		**	The number of animation frames allotted to rotation is specified here.
		**	For an object that has no rotation, this value will be 1. For normal
		**	vehicles this value will be 32. There are some special case units that
		**	have intermediate rotation frames.
		*/
		int Rotation;

		/*
		**	This is the rotational speed of the object. This value represents the
		**	turret or body rotation speed expresses as 360/256ths rotation steps per
		**	game tick.
		*/
		int ROT;

		/*
		**	These are the weapons that this techno object is armed with.
		*/
		WeaponTypeClass const * PrimaryWeapon;
		WeaponTypeClass const * SecondaryWeapon;

		/*
		**	These specify the lepton offsets to locate the exact coordinate of the
		**	'tip of the barrel' for the weapon. This is used for generating the bullet
		**	at the proper location.
		*/
		int VerticalOffset;			// Distance to move north (compensates for perspective).
		int PrimaryOffset;			// Offset along turret centerline and facing.
		int PrimaryLateral;			// Sideways offset from turret centerline and facing.
		int SecondaryOffset;
		int SecondaryLateral;

		/*
		** Points you're awarded for destroying an object of this type, and
		** points you lose if you lose an object of this type.
		*/
		int Points;

		//--------------------------------------------------------------------
		TechnoTypeClass(NoInitClass const & x) : ObjectTypeClass(x) {}
		TechnoTypeClass(
				RTTIType rtti,
				int id,
				int name,
				char const * ininame,
				RemapType remap,
				int verticaloffset,
				int primaryoffset,
				int primarylateral,
				int secondaryoffset,
				int secondarylateral,
				bool is_nominal,
				bool is_stealthy,
				bool is_selectable,
				bool is_legal_target,
				bool is_insignificant,
				bool is_immune,
				bool is_theater,
				bool is_turret_equipped,
				bool is_remappable,
				bool is_footprint,
				int rotation,
				SpeedType speed
				);

		bool Is_Two_Shooter(void) const;
		int Legal_Placement(CELL pos) const;
		virtual int Raw_Cost(void) const;
		virtual int Max_Passengers(void) const {return(MaxPassengers);}
		virtual int Repair_Cost(void) const;
		virtual int Repair_Step(void) const;
		virtual void const * Get_Cameo_Data(void) const;
		virtual int Cost_Of(void) const;
		virtual int Time_To_Build(void) const;
		virtual int Get_Ownable(void) const;
		virtual bool Read_INI(CCINIClass & ini);

		/*
		**	This is a pointer to the wake shape (as needed by the gunboat).
		*/
		static void const * WakeShapes;
		static void const * TurretShapes;
		static void const * SamShapes;
		static void const * MGunShapes;
};

#endif // TECHNOTYPECLASS_H
