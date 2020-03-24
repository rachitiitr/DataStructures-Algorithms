//g++  5.4.0
//Are private functions really private? Well...
//Checkout video at: https://youtu.be/TVKsaq7Bohs
#include <bits/stdc++.h>

using namespace std;

class SocialWebsite{
private:
protected:
public:
    virtual void secret() {} ;
};

class Facebook: public SocialWebsite{
private:
    string fbPassword;
    
    void secret(){
        cout << "The Facebook password is: " << fbPassword << endl;
        cout << "Its risky, but its fine to print here as it's a private function\n";
    }
public:
    Facebook(string pwd) {
        fbPassword = pwd;
    }
};

int main()
{
    Facebook f("Rachit95@fb");
    
    SocialWebsite *ptr = &f;
    ptr->secret();
}
