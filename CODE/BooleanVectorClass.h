#ifndef BOOLVECTORCLASS_H
#define BOOLVECTORCLASS_H

#include "vector.h"
#include "jshell.h"

/**************************************************************************
**	This is a derivative of a vector class that supports boolean flags. Since
**	a boolean flag can be represented by a single bit, this class packs the
**	array of boolean flags into an array of bytes containing 8 boolean values
**	each. For large boolean arrays, this results in an 87.5% savings. Although
**	the indexing "[]" operator is supported, DO NOT pass pointers to sub elements
**	of this bit vector class. A pointer derived from the indexing operator is
**	only valid until the next call. Because of this, only simple
**	direct use of the "[]" operator is allowed.
*/
class BooleanVectorClass
{
	public:
		BooleanVectorClass(unsigned size=0, unsigned char * array=0);
		BooleanVectorClass(BooleanVectorClass const & vector);

		// Assignment operator.
		BooleanVectorClass & operator =(BooleanVectorClass const & vector);

		// Equivalency operator.
		int operator == (BooleanVectorClass const & vector);

		// Fetch number of boolean objects in vector.
		int Length(void) {return BitCount;};

		// Set all boolean values to false;
		void Reset(void);

		// Set all boolean values to true.
		void Set(void);

		// Resets vector to zero length (frees memory).
		void Clear(void);

		// Change size of this boolean vector.
		int Resize(unsigned size);

		// Fetch reference to specified index.
		bool const & operator[](int index) const {
			if (LastIndex != index) Fixup(index);
			return(Copy);
		};
		bool & operator[](int index) {
			if (LastIndex != index) Fixup(index);
			return(Copy);
		};

		// Quick check on boolean state.
		bool Is_True(int index) const {
			if (index == LastIndex) return(Copy);
			return(Get_Bit(&BitArray[0], index));
		};

		// Find first index that is false.
		int First_False(void) const {
			if (LastIndex != -1) Fixup(-1);

			int retval = First_False_Bit(&BitArray[0]);
			if (retval < BitCount) return(retval);

			/*
			**	Failure to find a false boolean value in the vector. Return this
			**	fact in the form of an invalid index number.
			*/
			return(-1);
		}

		// Find first index that is true.
		int First_True(void) const {
			if (LastIndex != -1) Fixup(-1);

			int retval = First_True_Bit(&BitArray[0]);
			if (retval < BitCount) return(retval);

			/*
			**	Failure to find a true boolean value in the vector. Return this
			**	fact in the form of an invalid index number.
			*/
			return(-1);
		}

	private:
		void Fixup(int index=-1) const;

		/*
		**	This is the number of boolean values in the vector. This value is
		**	not necessarily a multiple of 8, even though the underlying character
		**	vector contains a multiple of 8 bits.
		*/
		int BitCount;

		/*
		**	This is a referential copy of an element in the bit vector. The
		**	purpose of this copy is to allow normal reference access to this
		**	object (for speed reasons). This hides the bit packing scheme from
		**	the user of this class.
		*/
		bool Copy;

		/*
		**	This records the index of the value last fetched into the reference
		**	boolean variable. This index is used to properly restore the value
		**	when the reference copy needs updating.
		*/
		int LastIndex;

		/*
		**	This points to the allocated bitfield array.
		*/
		VectorClass<unsigned char> BitArray;
};

#endif // BOOLVECTORCLASS_H
