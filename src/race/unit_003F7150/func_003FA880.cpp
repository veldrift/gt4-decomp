/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { char pad0[0x89]; unsigned char kind; char pad1[14]; float v; char pad2[0x50]; };
struct Obj { char pad[0x164]; Entry entries[1]; };
extern "C" float func_003FA880(Obj *o,int i) {
 Entry *e=o->entries+i;
 unsigned char k=e->kind;
 if(k==1 || k==10 || k==11) return 0.0f;
 float r=e->v;
 r=-(r+1.5f);
 if(r<0.0f) r=0.0f;
 else { r+=0.5f; if(r>1.0f) r=1.0f; }
 return r;
}
