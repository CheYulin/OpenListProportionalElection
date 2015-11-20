//
// Created by cheyulin on 11/19/15.
//

#include "open_list_data.h"

using namespace election;

Profile election::Solver::ComputePayOff(Strategy *first_party_strategy,
                                        Strategy *second_party_strategy) {
    int sum_votes = 0;
    auto *first_party_partition_info = &(first_party_strategy->partition_info);
    auto *second_party_partition_info = &(second_party_strategy->partition_info);
    for (auto iter = first_party_partition_info->begin(); iter != first_party_partition_info->end(); iter++) {
        sum_votes += iter->first;
    }
    for (auto iter = second_party_partition_info->begin(); iter != second_party_partition_info->end(); iter++) {
        sum_votes += iter->first;
    }

    int remaining_seats = seats_num;
    int quota = sum_votes / seats_num;
    multimap<GroupVoteCount, Group *> first_party_remaining_potential = first_party_strategy->partition_info;
    multimap<GroupVoteCount, Group *> second_party_remaining_groups = second_party_strategy->partition_info;


    return nullptr;
}

Strategy::Strategy(multimap<GroupVoteCount, Group *> partition_info) : partition_info(partition_info),
                                                                       possible_nash_equilibrium(vector<Strategy>()),
                                                                       max_pay_off(-1) {

}

Profile::Profile(Strategy *first_party_strategy, Strategy *second_party_strategy, StrategyPayOff first_party_payoff,
                 StrategyPayOff second_party_payoff) : first_party_strategy(first_party_strategy),
                                                       second_party_strategy(second_party_strategy),
                                                       first_party_payoff(first_party_payoff),
                                                       second_party_payoff(second_party_payoff) {

}