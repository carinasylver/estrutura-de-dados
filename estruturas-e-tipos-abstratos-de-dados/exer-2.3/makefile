TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: conta.o
	ar rcs $@ $^

funcoes.o: conta.c conta.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



