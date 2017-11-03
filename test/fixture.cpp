/**
 * @file
 * @copyright (c) 2013 Stephan Brenner
 * @license   This project is released under the MIT License.
 *
 * This file contains test cases for the gtest_memory_leak_detector.
 */

#include <malloc.h>
#include <gtest/gtest.h>

TEST(MemCheck, MemoryLeak)
{
  malloc(7);
  // Should fail as 7 bytes are not freed.
}

TEST(MemCheck, NoMemoryLeak)
{
  // Should succeed as there is no memory leak.
}