# Tile World Problem (C++)

Repository contains the search algorithms required to solve the "Tile World" problem.

An agent ("P") moves within a simulated N x N grid which contains other types of tiles ("A", "B", "C" and "X"). The goal of the agent is move around this grid and position the "A", "B" and "C" tiles so that they match their positions in the goal state from a start state.

Start State:

|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; A &nbsp;|&nbsp; B &nbsp;|&nbsp; C &nbsp;|&nbsp; P &nbsp;|<br>

Goal State:

|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; X &nbsp;|&nbsp; A &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; X &nbsp;|&nbsp; B &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; X &nbsp;|&nbsp; C &nbsp;|&nbsp; X &nbsp;|&nbsp; P &nbsp;|<br>

When the agent moves into a position that is already occupied by another tile, their positions are swapped.

e.g. &nbsp; Agent moves left (new position occupied by tile "C")

|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; A &nbsp;|&nbsp; B &nbsp;|&nbsp; C &nbsp;|&nbsp; P &nbsp;|<br>

|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|&nbsp; X &nbsp;|<br>
|&nbsp; A &nbsp;|&nbsp; B &nbsp;|&nbsp; P &nbsp;|&nbsp; C &nbsp;|<br>

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
