all : bsort.v
	
bsort.v : sort_gen
	./sort_gen > bsort.v

sort_gen : main.cpp
	g++ $< -o $@

clean : 
	rm -f sort_gen
	rm -f bsort.v

