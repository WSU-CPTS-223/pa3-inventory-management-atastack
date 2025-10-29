#ifndef REPL_H
#define REPL_H

#include <string>
#include <vector>
using namespace std;

class Repl
{
private:
    void h_find(const vector<string>& tokens);
    void h_list(const vector<string>& tokens);
    vector<string> token_size(const string& input);

public:
    Repl();
    bool load_inventory(const string& filename);
    void process_cmd(const string& cmd);
};



#endif 