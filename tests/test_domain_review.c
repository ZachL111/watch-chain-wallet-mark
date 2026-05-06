#include "domain_review.h"
#include <assert.h>
#include <string.h>

int main(void) {
    DomainReview item = {58, 22, 9, 47};
    assert(domain_review_score(item) == 158);
    assert(strcmp(domain_review_lane(item), "ship") == 0);
    return 0;
}
