// --- Author : Moreau Cyril - Spl3en <spl3en.contact@gmail.com>
#pragma once

// ---------- Includes ------------
#include "MemProc/MemProc.h"

// ---------- Defines -------------

// ------ Structure declaration -------
#pragma pack(push, 1)
typedef struct _GameClock
{
	struct GameClockVftable *vftable;
	char gap_4[4];
	int field_1;
	char gap_C[4];
	__int64 field_2;
	char field_3;
	char gap_19[7];
	int field_5;
	int field_7;
	int field_8;
	int field_9;
	int field_10;
	int field_11;
	float gameTimeSeconds;
	int field_13;
	int field_14;
	int field_15;
	int field_16;
	int field_17;

	DWORD pThis;

} GameClock;
#pragma pack(pop)

#pragma pack(push, 1)
struct GameClockVftable
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	unsigned __int8 (*IsInitialized)(void);
};
#pragma pack(pop)



// --------- Constructors ---------

/*
 * Description 	: Allocate a new GameClock structure.
 * MemProc *mp  : Address of an allocated and running MemProc target process
 * Return		: A pointer to an allocated GameClock.
 */
GameClock *
GameClock_new (
	MemProc *mp
);


// ----------- Functions ------------

/*
 * Description : Initialize an allocated GameClock structure.
 * GameClock *this : An allocated GameClock to initialize.
 * MemProc *mp : The target LoL process
 * Return : true on success, false on failure.
 */
bool
GameClock_init (
	GameClock *this,
	MemProc *mp
);

/*
 * Description : Unit tests checking if a GameClock is coherent
 * GameClock *this : The instance to test
 * Return : true on success, false on failure
 */
bool
GameClock_test (
	GameClock *this
);

// --------- Destructors ----------

/*
 * Description : Free an allocated GameClock structure.
 * GameClock *this : An allocated GameClock to free.
 */
void
GameClock_free (
	GameClock *this
);


