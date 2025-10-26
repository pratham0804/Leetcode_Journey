class Bank {
public:
    vector<long long> bal;
    Bank(vector<long long>& balance) {
        this->bal = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {

         if(account1 > this->bal.size() || account2 > this->bal.size()) {
          return false;
        }        
         
         if(money <= this->bal[account1-1]){
            this->bal[account1-1] -= money;
            this->bal[account2-1] += money;

            return true;
         }

         return false;
    }
    
    bool deposit(int account, long long money) {
         if(account > this->bal.size()) {
          return false;
        }

        this->bal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
         
        if(account > this->bal.size()) {
          return false;
        }


         if(money <= this->bal[account-1]){
            this->bal[account-1] -= money;
            return true;
         }

         return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */