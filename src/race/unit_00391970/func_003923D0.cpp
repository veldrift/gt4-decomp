/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_00391970(void *, void *) throw();
extern "C" void func_0044CD10(void *, void *);
extern "C" int func_0057DA20(void *, const char *, ...);
extern "C" void func_004627E8();
extern char D_006A02D8[], D_006A02F0[], D_00623A50[];
extern char *D_006213F8[];
struct Engine { char pad[0x10]; int sample; char pad2[4]; int size; char pad3[4]; Engine *link; };
struct Pair { void (*fn)(); void *obj; };
extern "C" void func_003923D0(char *self, int id, int type) {
    Engine *second = (Engine *)(self + 0x2d0);
    char *buf1 = self + 0xaf8;
    Engine *first = (Engine *)(self + 0x30);
    int sample = *(int *)(self + 0xaf4);
    first->sample = sample;
    first->size = 0x25800;
    first->link = second;
    second->sample = sample;
    second->size = 0x25800;
    func_0057DA20(buf1, D_006A02D8, id);
    Pair pair;
    pair.fn = func_004627E8;
    pair.obj = first;
    func_0044CD10(buf1, &pair);
    char *buf2 = self + 0xb18;
    func_0057DA20(buf2, D_006A02F0, D_006213F8[type], id);
    pair.fn = func_004627E8;
    pair.obj = second;
    func_0044CD10(buf2, &pair);
    func_00391970(self + 0x154, D_00623A50);
}
