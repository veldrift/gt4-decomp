/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { unsigned char pad[2], a,b; int id; float amount,alpha,beta,angle,scale; unsigned short index; unsigned char unknown; signed char kind; float x,y,z,w,nx,ny,nz,d; };
extern "C" void GT4Model__BinStreamWriter__write8u(void *, int);
extern "C" void GT4Model__BinStreamWriter__write8(void *, int);
extern "C" void func_0045AF78(void *, int);
extern "C" void func_0045AFC8(void *, int);
extern "C" void GT4Model__BinStreamWriter__writeFloat(void *, float);
static inline const int &minimum(const int &a, const int &b) { return b<a ? b:a; }
static inline const int &maximum(const int &a, const int &b) { return a<b ? b:a; }
extern "C" void func_003E93D0(Obj *o, void *stream) {
    GT4Model__BinStreamWriter__write8u(stream,o->a);
    GT4Model__BinStreamWriter__write8u(stream,o->b);
    func_0045AFC8(stream,o->id);
    GT4Model__BinStreamWriter__write8u(stream,minimum((int)(o->amount*255.0f/10.0f),255));
    GT4Model__BinStreamWriter__write8u(stream,minimum((int)(o->alpha*255.0f),255));
    GT4Model__BinStreamWriter__write8u(stream,minimum((int)(o->beta*255.0f),255));
    GT4Model__BinStreamWriter__write8(stream,(int)(o->angle*256.0f/360.0f));
    GT4Model__BinStreamWriter__write8(stream,maximum(minimum((int)(o->scale*127.0f*0.5f),127),-128));
    func_0045AF78(stream,o->index);
    GT4Model__BinStreamWriter__write8(stream,o->kind);
    GT4Model__BinStreamWriter__writeFloat(stream,o->x);
    GT4Model__BinStreamWriter__writeFloat(stream,o->y);
    GT4Model__BinStreamWriter__writeFloat(stream,o->z);
    GT4Model__BinStreamWriter__writeFloat(stream,o->w);
    GT4Model__BinStreamWriter__write8(stream,maximum(minimum((int)(o->nx*127.0f),127),-128));
    GT4Model__BinStreamWriter__write8(stream,maximum(minimum((int)(o->ny*127.0f),127),-128));
    GT4Model__BinStreamWriter__write8(stream,maximum(minimum((int)(o->nz*127.0f),127),-128));
}
