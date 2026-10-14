/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long long s64;
typedef int s32;
struct Ent { s64 a; s64 flags; s64 c, d; };
struct M { char pad[8]; Ent ents[0x40E]; s32 cur; };
extern "C" s32 func_00435568(M *, s32, char *);
extern "C" void func_00435690(M *, s32);
extern "C" s32 func_004354F8(M *m, s32 i) {
    if (!func_00435568(m, i, (char *)m + 0x7D08)) return 0;
    Ent *e = &m->ents[i];
    e->flags |= 2;
    m->cur = i;
    func_00435690(m, i);
    return 1;
}
