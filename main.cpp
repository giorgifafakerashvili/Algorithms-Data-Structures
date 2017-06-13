#include <iostream>
#include <gtest/gtest.h>


/**
 * Wrapper class for our function
 */
class MaximumCoins {
private:
  int SolutionUtil(const std::vector<int>& data) {
#ifdef DEBUG
    std::cout << "print data size " << data.size() << "\t " << __LINE__ << std::endl;
#endif
    /**
     * Data is alreay augmented
     */

    // dp table for tabulation
    // fill it with zeros
    std::vector<std::vector<int>> dp(data.size(), std::vector<int>(data.size(), 0));

    dp[0][0] = 1;
    dp[data.size()-1][data.size()-1] = 1;

    for(int i = 1; i < data.size()-1; ++i) {
      dp[i][i] = data[i] * data[i-1] * data[i+1];
    }

#ifdef DEBUG
    std::cout << "Debug ==> \tprint one length substring values from dp array" << std::endl;
    for(int i = 0; i < data.size()-2; ++i) {
      std::cout << dp[i][i] << "\t";
    }
    std::cout << std::endl;
#endif

    // try every subset starting with 2 length subsets
    // up to n length substes
    for(int length = 2; length <= data.size()-2; ++length) {
      for(int start = 1; start  + length < data.size()-1; ++start) {
        int end = start + length - 1;

        // try every elment between [start, end];
        int result {0};
        for(int k = start; k <= end; ++k) {
          // sub_solution is same as removing kth element last
          int sub_solution = data[k] * data[start-1] * data[end+1] + dp[start][k-1] + dp[k+1][end];
          result = std::max(result, sub_solution);
        }

        // save it in dp array for future uses
        dp[start][end] = result;
      }
    }

    return dp[1][data.size()-1];
  }


public:
  int Solution(const std::vector<int>& coins) {
    // base case: if empty ->
    if(coins.empty()) return 0;

    // if just one element return it
    if(coins.size() == 1) return coins[0];

    // augment the array adding 1's before head and after tail
    std::vector<int> coins_copy (coins);
    // insert in first position
    coins_copy.insert(coins_copy.begin(), 1);

    // append at the end of the array
    coins_copy.push_back(1);

    return SolutionUtil(coins_copy);
  }
};

int main(int argc, char* argv[]) {

  std::vector<int> coins {3, 1, 5, 8};
  MaximumCoins max_coins;

  std::cout << max_coins.Solution(coins) << std::endl;

  return 0;
}
