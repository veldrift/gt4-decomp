/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row { char pad[0x68]; char label[0x58]; };
struct Result { Row row[6]; char pad[0x68]; int time; int lap; };
extern "C" void func_003E0278(void *, int, int);
extern "C" void func_003E0348(void *, int, int);
static inline char *label(Result *self, int index) { return self->row[index].label; }
static inline bool isFirst(int index) { return index == 0; }
extern "C" void func_003E00B0(Result *self, int index, int time, int lap) {
    if (isFirst(index)) {
        self->time = time;
        self->lap = lap;
        return func_003E0348(label(self,index), lap, 0);
    }
    if (self->lap == lap) {
        return func_003E0278(label(self,index), time - self->time, 1);
    }
    func_003E0348(label(self,index), lap, 0);
}
