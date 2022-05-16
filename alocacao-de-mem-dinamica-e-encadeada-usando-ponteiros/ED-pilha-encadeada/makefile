TARGET = prog

$(TARGET): mainPilhaSE.o lib.a
	gcc $^ -o $@

main.o: mainPilhaSE.c
	gcc -c $< -o $@

lib.a: pilhaSE.o
	ar rcs $@ $^

funcoes.o: pilhaSE.c pilhaSE.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)



