FLAGS = -ansi -pedantic -lglfw -lGL -lGLEW -g
NAME = Vertex_t

Test_$(NAME).out: Test_$(NAME).cpp $(NAME).cpp $(NAME).hpp
	g++ Test_$(NAME).cpp $(NAME).cpp $(FLAGS) -o Test_$(NAME).out

clean:
	rm Test_$(NAME).out