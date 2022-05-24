TARGET = prog

$(TARGET): mainFila.o lib.a
	gcc $^ -o $@

main.o: mainFila.c
	gcc -c $< -o $@

lib.a: fila.o
	ar rcs $@ $^

funcoes.o: fila.c fila.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



