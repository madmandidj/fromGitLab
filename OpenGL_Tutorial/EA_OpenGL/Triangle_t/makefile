FLAGS = -ansi -pedantic -lglfw -lGL -lGLEW -g
VERTEX_PATH =../Vertex_t/
objects = Vertex_t.o Triangle_t.o Test_Triangle_t.o

Test_Triangle_t.out: $(objects)
	g++ $(objects) -o Test_Triangle_t.out

Test_Triangle_t.o: Test_Triangle_t.cpp Triangle_t.hpp
	g++ Test_Triangle_t.cpp  -c $(FLAGS) -o Test_Triangle_t.o

Triangle_t.o: Triangle_t.cpp Triangle_t.hpp $(VERTEX_PATH)Vertex_t.hpp
	g++ Triangle_t.cpp  -c $(FLAGS) -o Triangle_t.o

Vertex_t.o: $(VERTEX_PATH)Vertex_t.cpp $(VERTEX_PATH)Vertex_t.hpp
	g++ $(VERTEX_PATH)Vertex_t.cpp  -c $(FLAGS) -o Vertex_t.o

clean:
	rm $(objects) Test_Triangle_t.out