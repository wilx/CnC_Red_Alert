#ifndef FIXEDHEAPCLASS_H
#define FIXEDHEAPCLASS_H

#include "BooleanVectorClass.h"

/**************************************************************************
**	This is a block memory management handler. It is used when memory is to
**	be treated as a series of blocks of fixed size. This is similar to an
**	array of integral types, but unlike such an array, the memory blocks
**	are anonymously. This facilitates the use of this class when overloading
**	the new and delete operators for a normal class object.
*/
class FixedHeapClass
{
	public:
		FixedHeapClass(int size);
		virtual ~FixedHeapClass(void);

		int Count(void) const {return ActiveCount;};
		int Length(void) const {return TotalCount;};
		int Avail(void) const {return TotalCount-ActiveCount;};

		virtual int ID(void const * pointer) const;
		virtual int Set_Heap(int count, void * buffer=0);
		virtual void * Allocate(void);
		virtual void Clear(void);
		virtual int Free(void * pointer);
		virtual int Free_All(void);

		void * operator[](int index) {return ((char *)Buffer) + (index * Size);};
		void const * operator[](int index) const {return ((char *)Buffer) + (index * Size);};

	protected:
		/*
		**	If the memory block buffer was allocated by this class, then this flag
		**	will be true. The block must be deallocated by this class if true.
		*/
		unsigned IsAllocated:1;

		/*
		**	This is the size of each sub-block within the buffer.
		*/
		int Size;

		/*
		**	This records the absolute number of sub-blocks in the buffer.
		*/
		int TotalCount;

		/*
		**	This is the total blocks allocated out of the heap. This number
		**	will never exceed Count.
		*/
		int ActiveCount;

		/*
		**	Pointer to the heap's memory buffer.
		*/
		void * Buffer;

		/*
		**	This is a boolean vector array of allocation flag bits.
		*/
		BooleanVectorClass FreeFlag;

	private:
		// The assignment operator is not supported.
		FixedHeapClass & operator = (FixedHeapClass const &);

		// The copy constructor is not supported.
		FixedHeapClass(FixedHeapClass const &);
};

#endif // FIXEDHEAPCLASS_H
