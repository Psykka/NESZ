#include <gtest/gtest.h>
#include "CPU.hpp"

#define GTEST_COUT std::cerr << "\033[0;32m[  MODE    ] \033[0m"

class CPUTest : public ::testing::Test
{
    protected:
        CPU cpu;

        virtual void SetUp()
        {
            for (auto&& i : cpu.bus.ram) cpu.bus.ram[i] = 0;
            cpu.bus.cycles = 0;
            cpu.pc = 0;
        }

        virtual void TearDown(){}
};

TEST_F(CPUTest, TestAllLDAModes)
{
    /**
     * Expects accumulator equal memory data
     */

    GTEST_COUT << "IMM\n";

    cpu.bus.ram[cpu.pc] = 0xa9;
    cpu.bus.ram[cpu.pc + 1] = 0x01;

    cpu.runNextInstruction();
    EXPECT_EQ(0x01, cpu.a);


    GTEST_COUT << "ZP0\n";

    cpu.bus.ram[cpu.pc] = 0xa5;
    cpu.bus.ram[cpu.pc + 1] = 0x02;

    cpu.runNextInstruction();
    EXPECT_EQ(0x02, cpu.a);


    GTEST_COUT << "ZPX\n";

    cpu.bus.ram[cpu.pc] = 0xb5;
    cpu.bus.ram[cpu.pc + 1] = 0x03;

    cpu.runNextInstruction();
    EXPECT_EQ(0x03, cpu.a);


    GTEST_COUT << "ABS\n";

    cpu.bus.ram[cpu.pc] = 0xad;
    cpu.bus.ram[cpu.pc + 1] = 0x04;

    cpu.runNextInstruction();
    EXPECT_EQ(0x04, cpu.a);


    GTEST_COUT << "ABX\n";

    cpu.bus.ram[cpu.pc] = 0xbd;
    cpu.bus.ram[cpu.pc + 1] = 0x05;

    cpu.runNextInstruction();
    EXPECT_EQ(0x05, cpu.a);


    GTEST_COUT << "ABY\n";

    cpu.bus.ram[cpu.pc] = 0xbd;
    cpu.bus.ram[cpu.pc + 1] = 0x06;

    cpu.runNextInstruction();
    EXPECT_EQ(0x06, cpu.a);


    GTEST_COUT << "IZX\n";

    cpu.bus.ram[cpu.pc] = 0xbd;
    cpu.bus.ram[cpu.pc + 1] = 0x07;

    cpu.runNextInstruction();
    EXPECT_EQ(0x07, cpu.a);


    GTEST_COUT << "IZY\n";

    cpu.bus.ram[cpu.pc] = 0xbd;
    cpu.bus.ram[cpu.pc + 1] = 0x08;

    cpu.runNextInstruction();
    EXPECT_EQ(0x08, cpu.a);
}


TEST_F(CPUTest, TestAllLDXModes)
{
    GTEST_COUT << "IMM\n";

    cpu.bus.ram[cpu.pc] = 0xa2;
    cpu.bus.ram[cpu.pc + 1] = 0x01;

    cpu.runNextInstruction();
    EXPECT_EQ(0x01, cpu.x);

    GTEST_COUT << "ZP0\n";

    cpu.bus.ram[cpu.pc] = 0xa6;
    cpu.bus.ram[cpu.pc + 1] = 0x02;

    cpu.runNextInstruction();
    EXPECT_EQ(0x02, cpu.x);

    GTEST_COUT << "ZPY\n";

    cpu.bus.ram[cpu.pc] = 0xb6;
    cpu.bus.ram[cpu.pc + 1] = 0x03;

    cpu.runNextInstruction();
    EXPECT_EQ(0x03, cpu.x);

    GTEST_COUT << "ABS\n";

    cpu.bus.ram[cpu.pc] = 0xae;
    cpu.bus.ram[cpu.pc + 1] = 0x04;

    cpu.runNextInstruction();
    EXPECT_EQ(0x04, cpu.x);

    GTEST_COUT << "ABY\n";

    cpu.bus.ram[cpu.pc] = 0xbe;
    cpu.bus.ram[cpu.pc + 1] = 0x05;

    cpu.runNextInstruction();
    EXPECT_EQ(0x05, cpu.x);
}
