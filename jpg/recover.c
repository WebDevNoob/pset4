/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[]){
FILE* inptr = fopen("card.raw", "r");
FILE* ouptr = 0;
BYTE byteBlock[512];
char fileName[6];
int jpgCount = 000;

while((fread(&byteBlock,512,1,inptr)==1)){
    if((byteBlock[0] == 0xff)
     && (byteBlock[1] == 0xd8)
     && (byteBlock[2] == 0xff)
     &&((byteBlock[3] == 0xe0) || (byteBlock[3] == 0xe1))){
            if(ouptr != 0){
                fclose(ouptr);
            }        
            sprintf(fileName,"%03d.jpg",jpgCount);
            ouptr = fopen(fileName,"w");
            jpgCount += 001;
    }
    if(ouptr != 0){
        fwrite(byteBlock, 512, 1, ouptr);
    }
} 
fclose(inptr);
}
