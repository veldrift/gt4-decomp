#include "spr.h"
extern "C" int func_004A0080(void *) throw();
extern "C" int func_004A0160(void *) throw();
extern "C" int func_004A0640() {
    void *p = (void *)spr_base();
    func_004A0080(p);
    return func_004A0160(p);
}
