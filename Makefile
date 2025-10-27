TARGET = ray_tracer

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lm

SRC = main.cpp
OBJDIR = compiler
OBJ = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I include -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
