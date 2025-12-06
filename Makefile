CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -I./test
OBJ=./test/main.o ./test/SSD1306.o 

./test/main: $(OBJ)
	$(CC) $(OBJ) -o $@

./test/main.o: ./test/main.c ./test/SSD1306.h
	$(CC) $(CFLAGS) -c $< -o $@

./test/SSD1306.o: ./test/SSD1306.c ./test/SSD1306.h
	$(CC) $(CFLAGS) -c $< -o $@

./test/SSD1306_cmd.o: ./test/SSD1306_cmd.c ./test/SSD1306.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) ./test/main