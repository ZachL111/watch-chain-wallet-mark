#include "policy.h"
#include <assert.h>
#include <string.h>

int main(void) {
    Signal signal_case_1 = {67, 86, 16, 25, 13};
    assert(score_signal(signal_case_1) == 49);
    assert(strcmp(classify_signal(signal_case_1), "review") == 0);
    Signal signal_case_2 = {79, 87, 9, 13, 11};
    assert(score_signal(signal_case_2) == 171);
    assert(strcmp(classify_signal(signal_case_2), "accept") == 0);
    Signal signal_case_3 = {92, 78, 19, 21, 6};
    assert(score_signal(signal_case_3) == 82);
    assert(strcmp(classify_signal(signal_case_3), "review") == 0);
    return 0;
}
