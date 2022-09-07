

#ifndef DEFINES_H
#define DEFINES_H

#define ASSERT_TOTAL_PROB(prob_sum,eps,message)		assert((abs(prob_sum-1) < eps) && (message))
#define ASSERT_PROB_RANGE(prob, a, b, message)		assert((prob > a) && (prob <= b) && (message))
#define ASSERT_EQUAL_SIZES(probs,codes, message)	assert((probs.size() == codes.size()) && (message));

using codingStrategy_t = std::function<void(vector<double>&, vector<string>&)>;

inline int gSTAR_COUNT = 100;
#endif 

