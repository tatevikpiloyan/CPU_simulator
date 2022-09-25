#ifndef CPULATOR
#define CPULATOR

class CPUlator
{
private:
    int r1, r2, r3, r4, r5, r6, r7, r8, r9, r10;
    
public:
    std::map<std::string, int*> R;
    std::map<std::string, int> jump;
    std::map<std::string, std::vector<std::string>> cond_jump;

public:
    CPUlator();

public:
    void MOV(std::string& src, std::string& des);
    void ADD(std::string& src, std::string& des);
    void SUB(std::string& src, std::string& des);
    void MUL(std::string& src, std::string& des);
    void DIV(std::string& src, std::string& des);
    void AND(std::string& src, std::string& des);
    void OR(std::string& src, std::string& des);
    std::string CMP(std::string& src, std::string& des);
    void PRINT(std::string& src);

} CPU;

#endif