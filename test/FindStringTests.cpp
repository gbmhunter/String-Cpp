//!
//! @file 			FindStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-08-21
//! @brief 			Makes sure the String::Find() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(FindStringTests)
	{

		TEST(CStringPresentFindTest)
		{
			MbeddedNinja::String myString("Looking for the needle in the haystack.");

			// "needle" should be found, and Find() return 0-based index to first occurance
			CHECK_EQUAL(16, myString.Find("needle"));
		}

		TEST(StringPresentFindTest)
		{
			MbeddedNinja::String myString("Looking for the needle in the haystack.");

			MbeddedNinja::String stringToFind("needle");

			// "needle" should be found, and Find() return 0-based index to first occurance
			CHECK_EQUAL(16, myString.Find(stringToFind));
		}

		TEST(StringNotPresentFindTest)
		{
			MbeddedNinja::String myString("Looking for the needle in the haystack.");

			MbeddedNinja::String stringToFind("noneedle");

			// Char should not be found, and Find() should return -1
			CHECK_EQUAL(-1, myString.Find(stringToFind));
		}

		TEST(StringPresentMultipleTimesFindTest)
		{
			MbeddedNinja::String myString("Looking for the needle in the haystack full of needles.");

			MbeddedNinja::String stringToFind("needle");

			// Find should return first occurrance of "needle"
			CHECK_EQUAL(16, myString.Find(stringToFind));

			// Now look for second occurrance of the word needle
			CHECK_EQUAL(47, myString.Find(stringToFind, 17));
		}

	} // SUITE(FindStringTests)
} // namespace StringTestsNs
