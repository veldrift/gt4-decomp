/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
struct VI {short delta, index; int (*fn)(void *);};
struct VF {short delta, index; float (*fn)(void *,void *);};
#define NULL 0

#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))

extern "C" void func_00345A20(void *);                      /* extern */
extern "C" char *func_00359510(void *) throw();                        /* extern */
extern "C" void func_0035D350(void *) throw();                      /* extern */
extern "C" f32 func_0036A578(void *, s32, f32, f32);   /* extern */
extern "C" f32 func_0036A690(void *, s32, f32, f32);   /* extern */
extern "C" void func_0036C9F8(void *, void *, void *, f32, f32, f32); /* extern */
extern "C" void func_00395760(s32, void *);  /* extern */
extern "C" s32 func_003F4E40(void *);                           /* extern */
extern "C" s32 func_003F4EA0(void *);                          /* extern */
extern "C" s32 func_003F7C80();                                /* extern */
extern "C" f32 func_003F7CA8(void *, s32, f32, f32); /* extern */
extern "C" f32 func_0057D118(f32, f32);                        /* extern */

struct V {float x,y,z;};
static inline void convert(float *d, const V *s) {
 float z=-s->y; d[1]=s->z; float x=s->x; d[2]=z; d[0]=x;
}
static inline void convertInit(float *d, const V *s) { float x=s->x,y=s->z,z=-s->y; d[0]=x; d[1]=y; d[2]=z; }
static inline int mapWheel(char *p,int i) { if(i < (int)*(u8 *)(p+1)) return *((u8 *)p+0x14+i); return 0; }
extern "C" s32 func_003630C0(char *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    struct Query { f32 x,y,z; s32 id; f32 height; char rest[0x2c]; } query;
    union Vec {V v; f32 a[3];} pos;
    char *sp50;
    char *base14;
    char *base8;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    s32 temp_v1_3;
    s32 var_s5;
    s32 var_v0;
    s32 var_fp;
    s32 var_s7;
    u8 *var_s1_2;
    s32 temp_v1_2;
    s32 var_a2;
    char *temp_a1;
    char *temp_a2;
    char *temp_s2;
    char *temp_s3;
    char *temp_v0;
    char *temp_v0_2;
    char *temp_v1;
    char *var_s0;
    char *var_s0_2;
    char *var_s1;

    var_s5 = 0;
    var_s7 = 0;
    var_fp = 0;
    pos.v.y = fparg1;
    temp_s2 = arg0 + 0x104;
    pos.v.z = fparg2;
    pos.v.x = fparg0;
    temp_s3 = M2C_FIELD(arg0, char **, 0x10);
    convertInit(&query.x, &pos.v);
    query.id = arg1;
    func_00395760(M2C_FIELD(arg0, s32 *, 8), &query);
    M2C_FIELD(temp_s2, f32 *, 0) = fparg0;
    M2C_FIELD(temp_s2, s32 *, 0x4A8) = query.id;
    M2C_FIELD(temp_s2, f32 *, 4) = fparg1;
    float height = query.height;
    temp_f0 = height + M2C_FIELD(temp_s3, f32 *, 0x3C);
    M2C_FIELD(temp_s2, f32 *, 0x568) = 0x0.0p+0f;
    M2C_FIELD(temp_s2, f32 *, 0x56C) = 0x0.0p+0f;
    temp_f12 = M2C_FIELD(temp_s2, f32 *, 0x568);
    M2C_FIELD(temp_s2, f32 *, 0x570) = fparg3;
    M2C_FIELD(temp_s2, f32 *, 8) = temp_f0;
    func_0036C9F8(arg0 + 0x110, arg0 + 0x11C, arg0 + 0x128, temp_f12, temp_f12, fparg3);
    pos.v.z = height;
    func_00345A20(arg0);
    temp_v0 = func_00359510(temp_s3);
    if (M2C_FIELD(temp_v0, u8 *, 1) != 0) {
        var_s1 = arg0 + 0x7B8;
        var_s0 = arg0 + 0x164;
        do {
            f32 ox = M2C_FIELD(var_s0, f32 *, 0xC);
            f32 oy = M2C_FIELD(var_s0, f32 *, 0x10);
            f32 oz = M2C_FIELD(var_s0, f32 *, 0x14);
            temp_f0 = M2C_FIELD(temp_s2, f32 *, 0) + ox;
            temp_f1 = M2C_FIELD(temp_s2, f32 *, 4) + oy;
            temp_f2 = M2C_FIELD(temp_s2, f32 *, 8) + oz;
            pos.v.x = temp_f0;
            pos.v.y = temp_f1;
            pos.v.z = temp_f2;
            convert((float *)var_s1, &pos.v);
            M2C_FIELD(var_s1, s32 *, 0xC) = (s32) M2C_FIELD(temp_s2, s32 *, 0x4A8);
            func_00395760(M2C_FIELD(arg0, s32 *, 8), var_s1);
            if (M2C_FIELD(var_s1, u8 *, 0x30) == 0) {
                M2C_FIELD(var_s0, f32 *, 0x8C) = (f32) M2C_FIELD(var_s1, f32 *, 0x10);
                M2C_FIELD(var_s0, s8 *, 0x89) = func_003F4E40(var_s1);
                M2C_FIELD(var_s0, u8 *, 0x8A) = (u8) M2C_FIELD(var_s1, u8 *, 0x32);
                M2C_FIELD(var_s0, u8 *, 0x8B) = (u8) M2C_FIELD(var_s1, u8 *, 0x33);
                var_s7 += M2C_FIELD(var_s1, u8 *, 0x33) & 1;
                if (func_003F4EA0(var_s1) != 0) {
                    var_fp += 1;
                }
            } else {
                M2C_FIELD(var_s0, s8 *, 0x89) = 0;
                M2C_FIELD(var_s0, u8 *, 0x8A) = 0U;
                M2C_FIELD(var_s0, u8 *, 0x8B) = 0U;
                M2C_FIELD(var_s0, f32 *, 0x8C) = (f32) (height + M2C_FIELD(var_s0, f32 *, 0x14));
            }
            var_s5 += 1;
            var_s1 += 0x34;
            var_s0 += 0xEC;
        } while (var_s5 < (s32) M2C_FIELD(temp_v0, u8 *, 1));
    }
    M2C_FIELD(temp_s2, u8 *, 0x4B1) = (u8) (M2C_FIELD(temp_s2, u8 *, 0x4B1) & 0xEF);
    if (var_s7 != 0) {
        temp_a1 = M2C_FIELD(arg0, char **, 4);
        temp_v1 = M2C_FIELD(temp_a1, char **, 0x10140);
        VI *entry = (VI *)(temp_v1 + 0x180);
        if (entry->fn(temp_a1 + entry->delta) != 0) {
            M2C_FIELD(temp_s2, u8 *, 0x4B1) = (u8) (M2C_FIELD(temp_s2, u8 *, 0x4B1) | 0x10);
        }
    }
    M2C_FIELD(temp_s2, s8 *, 0x62C) = var_fp;
    M2C_FIELD(temp_s2, s8 *, 0x62D) = var_s7;
    for (var_s5 = 0; var_s5 < (s32)M2C_FIELD(temp_v0, u8 *, 1); var_s5++) {
        sp50 = temp_v0 + 4;
        base14 = temp_s3 + 0x14;
        base8 = temp_s3 + 8;
        var_s0_2 = arg0 + 0x164 + var_s5 * 0xEC;
            var_a2 = mapWheel(temp_v0, var_s5);
            temp_v1_3 = var_a2 * 0x58;
            temp_f1_2 = (M2C_FIELD(((var_a2 * 4) + temp_s3), f32 *, 0x1040) / (f32) *(u8 *)(sp50 + var_a2)) + M2C_FIELD((temp_v1_3 + (s32)base14), f32 *, 0x330);
            M2C_FIELD(var_s0_2, s8 *, 0xB3) = 0;
            M2C_FIELD(var_s0_2, f32 *, 0x48) = temp_f1_2;
            M2C_FIELD(var_s0_2, f32 *, 0x4C) = temp_f1_2;
            M2C_FIELD(var_s0_2, f32 *, 0x94) = (f32) M2C_FIELD((temp_v1_3 + (s32)base8), f32 *, 0x310);
            temp_f0_2 = func_003F7CA8(temp_s3, var_s5, 0.0f, 0.0f);
            M2C_FIELD(var_s0_2, f32 *, 0x1C) = 0x0.0p+0f;
            M2C_FIELD(var_s0_2, f32 *, 0) = temp_f0_2;
            M2C_FIELD(var_s0_2, f32 *, 0x18) = 0x0.0p+0f;
            if (func_003F7C80() == 2) {
                M2C_FIELD(var_s0_2, f32 *, 0x18) = 0x0.0p+0f;
                M2C_FIELD(var_s0_2, f32 *, 0x1C) = (f32) M2C_FIELD(var_s0_2, f32 *, 0);
            }
            M2C_FIELD(var_s0_2, f32 *, 4) = func_0036A578(temp_s3, var_s5, 0.0f, 0.0f);
            temp_f0_3 = func_0036A690(temp_s3, var_s5, 0.0f, 0.0f);
            M2C_FIELD(var_s0_2, f32 *, 8) = temp_f0_3;
    }
    func_0035D350(arg0);
    M2C_FIELD(temp_s2, f32 *, 0x568) = (f32) M2C_FIELD(temp_s2, f32 *, 0x574);
    M2C_FIELD(temp_s2, f32 *, 0x56C) = (f32) M2C_FIELD(temp_s2, f32 *, 0x578);
    temp_f0_3 = func_0057D118(M2C_FIELD(temp_s3, f32 *, 0x40) - M2C_FIELD(temp_s3, f32 *, 0x44), M2C_FIELD(temp_s3, f32 *, 0x18));
    temp_f12_2 = M2C_FIELD(temp_s2, f32 *, 0x568) + temp_f0_3;
    M2C_FIELD(temp_s2, f32 *, 0x568) = temp_f12_2;
    func_0036C9F8(temp_s2 + 0xC, temp_s2 + 0x18, temp_s2 + 0x24, temp_f12_2, M2C_FIELD(temp_s2, f32 *, 0x56C), M2C_FIELD(temp_s2, f32 *, 0x570));
    M2C_FIELD(temp_s2, f32 *, 8) = (f32) (M2C_FIELD(temp_s2, f32 *, 0x38) + (M2C_FIELD(temp_s2, f32 *, 0x2C) * M2C_FIELD(temp_s3, f32 *, 0x3C)));
    func_00345A20(arg0);
    temp_a2 = M2C_FIELD(arg0, char **, 4);
    if (M2C_FIELD(temp_a2, u8 *, 0xCBDE) == 2) {
        M2C_FIELD(temp_s2, f32 *, 0x4A4) = 0x0.0p+0f;
    } else {
        temp_v0_2 = M2C_FIELD(temp_a2, char **, 0x10140);
        VF *entry = (VF *)(temp_v0_2 + 0x108);
        M2C_FIELD(temp_s2, f32 *, 0x4A4) = entry->fn(temp_a2 + entry->delta, arg0);
    }
    M2C_FIELD(temp_s2, s32 *, 0x628) = (s32) M2C_FIELD(temp_s2, s32 *, 0x4A8);
    float x = M2C_FIELD(temp_s2, f32 *, 0x30);
    float y = M2C_FIELD(temp_s2, f32 *, 0x34);
    float z = M2C_FIELD(temp_s2, f32 *, 0x38);
    M2C_FIELD(temp_s2, f32 *, 0x624) = z;
    M2C_FIELD(temp_s2, f32 *, 0x61C) = x;
    M2C_FIELD(temp_s2, f32 *, 0x620) = y;
    M2C_FIELD(temp_s2, s32 *, 0x650) = 0;
    return 0;
}
