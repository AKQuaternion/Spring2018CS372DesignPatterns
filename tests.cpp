#include "catch.hpp"
#include "Expression.hpp"
using std::map;
using std::string;
#include "Composite.hpp"
#include "Visitor.hpp"
#include <memory>
using std::unique_ptr;
using std::make_unique;
using std::move;

TEST_CASE( "We can make and add numbers", "[Expression]" ) {
    unique_ptr<Expression> pi = make_unique<Number>(3.14159);
    REQUIRE( pi->evaluate({}) == Approx(3.14159));
    unique_ptr<Term> two = make_unique<Number>(2.0);
    auto sum = make_unique<Sum>(move(pi),move(two));
    REQUIRE( sum->evaluate({}) == Approx(5.14159));
    REQUIRE( sum->toString() == "3.141590+2.000000");
}
