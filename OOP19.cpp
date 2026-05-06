#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <queue>


            ////1. is a word ISOGRAMM or not

//bool is_isogramm_1(const std::string& s) {
//    std::stack<char> MyStack;
//    for (int i = 0; i < s.length(); i++) {
//        
//        if (!MyStack.empty() && s[i] == MyStack.top())
//            return true;
//        MyStack.push(s[i]);
//    }
//    return false;
//}
        ////It turned out if a word contains any non-unique letter (not consecutive) - the word cannot be considered an isogram. e.g. MAMA;

//bool is_isogramm(const std::string& s) {
//    std::set<char> set;
//    for (int i = 0; i < s.length(); i++) {
//        if (!(set.insert(s[i])).second) {
//            return false;
//        }
//    }
//    return true;
//}
//
//
//int main()
//{
//    std::string s1 = "hello";
//    std::string s2 = "python";
//    std::string s3 = "isogramm";
//
//    
//
//    if (is_isogramm(s1)) {
//        std::cout << "is isogramm";
//    }
//    else {
//        std::cout << "is not isogramm";
//    }
//}



/*            //2. count avery instanse of overy symbol

int main() {
    std::string s1 = "hello world, you are beautifull!";

    std::map<char, int> map;
    
    for (char ch: s1) {
        map[ch]++;
    }
    for (const auto& [ch, count] : map) {
        std::cout << ch << ":" << count << std::endl;
    }

}*/






/*            //3. take out middle element from stack.
int main() {
    std::stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    //stack1.push(6);

    int mid = stack1.size() / 2;;
        

    std::stack<int> buff;

    for (int i = 0; i < mid; i++) {
        buff.push(stack1.top());
        stack1.pop();
    }

    stack1.pop();

    while (!buff.empty()) {
        stack1.push(buff.top());
        buff.pop();
    }

    // print
    while (!stack1.empty()) {
        std::cout << stack1.top() << "  ";
        stack1.pop();
    }
    std::cout << " \n ";

}
*/



            //4. take out middle element from stack, and revers the SAME stack
int main() {
    std::stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    //stack1.push(6);

    int mid = stack1.size() / 2;;


    std::queue<int> buff;
    int i = 0;
    while (!stack1.empty()) {
        if(i!=mid)
            buff.push(stack1.top());
        stack1.pop();
        i++;
    }







    
    while (!buff.empty()) {
        stack1.push(buff.top());
        buff.pop();
    }

    // print
    while (!stack1.empty()) {
        std::cout << stack1.top() << "  ";
        stack1.pop();
    }
    std::cout << " \n ";

}