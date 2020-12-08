#include<bits/stdc++.h>
using namespace std;
const int BASE1 = 10;   //原始进制
const int BASE2 = 16;   //目标转换进制
string change( string);   //进制转换
int main(){
    string number("0");
    cin >> number;
    string afterChange;
    afterChange = change(number);
    if(afterChange.length() % 4 ){   //不够4的倍数个时, 在前面补0
        afterChange.insert( 0, 4 - afterChange.length() % 4, '0');
    }
    for( int i = 0; i < afterChange.length(); i++){
        cout << afterChange[i];
        if( (i+1) %4 == 0)   //每输出四个字符另外输出一个" "
            cout << " ";
    }
    return 0;
}
string change( string number){
    stack<int> reminder;
    int i;
    while( number[0] != '\0' ){   //number为空时停止
        string merchant;   //保存商，商为下一次的被除数
        merchant.assign( number.length(), '0');
        int reminder_ = 0;   //保存每一次列竖式除一次后的余数
        for( i = 0; i < number.length(); i++){
            merchant[i] = ( number[i] - '0' + reminder_*BASE1)/BASE2 + '0';
            reminder_ =  ( number[i] - '0' + reminder_*BASE1)%BASE2;
        }
        reminder.push(reminder_);   //把最后的余数压入堆栈
        for( i = 0; i < merchant.length(); i++)
            if(merchant[i] != '0')
                break;
        number = merchant.substr( i, merchant.length() - i);
    }
    string key;
    key.assign( reminder.size(), '0');
    for(i = 0; !reminder.empty(); i++, reminder.pop()){   //利用堆栈先进后出性质, 使得其变为正序
        if(reminder.top() < 10)
            key[i] = reminder.top()+'0';
        else
            key[i] = 'A' + reminder.top() - 10;
    }
    return key;
}
