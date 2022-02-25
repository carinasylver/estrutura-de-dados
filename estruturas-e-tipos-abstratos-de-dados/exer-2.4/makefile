TARGET = prog

$(TARGET): main.o lib.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

lib.a: cheque.o
	ar rcs $@ $^

funcoes.o: cheque.c cheque.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



