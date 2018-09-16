FLAGS = -ansi -pedantic -lglfw -lGL -lGLEW -g
objects = Vertex_t.o Test_Vertex_t.o

Test_Vertex_t.out: $(objects)
	g++ $(objects) -o Test_Vertex_t.out

Test_Vertex_t.o: Test_Vertex_t.cpp Vertex_t.hpp
	g++ Test_Vertex_t.cpp  -c $(FLAGS) -o Test_Vertex_t.o

Vertex_t.o: Vertex_t.cpp Vertex_t.hpp
	g++ Vertex_t.cpp  -c $(FLAGS) -o Vertex_t.o

clean:
	rm $(objects) Test_Vertex_t.out