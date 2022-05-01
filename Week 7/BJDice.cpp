//
//  BJDice.cpp
//  Project7
//

#include "BJDice.h"
#include "TurnEvaluator.h"
#include <iostream>
using namespace std;

namespace cs31
{
    // human goes first
    BJDice::BJDice() : mHuman(), mComputer(), mBoard()
    {
        
    }
    
    std::string BJDice::display( std::string msg )
    {
        using namespace std;
        std::string s( "" );
        
        s = mBoard.display();
        if (!isGameOver())
        {
            s = s + msg;
        }

        return( s );
    }

    void BJDice::humanPlay( )
    {
        mHuman.roll();
        mHuman.addDiceToRunningTotal();
        mBoard.updateBoardMessageForHuman(mHuman);
    }

    void BJDice::humanPlay( Die d1, Die d2 )
    {
        // cheating...
        mHuman.roll( d1, d2 );
        mHuman.addDiceToRunningTotal( );
        mBoard.updateBoardMessageForHuman( mHuman );
    }

    void BJDice::humanEndTurn()
    {
        mBoard.setHumanTotal( mHuman.getRunningTotal() );
        mBoard.buildBoardMessageForHumanEndTurn();
    }
    
    void BJDice::computerPlay( )
    {
        mComputer.roll();
        mComputer.addDiceToRunningTotal();
        mBoard.updateBoardMessageForComputer(mComputer);
    }
    
    void BJDice::computerPlay( Die d1, Die d2 )
    {
        // cheating...
        mComputer.roll( d1, d2 );
        mComputer.addDiceToRunningTotal( );
        mBoard.updateBoardMessageForComputer( mComputer );
    }
    
    void BJDice::computerEndTurn()
    {
        mBoard.setComputerTotal( mComputer.getRunningTotal() );
        mBoard.buildBoardMessageForComputerEndTurn();
    }

    void BJDice::finishTurn()
    {
        // now that both turns have ended, figure out what happened
        TurnEvaluator evaluator( mHuman, mComputer );
        TurnEvaluator::POSSIBILITIES outcome = evaluator.evaluateTurn();
        mBoard.clearBoardMessage();
        switch (outcome) {
            case TurnEvaluator::HUMANWON:
                mHuman.wonTurn();
                mBoard.buildBoardMessageForHumanWon();
                break;
            case TurnEvaluator::HUMANBLACKJACK:
                mHuman.won21();
                mBoard.humanHitBlackJackMessage();
                break;
            case TurnEvaluator::HUMANBUSTED:
                mComputer.wonTurn();
                mBoard.humanBustedMessage();
                break;
            case TurnEvaluator::COMPUTERWON:
                mComputer.wonTurn();
                mBoard.buildBoardMessageForComputerWon();
                break;
            case TurnEvaluator::COMPUTERBLACKJACK:
                mComputer.won21();
                mBoard.computerHitBlackJackMessage();
                break;
            case TurnEvaluator::COMPUTERBUSTED:
                mHuman.wonTurn();
                mBoard.computerBustedMessage();
                break;
            case TurnEvaluator::BOTHHAVEBLACKJACK:
            case TurnEvaluator::NOONEWON:
                mBoard.nooneWonTurnMessage();
                break;
        }
        
        
        mBoard.setHumanScore( mHuman.getScore() );
        mBoard.setComputerScore( mComputer.getScore() );
        mBoard.setComputerTotal(0);
        mBoard.setHumanTotal(0);
        mBoard.setRunningTotal(0);
        mHuman.resetRunningTotal();
        mComputer.resetRunningTotal();
    }

    // TODO: complete determineGameOutcome()
    BJDice::GAMEOUTCOME  BJDice::determineGameOutcome( ) const
    {
        if (mBoard.getHumanTotal() == 10)
        {
            return ( GAMEOUTCOME::HUMANWONGAME );
        }
        if (mBoard.getComputerTotal() == 10)
        {
            return ( GAMEOUTCOME::COMPUTERWONGAME );
        }
        else
        {
            return ( GAMEOUTCOME::GAMENOTOVER );
        }
    }
    
    bool BJDice::isGameOver()
    {
        GAMEOUTCOME result = determineGameOutcome();
        if (result != GAMEOUTCOME::GAMENOTOVER)
        {
            if (result == GAMEOUTCOME::HUMANWONGAME)
            {
                mBoard.buildBoardMessageForHumanWon();
            }
            else if (result == GAMEOUTCOME::COMPUTERWONGAME)
            {
                mBoard.buildBoardMessageForComputerWon();
            }
        }
        return( result != GAMEOUTCOME::GAMENOTOVER );
    }

    Player BJDice::getHuman() const
    {
        return( mHuman );
    }
    
    Player BJDice::getComputer() const
    {
        return( mComputer );
    }
    
    Board  BJDice::getBoard() const
    {
        return( mBoard );
    }

    bool BJDice::computerKeepPlaying( )
    {
        TurnEvaluator evaluator( mHuman, mComputer );
        return( evaluator.determineComputerStrategy() );
    }

}
