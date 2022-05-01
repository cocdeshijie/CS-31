//
//  Player.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mPriorRunningTotal(0), mRunningTotal(0), mScore( 0 )
    {
        
    }
    
    void Player::roll( Die d1, Die d2 )
    {
        // cheating...
        mDie1 = d1;
        mDie2 = d2;
    }

    void Player::roll( )
    {
        mDie1.roll();
        mDie2.roll();
    }
    
    Die Player::getDie1() const
    {
        return( mDie1 );
    }

    Die Player::getDie2() const
    {
        return( mDie2 );
    }
    
    void Player::addDiceToRunningTotal( )
    {
        if (mRunningTotal >= 16)
        {
            mPriorRunningTotal = mRunningTotal;
            mRunningTotal = mPriorRunningTotal + mDie1.getValue();
        }
        else
        {
            mPriorRunningTotal = mRunningTotal;
            mRunningTotal = mPriorRunningTotal + mDie1.getValue() + mDie2.getValue();
        }
    }

    int  Player::getRunningTotal( ) const
    {
        return( mRunningTotal );
    }

    int  Player::getPriorRunningTotal( ) const
    {
        return( mPriorRunningTotal );
    }

    void Player::resetRunningTotal( )
    {
        mRunningTotal = 0;
        mPriorRunningTotal = 0;
    }

    std::string Player::whatWasRolled()
    {
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        return( s );
    }
    
    int  Player::getScore() const
    {
        return( mScore );
    }

    void Player::wonTurn()
    {
        mScore = mScore + 1;
    }

    void Player::won21()
    {
        mScore = mScore + 2;
    }

}
