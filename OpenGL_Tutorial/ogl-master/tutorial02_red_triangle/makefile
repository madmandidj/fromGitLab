FLAGS = -ansi -pedantic -lglfw -lGL -lGLEW -g
NAME = tutorial02
NAME2 = ../common/shader
$(NAME).out: $(NAME).cpp
	g++ $(NAME).cpp $(NAME2).cpp $(FLAGS) -o $(NAME).out

clean:
	rm $(NAME).out