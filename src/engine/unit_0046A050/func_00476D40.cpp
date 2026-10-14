/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed char s8;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};
struct Str {
    char *p;
};
struct Val {
    s32 type;
    s32 v;
};
struct Node {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s8 unkC;
    char padD[0x3];
    s32 unk10;
    char pad14[0x4];
    Val val;
};
struct Obj5 {
    char pad[0x164];
    void *unk164;
};
struct Obj3 {
    char pad[8];
    s32 unk8;
};

extern char D_00659E20[];
extern char D_006AD5B0[];

extern "C" void func_004768C0(Val *) throw();
extern "C" void func_00476768(Val *, Val *) throw();
extern "C" void *func_00476790(void *, void *) throw();
extern "C" void func_004767E8(Val *) throw();
extern "C" s32 func_00477298(Val *);
extern "C" s32 func_0047A858(s32);
extern "C" void func_00480F78(void *);
extern "C" void func_00480FA0(void *, s32);
extern "C" void *func_004812C8(void *, Str *);
extern "C" void free(void *) throw();
extern "C" s32 func_00575E60(s32, s32);
extern "C" s32 func_0057DA20(char *, const char *, ...);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" s32 exception__structor_0(s32);
extern "C" char *strobe__toUpper(void *);
extern "C" void *strobe__Any__setMember(void *, u32, u32, const char *, u32);

struct StrT {
    char *p;
    char pad[0xC];
};

extern "C" void func_0047A5D8(s32 *, s32, s32, Val *, u32, s32, void *);

extern "C" void func_00476D40(Val *arg0, Val *arg1, s32 arg2, u32 arg3, s32 arg4, Obj5 *arg5) {
    char buf[16];
    s32 tmp[4];
    StrT str;
    struct ByteTag { s8 value; } b1;
    void *s5 = arg5->unk164;
    s32 type = 7;
    func_004768C0(arg0);
    arg0->type = type;
    s32 v_s1 = exception__structor_0(0x20);
    Node *v_s0 = (Node *)(v_s1 + 4);
    *(s32 *)v_s1 = 0;
    b1.value = 0;
    u8 *p_s0 = (u8 *)&b1;
    v_s0->unk4 = 0;
    s32 t1 = func_00575E60(0x10, 0x1c);
    v_s0->unk8 = 0;
    v_s0->unk4 = t1;
    v_s0->unkC = *p_s0;
    *(s32 *)t1 = 0;
    *(s32 *)(v_s0->unk4 + 4) = 0;
    *(s32 *)(v_s0->unk4 + 8) = v_s0->unk4;
    *(s32 *)(v_s0->unk4 + 0xc) = v_s0->unk4;
    v_s0->unk10 = 0;
    Val *s2 = (Val *)(v_s1 + 0x18);
    func_00476768(s2, arg1);
    func_004767E8(s2);
    if ((arg1->type ^ 13) == 0) {
        v_s0->unk10 = func_0047A858(func_00477298(s2));
    }
    arg0->v = v_s1;
    switch (arg1->type) {
    case 13: {
        s32 *pt = tmp;
        s32 value = func_00477298(arg1);
        func_0047A5D8(pt, value, arg2, arg0, arg3, arg4, arg5);
        func_004768C0((Val *)pt);
        break;
    }
    case 15: {
        u32 i = 0;
        if (arg3 != 0) {
            StrT *pk = &str;
            do {
                func_0057DA20(buf, D_006AD5B0, i);
                void *m = (void *)(arg0->v + 4);
                StrT *ps = &str;
                char *src = buf;
                Rep *g = (Rep *)D_00659E20;
                char *r;
                if (g->sel != 0) {
                    r = strobe__toUpper(g);
                } else {
                    r = (char *)g + 0x10;
                    g->ref++;
                }
                ps->p = r;
                strobe__Any__setMember(ps, 0, (u32)-1, src, func_0057F260(src));
                void *v = func_004812C8(m, (Str *)pk);
                func_00476790(v, (void *)(((Obj3 *)s5)->unk8 - 8));
                Rep *q = (Rep *)(pk->p - 0x10);
                if (--q->ref == 0) free(q);
                func_00480F78(s5);
                i++;
            } while (i < arg3);
        }
        break;
    }
    default:
        func_00480FA0(s5, arg3);
        break;
    }
}
