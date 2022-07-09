# 'Tile World Search'

Four tiles (A, B, C and P) are arranged in a 4x4 grid. The P tile must be moved around the grid such that the arrangement of tiles matches a goal state. If the new grid position for the P tile already contains another tile, their positions are swapped.

The program demonstrates three ways to solve the problem using three different search methods: breadth-first, iterative deepening and A* search. For A* search, either the number of misplaced tiles or the manhattan distance to the goal state can be used as the search heuristic function. The program also offers the option to perform graph search in which nodes previously expanded are ignored.

Finally, the complexity of each search is measured and outputted alongside the solution path. The time complexity counts the total number of nodes generated throughout the search while the space complexity counts the maximum number of nodes stored in memory at any one time. 

Some searches are incomplete and no solution is possible. A node limit is introduced to stop the search early in these situations.

Example 1: A* graph search selected using a Manhattan distance heuristic

![image](https://user-images.githubusercontent.com/65717521/147851719-7405318d-bbad-4f06-9e11-bc5312f81931.png)

Example 2: Time and space complexity (and partial solution path) for the search selected in Example 1

![image](https://user-images.githubusercontent.com/65717521/147851769-cad9e758-e44c-4baf-b091-19f213a73047.png)
