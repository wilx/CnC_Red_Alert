#ifndef EVENTCHOICECLASS_H
#define EVENTCHOICECLASS_H

#include "TEventType.h"
#include "ex_string.h"

class EventChoiceClass {
	public:
		EventChoiceClass(TEventType event=TEVENT_NONE) : Event(event) {}

		operator TEventType (void) const {return(Event);}
		bool operator == (EventChoiceClass const & rvalue) const {return(Event == rvalue.Event);}
		bool operator != (EventChoiceClass const & rvalue) const {return(Event != rvalue.Event);}
		bool operator > (EventChoiceClass const & rvalue) const {return(stricmp(Description(), rvalue.Description()) > 0);}
		bool operator < (EventChoiceClass const & rvalue) const {return(stricmp(Description(), rvalue.Description()) < 0);}
		bool operator <= (EventChoiceClass const & rvalue) const {return(Event == rvalue.Event || stricmp(Description(), rvalue.Description()) < 0);}
		bool operator >= (EventChoiceClass const & rvalue) const {return(Event == rvalue.Event || stricmp(Description(), rvalue.Description()) > 0);}
		char const * Description(void) const {return(Name_From_Event(Event));}
		void Draw_It(int index, int x, int y, int width, int height, bool selected, TextPrintType flags) const;

		TEventType Event;
};

extern EventChoiceClass EventChoices[TEVENT_COUNT];

#endif // EVENTCHOICECLASS_H
