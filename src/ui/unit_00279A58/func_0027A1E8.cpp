/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { float x,y,w,h,u,v,a; };
struct O { int pad; char *vt; };
struct E1 { short delta,index; int (*fn)(void *,void *); };
struct E2 { short delta,index; void (*fn)(void *,float,float,float,float,float,float,float,float); };
extern "C" void func_00203148(void *,float,float,float,float);
extern "C" void func_00203118(void *,int);
static inline float clamp(float a) { return a < 1.0f ? a : 1.0f; }
extern "C" void func_0027A1E8(Data *d,O *o) {
    int buf[4];
    if (d->a > 0.0f) {
        func_00203148(buf,1.0f,1.0f,1.0f,clamp(d->a));
        E1 *e = (E1 *)(o->vt+0x198);
        e->fn((char *)o+e->delta,buf);
        func_00203118(buf,2);
        E2 *e2 = (E2 *)(o->vt+0x248);
        e2->fn((char *)o+e2->delta,d->x,d->y,d->x+d->w,d->y+d->h,d->u,d->v,d->u+d->w,d->v+d->h);
    }
}
