#include <CodeAnimConfig.h>
#include <iostream>

#include <chaiscript/chaiscript.hpp>

#include "api/Production.hpp"

using namespace std;
using namespace CodeAnim;

int main(int argc, char* argv[]) {
    cout << CODEANIM_PROJECT_NAME << " v" << CODEANIM_VERSION_MAJOR << "." << CODEANIM_VERSION_MINOR
         << endl;

    // Get filename from command-line arguments, or default to 'main.chai'.
    const char* filename;
    if (argc < 2)
        filename = "main.chai";
    else
        filename = argv[1];

    // Initialize the ChaiScript engine.
    chaiscript::ChaiScript chai;
    chai.add(chaiscript::constructor<Production(int, int, int)>(), "Production");
    chai.add(chaiscript::user_type<Production>(), "Production");
    chai.add(chaiscript::fun(&Production::show), "show");

    // Start evaluating the ChaiScript code.
    try {
        cout << "Evaluating " << filename << "..." << endl;
        chai.eval_file(filename);
    } catch (chaiscript::exception::eval_error &ex) {
        cout << "Failed to evaluate " << ex.filename << endl;
        cout << "-> Reason: " << ex.reason << endl;
        return 1;
    } catch (chaiscript::exception::file_not_found_error &ex) {
        cout << "Failed to locate file: " << ex.filename << endl;
        return 1;
    }

    return 0;
}