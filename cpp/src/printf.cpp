#include <cstdio>
#include <string>

int main() 
{
    int age = 25;
    double score = 85.5;
    std::string name = "Bob";
    
    printf("Name: %s\nAge: %d\nScore: %.1f\nHex: 0x%x\n", 
           name.c_str(), age, score, 255);
    return 0;
}