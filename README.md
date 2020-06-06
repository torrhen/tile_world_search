# Tile Search Problem (C++)

## Overview
An agent (**P**) moves within a simulated (N x N) grid which contains other types of tiles (**A**, **B**, **C**). Squares within the grid that do not contain a tile are marked with an **X**. The agent starts in a pre-defined start grid. The objective is to move around the grid and position the **A**, **B** and **C** tiles so that the goal grid is satisfied.

**Start Grid**:

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **A** &nbsp;|&nbsp; **B** &nbsp;|&nbsp; **C** &nbsp;|&nbsp; **P** &nbsp;|<br>

**Goal Grid**:

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **A** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **B** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **C** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **P** &nbsp;|<br>

When the agent moves into a position that is already occupied by another tile, the position of the obstructing tile is automatically swapped with the agent.

e.g. &nbsp; Agent moves left into a position already occupied by the **C** tile.

**Before move**:

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **A** &nbsp;|&nbsp; **B** &nbsp;|&nbsp; **C** &nbsp;|&nbsp; **P** &nbsp;|<br>

**After move**:

&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|&nbsp; **X** &nbsp;|<br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|&nbsp; **A** &nbsp;|&nbsp; **B** &nbsp;|&nbsp; **P** &nbsp;|&nbsp; **C** &nbsp;|<br>

## Tree Search Algorithms

The search for this goal state is done using breadth-first, depth-first, iterative deepening and A* TREE search. The project can be used to investigate how performance scales with problem difficulty, based on two metrics.

1. Time Complexity <br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; total number of tree nodes generated.
2. Space Complexity <br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; maximum number of tree nodes generated at once.

The project also identifies which of these search strategies are complete and optimal.

3. Complete <br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; always returns the solution if one exists. <br>
4. Optimal <br>
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; solution found is guaranteed to be the shallowest. <br>
