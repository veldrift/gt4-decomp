/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;

struct VEnt {
    short delta;
    short pad;
    int (*fn)(void *);
};
struct VT {
    char pad0[0x10];
    VEnt e10;
    VEnt e18;
};
struct Src {
    VT *vt;
};

extern "C" void *func_005A4724(void *, const void *, unsigned int);

struct Handle {
    Src *src;
    int id;
    u8 *data;
    Handle(Src *s, int id) throw() __asm__("func_004B2388");
    void assign(int id) throw() __asm__("func_004B23F0");
    ~Handle() __asm__("func_004B22D8");
    static void operator delete(void *) __asm__("func_005C1628");
};

extern "C" {
int func_004B2518(Handle *, char *, int) throw();
int func_004B27D0(Handle *, char *, int, unsigned *) throw();

}

struct Result {
    int x[3];
    Result() throw() __asm__("func_004B2A18");
    Result(int, u8 *) throw() __asm__("func_004B2A80");
};

static inline unsigned rd16(const u8 *p)
{
    return p[0] | (p[1] << 8);
}

extern "C" Result func_004B30B8(Src *obj, int id, char *key, int len)
{
    char *buf = (char *)__builtin_alloca(len + 4);
    int total = len + 4;
    buf[0] = id >> 24;
    buf[1] = id >> 16;
    buf[2] = id >> 8;
    buf[3] = id;
    func_005A4724(buf + 4, key, len);
    VEnt *e = &obj->vt->e18;
    Handle h(obj, e->fn((char *)obj + e->delta));
    if (rd16(h.data) == 1) {
        do {
            h.assign(func_004B2518(&h, buf, total));
        } while (rd16(h.data) == 1);
    }
    unsigned sp10 = 0;
    if (func_004B27D0(&h, buf, total, &sp10) == 0) {
        return Result();
    } else {
        VEnt *e2 = &h.src->vt->e10;
        int end = e2->fn((char *)h.src + e2->delta);
        u8 *d = h.data;
        int offset = end - sp10 * 8;
        offset -= 4;
        struct Bytes { u8 bytes[1]; };
        u8 *p = &((Bytes *)d)->bytes[offset];
        return Result(id, d + rd16(p));
    }
}
