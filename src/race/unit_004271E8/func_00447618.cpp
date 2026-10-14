/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Db { char p[0x1E4]; int f1E4; };
struct Self { char pad[0xA0]; u32 key; };
extern Db D_006235A8;
extern "C" int SPEC_DATABASE__DatabaseStorage__getRow_2(void *, int, int, void *);
extern "C" void func_00449CD8(int, int);

extern "C" void func_00447618(Self *self) {
    int buf[4];
    unsigned long u = self->key;
    if (SPEC_DATABASE__DatabaseStorage__getRow_2(&D_006235A8, (int)u, 0x28, buf) != 0) {
        func_00449CD8(D_006235A8.f1E4, buf[0]);
    }
}
