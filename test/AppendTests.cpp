//!
//! @file 			AppendTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-08-21
//! @brief 			Makes sure the String::Append() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(AppendTests)
	{

		TEST(BasicAppendTest)
		{
			StringNs::String myString("Hello");

			myString.Append(", world!");

			CHECK_EQUAL("Hello, world!", myString.cStr);
		}

		TEST(LengthCorrectCheckTest)
		{
			StringNs::String myString("Hello");

			myString.Append(", world!");

			CHECK_EQUAL(13, myString.GetLength());
		}

		TEST(BasicAppendThroughPlusOperatorTest)
		{
			StringNs::String myString1("Hello");

			StringNs::String myString2(", world!");

			StringNs::String myString3 = myString1 + myString2;

			CHECK_EQUAL("Hello, world!", myString3.cStr);
		}

	} // SUITE(AppendTests)
} // namespace StringTestsNs
