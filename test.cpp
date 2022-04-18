#include "histogram.h"
#include "svg.h"
#include <ostream>

#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void
test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void
test_same_numbers() {
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}
void
test_one_number() {
    double min = 0;
    double max = 0;
    find_minmax({2}, min, max);
    assert(min == 2);
    assert(max == 2);
}
void
test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void
triplePositive() {

    stringstream stream;
    string str = "<line x1='0' y1='0' x2='100' y2='100' stroke='black' stroke-dasharray ='25 10' />'";
    svg_separator(0,0, 100, 100, 25, 10, stream);
    string str2;
    getline(stream,str2);
    cout<<str2;
    assert(str2 == str);
}

int
main() {
    test_positive();
    test_negative();
    test_same_numbers();
    test_one_number();
    test_empty();
    triplePositive();
}
