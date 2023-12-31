#include <TerminalDriver.hpp>

int TerminalDriver_test() {
    TerminalDriver terminalDriver;
    terminalDriver.initialize();

    // Example usage: read input character and print it
    char input = terminalDriver.readInput();
    std::string output = "You entered: ";
    output += input;
    terminalDriver.writeOutput(output);

    return 0;
}

int main(int argc, char *argv[]) {
    TerminalDriver_test();
    return 0;
}
