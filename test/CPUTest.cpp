#include <gtest/gtest.h>
#include "CPU.hpp"

#define GTEST_COUT std::cout << "\033[0;32m[  MODE    ] \033[0m"

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
}
