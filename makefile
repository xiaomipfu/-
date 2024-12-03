a.out:main.o std.o 
	gcc *.o -o $@
%.o:%.c
	gcc -c $< -o $@

clean:
	rm -rf a.out *.o