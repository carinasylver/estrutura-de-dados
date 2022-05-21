TARGET = prog

$(TARGET): mainListaDE.o lib.a
	gcc $^ -o $@

main.o: mainListaDE.c
	gcc -c $< -o $@

lib.a: listaDE.o
	ar rcs $@ $^

funcoes.o: listaDE.c listaDE.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



