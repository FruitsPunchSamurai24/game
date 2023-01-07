default:
	g++ src/*.cpp -o game.exe -O2 -Wall -Ideps/raylib/include -Ldeps/raylib -lraylib -lopengl32 -lgdi32 -lwinmm