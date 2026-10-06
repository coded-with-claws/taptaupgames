
const byte brocheBuzzer = 11;

void jouerMelodie(int * laMelodie, int nbNotes, int metro) {
  int wholenote = (60000L * 4) / metro;  // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
  int divider = 0, noteDuration = 0;

  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < nbNotes * 2; thisNote = thisNote + 2) {
    divider = laMelodie[thisNote + 1];        // calculates the duration of each note
    if (divider > 0) {
      noteDuration = (wholenote) / divider;       // regular note, just proceed
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);  // dotted notes are represented with negative durations!!
      noteDuration *= 1.5;                        // increases the duration in half for dotted notes
    }
    tone(brocheBuzzer, laMelodie[thisNote], noteDuration * 0.9); // 90% du temps de la note jouée et 10% de pause
    delay(noteDuration); // durée entre 2 notes
    noTone(brocheBuzzer); // arret du son entre 2 notes
  }
}

#include "pitches.h" // note de musique

#define REST 0

int snd_solo[] = {

  NOTE_C5, 128,  NOTE_D5, 128,

};
int snd_win_solo_normal[] = {

  NOTE_E5, 64,  NOTE_D5, 64,  NOTE_C5, 64,

};

int snd_solo_recofday[] = {
	
  NOTE_C5, 32,  NOTE_D5, 32,  NOTE_E5, 32,
  
};

int snd_win_solo_wr[] = {

  NOTE_C5, 16,  NOTE_D5, 16,  NOTE_E5, 16,  NOTE_F5, 16,

};

int snd_win_vs[] = {

  NOTE_C5, 128,  NOTE_D5, 128,  NOTE_E5, 128,

};

