#ifndef TARGETCLASS_H
#define TARGETCLASS_H

#include "target.h"
#include "noinitclass.h"

/*
**	This class only serves as a wrapper to the xTargetClass. This class must not define any members except
**	for the constructors. This is because the xTargetClass is used in a union and this target object is
**	used as its initializer. If this class had any extra members they would not be properly copied and
**	communicated to the other machines in a network/modem game. Combining this class with xTargetClass would
**	be more efficient, but Watcom doesn't allow class objects that have a constructor to be part of a union [even
**	if the class object has a default constructor!].
*/
class TargetClass : public xTargetClass
{
	public:

		TargetClass(void) {Invalidate();}
		TargetClass(NoInitClass const &) {}
		TargetClass(RTTIType rtti, int id) {
			Target.Sub.Exponent = rtti;
			Target.Sub.Mantissa = id;
		}
		TargetClass(CELL cell) {
			Target.Sub.Exponent = RTTI_CELL;
			Target.Sub.Mantissa = cell;
		}
		TargetClass(TARGET target);
		TargetClass(AbstractClass const * ptr);
		TargetClass(AbstractTypeClass const * ptr);
		TargetClass(CellClass const * ptr);
};

#endif // TARGETCLASS_H
