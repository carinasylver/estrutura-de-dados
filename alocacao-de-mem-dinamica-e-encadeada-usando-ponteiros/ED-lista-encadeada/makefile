TARGET = prog

$(TARGET): mainListaSE.o lib.a
	gcc $^ -o $@

main.o: mainListaSE.c
	gcc -c $< -o $@

lib.a: listaSE.o
	ar rcs $@ $^

funcoes.o: listaSE.c listaSE.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)

