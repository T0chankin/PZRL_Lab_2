TARGET = sed_simplified 
.PHONY: all clean run
all:$(TARGET)
main.o: main.c
	gcc -c -o main.o main.c
regex.o: regex.c
	gcc -c -o regex.o regex.c
$(TARGET): main.o regex.o
	gcc  main.o regex.o -o $(TARGET)
run:$(TARGET)
	./$(TARGET) input.txt 's/old_text_regex/new_text/'
clean:
	rm $(TARGET) *.o