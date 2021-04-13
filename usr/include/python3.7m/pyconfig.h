//#include <bits/wordsize.h>

#if __WORDSIZE == 32
#include "pyconfig-32.h"
#else __WORDSIZE == 64
#include "pyconfig-64.h"
#endif
