//
//  TurnEvaluator.cpp
//  Project7
//
//  Created by Howard Stahl on 6/2/21.
//  Copyright © 2021 Howard Stahl. All rights reserved.
//

#include "TurnEvaluator.h"

#include <iostream>

namespace cs31
{

TurnEvaluator::TurnEvaluator( Player human, Player computer )
{
    mHumanTotal = human.getRunningTotal();
    mComputerTotal = computer.getRunningTotal();
    mComputerPriorRunningTotal = computer.getPriorRunningTotal();
}

// TODO: complete evaluateTurn( )
// based on the player totals saved by the constructor call,
// determine which possibility has occurred
TurnEvaluator::POSSIBILITIES TurnEvaluator::evaluateTurn( ) const
{
    POSSIBILITIES result = HUMANWON;
    if (mHumanTotal > mComputerTotal)
    {
        result = HUMANWON;
    }
    if (mComputerTotal > mHumanTotal)
    {
        result = COMPUTERWON;
    }
    if (mHumanTotal > 21)
    {
        result = HUMANBUSTED;
    }
    if (mComputerTotal > 21) {
        result = COMPUTERBUSTED;
    }
    if (mHumanTotal == 21)
    {
        result = HUMANBLACKJACK;
    }
    if (mComputerTotal == 21) {
        result = COMPUTERBLACKJACK;
    }
    if (mHumanTotal == mComputerTotal)
    {
        result = NOONEWON;
    }
    if (mComputerTotal == 21 && mHumanTotal == 21) {
        result = BOTHHAVEBLACKJACK;
    }
    return( result );
}

// should the computer keep playing?
bool TurnEvaluator::determineComputerStrategy() const
{
    bool result = true;
    // if human busted, don't bust yourself
    if (mHumanTotal > 21)
        result = false;
    // stop if the computer has won!
    if (mComputerPriorRunningTotal > mHumanTotal)
        result = false;
    // stop once you 17 or more
    if (mComputerTotal > 17)
        result = false;
    return( result );

}

}
