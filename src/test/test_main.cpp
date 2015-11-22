//
// Created by cheyulin on 11/21/15.
//
#include "test_unit.h"

int main() {
    string in_file_name = "/home/cheyulin/gitrepos/Open-List-Proportional-Representation/input/input_example6_seatnum_1_group1_5_group2_4.txt";
    IOProcessor my_io_processor;
    Solver *my_solver = my_io_processor.GetSolver(in_file_name);

    TestUnit test_unit;

    test_unit.TestSeatNum(my_solver);

    test_unit.TestGroupsInit(my_solver);

    cout << endl << "First Party" << endl;
    test_unit.TestStrategiesInit(my_solver->getFirst_party_());
    cout << endl << "Second Party" << endl;
    test_unit.TestStrategiesInit(my_solver->getSecond_party_());

    test_unit.TestPayoffCompute(my_solver->getFirst_party_(), my_solver->getSecond_party_(), my_solver);
    cout << endl << endl << "Next : Nash Equ" << endl << endl;
    test_unit.TestNashEquilibriumWithBruteForceSolver(my_solver);

    delete my_solver;

    return 0;
}
