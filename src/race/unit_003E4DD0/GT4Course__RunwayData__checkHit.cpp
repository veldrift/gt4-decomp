/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { float x,y,z,w; };
struct Vertex { union { struct { float x,y,z; }; float xyz[3]; }; unsigned short pad; unsigned char shade, grip; };
struct Tri { unsigned short a,b,c; unsigned char type,flags; int pad; };
struct Section { short count; char pad[6]; unsigned short *indices; int tail; };
struct Runway { char pad[0x74]; Vertex *vertices; Tri *triangles; Section *sections; };
struct Hit { union { struct { float x,y,z; }; float xyz[3]; }; int type,flags; float shade,grip; float nx,ny,nz,d; short tri,section; };
extern "C" void GT4Course__anonymous_namespace__outerProduct(void *,void *,void *) throw();
extern "C" float func_003E5FA8(void *,void *) throw();
extern float D_006A39F4;
inline float minf(float a,float b) { float r; asm("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
inline float maxf(float a,float b) { float r; asm("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r; }
inline float rsqrt(float a) { float r; asm("rsqrt.s %0, %1, %2":"=f"(r):"f"(1.0f),"f"(a)); return r; }
inline void sub(Vec *o, const Vertex *a, const Vec *b) { o->x=a->x-b->x; o->y=a->y-b->y; o->z=a->z-b->z; }
extern "C" int GT4Course__RunwayData__checkHit(Runway *self, Hit *out, Vec *start, Vec *end, int section) {
    Vec delta, va,vb,vc,normal;
    float closest=D_006A39F4;
    delta.x=end->x-start->x; delta.y=end->y-start->y; delta.z=end->z-start->z;
    int best=-1;
    Section *sec=self->sections+section;
    float nx,ny,nz,u,v,w;
    for(int i=0;i<sec->count;i++) {
        unsigned short index=sec->indices[i];
        Tri *tri=self->triangles+index;
        Vertex *a=self->vertices+tri->a;
        Vertex *b=self->vertices+tri->b;
        Vertex *c=self->vertices+tri->c;
        sub(&va,a,start); sub(&vb,b,start);
        GT4Course__anonymous_namespace__outerProduct(&normal,&delta,&va);
        float sa=func_003E5FA8(&vb,&normal);
        if(sa>0.0f) continue;
        sub(&vc,c,start);
        float sb=func_003E5FA8(&vc,&normal);
        if(sb<0.0f) continue;
        GT4Course__anonymous_namespace__outerProduct(&normal,&vb,&vc);
        float sc=func_003E5FA8(&delta,&normal);
        if(sc>0.0f) continue;
        sub(&vb,b,(Vec*)a); sub(&vc,c,(Vec*)a);
        GT4Course__anonymous_namespace__outerProduct(&normal,&vb,&vc);
        float denom=func_003E5FA8(&normal,&delta);
        float t;
        if(denom==0.0f) t=0.0f;
        else {
            t=func_003E5FA8(&normal,&va);
            if(t>0.0f) continue;
            if(t<denom) continue;
            t=t/denom;
        }
        if(t<closest) {
            nx=normal.x; ny=normal.y; nz=normal.z;
            u=sa; v=-sb; w=sc;
            best=index; closest=t;
        }
    }
    if(best<0) return 0;
    out->x=(end->x-start->x)*closest+start->x;
    out->y=(end->y-start->y)*closest+start->y;
    out->z=(end->z-start->z)*closest+start->z;
    out->section=section; out->tri=best;
    Tri *tri=self->triangles+best;
    Vertex *a=self->vertices+tri->a;
    Vertex *b=self->vertices+tri->b;
    Vertex *c=self->vertices+tri->c;
    for(int j=0;j<3;j++) {
        float low,high;
        float av=a->xyz[j], bv=b->xyz[j];
        if(av<bv) { low=minf(av,c->xyz[j]); high=maxf(bv,c->xyz[j]); }
        else { high=maxf(av,c->xyz[j]); low=minf(bv,c->xyz[j]); }
        float clipped=minf(high,out->xyz[j]);
        high=maxf(low,clipped);
        out->xyz[j]=high;
    }
    out->type=tri->type&31; out->flags=tri->flags;
    float scale=rsqrt(nx*nx+ny*ny+nz*nz);
    float normalX=nx*scale, normalY=ny*scale, normalZ=nz*scale;
    float total=u+w+v;
    float shadeA=a->shade/255.0f,shadeB=b->shade/255.0f,shadeC=c->shade/255.0f;
    out->shade=minf(maxf(shadeA+((shadeB-shadeA)*v+(shadeC-shadeA)*u)/total,0.0f),1.0f);
    float gripA=(a->grip&127)/127.0f,gripB=(b->grip&127)/127.0f,gripC=(c->grip&127)/127.0f;
    out->grip=minf(maxf(gripA+((gripB-gripA)*v+(gripC-gripA)*u)/total,0.0f),1.0f);
    out->nx=normalX; out->ny=normalY; out->nz=normalZ;
    out->d=-func_003E5FA8(&out->nx,a);
    return 1;
}
