#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n................................................................\n";
    std::cout << "You are the referee in the The UEFA European Football Championship Final.\nThe match ball is locked into a safe of difficulty:" << Difficulty << " But you forgot the code sheet at home!!\n";
    std::cout << std::endl;        
    std::cout << "The players are waiting, the fans are waiting, everyone is waiting for the final\n...............\nCrack the safe by enter the correct codes to continue...";
    std::cout << "\n................................................................" << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    const int CodeA = rand() % Difficulty + 1; const int CodeB = rand() % Difficulty + Difficulty; const int CodeC = rand() % Difficulty + Difficulty;
    
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The codes add-up to: " << CodeSum << std::endl;
    std::cout << std::endl;
    std::cout << "Multiplying the codes will give you: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    

    std::cout << "Have a guess on 3 numbers: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout <<"Correct, you win! But the ball is locked in another safe in the safe!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "What are you doing? The world is waiting for the final, the players is waiting on the pitch, the crowd goes insane. You could not unlock the safe, You must try again!! " << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL));
    const int MaxDifficulty = 3;
    int LevelDifficulty = 1;
    
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            //increase level difficulty
        }
    }
        
    std::cout << "The UEFA EURO CHAMPIONSHIP WILL NOW BEGIN, WELL DONE, CONGRATULATIONS!";
    
    return 0;
}