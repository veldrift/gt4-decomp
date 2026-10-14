/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Table {float v[8];};
extern Table D_00620BA8, D_00620BF8;
struct Cfg {char pad[0x202]; unsigned short rpm; char pad2[0x247-0x204]; unsigned char mode;};
struct Obj {char pad[0x10]; Cfg *cfg; char pad2[0x600-0x14]; float f600;};
extern "C" float func_00359568(Table *, float);
extern "C" float func_00368128(Obj *self, float a, float b){
    Cfg *c = self->cfg;
    if (self->f600 < (float)c->rpm * 0x1.acee9cp-4f) return 0.0f;
    if (b <= 0.0f) return 0.0f;
    {
        float x = a * 60.0f / 0x1.921fb4p+2f;
        float t;
        if (c->mode == 1) t = func_00359568(&D_00620BA8, x);
        else t = func_00359568(&D_00620BF8, x);
        return b * t;
    }
}
