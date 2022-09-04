
#ifndef DEFINES_H
#define DEFINES_H

<<<<<<< HEAD
#define ASSERT_TOTAL_PROB(prob_sum,eps,message)		assert((abs(prob_sum-1) < eps) && (message))
#define ASSERT_PROB_RANGE(prob, a, b, message)		assert((prob > a) && (prob <= b) && (message))
#endif 
=======
#define ASSERT_TOTAL_PROB(prob_sum,eps,message)		assert((abs(prob_sum-1) < eps) && message)
#define ASSERT_PROB_RANGE(prob, a, b, message)			assert((prob > a) && (prob <= b) && message)
#endif 
>>>>>>> 0755e669a38b00218decf86afbbe6c3b9d2a9ba8
