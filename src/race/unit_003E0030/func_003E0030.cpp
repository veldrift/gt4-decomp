/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row { char pad[0x68]; char label[0x58]; };
struct Result { Row row[6]; char pad[0x68]; int time; int lap; };
extern "C" void func_003E0278(void *, int, int);
extern "C" void func_003E0348(void *, int, int);
static inline Row *getRow(Result *self,int index) {return self->row + index;}
static inline int getValue(Result *self,int time,int first) {if(!first)time-=self->time;return time;}
extern "C" void func_003E0030(Result *self, int index, int time, int lap) {
    int first = index == 0;
    if (first) { self->time = time; self->lap = lap; }
    int oldlap = self->lap;
    if (oldlap == lap) {
        return func_003E0278(self->row[index].label, getValue(self,time,first), first ^ 1);
    }
    func_003E0348(self->row[index].label, oldlap - lap, 1);
}
