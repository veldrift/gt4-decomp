/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pack { char pad[0xC]; void *mgr; };
struct Obj { int unk0; Pack *pack; int unk8; int cells[6][4]; };
extern "C" int ScenePack__isValid(void *);
extern "C" int func_003E7488(void *);
extern "C" int func_003D5828(int, int);
extern "C" void func_005FA890(void *, int, int (*)(int, int));
extern "C" int func_003D59F8(Obj *o) {
    if (ScenePack__isValid(o)) {
        if (o->pack->mgr) {
            for (int i = 0; i < 6; i++) {
                int *base = (int *)((char *)o + 0xC);
                int *p = (int *)(i * 16 + (int)base);
                for (int j = 0; j < 4; j++) {
                    if (*p) {
                        func_005FA890(o->pack->mgr, *p, func_003D5828);
                        *p = 0;
                    }
                    p++;
                }
            }
        }
    }
    return func_003E7488(o);
}
