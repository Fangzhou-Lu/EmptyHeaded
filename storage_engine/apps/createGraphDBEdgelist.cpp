#include "main.hpp"

template<class T>
struct createGraphDBEdgelist: public application<T> {
  ////////////////////emitInitCreateDB////////////////////
  // init ColumnStores
  void run(std::string path){
    ////////////////////emitLoadEncodedColumnStore////////////////////
    EncodedColumnStore<void *> *Encoded_R = NULL;
    {
      auto start_time = debug::start_clock();
      Encoded_R = EncodedColumnStore<void *>::from_binary(
          "/Users/caberger/Documents/Research/code/databases/higgs/db/relations/R/");
      debug::stop_clock("LOADING ENCODED RELATION R", start_time);
    }

    ////////////////////emitReorderEncodedColumnStore////////////////////
    EncodedColumnStore<void *> *Encoded_R_0_1 =
        new EncodedColumnStore<void *>(&Encoded_R->annotation);
    {
      auto start_time = debug::start_clock();
      // encodeRelation
      Encoded_R_0_1->add_column(Encoded_R->column(0),
                                Encoded_R->max_set_size.at(0));
      Encoded_R_0_1->add_column(Encoded_R->column(1),
                                Encoded_R->max_set_size.at(1));
      debug::stop_clock("REORDERING ENCODING R_0_1", start_time);
    }

    ////////////////////emitBuildTrie////////////////////
    const size_t alloc_size_R_0_1 =
        8 * Encoded_R_0_1->data.size() * Encoded_R_0_1->data.at(0).size() *
        sizeof(uint64_t) * sizeof(TrieBlock<hybrid, void *>);
    allocator<uint8_t> *data_allocator_R_0_1 =
        new allocator<uint8_t>(alloc_size_R_0_1);
    Trie<void *> *Trie_R_0_1 = NULL;
    {
      auto start_time = debug::start_clock();
      // buildTrie
      Trie_R_0_1 = new Trie<void *>( 
          &Encoded_R_0_1->max_set_size,
          &Encoded_R_0_1->data, 
          &Encoded_R_0_1->annotation);
      debug::stop_clock("BUILDING TRIE R_0_1", start_time);
    }

    ////////////////////emitWriteBinaryTrie////////////////////
    {
      auto start_time = debug::start_clock();
      Trie_R_0_1->to_binary(
          "/Users/caberger/Documents/Research/code/databases/higgs/db/relations/R/R_0_1/");
      debug::stop_clock("WRITING BINARY TRIE R_0_1", start_time);
    }

    data_allocator_R_0_1->free();
    delete data_allocator_R_0_1;
    delete Trie_R_0_1;
    ////////////////////emitReorderEncodedColumnStore////////////////////
    EncodedColumnStore<void *> *Encoded_R_1_0 =
        new EncodedColumnStore<void *>(&Encoded_R->annotation);
    {
      auto start_time = debug::start_clock();
      // encodeRelation
      Encoded_R_1_0->add_column(Encoded_R->column(1),
                                Encoded_R->max_set_size.at(1));
      Encoded_R_1_0->add_column(Encoded_R->column(0),
                                Encoded_R->max_set_size.at(0));
      debug::stop_clock("REORDERING ENCODING R_1_0", start_time);
    }

    ////////////////////emitBuildTrie////////////////////
    const size_t alloc_size_R_1_0 =
        8 * Encoded_R_1_0->data.size() * Encoded_R_1_0->data.at(0).size() *
        sizeof(uint64_t) * sizeof(TrieBlock<hybrid, void *>);
    allocator<uint8_t> *data_allocator_R_1_0 =
        new allocator<uint8_t>(alloc_size_R_1_0);
    Trie<void *> *Trie_R_1_0 = NULL;
    {
      auto start_time = debug::start_clock();
      // buildTrie
      Trie_R_1_0 = new Trie<void *>(
          &Encoded_R_1_0->max_set_size,
          &Encoded_R_1_0->data, 
          &Encoded_R_1_0->annotation);
      debug::stop_clock("BUILDING TRIE R_1_0", start_time);
    }

    ////////////////////emitWriteBinaryTrie////////////////////
    {
      auto start_time = debug::start_clock();
      Trie_R_1_0->to_binary(
          "/Users/caberger/Documents/Research/code/databases/higgs/db/relations/R/R_1_0/");
      debug::stop_clock("WRITING BINARY TRIE R_1_0", start_time);
    }

    data_allocator_R_1_0->free();
    delete data_allocator_R_1_0;
    delete Trie_R_1_0;
  }
};

template<class T>
application<T>* init_app(){
  return new createGraphDBEdgelist<T>(); 
}
