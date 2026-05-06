#include "raylib.h"
#include <vector>


class Sand {
public:
    int posX;
    int posY;


    Sand(int x, int y) {
        this->posX = x;
        this->posY = y;
    }

    void updatePos(int drX, int drY) {
        this->posX += drX;
        this->posY += drY;
    }
};


class Map {
private:
	int grid[800][600];


public:
    std::vector<Sand> sandParticles;
    Map(){
    for (int x = 0; x < 800; x++) {
        for (int y = 0; y < 600; y++) {
            grid[x][y] = 0; // 0 for empty, 1 for sand

            if (y > 590) {
				grid[x][y] = 2; // 2 for solid ground
            }
            if (x < 10) {
                grid[x][y] = 2; // 2 for solid ground
			}
            if (x > 790) {
                grid[x][y] = 2; // 2 for solid ground
            }
        }
    }
    }


    void calculateFrame() {
        for (auto& sand : sandParticles) {
            this->grid[sand.posX][sand.posY] = 0;

            if (grid[sand.posX][sand.posY + 1] == 0) {
				sand.posY += 1;
			}
            else if (grid[sand.posX - 1][sand.posY + 1] == 0) {
                sand.posX -= 1;
            }else if (grid[sand.posX + 1][sand.posY + 1] == 0) {
                sand.posX += 1;
            }
            else {

                this->grid[sand.posX][sand.posY] = 1;


            }
            this->grid[sand.posX][sand.posY] = 1;
           
		}
    }
};





Map map = Map();
int main() {
    InitWindow(800, 600, "Piasek");
    int fps = 144;
  
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(700, 10);
        //DrawText(TextFormat("VelX: %.2f", velocityX), 10, 10, 20, DARKGREEN);
        //DrawText(TextFormat("VelY: %.2f", velocityY), 10, 40, 20, DARKGREEN);

        Vector2 mousePosition = GetMousePosition();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {


            Sand sand = Sand((int)mousePosition.x, (int)mousePosition.y);
            Sand sand2 = Sand((int)mousePosition.x+1, (int)mousePosition.y);
            Sand sand3 = Sand((int)mousePosition.x, (int)mousePosition.y+1);
            Sand sand4 = Sand((int)mousePosition.x+1, (int)mousePosition.y+1);
			Sand sand5 = Sand((int)mousePosition.x - 1, (int)mousePosition.y);
			Sand sand6 = Sand((int)mousePosition.x - 1, (int)mousePosition.y + 1);
			Sand sand7 = Sand((int)mousePosition.x + 2, (int)mousePosition.y);
			Sand sand8 = Sand((int)mousePosition.x + 2, (int)mousePosition.y + 1);
            
			map.sandParticles.push_back(sand);
			map.sandParticles.push_back(sand2);
			map.sandParticles.push_back(sand3);
			map.sandParticles.push_back(sand4);
			map.sandParticles.push_back(sand5);
			map.sandParticles.push_back(sand6);
			map.sandParticles.push_back(sand7);
			map.sandParticles.push_back(sand8);



        }



        float delta = GetFrameTime();
        map.calculateFrame();

      
        for (auto& sand : map.sandParticles) {
            DrawPixel(sand.posX, sand.posY, BLACK);
		}
		



        //DrawCircle(posX, posY, 10, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}