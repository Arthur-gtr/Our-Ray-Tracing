TARGET = ray_tracer

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lm

SRC = raytracer.cpp

OBJ	= $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIBS) -I include -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean re
