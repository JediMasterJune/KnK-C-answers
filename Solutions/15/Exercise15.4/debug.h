//
//

#ifndef PRACTICE_DEBUG_H
#define PRACTICE_DEBUG_H

#ifdef DEBUG
#define PRINT_DEBUG(n) printf("Value of " #n ": %d\n", n)
#else
#define PRINT_DEBUG(n)
#endif

#endif //PRACTICE_DEBUG_H
