#ifndef ANIMTYPECLASS_H
#define ANIMTYPECLASS_H

#include "ObjectTypeClass.h"
#include "fixed.h"

/****************************************************************************
**	All the animation objects are controlled by this class. It holds the static
**	data associated with each animation type.
*/
class AnimTypeClass : public ObjectTypeClass
{
	public:

		/*
		**	If this animation should run at a constant apparent rate regardless
		**	of game speed setting, then this flag will be set to true.
		*/
		unsigned IsNormalized:1;

		/*
		**	If this animation should be rendered and sorted with the other ground
		**	units, then this flag is true. Typical of this would be fire and other
		**	low altitude animation effects.
		*/
		unsigned IsGroundLayer:1;

		/*
		**	If this animation should be rendered in a translucent fashion, this flag
		**	will be true. Translucent colors are some of the reds and some of the
		**	greys. Typically, smoke and some fire effects have this flag set.
		*/
		unsigned IsTranslucent:1;

		/*
		**	If this animation uses the white translucent table, then this flag
		**	will be true.
		*/
		unsigned IsWhiteTrans:1;

		/*
		**	If this is the special flame thrower animation, then custom affects
		**	occur as it is playing. Specifically, scorch marks and little fire
		**	pieces appear as the flame jets forth.
		*/
		unsigned IsFlameThrower:1;

		/*
		**	Some animations leave a scorch mark behind. Napalm and other flame
		**	type explosions are typical of this type.
		*/
		unsigned IsScorcher:1;

		/*
		**	Some explosions are of such violence that they leave craters behind.
		**	This flag will be true for those types.
		*/
		unsigned IsCraterForming:1;

		/*
		**	If this animation should attach itself to any unit that is in the same
		**	location as itself, then this flag will be true. Most vehicle impact
		**	explosions are of this type.
		*/
		unsigned IsSticky:1;

		/*
		**	If this animation is theater specific, then this flag will be
		**	set to true. Most animations are not theater specific.
		*/
		unsigned IsTheater:1;

		/*
		**	This is the type number for this animation kind. It can be used as
		**	a unique identifier for animation types.
		*/
		AnimType Type;

		/*
		**	This specified the maximum dimension of the shape (edge to edge). This dimension
		**	is used to build the appropriate cell refresh list. Keep this value as small
		**	as possible to ensure maximum performance. This is especially critical, since
		**	animations always cause the cells under them to be redrawn every frame.
		*/
		int Size;

		/*
		**	This is the frame that the animation is biggest. The biggest frame of animation
		**	will hide any changes to underlying ground (e.g., craters) that the animation
		**	causes, so these effects are delayed until this frame is reached. The end result
		**	is to prevent the player from seeing craters "pop" into existence.
		*/
		int Biggest;

		/*
		**	Some animations (when attached to another object) damage the object it
		**	is in contact with. Fire is a good example of this. This value is a
		**	fixed point number of the damage that is applied to the attached object
		**	every game tick. The damage is expressed as damage points per game frame.
		**	Because it is a fixed point fraction, the damage can be very slight.
		*/
		fixed Damage;

		/*
		**	Simple animation delay value between advancing of frames. This can
		**	be overridden by the control list.
		*/
		int Delay;

		/*
		**	The starting frame number for each animation sequence. Usually this is
		**	zero, but can sometimes be different if this animation is a sub sequence
		**	of a larger animation file.
		*/
		int Start;

		/*
		**	Looping animations might start at a different frame than the initial one.
		**	This is true for smoke effects that have a startup sequence followed by a
		**	continuous looping sequence.
		*/
		int LoopStart;

		/*
		**	For looping animations, this is the frame that will end all the middle loops
		**	of the animation. The last loop of the animation will proceed until the Stages
		**	has been fully completed.
		*/
		int LoopEnd;

		/*
		**	The number of stages that this animation sequence will progress through
		**	before it loops or ends.
		*/
		int Stages;

		/*
		**	This is the normal loop count for this animation. Usually this is one, but
		**	for some animations, it may be larger.
		*/
		unsigned Loops;

		/*
		**	This is the sound effect to play when this animation starts. Usually, this
		**	applies to explosion animations.
		*/
		VocType Sound;

		/*
		**	If the animation is to launch into another animation, then
		**	the secondary animation will be defined here.
		*/
		AnimType ChainTo;

		//---------------------------------------------------------------------------
		AnimTypeClass(NoInitClass const & x) : ObjectTypeClass(x) {}
		AnimTypeClass(AnimType anim,
							char const * name,
							int size,
							int biggest,
							bool istheater,
							bool isnormal,
							bool iswhite,
							bool isscorcher,
							bool iscrater,
							bool issticky,
							bool ground,
							bool istrans,
							bool isflame,
							fixed damage,
							int delaytime,
							int start,
							int loopstart,
							int loopend,
							int stages,
							int loops,
							VocType sound,
							AnimType chainto);

		static void Init_Heap(void);
		static void * operator new(size_t) throw();
		static void * operator new(size_t , void * ptr) throw() {return(ptr);};
		static void operator delete(void * ptr);

		static AnimTypeClass & As_Reference(AnimType type);
		static void Init(TheaterType theater);
		static void One_Time(void);

		virtual bool Create_And_Place(CELL , HousesType =HOUSE_NONE) const {return false;};
		virtual ObjectClass * Create_One_Of(HouseClass *) const {return 0;};
};


#endif // ANIMTYPECLASS_H