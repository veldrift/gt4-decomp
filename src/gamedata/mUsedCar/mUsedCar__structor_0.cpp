// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mUsedCar:hObject {void* const data;mUsedCar(void*) __asm__("func_001B24A0");virtual ~mUsedCar();};
mUsedCar::mUsedCar(void* value):data(value){}
