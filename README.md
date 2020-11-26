# The Game of Biquadris

![me](https://github.com/dgwarlug47/biquadris/blob/main/gif.gif)
Biquadris is a Latinization of the game Tetris, expanded for two players. The
game consists of 2 boards, each 11 columns wide and 15 rows high. Blocks consist
of four cells, they appear at the top of each board and then you must drop them.
Once an entire row gets filled, it disappears, and each remaining blocks goes
one unit down (like in Tetris). The major difference between Tetris is that it is
not real time, that is each player has as much time as he wants to make the play.

# Levels
level 2: normal
</br> 
</br>
level 3: blocks S and Z which are harder to fit are more likely to appear then the
other blocks, also every block is "heavy", that is every move like left, right, rotate
will be followed immediatly and automatically by a downward move of one row.
</br> 
</br>
level 4: in addition to level 3 rules, every time you place 5 blocks without clearing
a row, a 1X1 block will be dropped on the center of the board.

# Commands
The main commands are levelup, leveldown to change the levels, right, left, down, clockwise,
counterclockwise to move the block, and drop to finally drop the block.

# Special actions
If a player upon dropping a bloc, clears two or more rows simultaneously, a special
action gets triggered (A special action is a negative influence on the opponent's game.)
and the player needs to give one of the following commands to the command line:
</br> 
</br> blind: the other player's board, from columns 3-9, and rows 3-12 get covered with
a question mark (?)
</br> 
</br> heavy: Every time a player moves a block left or right the block automatically falls
by two rows. If it is not possible for the block to fall two rows, then it simply gets dropped.
If the player is already in a level where blocks are heavy the effect is cumulative.
</br> 
</br> force: Change the opponent's current block to be one of the player's choosing. Note you have to
specify the block, thus you could type force Z in order to force block Z.
