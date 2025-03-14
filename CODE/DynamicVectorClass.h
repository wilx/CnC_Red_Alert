#ifndef DYNAMICVECTORCLASS_H
#define DYNAMICVECTORCLASS_H

#include "vector.h"

/**************************************************************************
**	This derivative vector class adds the concept of adding and deleting
**	objects. The objects are packed to the beginning of the vector array.
**	If this is instantiated for a class object, then the assignment operator
**	and the equality operator must be supported. If the vector allocates its
**	own memory, then the vector can grow if it runs out of room adding items.
**	The growth rate is controlled by setting the growth step rate. A growth
**	step rate of zero disallows growing.
*/
template<class T>
class DynamicVectorClass : public VectorClass<T>
{
	public:
		DynamicVectorClass(unsigned size=0, T const * array=0);

		// Change maximum size of vector.
		virtual int Resize(unsigned newsize, T const * array=0);

		// Resets and frees the vector array.
		virtual void Clear(void) {ActiveCount = 0;VectorClass<T>::Clear();};

		// Fetch number of "allocated" vector objects.
		int Count(void) const {return(ActiveCount);};

		// Add object to vector (growing as necessary).
		int Add(T const & object);
		int Add_Head(T const & object);

		// Delete object just like this from vector.
		int Delete(T const & object);

		// Delete object at this vector index.
		int Delete(int index);

		// Deletes all objects in the vector.
		void Delete_All(void) {ActiveCount = 0;};

		// Set amount that vector grows by.
		int Set_Growth_Step(int step) {return(GrowthStep = step);};

		// Fetch current growth step rate.
		int Growth_Step(void) {return GrowthStep;};

		virtual int ID(T const * ptr) {return(VectorClass<T>::ID(ptr));};
		virtual int ID(T const & ptr);

	protected:

		/*
		**	This is a count of the number of active objects in this
		**	vector. The memory array often times is bigger than this
		**	value.
		*/
		int ActiveCount;

		/*
		**	If there is insufficient room in the vector array for a new
		**	object to be added, then the vector will grow by the number
		**	of objects specified by this value. This is controlled by
		**	the Set_Growth_Step() function.
		*/
		int GrowthStep;
};


#endif // DYNAMICVECTORCLASS_H
