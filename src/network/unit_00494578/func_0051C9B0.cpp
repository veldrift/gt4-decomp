struct Head { char data[8]; };
struct Result { Head head; int a; float x,y; int b; float z,w; int c; float u,v; int d; float s,t; };
struct API { char pad[0x50]; void (*get)(Result *); };
extern API *D_0064B4B0;
extern "C" int func_0051BE28() throw();
extern "C" int func_0051BE60() throw();
extern "C" int func_0051C9B0(int arg0, Result *out) {
    Result tmp;
    int ret = func_0051BE28();
    if (ret != 0) return ret;
    {
        int status;
        if (arg0 == 0) {
            status = 0;
            D_0064B4B0->get(&tmp);
            out->head = tmp.head;
            out->a = tmp.a;
            out->x = tmp.x;
            out->y = tmp.y;
            out->b = tmp.b;
            out->z = tmp.z;
            out->w = tmp.w;
            out->c = tmp.c;
            out->u = tmp.u;
            out->v = tmp.v;
            out->d = tmp.d;
            out->s = tmp.s;
            out->t = tmp.t;
        } else status = 4;
        func_0051BE60();
        ret = status;
    }
    return ret;
}
