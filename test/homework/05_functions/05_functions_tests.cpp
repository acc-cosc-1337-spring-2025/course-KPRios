#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "func.h" 

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Testing get_gc_content function", "[get_gc_content]") {
    REQUIRE(get_gc_content("AGCTATAG") == Approx(0.375).epsilon(0.001));
    REQUIRE(get_gc_content("CGCTATAG") == Approx(0.50).epsilon(0.001));
}

TEST_CASE("Testing get_reverse_string function", "[get_reverse_string]") {
    REQUIRE(get_reverse_string("AGCTATAG") == "GATATCGA");
    REQUIRE(get_reverse_string("CGCTATAG") == "GATATCGC");
}

TEST_CASE("Testing get_dna_complement function", "[get_dna_complement]") {
    REQUIRE(get_dna_complement("AAAACCCGGT") == "ACCGGGTTTT");
    REQUIRE(get_dna_complement("CCCGGAAAAT") == "ATTTTCCGGG");
}
