build:
	gcc -c -Wall -Wextra -fsanitize=address function_methods.c -lm -o methods.o -O0 -g3 -g
	gcc -c -Wall -Wextra -fsanitize=address function_in_details.c -lm -o details.o -O0 -g3 -g
	gcc -c -Wall -Wextra -fsanitize=address test.c -lm -o test.o -O0 -g3 -g
	gcc -c -Wall -Wextra -fsanitize=address out.c -lm -o out.o -O0 -g3 -g
	gcc -c -Wall -Wextra -fsanitize=address main.c  -lm -o main.o -O0 -g3 -g
	gcc *.o -lm -fsanitize=address -o bin -g
	rm *.o
