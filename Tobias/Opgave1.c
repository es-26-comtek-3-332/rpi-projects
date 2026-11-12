/* 
-----TEST kode-----

Her laves et int array for 20 studerende. En int fylder normalt 4 Bytes. 
*/
#include <stdio.h>
void main() {
    int students[20];
    printf("%zu", sizeof(students));
}