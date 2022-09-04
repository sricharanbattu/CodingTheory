
#ifndef USER_DEFINED_TYPES_H
#define USER_DEFINED_TYPES_H

enum class CodeMethod {
	eFANO,
	eSHANNON,
	eHUFFMAN,
};

struct Message {
	char symbol;
	double prob;
	string code;
};
#endif
