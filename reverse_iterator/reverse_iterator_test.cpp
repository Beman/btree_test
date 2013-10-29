#include <boost/btree/btree_index_set.hpp>
#include <boost/btree/support/string_view.hpp>
#include <iostream>
#include <boost/detail/lightweight_main.hpp>
#include "bi_data.hpp"

using std::cout;
using namespace boost::btree;

int cpp_main(int, char *[]) {
  typedef btree_index_set<bi_data_t> btree_by_key_t;
  typedef btree_index_set<bi_data_t, default_traits, value_ordering> btree_by_value_t;

  btree_by_key_t btree_by_key("bi_data.idx1", "bi_data.dat", flags::truncate);
  btree_by_value_t btree_by_value("bi_data.idx2", btree_by_key.file(),
                                  flags::truncate, -1, value_ordering());

  btree_by_key_t::file_position pos;

  pos = btree_by_key.push_back(bi_data_t(1, "one"));
  btree_by_key.insert_file_position(pos);
  btree_by_value.insert_file_position(pos);

  pos = btree_by_key.push_back(bi_data_t(2, "two"));
  btree_by_key.insert_file_position(pos);
  btree_by_value.insert_file_position(pos);

  pos = btree_by_key.push_back(bi_data_t(3, "three"));
  btree_by_key.insert_file_position(pos);
  btree_by_value.insert_file_position(pos);

  pos = btree_by_key.push_back(bi_data_t(0, "zero"));
  btree_by_key.insert_file_position(pos);
  btree_by_value.insert_file_position(pos);

  // forward lookup
  cout << "iterator by key:\n";
  for (btree_by_key_t::iterator it = btree_by_key.begin(); it != btree_by_key.end(); ++it) {
    cout << "    " << *it << "\n";
  }

  // reverse lookup
  cout << "iterator by value:\n";
  for (btree_by_value_t::iterator it = btree_by_value.begin(); it != btree_by_value.end(); ++it) {
    cout << "    " << *it << "\n";
  }

  // reverse iterator test
  // forward lookup using reverse iterator
  cout << "reverse iterator by key:\n";
  for (btree_by_key_t::const_reverse_iterator rit = btree_by_key.crbegin(); rit != btree_by_key.crend(); ++rit) {

    // this works
    cout << "    " << *rit << "\n";

    // this fails
    cout << "    " << rit->key << "\n";

    // this works
    cout << "    " << (*rit).key << "\n";

    // this works
    bi_data_t *bi_data = new bi_data_t;
    cout << "    " << bi_data->key << "\n";
  }

  // reverse lookup using reverse iterator
  cout << "reverse iterator by value:\n";
  for (btree_by_value_t::const_reverse_iterator rit = btree_by_value.crbegin(); rit != btree_by_value.crend(); ++rit) {
    cout << "    " << *rit << "\n";
  }

  return 0;
}

