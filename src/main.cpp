#include "CodeAnimConfig.h"
#include <iostream>

#include <chaiscript/chaiscript.hpp>

using namespace std;

int main(int argc, char* argv[]) {
    cout << CODEANIM_PROJECT_NAME << " v" << CODEANIM_VERSION_MAJOR << "." << CODEANIM_VERSION_MINOR
         << endl;

    // Get filename from command-line arguments, or default to 'main.chai'.
    const char* filename;
    if (argc < 1)
        filename = "main.chai";
    else
        filename = argv[0];

    // Initialize the ChaiScript engine.
    chaiscript::ChaiScript chai;

    // Start evaluating the ChaiScript code.
    try {
        chai.eval_file("main.chai");
    } catch (chaiscript::exception::eval_error ex) {
        cout << "Failed to evaluate " << ex.filename << endl;
        cout << "-> Reason: " << ex.reason << endl;
        return 1;
    } catch (chaiscript::exception::file_not_found_error ex) {
        cout << "Failed to locate file: " << ex.filename << endl;
        return 1;
    }

    return 0;
}