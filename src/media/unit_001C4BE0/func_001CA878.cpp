/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0[0x54]; int active; char p58[0x14]; int id; int flags; int mode; int status; };
extern char D_00693F50[], D_00693F68[], D_00693F78[];
extern "C" int func_005C1D18();
extern "C" int func_005C1D20(int *);
extern "C" int func_005C1D30(int,int,int*);
static inline int mapped(int bits) {
 return bits & 8 ? 32 : 0;
}
static inline int convert(int bits) {
 int f=mapped(bits) | (bits&1);
 int g=f|8;
 if (!(bits&2)) g=f;
 if (bits&4) g |= 2;
 int h=(bits&16) | g;
 if(bits&32) h |= 4;
 return h;
}
static inline int maxflag(int id) { return id != 57 ? 8 : 32; }
extern "C" int func_001CA878(Obj *o) {
 int sp[4];
 if (!o->active) return (int)D_00693F50;
 sp[0] = func_005C1D18();
 int id=func_005C1D20(sp);
 o->id=id;
 if(id<0) return (int)D_00693F68;
 sp[1]=0; sp[2]=0; sp[3]=0;
 int r;
 if(func_005C1D30(id,0,sp+1) || func_005C1D30(o->id,2,sp+2) || (r=func_005C1D30(o->id,1,sp+3))) return (int)D_00693F78;
 int f=convert(sp[2]);
 int status=sp[1]&1;
 int mode=sp[3]&15;
 int flags=f & ((maxflag(o->id)*2)-1);
 o->status=status;
 o->mode=mode;
 o->flags=flags;
 return r;
}
