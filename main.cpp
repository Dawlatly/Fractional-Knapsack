#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

//A simple structure for the items that will be generated
struct Item{
    int itemno;
    float itemvalue;
    float itemweight;
    float itembenefit;

};

int main()
{
    srand(time(0));
    bool done = false;
    int number;
    float knapsack;
    int totben = 0;
    priority_queue<float> pq;//The heap-based priority queue


    //Prompting the user to enter the number of items to be generated and the weight of the knapsack
    cout << "Enter the Number of items" << endl;
    cin >> number;
    cin.clear();
    cin.ignore();
    cout << "Enter the weight of knapsack" << endl;
    cin >> knapsack;
    Item items[number];

    cout << "------------------------------------------------------------------------------------------" << endl;
    cout<<setw(15) <<"item number |" << setw(25) << "item benefit |" << setw(25) << "item weight |" << setw(25) << "item value |" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    //for loop generates the items with random weights and benefits
    for (int i = 0; i < number; i++){
       items[i].itembenefit =  rand() % 100;
       items[i].itemno = i+1;
       items[i].itemweight =  1 + rand() % 10;
       items[i].itemvalue = items[i].itembenefit / items[i].itemweight;

       cout << setw(5) << items[i].itemno << setw(10) <<" |" ;
       cout << setw(15) << items[i].itembenefit << setw(10) << " |" ;
       cout << setw(15)<< items[i].itemweight   << setw(10) << " |" ;
       cout << setw(20)<< items[i].itemvalue <<setprecision(3)<< setw(5) << " |" <<endl;
       cout << "------------------------------------------------------------------------------------------" << endl;


    }

    cout << endl << endl;

    //The items are then pushed onto the queue

    for(int i = 0;i <number;i++){
        pq.push(items[i].itemvalue);

    }

    cout << "After Knapsack algorithm " << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout<<setw(15) <<"item number |" << setw(15) << "item benefit |" << setw(15) << "item weight |" << setw(15) << "item value |" << setw(15) <<"total benefit |" <<setw(15) << "item portions |" <<setw(10) << "knapsack |" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
                //Implementation of the algorithm until the priority queue is empty
                for(int i =0;!done && !pq.empty();i++){
                    //searches for the item in the items array that matches the one in the priority queue
                    if(pq.top() == items[i].itemvalue){
                        //once it is found then the weight of the knapsack is compared with its weight
                        if(items[i].itemweight < knapsack){
                            knapsack=knapsack -items[i].itemweight;
                            totben = totben + items[i].itembenefit;
                            cout << setw(5) << items[i].itemno  <<setw(10)<<" |"<<setw(5)<<items[i].itembenefit<<setw(10) <<" |" <<setw(5)<< items[i].itemweight <<setw(10)<<" |" <<setw(5) << items[i].itemvalue << setw(10) << " |";
                            cout << setw(5) << totben << setw(10) << " |" << setw(5) << " " << setw(10) << " |" <<setw(5) << knapsack << setw(5) << " |"<< endl;
                            cout << "----------------------------------------------------------------------------------------------------" << endl;
                            pq.pop();
                            i = -1;

                        }else if(items[i].itemweight == knapsack){
                             //done variable represents the knapsack has been completely filled up
                             //totben is the total benefits that are increased whenever a new item goes into the knapsack
                             knapsack=knapsack -items[i].itemweight;
                             totben = totben + items[i].itembenefit;
                             cout << setw(5) << items[i].itemno  <<setw(10)<<" |"<<setw(5)<<items[i].itembenefit<<setw(10) <<" |" <<setw(5)<< items[i].itemweight <<setw(10)<<" |" <<setw(5) << items[i].itemvalue << setw(10) << " |";
                             cout << setw(5) << totben << setw(10) << " |" << setw(5) << " " << setw(10) << " |" <<setw(5) << knapsack << setw(5) << " |"<< endl;
                             cout << "----------------------------------------------------------------------------------------------------" << endl;
                             done = true;

                        }else if(items[i].itemweight > knapsack){
                            //done variable represents the knapsack has been completely filled up
                            //totben is the total benefits that are increased whenever a new item goes into the knapsack
                            totben = totben + items[i].itembenefit;
                            cout << setw(5) << items[i].itemno  <<setw(10)<<" |"<<setw(5)<<items[i].itembenefit<<setw(10) <<" |" <<setw(5)<< items[i].itemweight <<setw(10)<<" |" <<setw(5) << items[i].itemvalue << setw(10) << " |";
                            cout << setw(5) << totben << setw(10) << " |" << setw(5) << knapsack/items[i].itemweight << setw(10) << " |" <<setw(5) << 0 << setw(5) << " |"<< endl;
                            cout << "----------------------------------------------------------------------------------------------------" << endl;
                            done = true;
                        }
                    }else{

                    }
    }

return 0;
}
