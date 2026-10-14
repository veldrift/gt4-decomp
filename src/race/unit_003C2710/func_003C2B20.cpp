/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x,y,z,w,k; };
struct S { float a[14]; V b,c,d,e; float f[5]; int n,m; float g; int h; };
static inline void set(V *p, float x,float y,float z,float w,float k) { p->x=x; p->y=y; p->z=z; p->w=w; p->k=k; }
extern "C" void func_003C2B20(S *p) {
 p->a[0] = 0x1.6666220000000p-2f;
 p->a[1] = 0x1.39eb840000000p+3f;
 p->a[2] = 0x1.ffff780000000p-2f;
 p->a[3] = 0x1.ffff780000000p-2f;
 p->a[4] = 0x1.4000000000000p+3f;
 p->a[5] = 0x1.3332ac0000000p-2f;
 p->a[6] = 0x1.6666220000000p-1f;
 p->a[7] = 0x1.9999120000000p-3f;
 p->a[8] = 0x1.479d4c0000000p-7f;
 p->a[9] = 0x1.47a5b00000000p-6f;
 p->a[10] = 0x1.2c00000000000p+8f;
 p->a[11] = 0x1.3333100000000p-1f;
 p->a[12] = 0x1.ffffcc0000000p+0f;
 p->a[13] = 0x1.3333100000000p-1f;
 p->f[0] = 0x1.70a1be0000000p-4f;
 p->f[1] = 0x1.c28e4e0000000p-4f;
 p->f[2] = 0x1.ccccaa0000000p-1f;
 p->f[3] = 0x1.1686540000000p-7f;
 p->f[4] = 0x1.9000000000000p+6f;
 p->n=5; p->m=20; p->g=200.0f; p->h=0;
 set(&p->b,1.0f,0x1.333310p-1f,0x1.999912p-3f,1.0f,0x1.999998p-1f);
 set(&p->c,0x1.ffffbcp-1f,0x1.ffff78p-2f,0.0f,1.0f,0x1.999912p-2f);
 set(&p->d,0x1.999956p-1f,0.0f,0.0f,1.0f,0x1.333226p-3f);
 set(&p->e,0x1.999912p-3f,0.0f,0.0f,1.0f,0.0f);
}
