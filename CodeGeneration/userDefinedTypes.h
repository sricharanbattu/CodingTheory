
#ifndef USER_DEFINED_TYPES_H
#define USER_DEFINED_TYPES_H

enum class CodeMethod {
	eFANO,
	eSHANNON,
	eHUFFMAN,
	eMAXCODES,
};

template <typename T>
struct Message {
	T		symbol{}; //Message can be a character, int, double or whatever type one needs
	double	prob{};
	string	code{};
};

#endif
