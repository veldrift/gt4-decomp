/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { char pad[0x74]; int type; char pad78[0x14]; unsigned int size; int x; int dest; };
struct Obj { int error; Base *base; char pad8[0x20]; long offset; int dest; unsigned int size; };
struct Args { int dest; unsigned int size; };
extern "C" int func_004AF7D0(Obj *) throw();
extern "C" int func_004AF818(Obj *) throw();
extern "C" int func_004AF8B8(Obj *,Args *) throw();
extern "C" int func_004AF910(Obj *,Args *) throw();
extern "C" int func_004AF968(Obj *,int,long) throw();
extern "C" int func_004AF9D8(Obj *) throw();
extern "C" int func_004AFA88(int unused,Obj *o) {
    int spare[4];
    Args a0,a1;
    int busy=0;
    unsigned int rem;
    int result;
    Base *b=o->base;
    long off=o->offset;
    unsigned int total=b->size;
    unsigned int size=o->size;
    int dest=o->dest;
    if (off<0 || (unsigned int)(int)off>=total) goto fail;
    rem=total-(int)off;
    if (rem<size) size=rem;
    result=func_004AF7D0(o);
    if (result<0) return result;
    busy=1;
    if (off) {
        result=func_004AF968(o,0,off);
        if (result<0) return result;
        if (func_004AF9D8(o)!=off) {func_004AF818(o);goto fail;}
    }
    {
        int type=b->type;
        b->dest=dest;
        int n;
        switch(type) {
        case 0: { Args *p=&a0; p->dest=dest; a0.size=size; n=func_004AF8B8(o,p); break; }
        case 1: { Args *p=&a1; p->dest=dest; a1.size=size; n=func_004AF910(o,p); break; }
        default: n=-1; o->error=2; break;
        }
        result=func_004AF818(o);
        return n<0?n:result;
    }
fail:
    if (busy) func_004AF818(o);
    o->error=14;
    return -1;
}
