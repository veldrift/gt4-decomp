/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub {char pad0[0xC]; float v0C[3]; float v18[3]; float v24[3]; char pad1[0x4B7-0x30]; signed char c4B7; char pad2[2]; unsigned short u4BA; char pad3[0x568-0x4BC]; float f568, f56C, f570;};
struct Info {char pad[0xC]; float f0C; char pad2[0x44-0x10]; float f44;};
struct Obj {char pad0[4]; int i4; char pad1[8]; char *p10; char pad2[0xF0]; Sub sub; };
extern "C" int func_0036A318(Obj *, int *, float) throw();
extern "C" float func_0034C7C0(int, int);
extern "C" float func_0036CC40(float, float);
extern "C" void func_0036C9F8(float *, float *, float *, float, float, float);
extern "C" int func_0036AE20(Obj *self){
    int r = 0;
    Sub *s = &self->sub;
    float f21 = *(float *)((char *)self + 0x54C);
    if (s->u4BA == 0) return r;
    int sp[4];
    Info *t = (Info *)(self->p10 + 0x308);
    r = func_0036A318(self, sp, 0x1.d70a3ap-2f - (t->f0C - t->f44));
    if (r == 0) return r;
    float f20 = func_0034C7C0(self->i4, s->c4B7);
    float f2 = func_0036CC40(f20, s->f570);
    if (f2 != 0.0f) {
        float f1 = f21 * 0x1.0c1520p-1f;
        if (f1 < f2) s->f570 += f1;
        else if (f2 < -f1) s->f570 -= f1;
        else s->f570 = f20;
    }
    func_0036C9F8(s->v0C, s->v18, s->v24, s->f568, s->f56C, s->f570);
    return 1;
}
