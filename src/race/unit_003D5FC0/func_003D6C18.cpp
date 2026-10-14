/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_00359538(void *);
struct Rec { float a,b,c,d; int e; };
struct S { int pad; void *p; int flag; signed char c,d,e,f; Rec rec[4]; int a60,a64,a68; };
extern "C" void func_003D6C18(S *s) {
    if (s->p) {
        int v = *(unsigned char *)func_00359538(s->p);
        switch(v) {
        case 1: s->c=0; s->d=0; s->e=1; s->f=1; break;
        case 2: s->c=0; s->d=0; s->e=1; s->f=2; break;
        case 3: s->c=0; s->d=1; s->e=2; s->f=2; break;
        case 0: default: s->c=0; s->d=1; s->e=2; s->f=3; break;
        }
        Rec *p=s->rec;
        for(int i=0;i<4;i++,p++) {
            p->c = p->b = p->a = 0.0f; p->e=0; p->d=p->c;
        }
        s->a60=0; s->a64=0; s->a68=0x54321098;
    }
}
