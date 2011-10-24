TARGET = gui
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix ,$(notdir $(CPP_FILES:.cpp=.o)))

CFLAGS = -Wall -Wextra -g
CFLAGS += `sdl-config --cflags --libs`
CFLAGS += -I/usr/local/include/SDL -L/usr/local/lib -lSDL_ttf
CFLAGS += -Weffc++ -std=gnu++0x

all: $(TARGET)

%.o:%.cpp
	g++ $(CFLAGS) -c -o $@ $<

gui:$(OBJ_FILES)
	g++ $(CFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) *.o
