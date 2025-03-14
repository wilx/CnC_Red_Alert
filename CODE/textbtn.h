/*
**	Command & Conquer Red Alert(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Header: /CounterStrike/TEXTBTN.H 1     3/03/97 10:25a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : TEXTBTN.H                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 01/15/95                                                     *
 *                                                                                             *
 *                  Last Update : January 15, 1995 [JLB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef TEXTBTN_H
#define TEXTBTN_H

#include	"toggle.h"


class TextButtonClass : public ToggleClass
{
	public:
		TextButtonClass(void);
		TextButtonClass(unsigned id, char const * text, TextPrintType style, int x, int y, int w=-1, int h=-1, int blackborder=false);
		TextButtonClass(unsigned id, int text, TextPrintType style, int x, int y, int w=-1, int h=-1, int blackborder=false);
		virtual int Draw_Me(int forced=false);
		virtual void Set_Text(char const *text, bool resize = false);
		virtual void Set_Text(int text, bool resize = false);
		virtual void Set_Style (TextPrintType style) {PrintFlags = style;}

	protected:

		virtual void Draw_Background(void);
		virtual void Draw_Text(char const * text);

		unsigned IsBlackBorder:1;

		/*
		**	This points to a constant string that is used for the button's text.
		*/
		char const * String;

		/*
		**	This is the print flags to use when rendering this button's text.
		*/
		TextPrintType PrintFlags;
};

#endif

