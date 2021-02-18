CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Wshadow \
			            --debug -fsanitize=address,undefined -D_GLIBCXX_DEBUG

MAKE_FLAG := --no-print-directory

%: INPUT = $(shell echo $@ | tr [:upper:] [:lower:]).in
%: EXE = x$@.exe
%: 
	@make $(MAKE_FLAG) $(EXE)
	@make $(MAKE_FLAG) $(INPUT)
	./$(EXE) < $(INPUT)

x%.exe: %.cpp
	g++ $(CXXFLAGS) -o $@ $<

%.in: 
	vim $@

clean:
	rm -f *.exe
