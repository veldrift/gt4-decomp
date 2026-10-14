/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Dev { char pad[0x74]; s32 f74; char pad2[0x94 - 0x78]; void *f94; };
struct Ctx {
    s32 status;
    Dev *dev;
    char pad[0x28 - 8];
    long f28;
    void *f30;
    u32 f34;
};
struct Obj { char pad[0x10]; s32 f10; };
struct Req { s32 a; void *b; s32 c; s32 d; };

extern "C" void *func_004AC430(u32, s32);
extern "C" s32 func_004AF7D0(void *);
extern "C" s32 func_004AF818(void *);
extern "C" s32 func_004AFA20(void *, void *);
extern "C" void free(void *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A47D4(void *, const void *, unsigned) throw();

static inline s32 narrow(long x) { return x; }
static inline void request(Req *r, s32 type, void *data, s32 n) { r->a = type; r->b = data; r->c = n; }

extern "C" s32 func_0044D540(Obj *arg0, Ctx *arg1) {
    char raw[0x80];
    Req r1;
    Req r2;
    void *mem = 0;
    Dev *dev = arg1->dev;
    s32 id = narrow(arg1->f28);
    u32 want = arg1->f34;
    void *user = arg1->f30;
    char *hdr;
    s32 status;
    u32 size;
    s32 fail;
    if (arg0)
        id = arg0->f10;
    if (dev->f74 != 0) {
        arg1->status = 2;
        return -1;
    }
    s32 rv = func_004AF7D0(arg1);
    if (rv < 0)
        return rv;
    status = 0;
    hdr = (char *)(((u32)raw + 0x3F) & ~0x3F);
    r1.c = 0x20;
    r1.a = 1;
    r1.b = hdr;
    if (func_004AFA20(arg1, &r1) == 0) {
        goto fail2;
    }
    {
    u32 magic = *(u32 *)hdr;
    if (magic == 0x4E474E45 || magic == 0x54534E49) {
        size = *(u32 *)(hdr + 0x14);
        if (want == 0)
            want = size;
        if (want < size) {
            goto fail3;
        }
        mem = user;
        if (mem == 0) {
            mem = func_004AC430(want, 1);
            if (mem == 0) {
                goto fail3;
            }
        }
        r1.a = 1;
        r1.b = mem;
        r1.c = want - 0x20;
        if (func_004AFA20(arg1, &r1) == 0) {
            goto fail2;
        }
        func_005A47D4((char *)mem + 0x20, mem, size - 0x20);
        func_005A4724(mem, hdr, 0x20);
        r2.a = 2;
        r2.b = (void *)id;
        r2.c = *(s32 *)((char *)mem + 0x10);
        if (func_004AFA20(arg1, &r2) == 0) {
            goto fail2;
        }
        dev->f94 = mem;
    } else {
        status = -1;
        arg1->status = 2;
    }
    }
done:
    {
        s32 r = func_004AF818(arg1);
        return status < 0 ? status : r;
    }
fail3:
    fail = 3;
    goto cleanup;
fail2:
    fail = 2;
cleanup:
    func_004AF818(arg1);
    if (user == 0)
        free(mem);
    arg1->status = fail;
    return -1;
}
