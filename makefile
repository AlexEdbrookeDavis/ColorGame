LIB=-lglew32 -lglfw3 -lopengl32 -lglu32 -lgdi32
INC=-I GameCode\include -I GameEngine\include

all: main

main: App GameLoop
	g++  -o main main.cpp GameLoop.o App.o Renderer.o Triangle.o Window.o inputHandler.o $(INC) $(LIB)
	

	
GameLoop: Renderer InputHandler App
	g++ -c GameEngine\Core\gameLoop.cpp $(INC) $(LIB)

App:
	g++ -c GameCode\app.cpp $(INC) $(LIB)
	
Triangle: Window
	g++ -c GameEngine\Graphics\triangle.cpp $(INC) $(LIB)
	
Renderer: Triangle
	g++ -c GameEngine\Graphics\renderer.cpp $(INC) $(LIB)
	
Window:
	g++ -c GameEngine\Graphics\window.cpp $(INC) $(LIB)
	
InputHandler:
	g++ -c GameEngine\Input\inputHandler.cpp $(INC) $(LIB)