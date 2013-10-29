#include <boost/detail/lightweight_main.hpp>
#include "bi_data_types.hpp"
#include "bi_store.hpp"

typedef bi_store_t<bi_data_64_pair_t> store_t;
typedef std::pair<uint64_t, uint64_t> pair_t;

int cpp_main(int, char *[]) {

/*
  store_t *bi_store = new store_t("test_db", boost::btree::flags::truncate);

  bi_store->insert_value(pair_t(10,11));
  bi_store->insert_value(pair_t(20,21));
  bi_store->insert_value(pair_t(30,31));

  delete bi_store;
*/

  // read_only test
  store_t *bi_store_ro = new store_t("test_db", boost::btree::flags::read_only);
  uint64_t key;
  pair_t value;
  bi_store_ro->get_value(1, value);
  std::cout << "ro by key: " << value.first << ", " << value.second << "\n";
  bi_store_ro->get_key(pair_t(20,21), key);
  std::cout << "ro by value: " << key << "\n";

  delete bi_store_ro;

  return 0;
}

