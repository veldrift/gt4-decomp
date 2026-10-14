/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int used,value; };
struct Self { char pad0[0x3c]; unsigned int n; char pad40[8]; Entry *entries; };
struct Obj { int destroy,advance,retreat,put,get,other; int self; unsigned int type,index; int value; int pad[2]; };
extern "C" int func_00538BF8(int *,int);
extern "C" void func_00511B90(),func_00511DC0(),func_00511DE8(),func_00511BB8(),func_00511C90(),func_00511EB8(),func_00511C48(),func_00511D68(),func_00511FB8();
extern "C" int func_005119F0(Self *self,unsigned int type,int *out) {
    int p;
    if (self && out && type<3 && type) {
    if(func_00538BF8(&p,0x30)) return 2;
    {
    ((Obj *)p)->self=(int)self;
    ((Obj *)p)->type=type;
    ((Obj *)p)->destroy=(int)func_00511B90;
    ((Obj *)p)->get=(int)func_00511DC0;
    ((Obj *)p)->other=(int)func_00511DE8;
    switch(type) {
    case 1:
        ((Obj *)p)->advance=(int)func_00511BB8;
        ((Obj *)p)->retreat=(int)func_00511C90;
        ((Obj *)p)->put=(int)func_00511EB8;
        break;
    case 2:
        ((Obj *)p)->advance=(int)func_00511C48;
        ((Obj *)p)->retreat=(int)func_00511D68;
        ((Obj *)p)->put=(int)func_00511FB8;
        break;
    default:
        goto invalid_type;
    }
    for(unsigned int i=0;i<self->n;++i) {
        if(self->entries[i].used) {
            int value=self->entries[i].value;
            ((Obj *)p)->index=i;
            ((Obj *)p)->value=value;
            break;
        }
    }
    *out=p;
    return 0;
    }
invalid_type:
    if(p) ((void (*)(int))((Obj *)p)->destroy)(p);
    }
    return 1;
}
