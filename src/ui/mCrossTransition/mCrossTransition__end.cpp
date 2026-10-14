/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec4 { float x,y,z,w; };
struct E0 { short d,i; void (*fn)(void *); };
struct E1 { short d,i; void (*fn)(void *,int); };
struct EP { short d,i; void (*fn)(void *,Vec4 *); };
struct E4 { short d,i; void (*fn)(void *,float,float,float,float); };
struct E5 { short d,i; void (*fn)(void *,int,float,float,float,float); };
struct VT {
    char p0[0x198]; EP e198; E4 e1a0;
    char p1[0x1c0-0x1a8]; E1 e1c0;
    char p2[8]; E0 e1d0; E0 e1d8;
    char p3[0x230-0x1e0]; E0 e230;
    char p4[8]; E0 e240;
    char p5[8]; E5 e250;
};
struct Dev { int pad; VT *vt; };
struct Self { char pad[0x18]; int state, enabled, kind; float progress, opacity, step, x, y; int black, waiting; };
extern "C" int func_0024D1B0(Self *);
extern "C" void func_0024D2D8(Self *);
extern "C" void func_00203118(Vec4 *,int);
extern "C" Vec4 *func_00203148(Vec4 *,float,float,float,float);
extern "C" void mCrossTransition__end(Self *self,Dev *dev) {
    Vec4 color;
    if (func_0024D1B0(self) != 0) {
        switch (self->state) {
        case 0: func_0024D2D8(self); break;
        case 1: break;
        case 2: {
            float f = self->progress - self->step;
            self->progress = f;
            if (f < 0.0f) {
                self->progress = 0.0f;
                if (self->waiting == 0) self->waiting = 1;
                else {
                    if (self->kind == 0) {
                        E0 *e = &dev->vt->e230;
                        e->fn((char *)dev + e->d);
                    }
                    func_0024D2D8(self);
                }
            }
            break;
        }
        case 3: return;
        default: break;
        }
        if (self->kind == 0) {
            if (self->progress > 0.0f) {
                E1 *a = &dev->vt->e1c0;
                a->fn((char *)dev + a->d,0);
                E0 *b = &dev->vt->e1d0;
                b->fn((char *)dev + b->d);
                func_00203148(&color,1.0f,1.0f,1.0f,self->progress);
                EP *c = &dev->vt->e198;
                c->fn((char *)dev + c->d,&color);
                func_00203118(&color,2);
                E0 *d = &dev->vt->e240;
                d->fn((char *)dev + d->d);
            }
        } else if (self->enabled != 0) {
            E5 *e = &dev->vt->e250;
            e->fn((char *)dev + e->d,-1,0.0f,0.0f,self->x,self->y);
            if (self->black != 0) {
                func_00203148(&color,0.0f,0.0f,0.0f,self->opacity);
                E1 *a = &dev->vt->e1c0;
                a->fn((char *)dev + a->d,0);
                E0 *b = &dev->vt->e1d8;
                b->fn((char *)dev + b->d);
                EP *c = &dev->vt->e198;
                c->fn((char *)dev + c->d,&color);
                E4 *d = &dev->vt->e1a0;
                d->fn((char *)dev + d->d,0.0f,0.0f,640.0f,480.0f);
                func_00203118(&color,2);
            }
        }
    }
}
