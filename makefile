ifeq ($(OS), Windows_NT)
	INCLUDES := include\\
	BUILD := build\\
	BIN := bin\\
	EXECUTABLE := $(BIN)Assignment3.exe
	SOURCE := source\\
	DELETE := del
else
	INCLUDES := include/
	BUILD := build/
	BIN := bin/
	EXECUTABLE := $(BIN)Assignment3
	SOURCE := source/
	DELETE := rm
endif

CPP := g++
CPPFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Werror

all: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD)Tests.o $(BUILD)MemoryLeakChecker.o $(BUILD)Main.o $(BUILD)Shape.o $(BUILD)ShapeContainer.o $(BUILD)Circle.o $(BUILD)Rectangle.o
	$(CPP) $(CPPFLAGS) $(BUILD)Tests.o $(BUILD)MemoryLeakChecker.o $(BUILD)Main.o $(BUILD)Shape.o $(BUILD)ShapeContainer.o $(BUILD)Circle.o $(BUILD)Rectangle.o -o $(EXECUTABLE)

$(BUILD)Tests.o: $(SOURCE)Tests.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)Tests.cpp -I$(INCLUDES) -o $(BUILD)Tests.o
	
$(BUILD)MemoryLeakChecker.o: $(SOURCE)MemoryLeakChecker.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)MemoryLeakChecker.cpp -I$(INCLUDES) -o $(BUILD)MemoryLeakChecker.o
	
$(BUILD)Main.o: $(SOURCE)Main.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)Main.cpp -I$(INCLUDES) -o $(BUILD)Main.o

$(BUILD)Shape.o: $(SOURCE)Shape.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)Shape.cpp -I$(INCLUDES) -o $(BUILD)Shape.o

$(BUILD)ShapeContainer.o: $(SOURCE)ShapeContainer.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)ShapeContainer.cpp -I$(INCLUDES) -o $(BUILD)ShapeContainer.o

$(BUILD)Circle.o: $(SOURCE)Circle.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)Circle.cpp -I$(INCLUDES) -o $(BUILD)Circle.o
	
$(BUILD)Rectangle.o: $(SOURCE)Rectangle.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)Rectangle.cpp -I$(INCLUDES) -o $(BUILD)Rectangle.o


clean:
	-$(DELETE) $(EXECUTABLE) 
	-$(DELETE) $(BUILD)Tests.o
	-$(DELETE) $(BUILD)MemoryLeakChecker.o
	-$(DELETE) $(BUILD)Main.o
	-$(DELETE) $(BUILD)Shape.o
	-$(DELETE) $(BUILD)ShapeContainer.o
	-$(DELETE) $(BUILD)Circle.o
	-$(DELETE) $(BUILD)Rectangle.o
