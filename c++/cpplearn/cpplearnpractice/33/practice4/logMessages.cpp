#include "logMessages.h"

int main(){
    logMessages("Starting program...");
    logMessages(1, 2, 3);
    logMessages("The answer is", 42);
    logMessages("Pi is approximately", 3.14159);
    logMessages("Status:", true, "Memory:", 1024, "MB");
    logMessages();
    return 0;
}