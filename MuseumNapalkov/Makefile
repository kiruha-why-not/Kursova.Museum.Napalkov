CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

SRCS = main.cpp \
       classes/Room.cpp \
       classes/Exhibit.cpp \
       classes/Painting.cpp \
       classes/VolumetricExhibit.cpp \
       classes/Sculpture.cpp \
       classes/Technics.cpp \
       classes/HouseholdItem.cpp

TARGET = museum

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean
