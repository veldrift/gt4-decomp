/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Obj { char pad[0x640]; float speed; };
struct Info { u8 pad; u8 n; char gap[0x1a]; u8 side[8]; };
extern "C" float func_003451B0(Obj *) throw();
extern "C" Info *func_00359538(Obj *);
static inline u8 count(Info *p) { return p->n; }
extern "C" int func_0034A950(Obj *o, float *out) {
    if (o->speed < 0x1.638e36p+4f) return 0;
    int dir = -1;
    float f = func_003451B0(o) * 0x1.a1f58ep-4f;
    if (!(f > 0x1.666666p-1f)) {
        dir = 1;
        if (!(f < -0x1.666666p-1f)) return 0;
    }
    int found = 0;
    Info *info = func_00359538(o);
    int i = 0;
    if (i < count(info)) {
    u8 *state = (u8 *)o + 0x1ed;
    do {
        int st = *state;
        state += 0xec;
        if (st == 1 || st == 10) {
            if (dir == -1 && info->side[i] == 0) { found = 1; break; }
            if (dir == 1 && (info->side[i] ^ 1) == 0) { found = 1; break; }
        }
        ++i;
    } while (i < count(info));
    }
    *out = f;
    return found;
}
