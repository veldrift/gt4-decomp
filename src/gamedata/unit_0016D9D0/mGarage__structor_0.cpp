// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mGarage:hObject {void* const data;mGarage(void*) __asm__("func_00170960");virtual ~mGarage();};
mGarage::mGarage(void* value):data(value){}
