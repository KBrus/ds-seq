#ifndef NOTES_INCLUDE
#define NOTES_INCLUDE

#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

#define NOTE_C6  (2*523)
#define NOTE_CS6 (2*554)
#define NOTE_D6  (2*587)
#define NOTE_DS6 (2*622)
#define NOTE_E6  (2*659)
#define NOTE_F6  (2*698)
#define NOTE_FS6 (2*740)
#define NOTE_G6  (2*784)
#define NOTE_GS6 (2*831)
#define NOTE_A6  (2*880)
#define NOTE_AS6 (2*932)
#define NOTE_B6  (2*988)

#define NOTE_C7  (4*523)
#define NOTE_CS7 (4*554)
#define NOTE_D7  (4*587)
#define NOTE_DS7 (4*622)
#define NOTE_E7  (4*659)
#define NOTE_F7  (4*698)
#define NOTE_FS7 (4*740)
#define NOTE_G7  (4*784)
#define NOTE_GS7 (4*831)
#define NOTE_A7  (4*880)
#define NOTE_AS7 (4*932)
#define NOTE_B7  (4*988)

typedef enum
{
    Note_C5 = 0,
    Note_CS5,
    Note_D5,
    Note_DS5,
    Note_E5,
    Note_F5,
    Note_FS5,
    Note_G5,
    Note_GS5,
    Note_A5,
    Note_AS5,
    Note_B5,
    Note_C6,
    Note_CS6,
    Note_D6,
    Note_DS6,
    Note_E6,
    Note_F6,
    Note_FS6,
    Note_G6,
    Note_GS6,
    Note_A6,
    Note_AS6,
    Note_B6,
    Note_C7,
    Note_CS7,
    Note_D7,
    Note_DS7,
    Note_E7,
    Note_F7,
    Note_FS7,
    Note_G7,
    Note_GS7,
    Note_A7,
    Note_AS7,
    Note_B7
} Notes;

int NoteValues[] = {
    NOTE_C5,
    NOTE_CS5,
    NOTE_D5,
    NOTE_DS5,
    NOTE_E5,
    NOTE_F5,
    NOTE_FS5,
    NOTE_G5,
    NOTE_GS5,
    NOTE_A5,
    NOTE_AS5,
    NOTE_B5,
    NOTE_C6,
    NOTE_CS6,
    NOTE_D6,
    NOTE_DS6,
    NOTE_E6,
    NOTE_F6,
    NOTE_FS6,
    NOTE_G6,
    NOTE_GS6,
    NOTE_A6,
    NOTE_AS6,
    NOTE_B6,
    NOTE_C7,
    NOTE_CS7,
    NOTE_D7,
    NOTE_DS7,
    NOTE_E7,
    NOTE_F7,
    NOTE_FS7,
    NOTE_G7,
    NOTE_GS7,
    NOTE_A7,
    NOTE_AS7,
    NOTE_B7
    };

#endif // NOTES_INCLUDE