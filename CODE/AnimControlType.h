#ifndef ANIMCONTROLTYPE_H
#define ANIMCONTROLTYPE_H

/**********************************************************************
**	For each stage that a building may be in, its animation is controlled
**	by this structure. It dictates the starting and length of the animation
**	frames needed for the specified state. In addition it specifies how long
**	to delay between changes in animation. With this data it is possible to
**	control the appearance of all normal buildings. Turrets and SAM sites are
**	an exception since their animation is not merely cosmetic.
*/
typedef struct {
    int	Start;			// Starting frame of animation.
    int	Count;			// Number of frames in this animation.
    int	Rate;			// Number of ticks to delay between each frame.
} AnimControlType;

#endif // ANIMCONTROLTYPE_H
