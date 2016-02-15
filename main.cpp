#include <iostream>
#include <App/App.hpp>

using namespace std;


int main() {
    App app;
    try{
        app.run();
    }
    catch (std::string error)
    {
        std::cerr<<error<<std::endl;
    }
    return 0;
}