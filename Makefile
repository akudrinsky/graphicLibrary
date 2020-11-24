CXX      := g++
CXXFLAGS := -std=c++17 -pedantic-errors -Wall -Wextra -Werror -O3
LDFLAGS  := -Wall -lsfml-graphics -lsfml-window -lsfml-system
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/
TARGET   := app
INCLUDE  := 
SRC      :=                           								\
   	$(wildcard kudry/window/RectangleWindow/*.cpp)      			\
	$(wildcard kudry/window/SystemWindow/*.cpp)      				\
	$(wildcard kudry/window/RectangleButton/*.cpp)      			\
	$(wildcard kudry/window/Components/*.cpp)         				\
	$(wildcard kudry/window/Components/Shapes/*.cpp)    			\
	$(wildcard kudry/window/Scrollbar/*.cpp)    					\
	$(wildcard kudry/window/Button/*.cpp)         					\
	$(wildcard kudry/engine/SFML/*.cpp)     						\
	$(wildcard kudry/engine/OpenGL/*.cpp)  							\
	$(wildcard kudry/window/FigureDrawer/*.cpp)  					\
	$(wildcard kudry/simpleGraphics/color/*.cpp)        			\
	$(wildcard kudry/application/*.cpp)          					\
	$(wildcard kudry/application/SubscriptionManager/*.cpp)     	\
	$(wildcard kudry/engine/*.cpp)          						\
	$(wildcard kudry/window/*.cpp)          						\
	$(wildcard kudry/window/Text/*.cpp)          					\
	$(wildcard kudry/window/Instrument/Instrument.cpp)          	\
	$(wildcard files-dialog/main.cpp)          						\

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

run: $(APP_DIR)/$(TARGET)
	./$(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -Wshadow -Wformat=2 -Wfloat-equal \
				   -Wconversion \
				   -Wcast-qual -Wcast-align       \
				   -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC       \
				    -fsanitize=address 		    \
				   -fsanitize=undefined 	\
				   -fstack-protector -Wno-format-nonliteral    \
				   -Wno-shadow
debug: all

findcpp:
	find . -name '*.cpp'

release: CXXFLAGS += -Wno-unused-parameter
release: all

clean:
	-@rm -rvi $(OBJ_DIR)/*
	-@rm -rvi $(APP_DIR)/*
