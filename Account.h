#pragme once
#include<string>
#include<vector>
#include<pair>
class Account{
    private:
        std::vector<std::pair<std::string, int>> expenses;
    public:
        std::string name;
        void addExpense(std::string category, int amount);
        void show();
};
