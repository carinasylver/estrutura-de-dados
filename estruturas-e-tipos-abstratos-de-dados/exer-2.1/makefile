TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: horario.o
	ar rcs $@ $^

funcoes.o: horario.c horario.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



