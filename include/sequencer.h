#ifndef SEQUENCER_INCLUDE
#define SEQUENCER_INCLUDE

#include <stdio.h>

typedef struct Sequencer
{
	int *pitches;
	int *length;
	int position;
} Sequencer;

void sequencer_advance(Sequencer *sequencer, void (*callback)())
{
    // sequencer->position++;
    ++sequencer->position %= *(sequencer->length);

    // do the hustle
    if (callback != NULL)
    {
        callback();
    }
}

#endif // SEQUENCER_INCLUDE