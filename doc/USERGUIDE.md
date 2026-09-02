# User guide

## Notation
- P1 = Player 1, P2 = Player 2

## Start-up

When the game is powered up, it starts depending on button already pressed:
- if the Red button of Player 1 is pressed (`P1_3`), it runs diagnostic mode for LEDs,
- if the Red button of Player 2 is pressed (`P2_3`), it runs diagnostic mode for buttons,
- if no button is pressed, it automatically starts the game `taupitaupe`.

### Diagnostic mode
- LEDs: runs various functions displaying LEDs
- buttons: lights buttons whenever they are pressed (can be used to show conflicts).

### Taupitaupe
Two buttons are flashing : one on P1's side, one on P2's side.
Press P1's button for a solo game, P2's button for a versus game.
In solo mode, you play whack-a-mole with all the buttons. You have to hit a score of 20 in the shortest time possible.
In versus mode, each player plays whack-a-mole on their side. The first player to hit a score of 20 wins.
After a game, the choice is up again between solo and versus.

Solo mode highscore:
(WIP)
There is a highscore "of the day" (= since last power up), and a highscore of ever: "world record".
When the game is powered up, the highest score of the day is clear (zero), but the world record is already memorized.
When a player beats the score of the day, there is a special win animation.
When a player beats the world record, there is another special win animation.

