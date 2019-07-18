#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// string splitting function
vector<string> split(string str, char d = ' '){
    vector<string> res;
    string tkn;
    istringstream tknstm(str);
    while(getline(tknstm, tkn, d)) res.push_back(tkn);
    return res;
}
// simple assembly interpreter function
unordered_map<string, int> assembler(vector<string> program){
    unordered_map<string, int> reg;
    for(int i = 0; i < program.size(); i++){
        vector<string> ins = split(program[i]);
        string cmd = ins[0], var = ins[1], val = (ins.size() > 2)? ins[2] : "";
        if(cmd == "mov") {
            auto mpfind = reg.find(val);
            if(mpfind == reg.end()) reg[var] = stoi(val);
            else reg[var] = reg[val];
        }
        if(cmd == "inc")
            reg[var]++;
        if(cmd == "dec")
            reg[var]--;
        if(cmd == "jnz" && (reg.find(var) != reg.end()? reg[var] : stoi(var)))
            i += stoi(val) - 1;
    }
    return reg;
}
// for testing purpose
Describe(SolutionTest)
{
  It(Simple1)
  {
    std::vector<std::string> program{ "mov a 5", "inc a", "dec a", "dec a",
      "jnz a -1", "inc a" };
    std::unordered_map<std::string, int> out{ { "a", 1 } };
    Assert::That(assembler(program), Equals(out));
  }
  It(Simple2)
  {
    std::vector<std::string> program{ "mov a -10", "mov b a", "inc a", "dec b",
      "jnz a -2" };
    std::unordered_map<std::string, int> out{ { "a", 0 }, { "b", -20 } };
    Assert::That(assembler(program), Equals(out));
  }
  It(Complex1)
  {
    std::vector<std::string> program{ "mov a 1", "mov b 1", "mov c 0",
      "mov d 26", "jnz c 2", "jnz 1 5", "mov c 7", "inc d", "dec c", "jnz c -2",
      "mov c a", "inc a", "dec b", "jnz b -2", "mov b c", "dec d", "jnz d -6",
      "mov c 18", "mov d 11", "inc a", "dec d", "jnz d -2", "dec c",
      "jnz c -5" };
    std::unordered_map<std::string, int> out{ { "a", 318009 }, { "b", 196418 },
      { "c", 0 }, { "d", 0 } };
    Assert::That(assembler(program), Equals(out));
  }
  It(Complex2)
  {
    std::vector<std::string> program{ "mov d 100", "dec d", "mov b d",
    "jnz b -2", "inc d", "mov a d", "jnz 5 10", "mov c a" };
    std::unordered_map<std::string, int> out{ { "a", 1 }, { "b", 0 },
      { "d", 1 } };
    Assert::That(assembler(program), Equals(out));
  }
  It(Complex3)
  {
    std::vector<std::string> program{ "mov c 12", "mov b 0", "mov a 200",
      "dec a", "inc b", "jnz a -2", "dec c", "mov a b", "jnz c -5", "jnz 0 1",
      "mov c a" };
    std::unordered_map<std::string, int> out{ { "a", 409600 }, { "b", 409600 },
      { "c", 409600 } };
    Assert::That(assembler(program), Equals(out));
  }
};
