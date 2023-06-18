gcccleanunuse_normal:
	gcc -c gcccleanunuse.c
	gcc -o $@ gcccleanunuse.o

gcccleanunuse_special:
	gcc -ffunction-sections -fdata-sections -c gcccleanunuse.c
	gcc -Wl,--gc-sections -o $@ gcccleanunuse.o

clean:
	rm -rf *.o gcccleanunuse_normal gcccleanunuse_special
