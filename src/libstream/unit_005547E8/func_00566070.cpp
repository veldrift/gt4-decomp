#include "types.h"
#define NULL 0

struct Obj {
    char pad0[0x14];
    int active;
    char pad18[0x5C - 0x18];
    void *sender;
    Obj *map;
};

extern "C" int func_005657E0(Obj *o, int i, int *out);
extern "C" void func_00553EF8(void *sender, Obj *self, int index, int type, void *data, int size, int flag);

extern "C" void func_00566070(Obj *self, int value) {
    int index;
    if (self->active != 0 && func_005657E0(self->map, value, &index) == 0)
        func_00553EF8(self->sender, self, index, 6, NULL, 0, 1);
}
