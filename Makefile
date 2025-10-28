TARGET = ray_tracer

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lm

INC = -I include
INC += -I include/engine
INC += -I include/parser_cmd

SRC = main.cpp

PARSING =  src/ParserCmd/parse_flag.cpp
PARSING += src/ParserCmd/getter/get_config.cpp
PARSING += src/ParserCmd/getter/get_error.cpp

ENGINE  = src/Engine/builder.cpp
ENGINE += src/Engine/set_config.cpp
ENGINE += src/Engine/run.cpp

SRC += $(PARSING)
SRC += $(ENGINE)

OBJDIR = compiler
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.cpp=.o)))


all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
