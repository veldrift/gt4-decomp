/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xDC]; char *str; };
struct Event { char pad[0x20]; unsigned key; int pad24; float x,y; };
struct Context { char pad[0x1D50]; int mode; };
struct Rep { int len,cap,ref,sel; };
struct VObj { int pad; char *vt; };
struct VE { short d,i; int (*fn)(void *); };
extern char D_00698A18[];
extern "C" int mWidget__onKeyPress(Obj*,Context*,Event*);
extern "C" int func_00233E08(Obj*) throw();
extern "C" int func_00234810(Obj*,int,float,float) throw();
extern "C" void *func_00235C00(Obj*);
extern "C" void func_00277850(void*,Context*,void*);
extern "C" void func_00282D80(void*,Context*,void*);
extern "C" void func_00277438(void*,int);
extern "C" void func_00282968(void*,int);
extern "C" void func_0023FB80(void*);
extern "C" void func_0023F8C8(int,const char*);
extern "C" void func_0023DDF0(void*,int);
static inline int vcall(VObj *o) { VE *e=(VE*)(o->vt+0x190);return e->fn((char*)o+e->d); }
static inline int move(Obj*self,float x,float y,int*buf) {
    if(func_00234810(self,0,x,y)) {
        func_0023FB80(buf);
        char **p=&self->str;
        char *str=*p;
        int len=((Rep*)(str-16))->len;
        int val=buf[0];
        const char *text;
        if(len==0) text=D_00698A18;
        else {str[len]=0;text=*p;}
        func_0023F8C8(val,text);
        func_0023DDF0(buf,2);
    }
    return 1;
}
extern "C" int mRootWindow__onKeyPress(Obj*self,Context*ctx,Event*event) {
    int buf[4];
    int r=mWidget__onKeyPress(self,ctx,event);
    if(r==0) {
        switch(event->key) {
        case 0xFF0D:
            r=0;
            func_00277850(buf,ctx,func_00235C00(self));
            r = vcall((VObj*)buf[0]) ? 2 : 0;
            func_00277438(buf,2);
            break;
        case 0xFF1B: {
            r=0;
            void *p=func_00235C00(self);
            func_00282D80(buf,ctx,p?p:self);
            r = vcall((VObj*)buf[0]) ? 2 : 0;
            func_00282968(buf,2);
            break;
        }
        case 0xFF52: case 0xFF97:
            if(ctx->mode) r=move(self,0.0f,-1.0f,buf);
            break;
        case 0xFF54: case 0xFF99:
            if(ctx->mode) r=move(self,0.0f,1.0f,buf);
            break;
        case 0xFF51: case 0xFF96:
            if(ctx->mode) r=move(self,-1.0f,0.0f,buf);
            break;
        case 0xFF53: case 0xFF98:
            if(ctx->mode) r=move(self,1.0f,0.0f,buf);
            break;
        case 0xFEFA:
            if(func_00233E08(self)) r=move(self,event->x,event->y,buf);
            break;
        case 0xFEE4:
            if(func_00233E08(self)) r=move(self,-0.70710677f,-0.70710677f,buf);
            break;
        case 0xFEE5:
            if(func_00233E08(self)) r=move(self,0.70710677f,-0.70710677f,buf);
            break;
        case 0xFEE6:
            if(func_00233E08(self)) r=move(self,-0.70710677f,0.70710677f,buf);
            break;
        case 0xFEE7:
            if(func_00233E08(self)) r=move(self,0.70710677f,0.70710677f,buf);
            break;
        default: break;
        }
    }
    return r;
}
