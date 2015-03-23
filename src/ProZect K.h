#ifndef PROZECT_K_H_INCLUDED
#define PROZECT_K_H_INCLUDED

#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN

typedef struct {
	char *question;
	int nanswer;
	int nquestions;
	char *options[30];
} multichoice;

typedef struct {
	char *presentence;
	char *correctanswer;
	char *usersanswer;
} fillin;

enum qtype {
	QT_MULTICHOICE = 1,
	QT_SPOKEN,
	QT_FILLIN,
	QT_ESSAY
};

struct _questions{
	enum qtype type;
	union {
		fillin fi;
		multichoice mc;
	};
};

extern struct _questions questions[];

#endif // PROZECT_K_H_INCLUDED
