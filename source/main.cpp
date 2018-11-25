/*---------------------------------------------------------------------------------

	Basic template code for starting a DS app

---------------------------------------------------------------------------------*/
#include <nds.h>
#include <stdio.h>
#include <math.h>
#include <nds/arm9/sound.h>
#include <time.h>
#include "sequencer.h"
#include "notes.h"

// int pitches1[] = {4000, 2000, 3000, 6000, 4000, 2500, 4500, 6000};
// int pitches1[] = {131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 246};
int pitches1[] = {Note_C6, Note_C6, Note_C6, Note_C6, Note_C6, Note_C6, Note_C6, Note_C6};
int pitches1Len = 4;
int pitches2[] = {Note_C5, Note_C5, Note_C5, Note_C5, Note_C5, Note_C5, Note_C5, Note_C5};
int pitches2Len = 4;
int vblanks = 0;
int soundId1 = -1;
int soundId2 = -1;
int shiftY = 2;

int tickLength = 6;

int editedSequencer = 0;
int editedStep = 0;
int *editedPitchesPtr = pitches1;
int *editedSequencerLenPtr = &pitches1Len;

Sequencer s1, s2, s3;

void onVBlank()
{}

void onSequencer1Advance()
{
	soundSetFreq(soundId1, (shiftY * NoteValues[s1.pitches[s1.position]]));
}

void onSequencer2Advance()
{
	soundSetFreq(soundId2, (shiftY * NoteValues[s2.pitches[s2.position]]) / 2);
}

//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	irqSet(IRQ_VBLANK, onVBlank);
	srand(time(NULL));
	
	consoleDemoInit();

	videoSetMode(MODE_FB0);
	// videoSetModeSub(MODE_5_2D);
	vramSetBankA(VRAM_A_LCD);
	// vramSetBankC(VRAM_C_SUB_BG_0x06200000);

	// consoleInit(NULL, OBJPRIORITY_0, BgType_Text4bpp, BgSize_T_256x256, 0, 1, false, true);

	soundEnable();
	iprintf("Sound enabled\n");

	// setup sequencers
	s1.pitches = pitches1;
	s1.length = &pitches1Len;
	s1.position = 0;

	s2.pitches = pitches2;
	s2.length = &pitches2Len;
	s2.position = 0;

	soundId1 = soundPlayPSG(DutyCycle_50, s1.pitches[0], 32, 64);
	soundId2 = soundPlayPSG(DutyCycle_12, s2.pitches[0], 48, 64);

	iprintf("1: %d\n", soundId1);
	iprintf("2: %d\n", soundId2);

	touchPosition touchPos;

	while(1) {
		swiWaitForVBlank();

		scanKeys();
		int pressed = keysDown();
		if(pressed & KEY_START) break;

		if (pressed & KEY_SELECT)
		{
			editedSequencer = editedSequencer == 1 ? 0 : 1;
			editedPitchesPtr = editedSequencer == 0 ? pitches1 : pitches2;
			editedSequencerLenPtr = editedSequencer == 0 ? &pitches1Len : &pitches2Len;

			editedStep = 0;

		}
		else if (pressed & KEY_LEFT)
		{
			--editedStep;
			if (editedStep < 0)
			{
				editedStep += *editedSequencerLenPtr;
			}
		}
		else if (pressed & KEY_RIGHT)
		{
			++editedStep %= *editedSequencerLenPtr;
		}
		else if (pressed & KEY_UP)
		{
			editedPitchesPtr[editedStep]++;
		}
		else if (pressed & KEY_DOWN)
		{
			editedPitchesPtr[editedStep]--;
		}
		else if (pressed & KEY_L)
		{
			if (*editedSequencerLenPtr > 1)
			{
				(*editedSequencerLenPtr)--;
			}
		}
		else if (pressed & KEY_R)
		{
			if (*editedSequencerLenPtr < 8)
			{
				(*editedSequencerLenPtr)++;
			}
		}

		iprintf("\x1b[3;0Hedited = %d-%d    \n", editedSequencer, editedStep);

		iprintf("\x1b[4;0H\x1b[0K\x1b32m1(%d):", pitches1Len);
		for (int i = 0; i < pitches1Len; ++i)
		{
			printf("%d ", pitches1[i]);
		}
		iprintf("\x1b[5;0H\x1b[0K2(%d):", pitches2Len);
		for (int i = 0; i < pitches2Len; ++i)
		{
			printf("%d ", pitches2[i]);
		}
		// touchRead(&touchPos);

		// if (pressed & KEY_TOUCH)
		// {
		// 	int step = touchPos.px / 16;
		// 	int pitch = touchPos.py / 12;

		// 	iprintf("\x1b[3;0Hstep %d pitch %d\n", step, pitch);
		// }
		// else
		// {
		// 	iprintf("\x1b[3;0Hstep -1 pitch -1\n");
		// }

		++vblanks;
		if (vblanks >= tickLength)
		{
			vblanks = 0;
			sequencer_advance(&s1, &onSequencer1Advance);
			sequencer_advance(&s2, &onSequencer2Advance);
		}

		iprintf("\x1b[11;0HPos = %d %d     \n", s1.position, s2.position);
		iprintf("\x1b[12;0HFreq = %d    %d    \n", s1.pitches[s1.position], s2.pitches[s2.position]);

		// VRAM_A[]

		// for(int i = 0; i < 256*192; i++)
		// 	VRAM_A[i] = RGB15(31,0,0);
	}
}