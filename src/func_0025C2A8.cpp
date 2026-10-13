#include "gt4/mSceneViewFace.h"
typedef int s32;

extern "C" void func_0025A810(s32 arg0, void *arg1);

extern "C" void mSceneViewFace__virtual_94(struct mSceneViewFace *arg0, s32 arg1) {
    char *p = (char *)arg0 + 0x30;
    if (*(void **)(p) != 0) {
        func_0025A810(arg1, p);
    }
}
