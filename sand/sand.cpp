#include "raylib.h"
#include <vector>


enum ParticleType {
	EMPTY,
    SAND,
    WATER,
    WALL
};

struct Cell {
    ParticleType type;
    bool updated; 
};

//class Sand {
//public:
//    int posX;
//    int posY;
//
//
//    Sand(int x, int y) {
//        this->posX = x;
//        this->posY = y;
//    }
//
//    void updatePos(int drX, int drY) {
//        this->posX += drX;
//        this->posY += drY;
//    }
//};
//

//class Map {
//private:
//	int grid[800][600];
//
//
//public:
   // std::vector<Sand> sandParticles;
   // Map(){
   // for (int x = 0; x < 800; x++) {
   //     for (int y = 0; y < 600; y++) {
   //         grid[x][y] = 0; // 0 for empty, 1 for sand

   //         if (y > 590) {
			//	grid[x][y] = 2; // 2 for solid ground
   //         }
   //         if (x < 10) {
   //             grid[x][y] = 2; // 2 for solid ground
			//}
   //         if (x > 790) {
   //             grid[x][y] = 2; // 2 for solid ground
   //         }
   //     }
   // }
   // }


//    void calculateFrame() {
//        for (auto& sand : sandParticles) {
//            this->grid[sand.posX][sand.posY] = 0;
//
//            if (grid[sand.posX][sand.posY + 1] == 0) {
//				sand.posY += 1;
//			}
//            else if (grid[sand.posX - 1][sand.posY + 1] == 0) {
//                sand.posX -= 1;
//            }else if (grid[sand.posX + 1][sand.posY + 1] == 0) {
//                sand.posX += 1;
//            }
//            else {
//
//                this->grid[sand.posX][sand.posY] = 1;
//
//
//            }
//            this->grid[sand.posX][sand.posY] = 1;
//           
//		}
//    }
//};




struct Map {
//private:

public:
	Cell grid[800][600];

	Map() {
		for (int i = 0; i < 800; i++) {
			for (int j = 0; j < 600; j++) {
				grid[i][j].type = EMPTY;
				grid[i][j].updated = false;
				if (j > 590) {
					grid[i][j].type = WALL;
				}
				if (i < 10) {
					grid[i][j].type = WALL;
				}
				if (i > 790) {
					grid[i][j].type = WALL;
				}
			}
		}
	};

    void calculateFrame() {
		for (int i = 800; i > 0; i--) {
			for (int j = 600; j > 0; j--) {
				if (grid[i][j].type == SAND && !grid[i][j].updated) {
					if (grid[i][j + 1].type == EMPTY) {
						grid[i][j + 1].type = SAND;
						grid[i][j].type = EMPTY;
						grid[i][j + 1].updated = true;
					}
					else if (grid[i - 1][j + 1].type == EMPTY) {
						grid[i - 1][j + 1].type = SAND;
						grid[i][j].type = EMPTY;
						grid[i - 1][j + 1].updated = true;
					}
					else if (grid[i + 1][j + 1].type == EMPTY) {
						grid[i + 1][j + 1].type = SAND;
						grid[i][j].type = EMPTY;
						grid[i + 1][j + 1].updated = true;
					}
					else if (grid[i][j + 1].type == WATER) {
						grid[i][j + 1].type = SAND;
						grid[i][j].type = WATER;
						grid[i][j + 1].updated = true;
					}
				}
				else if (grid[i][j].type == WATER && !grid[i][j].updated) {
					if (grid[i][j + 1].type == EMPTY) {
						grid[i][j + 1].type = WATER;
						grid[i][j].type = EMPTY;
						grid[i][j + 1].updated = true;
					}
					else if (grid[i - 1][j + 1].type == EMPTY) {
						grid[i - 1][j + 1].type = WATER;
						grid[i][j].type = EMPTY;
						grid[i - 1][j + 1].updated = true;
					}
					else if (grid[i + 1][j + 1].type == EMPTY) {
						grid[i + 1][j + 1].type = WATER;
						grid[i][j].type = EMPTY;
						grid[i + 1][j + 1].updated = true;
					}
					else if (grid[i - 1][j].type == EMPTY) {
						grid[i - 1][j].type = WATER;
						grid[i][j].type = EMPTY;
						grid[i - 1][j].updated = true;
					}
					else if (grid[i + 1][j].type == EMPTY) {
						grid[i + 1][j].type = WATER;
						grid[i][j].type = EMPTY;
						grid[i + 1][j].updated = true;
					}
				}

				else {
					grid[i][j].updated = false;
				}
			}
		}
    
    }

};


Map map = Map();
int main() {
    InitWindow(800, 600, "Piasek");
    int fps = 0;
	SetTargetFPS(fps);
  
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(700, 10);
        //DrawText(TextFormat("VelX: %.2f", velocityX), 10, 10, 20, DARKGREEN);
        //DrawText(TextFormat("VelY: %.2f", velocityY), 10, 40, 20, DARKGREEN);

        Vector2 mousePosition = GetMousePosition();

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

			for (int i = 0; i < 100; i++) {
				map.grid[(int)mousePosition.x+i][(int)mousePosition.y].type = SAND;
			}
			//map.grid[(int)mousePosition.x][(int)mousePosition.y].type = SAND;
			//map.grid[(int)mousePosition.x+1][(int)mousePosition.y].type = SAND;
			//map.grid[(int)mousePosition.x][(int)mousePosition.y+1].type = SAND;
			//map.grid[(int)mousePosition.x+1][(int)mousePosition.y+1].type = SAND;
			//map.grid[(int)mousePosition.x-1][(int)mousePosition.y].type = SAND;
			//map.grid[(int)mousePosition.x-1][(int)mousePosition.y+1].type = SAND;
			//map.grid[(int)mousePosition.x+2][(int)mousePosition.y].type = SAND;
			//map.grid[(int)mousePosition.x+2][(int)mousePosition.y+1].type = SAND;


   //         Sand sand = Sand((int)mousePosition.x, (int)mousePosition.y);
   //         Sand sand2 = Sand((int)mousePosition.x+1, (int)mousePosition.y);
   //         Sand sand3 = Sand((int)mousePosition.x, (int)mousePosition.y+1);
   //         Sand sand4 = Sand((int)mousePosition.x+1, (int)mousePosition.y+1);
			//Sand sand5 = Sand((int)mousePosition.x - 1, (int)mousePosition.y);
			//Sand sand6 = Sand((int)mousePosition.x - 1, (int)mousePosition.y + 1);
			//Sand sand7 = Sand((int)mousePosition.x + 2, (int)mousePosition.y);
			//Sand sand8 = Sand((int)mousePosition.x + 2, (int)mousePosition.y + 1);
   //         
			//map.sandParticles.push_back(sand);
			//map.sandParticles.push_back(sand2);
			//map.sandParticles.push_back(sand3);
			//map.sandParticles.push_back(sand4);
			//map.sandParticles.push_back(sand5);
			//map.sandParticles.push_back(sand6);
			//map.sandParticles.push_back(sand7);
			//map.sandParticles.push_back(sand8);

		}

		//if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		//	map.grid[(int)mousePosition.x][(int)mousePosition.y].type = WALL;
		//}
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
			map.grid[(int)mousePosition.x][(int)mousePosition.y].type = WATER;
			map.grid[(int)mousePosition.x+1][(int)mousePosition.y].type = WATER;
			map.grid[(int)mousePosition.x][(int)mousePosition.y+1].type = WATER;
			map.grid[(int)mousePosition.x+1][(int)mousePosition.y+1].type = WATER;
			map.grid[(int)mousePosition.x-1][(int)mousePosition.y].type = WATER;
			map.grid[(int)mousePosition.x-1][(int)mousePosition.y+1].type = WATER;
			map.grid[(int)mousePosition.x+2][(int)mousePosition.y].type = WATER;
			map.grid[(int)mousePosition.x+2][(int)mousePosition.y+1].type = WATER;
			map.grid[(int)mousePosition.x+3][(int)mousePosition.y].type = WATER;
			map.grid[(int)mousePosition.x+3][(int)mousePosition.y+1].type = WATER;
		}
		float delta = GetFrameTime();
		//map.calculateFrame();


		//for (auto& sand : map.sandParticles) {
		//    DrawPixel(sand.posX, sand.posY, BLACK);
		//}

		//DrawCircle(posX, posY, 10, RED);

		map.calculateFrame();

		for (int x = 0; x < 800; x++) {
			for (int y = 0; y < 600; y++) {
				if (map.grid[x][y].type == SAND) {
					DrawPixel(x, y, BLACK);
				}
				else if (map.grid[x][y].type == WALL) {
					DrawPixel(x, y, GRAY);
				}
				else if (map.grid[x][y].type == WATER) {
					DrawPixel(x, y, BLUE);
				}
			}
		}


		EndDrawing();
	}

    CloseWindow();
    return 0;
}