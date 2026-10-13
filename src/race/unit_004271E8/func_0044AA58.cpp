typedef int s32;

struct Obj {
    s32 pad0;
    s32 count;
};

extern "C" s32 *func_0044A830(Obj *, s32) throw();
extern "C" s32 *func_0044A860(Obj *, s32) throw();
extern "C" s32 *func_0044A898(Obj *, s32) throw();

extern "C" s32 func_0044AA58(Obj *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 best = -1;

    for (i = 0; i < arg0->count; i++) {
        if (*func_0044A860(arg0, i) == -1) {
            continue;
        }
        if (arg1 != *func_0044A830(arg0, i)) {
            continue;
        }
        if (arg2 != *func_0044A898(arg0, i)) {
            continue;
        }
        best = i;
        break;
    }
    return best;
}
