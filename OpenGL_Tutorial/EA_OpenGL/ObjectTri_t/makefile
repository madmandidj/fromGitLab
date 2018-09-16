FLAGS = -ansi -pedantic -lglfw -lGL -lGLEW -g
TRIANGLE_PATH=../Triangle_t/
VERTEX_PATH =../Vertex_t/
objects = Vertex_t.o Triangle_t.o Object_t.o Test_Object_t.o

Test_Object_t.out: $(objects)
	g++ $(objects) -o Test_Object_t.out

Test_Object_t.o: Test_Object_t.cpp Object_t.hpp $(TRIANGLE_PATH)Triangle_t.hpp $(VERTEX_PATH)Vertex_t.hpp 
	g++ Test_Object_t.cpp  -c $(FLAGS) -o Test_Object_t.o

Object_t.o: Object_t.cpp Object_t.hpp $(TRIANGLE_PATH)Triangle_t.hpp $(VERTEX_PATH)Vertex_t.hpp 
	g++ Object_t.cpp  -c $(FLAGS) -o Object_t.o

Triangle_t.o: $(TRIANGLE_PATH)Triangle_t.cpp $(TRIANGLE_PATH)Triangle_t.hpp $(VERTEX_PATH)Vertex_t.hpp
	g++ $(TRIANGLE_PATH)Triangle_t.cpp  -c $(FLAGS) -o Triangle_t.o

Vertex_t.o: $(VERTEX_PATH)Vertex_t.cpp $(VERTEX_PATH)Vertex_t.hpp
	g++ $(VERTEX_PATH)Vertex_t.cpp  -c $(FLAGS) -o Vertex_t.o

clean:
	rm $(objects) Test_Object_t.out