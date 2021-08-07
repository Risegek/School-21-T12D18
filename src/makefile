CC=gcc

CFLAGS=-Wall -Wextra -Werror

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

rebuild: clean all

print_module: main_module_entry_point.c print_module.c
	$(CC) $(CFLAGS) -o ../build/Quest_1 main_module_entry_point.c print_module.c -D print_module

documentation_module: main_module_entry_point.c documentation_module.c
	$(CC) $(CFLAGS) -o ../build/Quest_2 main_module_entry_point.c documentation_module.c -D documentation_module

bst_create_test: bst_create_test.c bst.c
	$(CC) $(CFLAGS) -o ../build/Quest_3 bst.c bst_create_test.c 

bst_insert_test: bst_insert_test.c bst.c
	$(CC) $(CFLAGS) -o ../build/Quest_4 bst.c bst_insert_test.c

bst_traverse_test: bst_traverse_test.c bst.c
	$(CC) $(CFLAGS) -o ../build/Quest_5 bst.c bst_traverse_test.c

check:
	python3 ../materials/linters/cpplint.py --extensions=c *c
	cppcheck --check-config --enable=all --suppress=missingIncludeSystem ./

clean:
	rm -f *.o
	rm ../build/Quest_*