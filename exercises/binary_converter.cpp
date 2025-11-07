/*
  Write a program that given a number as input convert it in binary.

  Output:
  Insert first number: 8
  The binary number is: 1000
*/

#include <iostream>
#include <string>


std::string to_binary(int num) {
  size_t size = sizeof(num) * 8;
  int mask = (1 << size-1); //2147483648;
  auto buffer = std::string(size, '\0');

  int started = 0;
  int skips = 0;
  for (int i = 0; (i + skips) < size; i++){
    if (started == 0) {
        started = (num & mask);
        
        if (started == 0) {
            skips++;
            i--;
        }
    }
    
    if (started){
        switch (num & mask){
            case 0:
                buffer[i] = '0';
                break;
            default:
                buffer[i] = '1';
                break;
        }
        
    }
    num = num << 1;
  }

  return buffer;
}


int main(void){
  std::cout << to_binary(8) << std::endl;
  return 0;
}