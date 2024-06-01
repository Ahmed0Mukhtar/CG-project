void Assignment08::createMazeMesh(int row, int col, char **maze) {
	// The procedure gets in input the number of rows <row> of the maze, and the number of columns <col>
	// Element <maze[r][c]>, with 0 <= r <= row-1 and 0 <= c <= col-1 contains:
	//		Symbol ' ' if there is an empty space
	//		Symbol '#' if there is a wall
	//
	// Example: The following piece of code executes the instruction in the ... section
	//          if there is a wall in position r=5, c=7
	//
	// int r, c;
	// r = 5; c = 7;
	// if(maze[r][c] == '#') {
	//		...
	// }
	//
	// The example below creates a square, with four vertices and two triangles.
	// It must be deleted and replaced with your code creating the mesh of the maze.

	float wallHight = 1.0f;
	float wallSize = 1.0f;
	int v_counter = 0;

	// THE FLOOR VERTICES
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(-20.0);	// vertex 0
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(row+20.0);	// vertex 1
	vPos.push_back(col); vPos.push_back(0.0); vPos.push_back(-20.0);	// vertex 2
	vPos.push_back(col); vPos.push_back(0.0); vPos.push_back(row+20.0);	// vertex 3

	//the indices of the vertices of 2 triangles to create the floor
	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle (0,1,2)
	vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle (1,2,3)
	v_counter += 4;

	//left out wall
	vPos.push_back(0.0); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 0
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(row);	// vertex 1
	vPos.push_back(0.0); vPos.push_back(wallHight); vPos.push_back(row+20.0);	// vertex 2
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(row+20.0);	// vertex 3
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 4
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row);	// vertex 5
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 6
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 7

	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle (0,1,2)
	vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle (1,2,3)
	vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6);	// third triangle (4,5,6)
	vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6); vIdx.push_back(v_counter + 7);	// fourth triangle (5,6,7)
	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4);	// First triangle (0,2,4)
	vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 6);	// First triangle (2,4,6)
	v_counter += 8;

	//right out wall
	vPos.push_back(col); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 0
	vPos.push_back(col); vPos.push_back(0.0); vPos.push_back(row);	// vertex 1
	vPos.push_back(col); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 2
	vPos.push_back(col); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 3
	vPos.push_back(col-1.0); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 4
	vPos.push_back(col-1.0); vPos.push_back(0.0); vPos.push_back(row);	// vertex 5
	vPos.push_back(col-1.0); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 6
	vPos.push_back(col-1.0); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 7

	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle (0,1,2)
	vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle (1,2,3)
	vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6);	// third triangle (4,5,6)
	vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6); vIdx.push_back(v_counter + 7);	// fourth triangle (5,6,7)
	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4);	// First triangle (0,2,4)
	vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 6);	// First triangle (2,4,6)
	v_counter += 8;

	//back out wall
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row+20.0);	// vertex 0
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 1
	vPos.push_back(col-1); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 2
	vPos.push_back(col-1); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 3
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row + 19.0);	// vertex 4
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row + 19.0);	// vertex 5
	vPos.push_back(col-1); vPos.push_back(wallHight); vPos.push_back(row + 19.0);	// vertex 6
	vPos.push_back(col-1); vPos.push_back(0.0); vPos.push_back(row + 19.0);	// vertex 7

	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle (0,1,2)
	vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle (1,2,3)
	vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6);	// third triangle (4,5,6)
	vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6); vIdx.push_back(v_counter + 7);	// fourth triangle (5,6,7)
	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4);	// First triangle (0,2,4)
	vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 6);	// First triangle (2,4,6)
	v_counter += 8;


	////////////////////////////////////////////////////////////

	//left out wall
	vPos.push_back(0.0); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 0
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(row);	// vertex 1
	vPos.push_back(0.0); vPos.push_back(wallHight); vPos.push_back(row+20.0);	// vertex 2
	vPos.push_back(0.0); vPos.push_back(0.0); vPos.push_back(row+20.0);	// vertex 3
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 4
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row);	// vertex 5
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 6
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 7

	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle (0,1,2)
	vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle (1,2,3)
	vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6);	// third triangle (4,5,6)
	vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6); vIdx.push_back(v_counter + 7);	// fourth triangle (5,6,7)
	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4);	// First triangle (0,2,4)
	vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 6);	// First triangle (2,4,6)
	v_counter += 8;

	//right out wall
	vPos.push_back(col); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 0
	vPos.push_back(col); vPos.push_back(0.0); vPos.push_back(row);	// vertex 1
	vPos.push_back(col); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 2
	vPos.push_back(col); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 3
	vPos.push_back(col-1.0); vPos.push_back(wallHight); vPos.push_back(row);	// vertex 4
	vPos.push_back(col-1.0); vPos.push_back(0.0); vPos.push_back(row);	// vertex 5
	vPos.push_back(col-1.0); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 6
	vPos.push_back(col-1.0); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 7

	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle (0,1,2)
	vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle (1,2,3)
	vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6);	// third triangle (4,5,6)
	vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6); vIdx.push_back(v_counter + 7);	// fourth triangle (5,6,7)
	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4);	// First triangle (0,2,4)
	vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 6);	// First triangle (2,4,6)
	v_counter += 8;

	//back out wall
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row+20.0);	// vertex 0
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 1
	vPos.push_back(col-1); vPos.push_back(wallHight); vPos.push_back(row + 20.0);	// vertex 2
	vPos.push_back(col-1); vPos.push_back(0.0); vPos.push_back(row + 20.0);	// vertex 3
	vPos.push_back(1.0); vPos.push_back(wallHight); vPos.push_back(row + 19.0);	// vertex 4
	vPos.push_back(1.0); vPos.push_back(0.0); vPos.push_back(row + 19.0);	// vertex 5
	vPos.push_back(col-1); vPos.push_back(wallHight); vPos.push_back(row + 19.0);	// vertex 6
	vPos.push_back(col-1); vPos.push_back(0.0); vPos.push_back(row + 19.0);	// vertex 7

	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle (0,1,2)
	vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle (1,2,3)
	vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6);	// third triangle (4,5,6)
	vIdx.push_back(v_counter + 5); vIdx.push_back(v_counter + 6); vIdx.push_back(v_counter + 7);	// fourth triangle (5,6,7)
	vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4);	// First triangle (0,2,4)
	vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 4); vIdx.push_back(v_counter + 6);	// First triangle (2,4,6)
	v_counter += 8;



	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			if (maze[r][c] == '#') {//if there is a wall on this position
				//I look around
				if (r == 0 || maze[r - 1][c] == ' ') {//look up: if there isn't another wall
					//Place a triangle
					vPos.push_back(c); vPos.push_back(0.0); vPos.push_back(r); //vertex 0
					vPos.push_back(c + wallSize); vPos.push_back(0.0); vPos.push_back(r); //vertex 1
					vPos.push_back(c); vPos.push_back(1.0); vPos.push_back(r); //vertex 2
					vPos.push_back(c + wallSize); vPos.push_back(1.0); vPos.push_back(r); //vertex 3
					//Insert 2 triangles
					vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle
					vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle
					v_counter += 4;
				}
				if (r == row - 1 || maze[r + 1][c] == ' ') {//look down: if there isn't another wall
					//Place a triangle
					vPos.push_back(c); vPos.push_back(0.0); vPos.push_back(r + wallSize); //vertex 0
					vPos.push_back(c + wallSize); vPos.push_back(0.0); vPos.push_back(r + wallSize); //vertex 1
					vPos.push_back(c); vPos.push_back(1.0); vPos.push_back(r + wallSize); //vertex 2
					vPos.push_back(c + wallSize); vPos.push_back(1.0); vPos.push_back(r + wallSize); //vertex 2
					//Insert 2 triangles
					vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle
					vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle
					v_counter += 4;

				}
				if (c == 0 || maze[r][c - 1] == ' ') {//look left : if there isn't another wall
					//Place a triangle
					vPos.push_back(c); vPos.push_back(0.0); vPos.push_back(r); //vertex 0
					vPos.push_back(c); vPos.push_back(0.0); vPos.push_back(r + wallSize); //vertex 1
					vPos.push_back(c); vPos.push_back(1.0); vPos.push_back(r); //vertex 2
					vPos.push_back(c); vPos.push_back(1.0); vPos.push_back(r + wallSize); //vertex 3
					//Insert 2 triangles
					vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle
					vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle
					v_counter += 4;
				}
				if (c == col - 1 || maze[r][c + 1] == ' ') {//look right: if there isn't another wall
					//Place a triangle
					vPos.push_back(c + wallSize); vPos.push_back(0.0); vPos.push_back(r); //vertex 0
					vPos.push_back(c + wallSize); vPos.push_back(0.0); vPos.push_back(r + wallSize); //vertex 1
					vPos.push_back(c + wallSize); vPos.push_back(1.0); vPos.push_back(r); //vertex 2
					vPos.push_back(c + wallSize); vPos.push_back(1.0); vPos.push_back(r + wallSize); //vertex 3
					//Insert 2 triangles
					vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle
					vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle
					v_counter += 4;
				}


				//create ceiling
				vPos.push_back(c); vPos.push_back(1.0); vPos.push_back(r); //vertex 0
				vPos.push_back(c); vPos.push_back(1.0); vPos.push_back(r + wallSize); //vertex 1
				vPos.push_back(c + wallSize); vPos.push_back(1.0); vPos.push_back(r); //vertex 2
				vPos.push_back(c + wallSize); vPos.push_back(1.0); vPos.push_back(r + wallSize); //vertex 3
				//Insert 2 triangles
				vIdx.push_back(v_counter + 0); vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2);	// First triangle
				vIdx.push_back(v_counter + 1); vIdx.push_back(v_counter + 2); vIdx.push_back(v_counter + 3);	// Second triangle
				v_counter += 4;


			}
		}
	}
}
