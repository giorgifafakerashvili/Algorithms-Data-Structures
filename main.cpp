#include <iostream>
#include <gtest/gtest.h>


/**
 * Interface for ComputeEngine
 * every compute engine must derived from this class
 */
class BaseComputeEngine {
public:
  /**
   * We've got only one function
   */
  virtual int Compute(int input) = 0;
};

class ComputeEngine : public BaseComputeEngine {
public:
  int Compute(int input) {
    // TODO: compute something
    // it's based on implementation
    return input * input;
  }
};

/*
 * ComputeFunction on input
 * this should return 0 when data = 0
 */
int ComputeFunction(int data, BaseComputeEngine* engine) {
  return engine->Compute(data);
}


//
//  compute_function_test.cpp
//

class MockComputeEngine : public BaseComputeEngine {
public:
  int result_to_be_returned_;


  MockComputeEngine(int data = 0)
    : result_to_be_returned_(data) {}


  // actual interface function
  int Compute(int input) {
    return result_to_be_returned_;
  }

};


TEST(ComputeFunctionTest, ComputeFunction) {
  MockComputeEngine* mock_engine = new MockComputeEngine();
  mock_engine->result_to_be_returned_ = 0;
  EXPECT_EQ(ComputeFunction(0, mock_engine), 0);

  mock_engine->result_to_be_returned_ = 17;
  EXPECT_EQ(ComputeFunction(10, mock_engine), 17);
  
}

int main(int argc, char* argv[]) {


  ::testing::InitGoogleTest(&argc, argv);
  auto ret = RUN_ALL_TESTS();

  return 0;
}
