# User guide

## Notation
- P1 = Player 1, P2 = Player 2

## Start-up

When the game is powered up, it starts depending on button already pressed:
- if the White button of Player 1 is pressed (`P1_1`), it runs diagnostic mode for LEDs,
- if the White button of Player 2 is pressed (`P2_1`), it runs diagnostic mode for buttons,
- if both Red buttons are pressed (`P1_3` and `P2_3`), it clears world record highscore,
- if no button is pressed, it automatically starts the game `taupitaupe`.

### Diagnostic mode
- LEDs: runs various functions displaying LEDs
- buttons: lights buttons whenever they are pressed (can be used to show conflicts).

### Taupitaupe
Three buttons are flashing: one symmetrically on P1's and P2's sides, and another button on P1's side.
For the symmetrical buttons: 
Press only P1's button during 2 seconds for a solo game.
Press both P1's and P2's buttons during 2 seconds for a versus game.
For the last button: press it during 2 secondsA for a classic solo game.
- In solo mode, you play whack-a-mole with all the buttons. You have to hit a score of 30 in the shortest time possible. If you hit a wrong button, you won't get the point when you hit the next good button.
- In versus mode, each player plays whack-a-mole on their side. The first player to hit a score of 30 wins. If you hit a wrong button at the same time as you hit the good button (with some restrictions due to the hardware design), you don't get the point.
- In classic solo mode, the moles appear and disappear with random delays. If you hit a wrong button at the same time as you hit the good button, you don't get the point.
After a game, the choice is up again between solo, versus and classic solo.

#### Solo mode highscore
There are two highscores:
- the highscore "of the day" (= since last power up),
- the highscore of ever: "world record".
When the game is powered up, the highest score of the day is cleared (zero), but the world record is already memorized (EEPROM).
When a player beats the score of the day, there is a special win animation.
When a player beats the world record, there is an even more special win animation.

