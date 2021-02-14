#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Extracts amount with a minimal number of coins present in stock. 
 * @param amount: amount to extract
 * @param stock: available coins
 * @param solution: coins used that perform the total amount (or not)
*/
void select(int &amount, stack<int> stock, vector<int> &solution)
{
    for (size_t i = stock.size(); i > 0; i--)
    {
        if (amount - stock.top() < 0)
            stock.pop();
        else
        {
            solution.push_back(stock.top());
            amount = amount - stock.top();
            stock.pop();       
        }      
    }
}

int main()
{
    int amount = 8;
    stack<int> stock;
    stock.push(1);
    stock.push(1);
    stock.push(1);
    stock.push(2);
    stock.push(2);
    stock.push(2);
    stock.push(2);
    stock.push(5);
    stock.push(5);
    stock.push(10);

    vector<int> solution;
    select(amount, stock, solution);

    if (amount == 0)
    {
        cout << "Arrived to optimal solution." << endl
             << "Change: {";
        for(int i = 0; i < solution.size() - 1; i++)
        {
            cout << solution.at(i) << ", ";
        }
        cout << solution.at(solution.size()-1) << "}" << endl;

    }
    else
    {
        cout << "Not arrived to optimal solution." << endl;
    }
    return 0;
}