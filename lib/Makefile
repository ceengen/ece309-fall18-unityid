
# add files you create here
OBJ = example.o StringList.o MaxHeap.o IntInf.o 

all: libece309.a

test: all

# add files you want to remove here
clean:
	rm -f *~ libece309.a $(OBJ)

libece309.a: $(OBJ)
	$(AR) -r $@ $(OBJ) 

%.o:%.cpp
	$(CXX) -c -o $@ -I . -I ../include $< -std=c++11 -Wall -Werror
