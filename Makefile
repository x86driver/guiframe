TARGET = gui

CFLAGS = -Wall -Wextra -g
#CFLAGS += -Weffc++

all: $(TARGET)

gui:gui.cpp
	g++ $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)
