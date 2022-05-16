TARGET = prog

$(TARGET): mainFilaSE.o lib.a
	gcc $^ -o $@

main.o: mainFilaSE.c
	gcc -c $< -o $@

lib.a: filaSE.o
	ar rcs $@ $^

funcoes.o: filaaSE.c filaSE.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



