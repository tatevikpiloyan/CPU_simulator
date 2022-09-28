#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include "cpu_simulator_class.h"

int main()
{
    std::string opcode;
    std::string operand1;
    std::string operand2;
    std::ifstream a_out;
    a_out.open("fasm.txt");
    if (!a_out.is_open())
    {
        std::cout << "Failed to open the file!" << std::endl;
        return 0;
    }
    while(!a_out.eof())
    {
        a_out >> opcode;
        
        if (opcode ==  "MOV")
        {
            a_out >> operand1;
            a_out >> operand2;
            CPU.MOV(operand2, operand1);
        }
        else if (opcode == "ADD")
        {
            a_out >> operand1;
            a_out >> operand2;
            CPU.ADD(operand2, operand1);
        }
        else if (opcode == "SUB")
        {
            a_out >> operand1;
            a_out >> operand2;
            CPU.SUB(operand2, operand1);
        }
        else if (opcode == "MUL")
        {
            a_out >> operand1;
            a_out >> operand2;
            CPU.MUL(operand2, operand1);
        }
        else if (opcode == "DIV")
        {
            a_out >> operand1;
            a_out >> operand2;
            CPU.DIV(operand2, operand1);
        }
        else if (opcode == "AND")
        {
            a_out >> operand1;
            a_out >> operand2;
            CPU.AND(operand2, operand1);
        }
        else if (opcode == "OR")
        {
            a_out >> operand1;
            CPU.OR(operand2, operand1);
        }
        else if (opcode == "PRINT")
        {
            a_out >> operand1;
            CPU.PRINT(operand1);
        }
        else if (opcode == "RET")
        {
            break;
        }
        else if (opcode == "CMP")
        {
            a_out >> operand1;
            a_out >> operand2;
            a_out >> opcode;
            for (auto& i : CPU.cond_jump[CPU.CMP(operand2, operand1)])
            {
                if (i == opcode)
                {
                    a_out >> operand1;
                    if (CPU.jump[operand1])
                    {
                        a_out.seekg(CPU.jump[operand1]);
                    }
                    else
                    {
                        while (!a_out.eof())
                        {
                            a_out >> operand2;
                            operand2.pop_back();
                            if (operand2 == operand1)
                            {
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (operand1 == "")
            {
                a_out >> operand1;
            }
        }
        else if (opcode == "JMP")
        {
            a_out >> operand1;
            if (CPU.jump[operand1])
            {
                a_out.seekg(CPU.jump[operand1]);
            }
            else
            {
                while(!a_out.eof())
                {
                    a_out >> operand2;
                    operand2.pop_back();
                    if (operand2 == operand1)
                    {
                        break;
                    }
                }
            }
        }
        else if (opcode.find(':') != -1)
        {
            opcode.pop_back();
            CPU.jump.insert(std::make_pair(opcode, a_out.tellg()));
            continue;
        }
        opcode.clear();
        operand1.clear();
        operand2.clear();
    }
    a_out.close();
}

#include "cpu_simulator.hpp"
