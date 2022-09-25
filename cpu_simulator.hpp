#include "cpu_simulator_class.h"

CPUlator::CPUlator() : r1(0), r2(0), r3(0), r4(0), r5(0), r6(0), r7(0), r8(0), r9(0), r10(0)
{
    R["r1"] = &r1;
    R["r2"] = &r2;
    R["r3"] = &r3;
    R["r4"] = &r4;
    R["r5"] = &r5;
    R["r6"] = &r6;
    R["r7"] = &r7;
    R["r8"] = &r8;
    R["r9"] = &r9;
    R["r10"] = &r10;
    cond_jump[">"] = {"JG", "JGE"};
    cond_jump[">="] = {"JGE"};
    cond_jump["=="] = {"JE", "JGE", "JLE"};
    cond_jump["<"] = {"JL", "JLE"};
    cond_jump["<="] = {"JLE"};
}

void CPUlator::MOV(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    if (R.find(src) == R.end())
    {
        *R[des] = stoi(src);
        return;
    }
    *R[des] = *R[src];
}

void CPUlator::ADD(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    if (R.find(src) == R.end())
    {
        *R[des] += stoi(src);
        return;
    }
    *R[des] += *R[src];
}

void CPUlator::SUB(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    if (R.find(src) == R.end())
    {
        *R[des] -= stoi(src);
        return;
    }
    *R[des] -= *R[src];
}

void CPUlator::MUL(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    if (R.find(src) == R.end())
    {
        *R[des] *= stoi(src);
        return;
    }
    *R[des] *= *R[src];
}

void CPUlator::DIV(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    if (R.find(src) == R.end())
    {
        *R[des] /= stoi(src);
        return;
    }
    *R[des] /= *R[src];
}

void CPUlator::AND(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    if (R.find(src) == R.end())
    {
        *R[des] &= stoi(src);
        return;
    }
    *R[des] &= *R[src];
}
void CPUlator::OR(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    if (R.find(src) == R.end())
    {
        *R[des] |= stoi(src);
        return;
    }
    *R[des] |= *R[src];
}

std::string CPUlator::CMP(std::string& src, std::string& des)
{
    if (R.find(des) == R.end())
    {
        std::cout << "Invalid operation!" << std::endl;
        exit(1);
    }
    int tmp = (R.find(src) == R.end()) ? std::stoi(src) : *R[src];
    if (*R[des] > tmp)
    {
        return ">";
    }
    else if (*R[des] >= tmp)
    {
        return ">=";
    }
    else if (*R[des] == tmp)
    {
        return "==";
    }
    else if (*R[des] < tmp)
    {
        return "<";
    }
    else
    {
        return "<=";
    }
}

void CPUlator::PRINT(std::string& src)
{
    if (R.find(src) == R.end())
    {
        std::cout << src << std::endl;
    }
    else
    {
        std::cout << *R[src] << std::endl;
    }
}