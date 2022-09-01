
#ifndef DEFINES_H
#define DEFINES_H

#define ASSERT_TOTAL_PROB(prob_sum,eps,message)		assert((abs(prob_sum-1) < eps) && message)
#define ASSERT_RANGE_PROB(prob, a, b, message)			assert((prob > a) && (prob <= b) && message)
#endif 