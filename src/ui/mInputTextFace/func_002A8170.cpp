/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void *fn; };
struct E0 { short delta,index; void (*fn)(void *); };
struct E1 { short delta,index; int (*fn)(void *,void *); };
struct E2 { short delta,index; void (*fn)(void *,float,float,float,float); };
struct Obj { int head; Entry *vt; };
struct Info { char pad[0x30]; float x,y; };
extern Info *PDISTD__global_font_manager;
extern "C" void *func_00202C48(void *, unsigned int);
extern "C" void func_00203118(void *, int);
extern "C" float func_00490830(Info *);
extern "C" float func_00490860(Info *);
extern "C" void func_002A8170(void *, Obj *o, unsigned int n) {
    int buf[4];
    float y;
    float x;
    E0 *e0 = (E0 *)((char *)o->vt+0x1d8);
    e0->fn((char *)o+e0->delta);
    func_00202C48(buf,n);
    E1 *e1 = (E1 *)((char *)o->vt+0x198);
    e1->fn((char *)o+e1->delta,buf);
    func_00203118(buf,2);
    Info *p = PDISTD__global_font_manager;
    x = p->x;
    float h = func_00490860(p);
    y = PDISTD__global_font_manager->y;
    y -= h;
    float w = func_00490830(PDISTD__global_font_manager);
    E2 *e2 = (E2 *)((char *)o->vt+0x1a0);
    e2->fn((char *)o+e2->delta,x,y,4.0f,w);
}
