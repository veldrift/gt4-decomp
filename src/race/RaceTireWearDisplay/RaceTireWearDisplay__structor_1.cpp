struct Obj { char pad[0x14]; void *table; int f18; int color; int wheel[4]; };
extern "C" char D_0067F6E0[];
extern "C" int func_003AEBA8(Obj *);
extern "C" void func_003A5F70(Obj *self) {
    func_003AEBA8(self); self->table=D_0067F6E0; self->f18=0; self->color=0x80877B80;
for(int i=3;i>=0;i--) self->wheel[i]=0;
}
