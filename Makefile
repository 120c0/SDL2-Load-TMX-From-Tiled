TARGET = App

CPP_FILES = $(shell find src -type f -iname *.cpp)
OBJECTS = $(CPP_FILES:.cpp=.o)

LIBS = -ltinyxml2 -lSDL2 -lSDL2_image
INCLUDE = -Iinclude
CXXFLAGS = -Wall -Werror -Wextra $(INCLUDE)

all: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm $(OBJECTS) $(TARGET)