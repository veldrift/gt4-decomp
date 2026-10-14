/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pos { float x,y,z; };
struct Vec { float x,y,z; int tag; };
struct Body { Pos p; char pad[0x440-12]; unsigned char idx; char gap[0x466-0x441]; signed char state; char tail[0x4a8-0x467]; int tag; };
struct Car { char pad[0x104]; Body body; };
struct Self { char pad[0xcbd8]; void *course; };
extern float D_00622020[][3];
extern "C" float RaceCourse__getVPosition(void *, Vec *);
extern "C" float DynamicsConductor__getCourseVbyCenter(Self *self, Car *car) {
    Body *b = &car->body;
    Vec v;
    if (b->state == 4) {
        float *p = D_00622020[b->idx];
        v.x = p[0];
        v.y = p[2];
        v.z = -p[1];
    } else {
        v.x = b->p.x;
        v.y = b->p.z;
        v.z = -b->p.y;
    }
    v.tag = b->tag;
    return RaceCourse__getVPosition(self->course, &v);
}
