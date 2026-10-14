#include "types.h"
#define NULL 0

extern "C" {
void func_003E7438(void *);
s32 ScenePack__isValid(void *);
s32 func_005FA820(void *, void *);
void func_00454698(void *, s32, void *, s32);
extern char D_006A3240[];
extern char func_003D5808[];
}

extern "C" void func_003D5920(char *arg0) {
    s32 s1;
    s32 s3;
    s32 v0;
    s32 *base;
    s32 *e;

    func_003E7438(arg0);
    if (ScenePack__isValid(arg0) != 0) {
        s3 = 0;
        if (*(s32 *)(*(char **)(arg0 + 4) + 0xC) != 0) {
            do {
                s1 = 0;
                do {
                    v0 = func_005FA820(*(void **)(*(char **)(arg0 + 4) + 0xC), func_003D5808);
                    base = (s32 *)(arg0 + 0xC);
                    e = base + (s3 * 4 + s1);
                    *e = v0;
                    if (v0 != 0) {
                        func_00454698(*(void **)(*(char **)(arg0 + 4) + 0xC), v0, D_006A3240, 1);
                    }
                    s1++;
                } while (s1 < 4);
                s3++;
            } while (s3 < 6);
        }
    }
}
