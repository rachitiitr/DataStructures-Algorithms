class Solution {
    string get_normalized(string email) {
        int i;
        string local_name = "";
        bool ignore_chars = false;
        for(i = 0; i < email.size(); i++) {
            char c = email[i];
            if (c == '@') {
                break;
            }
            
            if (c == '.' || ignore_chars) continue;
            if (c == '+') {
                ignore_chars = true;
                continue;
            }
            
            local_name += c;
        }
        string domain = email.substr(i);
        return local_name + domain;
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> email_set;
        for(string email: emails) {
            email_set.insert(get_normalized(email));
        }
        
        return email_set.size();
    }
};