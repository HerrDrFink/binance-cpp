#pragma once

#include <json.hpp>
using json = nlohmann::json;

#include <vector>
#include <string>
using namespace std;

namespace binance {
  namespace types {
    struct TickerPrice {
      string symbol;
      string price;
    };

    void to_json(json& j, const TickerPrice& t) {
      j = json{
        { "symbol", t.symbol },
        { "price", t.price }
      };
    }

    void from_json(const json& j, TickerPrice& t) {
      t.symbol = j.at("symbol").get<string>();
      t.price = j.at("price").get<string>();
    }
  }
}