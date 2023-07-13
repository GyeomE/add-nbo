#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

void add_num(uint8_t buf1[], uint8_t buf2[]) {
       	uint32_t* p1 = reinterpret_cast<uint32_t*>(buf1);
        uint32_t num1 = ntohl(*p1);

        uint32_t* p2 = reinterpret_cast<uint32_t*>(buf2);
        uint32_t num2 = ntohl(*p2);

        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",num1, num1, num2, num2, num1+num2, num1+num2);
}

int main(int argc, char *argv[]) {
        uint8_t buffer1[32], buffer2[32];
        FILE *f1, *f2;

        f1 = fopen(argv[1], "rb");
        f2 = fopen(argv[2], "rb");

        fread(buffer1, 1, 32, f1);
        fread(buffer2, 1, 32, f2);

        add_num(buffer1, buffer2);
        fclose(f1);
        fclose(f2);
}
