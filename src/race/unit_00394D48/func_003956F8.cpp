/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { unsigned short lo; short hi; };
struct Src { int a; float b; int c; unsigned char d; char padD[3]; unsigned char e; char pad11[3]; float f,g,h,i,j,k; Pair pair; };
struct Dst { char pad[12]; int x; float b,f,g,h,i,j,k; char pad2c[5]; unsigned char d,z,e; };
extern "C" void func_003956F8(Dst *o, Src *s) {
    o->b = s->b;
    o->h = s->h;
    o->i = s->i;
    o->j = s->j;
    o->k = s->k;
    Pair *p = &s->pair;
    o->x = (p->hi << 16) | p->lo;
    o->d = s->d;
    o->z = 0;
    o->e = s->e;
    o->f = s->f;
    o->g = s->g;
}
