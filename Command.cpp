#include "Command.h"


Command::Command(Staff* s, StaffCo_ordination* m) : appointed(s), mediator(m) {}


Command::~Command(){
	if(appointed){
		delete appointed;
		appointed = NULL;
	}

	if(mediator){
		delete mediator;
		mediator = NULL;
	}
}