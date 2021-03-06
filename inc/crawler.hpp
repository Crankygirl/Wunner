/**
 *
 * Author : Anishka Gupta
 * Created on : July 8, 2017
 *
 */

#ifndef CRAWLED_IDS
#define CRAWLED_IDS "res/crawled_ids"
#endif  // CRAWLED_IDS

#ifndef CRAWL_NUM_PAGE
#define CRAWL_NUM_PAGE 256
#endif  // CRAWL_NUM_PAGE

#ifndef CRAWL_SEED_SRC
#define CRAWL_SEED_SRC "res/crawl_seed"
#endif  // CRAWL_SEED_SRC

#ifndef PAGE_RANKS
#define PAGE_RANKS "res/page_ranks"
#endif  // PAGE_RANKS

#ifndef MAX_ITER_PAGE_RANK
#define MAX_ITER_PAGE_RANK 7
#endif  // MAX_ITER_PAGE_RANK

#ifndef CRAWLER
#define CRAWLER

#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "crawler_info.hpp"

namespace wunner
{

  class Crawler
  {
      private:
          std::unordered_set<std::string> visited;
          std::unordered_map<std::string, std::string> hashed;

      public:
          std::string get_id(std::string const &);
          std::string get_hash(std::string const &);
          int fetch_page_text(std::string const &, std::string const &) const;
          void crawl();
  };

  class PageRank
  {
      private:
          std::unordered_map<std::string, std::set<std::string>> adj_lst;       // the graph is expected to be sparse, hence using adjacency list

      public:
          void add_edge(std::string const &, std::string const &);
          void calculate_ranks(std::unordered_set<std::string> const &, std::unordered_map<std::string, int> &);
  };

}

#endif  // CRAWLER
