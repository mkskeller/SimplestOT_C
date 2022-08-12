#ifndef OT_RECEIVER_H
#define OT_RECEIVER_H

#include <stdio.h>

#include "sc.h"
#include "ge.h"
#include "ot_config.h"

struct ot_receiver
{
	unsigned char S_pack[ PACKBYTES ];
	ge_p3 S;

	// temporary

	ge_p3 xB[4];
	unsigned char x[4][32];
};

typedef struct ot_receiver RECEIVER;

void receiver_rsgen_part(RECEIVER *, unsigned char *, unsigned char, int i);
void receiver_keygen_part(RECEIVER *, unsigned char [HASHBYTES], int i);

// compatibility
void receiver_maketable(RECEIVER *);
void receiver_procS(RECEIVER *);
void receiver_rsgen(RECEIVER *, unsigned char *, unsigned char *);
void receiver_keygen(RECEIVER *, unsigned char (*)[HASHBYTES]);

#endif //ifndef OT_RECEIVER_H

