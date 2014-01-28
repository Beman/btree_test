// Test to manifest the use_count bug, 1/15/2014

#include "file_modes.h"
#include "map_btree.hpp"
#include <iostream>
#include <cstdio>
#include <boost/detail/lightweight_main.hpp>

namespace
{
  typedef map_btree_t<uint64_t, uint64_t> map_t;

  const char temp_file[] = "temp_file";

  void create_new_map()
  {
    // create new map
    map_t map(temp_file, RW_NEW);

    // check count
    size_t size __attribute__((unused));
    size = map.size();

    // change entry invalid
    map_t::map_const_iterator_bool_pair it_bool_pair = map.change(6000006, 60);

    // check count stayed same
    size = map.size();
  }
  
  void reopen_existing_map()
  {
    // open and reclose Read Only
    map_t map(temp_file, READ_ONLY);
  }

}  // unnamed namespace

int cpp_main(int argc, char* argv[]) {

  // clean up from any previous run
  remove(temp_file);

  create_new_map();
  reopen_existing_map();

  std::cout << "Almost done.\n";

  // done
  return 0;
}

