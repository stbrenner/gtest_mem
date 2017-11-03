/**
 * @file
 * @copyright (c) 2013 Stephan Brenner
 * @license   This project is released under the MIT License.
 *
 * This file implements a main() function for Google Test that runs all tests
 * and detects memory leaks.
 */

#include <iostream>
#include <crtdbg.h>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

namespace testing
{
  class MemoryLeakDetector : public EmptyTestEventListener
  {
#ifdef _DEBUG
  public:
    virtual void OnTestStart(const TestInfo&)
    {
      _CrtMemCheckpoint(&memState_);
    }

    virtual void OnTestEnd(const TestInfo& test_info){
      if(test_info.result()->Passed())
      {
        _CrtMemState stateNow, stateDiff;
        _CrtMemCheckpoint(&stateNow);
        int diffResult = _CrtMemDifference(&stateDiff, &memState_, &stateNow);
        if (diffResult)
        {
          FAIL() << "Memory leak of " << stateDiff.lSizes[1] << " byte(s) detected.";
        }
      }
    }

  private:
    _CrtMemState memState_;
#endif // _DEBUG
  };
}

GTEST_API_ int main(int argc, char **argv)
{
  cout << "Running main() from gtest_mld_main.cpp" << endl;

  InitGoogleTest(&argc, argv);
  UnitTest::GetInstance()->listeners().Append(new MemoryLeakDetector());

  return RUN_ALL_TESTS();
}
