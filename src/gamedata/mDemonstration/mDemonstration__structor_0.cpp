// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mDemonstration:hObject {void* const data;mDemonstration(void*) __asm__("func_0015DA20");virtual ~mDemonstration();};
mDemonstration::mDemonstration(void* value):data(value){}
