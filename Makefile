CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
LDFLAGS ?= -lsfml-audio -lsfml-system
PREFIX ?= /usr/local

TARGET = cpplayer
SRC = src/cpplayer.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

install: $(TARGET)
	install -Dm755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all install uninstall clean
