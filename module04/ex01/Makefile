NAME = Animal
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp 
OBJ = $(SRC:.cpp=.o)
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

