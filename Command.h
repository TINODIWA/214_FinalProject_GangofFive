#ifndef COMMAND_H
#define COMMAND_H

class Command {

protected:
	Staff* appointed;
	Nursery* mediator;

public:
	void execute();
};

#endif
