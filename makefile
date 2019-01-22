LIB=-static-libgcc -static-libstdc++ -DGLEW_STATIC -lglew32 -lglfw3 -lopengl32 -lglu32 -lgdi32
INC=-I GameCode\include -I GameEngine\include

all: main

main: GameLoop 
	g++  -o main main.cpp GameLoop.o App.o Renderer.o Cube.o Window.o inputHandler.o $(INC) $(LIB)
	

	
GameLoop: Renderer InputHandler App
	g++ -c GameEngine\Core\gameLoop.cpp $(INC) $(LIB)

App:
	g++ -c GameCode\app.cpp $(INC) $(LIB)
	
Cube: Window
	g++ -c GameEngine\Graphics\cube.cpp $(INC) $(LIB)
	
Renderer: Cube
	g++ -c GameEngine\Graphics\renderer.cpp $(INC) $(LIB)
	
Window:
	g++ -c GameEngine\Graphics\window.cpp $(INC) $(LIB)
	
InputHandler:
	g++ -c GameEngine\Input\inputHandler.cpp $(INC) $(LIB)