# A simple makefile that concatenates data.s to the end of e5.s
# and then compiles the result

e5:  e5.s data.s appendData 
	gcc -g e5.s  -o e5
	cp -f e5.s.bak e5.s 

appendData: 
	touch e5.s.bak
	cp -f e5.s.bak e5.s.bak.bak
	cp -f e5.s e5.s.bak
	cat data.s >> e5.s 

clean:
	rm -f e5 e5.s.bak e5.s.bak.bak 
