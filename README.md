# Tetris
A modified version of Tetris implemented using object-oriented programming.

**OVERVIEW**
- A 2 player game where each player's turn is finished once the player inputs the "drop"
- A grid of dimensions 18 x 11 is used
- 
**LEVELS (The way in which the upcoming block will be determined)** 
- **Level 0**: A sequence of characters (I, J, L, O, T, S, Z) are read in from a text file so that the next block to be shown on the grid is taken from that file in order
- **Level 1**: The block selector will randomly choose a block with probabilities skewed such that S and Z blocks are selected with probability 1/12 each, and the other blocks are selected with probability 1/6 each.

**COMMANDS :**
- left
- right
- down
- clockwise
- counterclockwise
- drop
- levelup
- leveldown
- restart


**Block Types:**

I-Block:

<pre>
I I I I
</pre>


---
J-Block:
<pre>
J
J J J
</pre>
---
L-Block:

<pre>
    L
L L L
</pre>

---
O-Block:
<pre>
  O O
  O O
</pre>


---
T-Block:
<pre>
T T T
  T 
</pre>


---
S-Block:
<pre>
  S S
S S 
</pre>


---
Z-Block:
<pre>
Z Z
  Z Z 
</pre>




Sample input and outputs are shown in the demo.pdf

