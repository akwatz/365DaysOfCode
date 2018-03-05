//This program calculates the number of ways by which an amount can be obtained from given coin values
//using Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

//Function to calculate the number of ways
int numberOfWays(int amount , vector<int> coins){

    int solMat[coins.size()+1][amount+1];        //matrix to store results row will represent
                                                   // number of coins and columns represent amount
    for(int i = 0 ; i < coins.size() + 1 ; i++){

        for(int j = 0 ; j < amount + 1 ; j++){

            if( i == 0  && j != 0)                        //if 0 coins then number 
                solMat[i][j] = 0;               //number of solutions is always 0
            
            else if( j == 0 )                   //if amount is 1 then 
                solMat[i][j] = 1;               //number of solutions is always 1

            else if( coins[i-1] > j )           //if highest valued coins has value greater
                solMat[i][j] = solMat[i-1][j];  //than amount then it contributes 0 solutions
            
            else    
                solMat[i][j] = solMat[i-1][j] + solMat[i][j-coins[i-1]];   //we can include as well as exclude 
                                                            //highest valued coin
        }

    }

    for(int i = 0 ; i < coins.size() + 1 ; i++){
        for(int j = 0 ; j < amount + 1 ; j++)
            cout<<solMat[i][j]<<" ";

        cout<<endl;

    }

    return solMat[coins.size()][amount];

}

int main(){

    int amount;

    cout<<"Enter the amount"<<endl;
    cin>>amount;

    cout<<"Enter number of coins"<<endl;

    int numberOfCoins;
    cin>>numberOfCoins;

    vector<int>coins(numberOfCoins , 0);

    cout<<"Enter value of coins"<<endl;

    for(int i = 0 ; i < numberOfCoins ; i++)
        cin>>coins[i];

    cout<<"Number of ways is:"<<endl;

    cout<<numberOfWays(amount,coins)<<endl;

    return 0;
}