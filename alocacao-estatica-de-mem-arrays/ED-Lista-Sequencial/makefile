TARGET = prog

$(TARGET): mainListaCF.o lib.a
	gcc $^ -o $@

main.o: mainListaCF.c
	gcc -c $< -o $@

lib.a: listaCF.o
	ar rcs $@ $^

funcoes.o: listaCF.c listaCF.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



