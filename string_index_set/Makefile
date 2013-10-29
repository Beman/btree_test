# include /usr/include/boost
# include local btree/include/boost/btree
# include endian
# include btree
# include some boost_* libraries when linking

all: binary_file.o buffer_manager.o
	g++ string_index_set.cpp binary_file.o buffer_manager.o -I /usr/include/boost -I ../endian/include -I ../btree/include -lboost_system -L/usr/lib64 -lboost_filesystem -lboost_iostreams -o string_index_set

binary_file.o:
	g++ ../btree/src/detail/binary_file.cpp -c -I /usr/include/boost -I ../endian/include -I ../btree/include

buffer_manager.o:
	g++ ../btree/src/detail/buffer_manager.cpp -c -I /usr/include/boost -I ../endian/include -I ../btree/include

clean:
	rm -rf *.o string_index_set string_index.dat string_index.ndx

