#include <iostream>
#include <memory>

#include <gtest/gtest.h>

#include "bst.cpp"


TEST(BSTTest, InsertAndContains) {
  BST<int> bst;

  // check if doesnt' contains
  EXPECT_FALSE(bst.contains(10));
  EXPECT_FALSE(bst.contains(0));

  // insert some elements
  // and check if contains would return
  // true
  bst.insert(10);
  bst.insert(0);

  EXPECT_TRUE(bst.contains(10));
  EXPECT_TRUE(bst.contains(0));

}



int main(int argc, char* argv[]) {

  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return 0;
}
