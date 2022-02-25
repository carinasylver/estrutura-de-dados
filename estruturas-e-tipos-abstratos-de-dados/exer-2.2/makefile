TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: aluno.o
	ar rcs $@ $^

funcoes.o: aluno.c aluno.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



