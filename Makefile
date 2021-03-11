# demo: demo.o arraylist.o
# 	gcc -g -std=c99 -Wvla -Wall -fsanitize=address,undefined -o demo demo.o arraylist.o

# demo.o: demo.c arraylist.h
# 	gcc -c -g -std=c99 -Wvla -Wall -fsanitize=address,undefined demo.c

# arraylist.o: arraylist.c arraylist.h
# 	gcc -c -g -std=c99 -Wvla -Wall -fsanitize=address,undefined arraylist.c


# # separate version of arraylist.o with debugging text enabled
# darraylist.o: arraylist.c arraylist.h
# 	gcc -c -g -std=c99 -Wvla -Wall -fsanitize=address,undefined -DDEBUG -o darraylist.o arraylist.c

# ddemo: demo.o darraylist.o
# 	gcc -g -std=c99 -Wvla -Wall -fsanitize=address,undefined -o demo demo.o darraylist.o

# clean:
# 	rm -f *.o demo ddemo

strbufDemo: strbufDemo.o strbuf.o
	gcc -g -std=c99 -Wvla -Wall -fsanitize=address,undefined -o demo strbufDemo.o strbuf.o

strbufDemo.o: strbufDemo.c strbuf.h
	gcc -c -g -std=c99 -Wvla -Wall -fsanitize=address,undefined strbufDemo.c

strbuf.o: strbuf.c strbuf.h
	gcc -c -g -std=c99 -Wvla -Wall -fsanitize=address,undefined strbuf.c


# separate version of arraylist.o with debugging text enabled
dstrbuf.o: strbuf.c strbuf.h
	gcc -c -g -std=c99 -Wvla -Wall -fsanitize=address,undefined -DDEBUG -o dstrbuf.o strbuf.c

dstrbufDemo: strbufDemo.o dstrbuf.o
	gcc -g -std=c99 -Wvla -Wall -fsanitize=address,undefined -o demo strbufDemo.o dstrbuf.o

clean:
	rm -f *.o strbufDemo dstrbufDemo